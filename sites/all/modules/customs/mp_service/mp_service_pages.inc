<?php

/**
 * auto reply message
 */
function mp_service_callback($account){
  $weObj = _mp_service_init_wechat($account);
  $weObj->valid();
  // $menu = $weObj->getMenu();
  // watchdog('menu', '<pre>'.print_r($menu,true), array(), WATCHDOG_NOTICE, 'link');
  // watchdog('wechat_plus_pages', '<pre>'.print_r($weObj->getRev(),true), array(), WATCHDOG_NOTICE, 'link');

  // TODO： history of wx msg.
  // if(is_record_history(gh_id)){
  //   entity_save('wxmsg');
  // }
  
  $type = $weObj->getRev()->getRevType();
  switch($type){
    case Wechat::MSGTYPE_TEXT:
      _mp_service_process_text($weObj,$account);
      break;
    case Wechat::MSGTYPE_EVENT:
      _mp_service_process_event($weObj,$account);
      module_invoke_all('wxservice_event_alter', $weObj);
      break;	  
  }
  $weObj->reply();
  exit;
}

function _mp_service_process_text($weObj,$account){
  //default behavior if not hook wxresources_alter!
  if(!is_array($weObj->Message(''))){
    $weObj->text(variable_get('wechat_default_message_'.$account->uid, "hello, I'm wechat"));
  }
  $keyword = $weObj->getRevContent();  
	$keyword = trim($weObj->getRevContent());
  $keyword = strtolower($keyword);
  mp_service_keyword_response($weObj,$keyword,$account);
}

function _mp_service_process_event($weObj,$account){	
	$event = $weObj->getRevEvent();
  if(!$event){
    break;
  }
  // else{
  //   $message = _wechat_menu_default_message($event);
  //   $message && $weObj->text($message);
  // }
	//add default behavior
  if($event['event']=='subscribe'){
    $weObj->text(variable_get("wechat_follow_message_".$account->uid, 'Thanks for your subscribe!'));
  }else{
    // $menu = $weObj->getMenu();
    // watchdog('menu', '<pre>'.print_r($menu,true), array(), WATCHDOG_NOTICE, 'link');
  	mp_service_keyword_response($weObj,$event['key'],$account);
  }
}

/**
 * ****** unstable *****
 * login user
 */
function wechat_auth(){
  global $user;
  $weObj = _wechat_init_obj();
  $state = isset($_GET['state']) ? $_GET['state'] : 0;
  $onerror = isset($_GET['onerror']) ? $_GET['onerror'] : '';
  $destination = isset($_GET['destination']) ? $_GET['destination'] : '';
  $code = isset($_GET['code']) ? $_GET['code'] : '';
  // user has logined
  if($user->uid){
    drupal_goto($destination);
  }
  
  // error
  if((!$state) || (!$code)){ // error
    drupal_goto($onerror);
  }

  $accessData = $weObj->getOauthAccessToken();
  if(empty($accessData)){
    drupal_goto($onerror);
  }
  // check if already connectted
  if($curuser = wechat_token_get_user($accessData['openid'])){
    _wechat_user_login($curuser->uid);
	// todo update user info
    drupal_goto($destination);
  }
  
  // auto register
  $user_name = 'wechat_'.substr($accessData['openid'], 0, 15);
  while(user_load_by_name($user_name)){
    $user_name = $user_name.rand(0, 100);
  }
  $new_user = array(
    'name' => $user_name,
    'pass' => user_password(),
    'mail' => $user_name.'@'.$_SERVER['SERVER_NAME'],
    'init' => $user_name.'@'.$_SERVER['SERVER_NAME'],
    'status' => 1,
  );
  // $account returns user object
  $account = user_save(null, $new_user);
  if(!$account){
    drupal_goto($onerror);
  }
  _wechat_user_login($account->uid);
  $wechat_user = array(
  	'uid' => $user->uid,
  	'openid' => $accessData['openid'],
    'extend' => array(),
  );
  // also save user wechat information.
  if($state == 2){
  	$user_info = $weObj->getOauthUserinfo($accessData['access_token'], $accessData['openid']);
  	if(!empty($user_info)){
  		module_invoke_all('wechat_userinfo', $user_info);
  		$wechat_user['nickname'] = $user_info['nickname'];
  		$wechat_user['sex'] = $user_info['sex'];
  		$wechat_user['province'] = $user_info['province'];
  		$wechat_user['city'] = $user_info['city'];
  		$wechat_user['country'] = $user_info['country'];
  		$wechat_user['headimgurl'] = $user_info['headimgurl'];
  	}
  }
  if(!drupal_write_record('wechat_user', $wechat_user)){
    drupal_goto($onerror);
  }

  drupal_goto($destination);
}

/**
 * find the default message
 */
function _wechat_menu_default_message($event){
  // get all click menu key
  $key = isset($event['key']) ? $event['key'] : '';
  if(!$key){
    return '';
  }
  $menu_tree = menu_build_tree('wechat', array('max_depth'=>2));
  foreach($menu_tree as $val){
    if($val['link']['hidden']){
      continue;
    }
    if(!empty($val['below'])){
      foreach($val['below'] as $subval){
        if($subval['link']['hidden']){
          continue;
        }
        if($subval['link']['options']['attributes']['wechat_key'] == $key){
          return $subval['link']['options']['attributes']['wechat_default_message'];
        }
      }
    }
    else if($val['link']['options']['attributes']['wechat_key'] == $key){
      return $val['link']['options']['attributes']['wechat_default_message'];
    }
  }
  return '';
}
