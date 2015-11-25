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

  ga_push_add_pageview(array(
      'location' => url('mp_service/'.$account->uid, array('absolute' => true)),
      'page'     => variable_get('mp_config_appname_'.$account->uid, "永不止息"),
      'title'    => '/'.variable_get('mp_config_appid_'.$account->uid, ""),
  ));
  
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

function _mp_service_process_text(&$weObj,$account){
	$ori_keyword = trim($weObj->getRevContent());
  $keyword = make_semiangle($ori_keyword);
  $keyword = str_replace('[', '', $keyword);
  $keyword = str_replace(']', '', $keyword);
  $keyword = str_replace("'", '', $keyword);
  $keyword = str_replace('"', '', $keyword);
  $keyword = str_replace("收听", '', $keyword);
  $keyword = str_replace('`', '', $keyword);
  $keyword = strtolower($keyword);
  // $emoj = array(':)',':~',':B',':|','8-)',':<',':$',':X',':Z',':’(',':-|',':@',':P',':D',':O',':(',':+','–b',':Q',':T',',@P',',@-D',':d',',@o',':g','|-)',':!',':L',':>',':,@',',@f',':-S','?',',@x',',@@',':8',',@!','!!!','xx','bye','wipe','dig','handclap','&-(','B-)','<@','@>',':-O','>-|','P-(',':’|','X-)',':*','@x','8*','pd','<W>','beer','basketb','oo','coffee','eat','pig','rose','fade','showlove','heart','break','cake','li','bome','kn','footb','ladybug','shit','moon','sun','gift','hug','strong','weak','share','v','@)','jj','@@','bad','lvu','no','ok','love','<L>','jump','shake','<O>','circle','kotow','turn','skip','#-0','kiss','<&','&>');
  // //[挥手] [街舞]
  // $text = array('微笑','伤心','美女','发呆','墨镜','哭','羞','哑','睡','哭','囧','怒','调皮','笑','惊讶','难过','酷','汗','抓狂','吐','笑','快乐','奇','傲','饿','累','吓','汗','高兴','闲','努力','骂','疑问','秘密','乱','疯','哀','鬼','打击','bye','汗','抠','鼓掌','糟糕','恶搞','什么','什么','累','看','难过','难过','坏','亲','吓','可怜','刀','水果','酒','篮球','乒乓','咖啡','美食','动物','鲜花','枯','唇','爱','分手','生日','电','炸弹','刀','足球','虫','臭','月亮','太阳','礼物','伙伴','赞','差','握手','优','恭','勾','顶','坏','爱','不','好的','爱','吻','跳','怕','尖叫','圈','拜','回头','跳','激动','吻','瑜伽','太极');
  // $keyword = str_replace('/:', '', $keyword);
  // $keyword = str_replace($emoj,$text,$keyword);
  // watchdog('$keyword', $keyword, array(), WATCHDOG_NOTICE, 'link');
  mp_service_keyword_response($weObj,$keyword,$account);
  //default behavior if not hook wxresources_alter!

  if(!is_array($weObj->Message(''))){
    module_invoke_all('wxservice_default_msg_alter', $weObj, $keyword,$account);
    $default_keyword = variable_get('mp_config_default_re_'.$account->uid, "");
    if($default_keyword){
      mp_service_keyword_response($weObj,$default_keyword,$account);
    }else{
      if(0&&$account->uid == '8'){
        $weObj->text("您好，谢谢您的反馈！[握手]")->reply();
        //firebaseset begin!
        $openid = $weObj->getRev()->getRevFrom();
        $user_info = $weObj->getUserInfo($openid);
        $data = array();
        $data['headimgurl'] = $user_info['headimgurl'].'.png';
        $data['province'] = $user_info['province'].' '.$user_info['city'];
        $data['nickname'] = $user_info['nickname'];
        $data['openid'] = $openid;
        $data['content'] = $keyword;
        $data['time'] = $weObj->getRevCtime(); //1444450304
        $id = $weObj->getRevID();//6203866816598959257
        $re = firebaseset('wechat/'.$id,$data);
        // watchdog('firebaseset', $data['nickname'].$keyword, array(), WATCHDOG_NOTICE, 'link');
        //firebaseset end!
      }else{
        $copyright = copyright($account);
        $weObj->text(variable_get('wechat_default_message_'.$account->uid, "您好，谢谢您的反馈！[握手]").$copyright);
      }
    }

  }
}

