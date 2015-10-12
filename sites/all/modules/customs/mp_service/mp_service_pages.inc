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
  $ori_keyword = $weObj->getRevContent();
	$ori_keyword = trim($ori_keyword);
  $keyword = make_semiangle($ori_keyword);
  $keyword = str_replace('[', '', $keyword);
  $keyword = str_replace(']', '', $keyword);
  $keyword = str_replace("'", '', $keyword);
  $keyword = str_replace('"', '', $keyword);
  $keyword = strtolower($keyword);
  mp_service_keyword_response($weObj,$keyword,$account);
  //default behavior if not hook wxresources_alter!

  if(!is_array($weObj->Message(''))){
      $openid = $weObj->getRev()->getRevFrom();
      $user_info = $weObj->getUserInfo($openid);
      $data = array();
      $data['headimgurl'] = $user_info['headimgurl'].'.png';
      $data['province'] = $user_info['province'].' '.$user_info['city'];
      $data['nickname'] = $user_info['nickname'];
      $data['content'] = $weObj->getRevContent();
      $data['time'] = $weObj->getRevCtime(); //1444450304
      $id = $weObj->getRevID();//6203866816598959257
      $re = firebaseset('wechat/'.$id,$data);
      // watchdog('firebaseset', $data['nickname'].$keyword, array(), WATCHDOG_NOTICE, 'link');
    $default_keyword = variable_get('mp_config_default_re_'.$account->uid, "");
    if($default_keyword){
      mp_service_keyword_response($weObj,$default_keyword,$account);
    }else{
      $copyright = copyright($account);
      $weObj->text(variable_get('wechat_default_message_'.$account->uid, "您好，谢谢您的反馈！").$copyright);
    }
    ga_push_add_event(array(
     'category'        => 'wxservice',
     'action'          => 'noservice',
     'label'           => $keyword,
    ));

  }else{
    ga_push_add_event(array(
     'category'        => 'wxservice',
     'action'          => 'text',
     'label'           => $keyword,
    ));

  }

}

function _mp_service_process_event($weObj,$account){	
	$event = $weObj->getRevEvent();
  if(!$event){
    break;
  }
  ga_push_add_event(array(
     'category'        => 'wxservice',
     'action'          => 'event',
     'label'           => $event['event'],
  ));
  // else{
  //   $message = _wechat_menu_default_message($event);
  //   $message && $weObj->text($message);
  // }
	//add default behavior
  if($event['event']=='subscribe'){
    $copyright = copyright($account);
    $weObj->text(variable_get("wechat_follow_message_".$account->uid, '您好，欢迎关注我们！').$copyright);
  }else{
    // $menu = $weObj->getMenu();
    if (isset($event['key'])) {
      mp_service_keyword_response($weObj,$event['key'],$account);
    }else{
      watchdog('error221222', '<pre>'.print_r($event,true), array(), WATCHDOG_NOTICE, 'link');

    }
  }
}

/**
 * ****** unstable *****
 * login user
 */