function _mp_service_process_event($weObj,$account){	
	$event = $weObj->getRevEvent();
  if(!$event){
    break;
  }
  if(!isset($event['key']))
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
    $weObj->text(variable_get("wechat_follow_message_".$account->uid, '您好，欢迎关注我们！[握手]').$copyright);
  }elseif($event['event']=='WifiConnected'){
    //do nothing!!!
    watchdog('mp_service_pages', 'WifiConnected event trigger!', array(), WATCHDOG_NOTICE, 'link');
    $weObj->text(variable_get("wechat_follow_message_".$account->uid, '您好，欢迎来到我家！[握手]'));
  }elseif($event['event']=='kf_create_session'){
    //
  }elseif(isset($event['key'])) {
    mp_service_keyword_response($weObj,$event['key'],$account);
    ga_push_add_event(array(
       'category'        => 'wxservice',
       'action'          => 'event_'.$event['event'],
       'label'           => $event['key'],//CLICK/VIEW!
    ));
  }else{
    watchdog('no track event!', '<pre>'.print_r($event,true), array(), WATCHDOG_NOTICE, 'error');
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

function mp_service_comments(){
  // $nid = 113;
  $node_type = 'wxcomments';
  //POST($user_info,$ori_keyword);
  $nid = $_POST['nid'];
  $id = $_POST['id'];
  $pid = $_POST['pid'];
  $user_info = (array)json_decode($_POST['user_info']);

  $comment_body = $_POST['content'];

  $mail = $user_info['openid'].'@wechat.bind';
  $account = user_load_by_mail($mail);
  if(!$account){
    watchdog('create user', 'message', array(), WATCHDOG_NOTICE, 'link');
    // create $user;
    $response = drupal_http_request($user_info['headimgurl']);

    if ($response->code == 200){
      $file = file_save_data($response->data, 'public://users/'. $user_info['openid'].'.jpg');
    }
    $user_name = $user_info['nickname'];
    while(user_load_by_name($user_name)){
      // $user_name = $user_name.rand(0, 100);
      $user_name = $user_info['nickname'].'_'.rand(0, 100);
    }
    $pass = date('Ymd');
    $new_user = array(
      'name' => $user_name,
      'pass' => $pass,//user_password()
      'mail' => $mail,
      'init' => $mail,
      'picture'=> $file->fid,  
      'status' => 1,
      'data'  => $user_info,
      'roles' => array(
        DRUPAL_AUTHENTICATED_RID => 'authenticated user',
      ),
      // 'field_sex' => 1,2男 ＝》 0 男 1 女
      'field_user_sex' => array(LANGUAGE_NONE => array(array('value' => ($user_info['sex'])%2))),
    );
    $account = user_save(null, $new_user);
    if(!$account){
      // drupal_set_message('账户创建失败！', 'error', FALSE);
      watchdog('mp_service_pages', '账户创建失败！', array(), WATCHDOG_NOTICE, 'error');
    }
    // drupal_set_message('恭喜您成功注册！', 'status', FALSE);
  }
  // check comment ID
  {
    

    // dpm($nid,'nid');
    // dpm($pid,'pid');
    // dpm($comment_body,'comment_body');
    $comment = new stdClass();
    $comment->nid = $nid; // nid of a node you want to attach a comment to
    $comment->cid = 0; // leave it as is
    $comment->pid = $pid; // parent comment id, 0 if none 
    $comment->uid = $account->uid; // user's id, who left the comment
    
    $comment->mail = $mail;//
    // $comment->thread = '01/'; // OPTIONAL. If you need comments to be threaded you can fill this value. Otherwise omit it.
    $comment->name = $account->name;//; // If user is authenticated you can omit this field, it will be auto-populated, if the user is anonymous and you want to name him somehow, input his name here
    // $comment->thread = '01/'; // OPTIONAL. If you need comments to be threaded you can fill this value. Otherwise omit it.
    $comment->hostname = $_SERVER['REMOTE_ADDR'] ;// OPTIONAL. You can log poster's ip here
    $comment->created = time(); // OPTIONAL. You can set any time you want here. Useful for backdated comments creation.
    $comment->is_anonymous = 0; // leave it as is
    $comment->homepage = ''; // you can add homepage URL here
    $comment->status = COMMENT_PUBLISHED;//COMMENT_PUBLISHED; // We auto-publish this comment
    $comment->language = LANGUAGE_NONE; // The same as for a node
    // $keyword = substr($keyword, 2);
    $subject = truncate_utf8($comment_body, 15, $wordsafe = FALSE, $add_ellipsis = FALSE, $min_wordsafe_length = 1);
    $comment->subject = $subject; 
    
    // $comment->signature = '';//$wechat_user_info['contact_info']['signature'] ;
    
    // $comment->signature_format = 'filtered_html'; 
    $comment->comment_body[$comment->language][0]['value'] = $comment_body; // Everything here is pretty much like with a node
    $comment->comment_body[$comment->language][0]['format'] = 'filtered_html'; 
    // $comment->field_custom_field_name[LANGUAGE_NONE][0]['value'] = 'Some value'; // OPTIONAL. If your comment has a custom field attached it can added as simple as this // preparing a comment for a save
     // saving a comment
    ///////////end
    if($comment = comment_submit($comment)) { // Prepare node for saving                      
      comment_save($comment);
        // return $comment;
      variable_set('mp_config_wxcomments_before', $id);
    }

  }
}