function wechat_auth($mp_account){
  global $user;
  // $mp_uid = 8;
  // $mp_account = user_load($mp_uid);
  $weObj = _mp_service_init_wechat($mp_account);
  $state = isset($_GET['state']) ? $_GET['state'] : 0;
  $onerror = isset($_GET['onerror']) ? $_GET['onerror'] : '';
  $destination = isset($_GET['destination']) ? $_GET['destination'] : '';
  $code = isset($_GET['code']) ? $_GET['code'] : '';
  
  // error
  if((!$state) || (!$code)){ // error
    die('啊哦，出错啦，请告知小永微信：649294139!');
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
  if($state == 2){
    ////create user begin// auto register

    $user_info = $weObj->getOauthUserinfo($accessData['access_token'], $accessData['openid']);
    // auto register

    // user has logined
    if($user->uid){
      $user->init = $user_info['openid'].'@wechat.bind';
      user_save($user);
      drupal_set_message('绑定成功！', 'status', FALSE);
      drupal_goto('user/'.$user->uid.'/wechat');
    }
    // $user_name = 'wechat_'.substr($accessData['openid'], 0, 15);
    $user_name = $user_info['nickname'];
    while(user_load_by_name($user_name)){
      // $user_name = $user_name.rand(0, 100);
      $user_name = $user_info['nickname'].'_'.rand(0, 100);
    }
    $response = drupal_http_request($user_info['headimgurl']);

    if ($response->code == 200){
      $file = file_save_data($response->data, 'public://users/'. $user_name.'.jpg');
    }
    $pass = date('Ymd');
    $mail = $user_info['openid'].'@wechat.bind';
    $new_user = array(
      'name' => $user_name,
      'pass' => $pass,//user_password()
      'mail' => $mail,
      'init' => $mail,
      'picture'=> $file->fid,  
      'status' => 1,
      'data'  => $user_info,
    );
    // $account returns user object
    $account = user_save(null, $new_user);
    if(!$account){
      drupal_set_message('账户创建失败！', 'error', FALSE);
      drupal_goto($onerror);
    }
    drupal_set_message('恭喜您成功注册！请'.l('修改','user/'.$account->uid.'/edit').'您的邮箱和初始密码:'.$pass, 'status', FALSE);
    _wechat_user_login($account->uid);

    ////create user end  
  
   // also save user wechat information.
    $wechat_user = array(
      'uid' => $user->uid,
      'openid' => $accessData['openid'],
      'extend' => array(),
    );
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


// 全角半角转． 
function make_semiangle($str)    
{    
    $arr = array('０' => '0', '１' => '1', '２' => '2', '３' => '3', '４' => '4',    
                 '５' => '5', '６' => '6', '７' => '7', '８' => '8', '９' => '9',    
                 'Ａ' => 'A', 'Ｂ' => 'B', 'Ｃ' => 'C', 'Ｄ' => 'D', 'Ｅ' => 'E',    
                 'Ｆ' => 'F', 'Ｇ' => 'G', 'Ｈ' => 'H', 'Ｉ' => 'I', 'Ｊ' => 'J',    
                 'Ｋ' => 'K', 'Ｌ' => 'L', 'Ｍ' => 'M', 'Ｎ' => 'N', 'Ｏ' => 'O',    
                 'Ｐ' => 'P', 'Ｑ' => 'Q', 'Ｒ' => 'R', 'Ｓ' => 'S', 'Ｔ' => 'T',    
                 'Ｕ' => 'U', 'Ｖ' => 'V', 'Ｗ' => 'W', 'Ｘ' => 'X', 'Ｙ' => 'Y',    
                 'Ｚ' => 'Z', 'ａ' => 'a', 'ｂ' => 'b', 'ｃ' => 'c', 'ｄ' => 'd',    
                 'ｅ' => 'e', 'ｆ' => 'f', 'ｇ' => 'g', 'ｈ' => 'h', 'ｉ' => 'i',    
                 'ｊ' => 'j', 'ｋ' => 'k', 'ｌ' => 'l', 'ｍ' => 'm', 'ｎ' => 'n',    
                 'ｏ' => 'o', 'ｐ' => 'p', 'ｑ' => 'q', 'ｒ' => 'r', 'ｓ' => 's',    
                 'ｔ' => 't', 'ｕ' => 'u', 'ｖ' => 'v', 'ｗ' => 'w', 'ｘ' => 'x',    
                 'ｙ' => 'y', 'ｚ' => 'z',    
                 '（' => '(', '）' => ')', '〔' => '[', '〕' => ']', '【' => '[',    
                 '】' => ']', '〖' => '[', '〗' => ']', '“' => '[', '”' => ']',    
                 '‘' => '[', '’' => ']', '｛' => '{', '｝' => '}', '《' => '<',    
                 '》' => '>',    
                 '％' => '%', '＋' => '+', '—' => '-', '－' => '-', '～' => '-',    
                 '：' => ':', '。' => '.', '、' => ',', '，' => '.', '、' => '.',    
                 '；' => ',', '？' => '?', '！' => '!', '…' => '-', '‖' => '|',    
                 '”' => '"', '’' => '`', '‘' => '`', '｜' => '|', '〃' => '"',    
                 '　' => ' ','＄'=>'$','＠'=>'@','＃'=>'#','＾'=>'^','＆'=>'&','＊'=>'*', 
                 '＂'=>'"'); 
   
    return strtr($str, $arr);    
}