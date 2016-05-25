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
  // if($account->uid>1) ga_push_add_pageview(array(
  //     'location' => 'mp_service/'.$account->uid,//url(, array('absolute' => true)),
  //     'page'     => $account->uid,//variable_get('mp_config_appname_'.$account->uid, "永不止息").'_'.$account->uid,
  //     'title'    => '/'.$account->name,//variable_get('mp_config_appid_'.$account->uid, ""),
  // ));

  $type = $weObj->getRev()->getRevType();
  switch($type){
    case Wechat::MSGTYPE_TEXT:
      _mp_service_process_text($weObj,$account,$weObj->getRevContent());
      break;
    case Wechat::MSGTYPE_EVENT:
      _mp_service_process_event($weObj,$account);
      break;
  }
  $weObj->reply();
  exit;
}

function _mp_service_process_text(&$weObj,$account,$ori_keyword){
  //TODO
  // if(in_array(strlen($ori_keyword),array(1437,72,164,1160,407))){
  //   //in_array($account->uid, array(1,8,12))&&
  //   $weObj->text("对不起，资源有限，[抱拳]\n如果再复制发送，就把你拉黑！[抱拳]\n如果是误会，请末尾加1后再次发送，谢谢体谅，小永敬上[握手]")->reply();//164
  //   return;
  // }
  // watchdog('len23', strlen($ori_keyword), array(), WATCHDOG_NOTICE, 'link');

  //TODO 数据收集！
  // if($account->uid == 8 && $ori_keyword=='test'){
  //   $openid = $weObj->getRev()->getRevFrom();
  //   // $img = array(
  //   //       'Title'=> '【今日良友节目概览】',
  //   //       'Description'=> "\n永不止息，需要有你\n回复【】内编号即可收听[加油]！",
  //   //       'PicUrl'=> 'http://mmbiz.qpic.cn/mmbiz/0fV5QBhibUJjvmqqUbJaL3ZPqIBKxPKpkq4SvjmagLGia5X6SDhTDKLY49qhWqE7ibyb6N1QUelvHv0ZnL5V7HWicA/640?wx_fmt=jpeg&tp=webp&wxfrom=5.jpg',
  //   //       'Url'=> 'http://ly.yongbuzhixi.com',
  //   //     );
  //   // $news[] = $img;
  //   // $music = array(
  //   //   'title'=>'test',
  //   //   'description'=>'description',
  //   //   'musicurl'=>'http://lywxaudio.b0.upaiyun.com/2016/ee/ee160408.mp3?_upt=26f931e81460195154',
  //   //   'hqmusicurl'=>'http://lywxaudio.b0.upaiyun.com/2016/ee/ee160408.mp3?_upt=26f931e81460195154',
  //   //   );
  //   $data = array(
  //     "touser"=>$openid,
  //     "msgtype"=>'text',
  //     'text'=>array('content'=>'hellp'),
  //   );
  //   $weObj->sendCustomMessage($data)->reply(array(),1);
  // }
  if($account->uid == 8){
    // $openid = $weObj->getRev()->getRevFrom();
    // watchdog('openid_'.$ori_keyword, $openid, array(), WATCHDOG_NOTICE, 'link');
    if(strpos($ori_keyword,'mp.weixin.qq.com/s?')!==FALSE){
      $openid = $weObj->getRev()->getRevFrom();
      $allows = array(
        '2189刘云胜'=>'oTjEwswNUrG9eOdr4QqxFwriz_Rw',
        '2250王正泉'=>'oTjEwsx2rsbb57zRQFLS1dWNPfOg',
        '孔莉萍'=>'oTjEwsyk2oHVYuBzJQxAFdt8_YLk',
        '陈玉'=>'oTjEws7dFeTScW2vBmjmANLQIBBY',
        '亚南'=>'oTjEws1hQOzexqQyybkOi2HY_iP8',
        '建华'=>'oTjEwsw9JKN1N1ysxhOlWAN4Ltvk',
        'bluesky_still'=>'oTjEwsycJgEpiKTzzisTRa8RP8y4',
        '小永'=>'oTjEws-8eAAUqgR4q_ns7pbd0zN8',
        '365'=>'oTjEwsxl5srb_PgAw7e1xvNp3xk4',
        '366'=>'oTjEws_LNd8maly0PugxnmFQPdTA',
      );
      if(in_array($openid,$allows)){
        if(strlen($ori_keyword)>255){
          $ori_keyword = substr($ori_keyword, 0, strpos( $ori_keyword,'&scene='));
        }
        mp_getwxcontent($ori_keyword,$openid,$weObj);
        return;
      }else{
          watchdog('openid', $openid, array(), WATCHDOG_NOTICE, 'link');
          $weObj->text('已申请管理员,审核后再次发送链接即可收集文章啦！');return;
      }
    }
    // $weObj->text("亲爱的主内家人，迫于经济压力，本号暂停服务，请关注<a href='http://mp.weixin.qq.com/s?__biz=MjM5ODQ4NjU4MA==&mid=402309376&idx=1&sn=8e7f77cb6014948fc572f12085521edd#rd'>永不止息主内婚恋网</a>订阅号，您将会每日收到我们推送的精彩图文。\n如果您对我们的服务有负担，请代祷或<a href='http://kdt.im/9Okuhr'>赞助支持</a>我们，谢谢！永不止息，需要有你！[抱拳]");
    // return;
  }
  $keyword = make_semiangle(strtolower($ori_keyword));//include trim;

  // if($account->uid == 1417){
  //   mp_lywx_keyword_response($weObj,$keyword,$account);
  //   return;
  // }

  //TODO emoj
  // $emoj= array(
    //   '微笑'=>':)',
    //   '伤心'=>':~',
    //   '美女'=>':B',
    //   '发呆'=>':|',
    //   '墨镜'=>'8-)',
    //   '哭'=>':<',
    //   '羞'=>':$',
    //   '哑'=>':X',
    //   '睡'=>':Z',
    //   '哭'=>':’(',
    //   '囧'=>':-|',
    //   '怒'=>':@',
    //   '调皮'=>':P',
    //   '笑'=>':D',
    //   '惊讶'=>':O',
    //   '难过'=>':(',
    //   '酷'=>':+',
    //   '汗'=>'–b',
    //   '抓狂'=>':Q',
    //   '吐'=>':T',
    //   '笑'=>',@P',
    //   '快乐'=>',@-D',
    //   '奇'=>':d',
    //   '傲'=>',@o',
    //   '饿'=>':g',
    //   '累'=>'|-)',
    //   '吓'=>':!',
    //   '汗'=>':L',
    //   '高兴'=>':>',
    //   '闲'=>':,@',
    //   '努力'=>',@f',
    //   '骂'=>':-S',
    //   '疑问'=>'?',
    //   '秘密'=>',@x',
    //   '乱'=>',@@',
    //   '疯'=>':8',
    //   '哀'=>',@!',
    //   '鬼'=>'!!!',
    //   '打击'=>'xx',
    //   'bye'=>'bye',
    //   '汗'=>'wipe',
    //   '抠'=>'dig',
    //   '鼓掌'=>'handclap',
    //   '糟糕'=>'&-(',
    //   '恶搞'=>'B-)',
    //   '左什'=>'<@',
    //   '右什'=>'@>',
    //   '累'=>':-O',
    //   '看'=>'>-|',
    //   '很难'=>'P-(',
    //   '难过'=>':’|',
    //   '坏'=>'X-)',
    //   '亲'=>':*',
    //   '吓'=>'@x',
    //   '可怜'=>'8*',
    //   '刀'=>'pd',
    //   '水果'=>'<W>',
    //   '酒'=>'beer',
    //   '篮球'=>'basketb',
    //   '乒乓'=>'oo',
    //   '咖啡'=>'coffee',
    //   '美食'=>'eat',
    //   '动物'=>'pig',
    //   '鲜花'=>'rose',
    //   '枯'=>'fade',
    //   '唇'=>'showlove',
    //   '爱'=>'heart',
    //   '分手'=>'break',
    //   '生日'=>'cake',
    //   '电'=>'li',
  // );
  // $keyword = str_replace('/:', '', $keyword);
  // $keyword = str_replace($emoj,$text,$keyword);
  // watchdog('$keyword', $keyword, array(), WATCHDOG_NOTICE, 'link');
  mp_service_keyword_response($weObj,$keyword,$account);
  //default behavior if not hook wxresources_alter!
  if(!$weObj->Message('')){
    module_invoke_all('wxservice_default_msg_alter', $weObj, $keyword,$account);
  }
  if(!$weObj->Message('')){
    $default_keyword = variable_get('mp_config_default_re_'.$account->uid, "");
    if($default_keyword){
      mp_service_keyword_response($weObj,$default_keyword,$account);
      if($account->uid>1) gapushagent('event',array(
       'category'        => 'default_keyword_resource',
       'action'          => $ori_keyword,
       'label'           => 'wxservice_'.$account->uid,
      ));
    }else{
      if(0&&$account->uid == '8'){
        $weObj->text("您好，谢谢您的反馈！[握手]")->reply();
        //firebaseset begin!
        $openid = $weObj->getRev()->getRevFrom();
        $user_info = $weObj->getUserInfo($openid);
        $data = array();
        $data['headimgurl'] = $user_info['headimgurl'].'.png';
        $data['province'] = $user_info['province'].' '.$user_info['city'];
        $data['nickname'] = mp_strip_utf8mb4_for_text_fields($user_info['nickname'],'?');
        $data['openid'] = $openid;
        $data['content'] = $keyword;
        $data['time'] = $weObj->getRevCtime(); //1444450304
        $id = $weObj->getRevID();//6203866816598959257
        $re = firebaseset('wechat/'.$id,$data);
        // watchdog('firebaseset', $data['nickname'].$keyword, array(), WATCHDOG_NOTICE, 'link');
        //firebaseset end!
        if($account->uid>1) gapushagent('event',array(
         'category'        => 'firebaseset',
         'action'          => $ori_keyword,
         'label'           => 'wxservice_'.$account->uid,
        ));
      }else{
        $copyright = copyright($account);
        $weObj->text(variable_get('wechat_default_message_'.$account->uid, "您好，谢谢您的反馈！[握手]").$copyright);
        if($account->uid>1) gapushagent('event',array(
         'category'        => 'copyrightGet',
         'action'          => $ori_keyword,
         'label'           => 'wxservice_'.$account->uid,
        ));
      }
    }

  }
}

function _mp_service_process_event($weObj,$account){
	$event = $weObj->getRevEvent();
  if(!$event){
    return;
  }

  // TODO
  module_invoke_all('wxservice_event_alter', $weObj,$event,$account);
  if(is_array($weObj->Message(''))){return;}

  if($event['event']=='MASSSENDJOBFINISH'){
      gapushagent('event',array(
       'category'        => 'event',
       'action'          => '图文发送成功',
       'label'           => 'wxservice_'.$account->uid,
      ));
      return ;
  }
  if(!isset($event['key'])){
    if($account->uid>1) gapushagent('event',array(
       'category'        => 'event',
       'action'          => $event['event'],
       'label'           => 'wxservice_'.$account->uid,
    ));
  }else{
    if($event['event']=='VIEW'){
      //MP menu!
      gapushagent('event',array(
       'category'        => 'event',
       'action'          => '图文VIEW',
       'label'           => 'wxservice_'.$account->uid,
      ));
    }else{
      if(is_string($event['key']))
        mp_service_keyword_response($weObj,$event['key'],$account);
    }
  }
	//add default behavior
  if($event['event']=='subscribe'){
    if($account->uid == 8){
      // watchdog($event['key'], strpos($event['key'],'qrscene_'), array(), WATCHDOG_NOTICE, 'link');
      // [event] => subscribe
      // [key] => qrscene_1079
      if(isset($event['key']) && strpos($event['key'],'qrscene_')!==FALSE){
        $uid = str_replace('qrscene_', '', $event['key']);
        // $user = user_load($uid);
        // watchdog('SCANinfo', '<pre>'.print_r($event,true), array(), WATCHDOG_NOTICE, 'error');
        $openid = $weObj->getRev()->getRevFrom();
        $user_info = $weObj->getUserInfo($openid);
        $ori_user_name = mp_strip_utf8mb4_for_text_fields($user_info['nickname'],'?');
        $user_name = $ori_user_name;
        $user_info['nickname'] = $ori_user_name;
        //if 用户不存在，则创建新用户！
        $mail = $user_info['openid'].'@wechat.bind';
        $account = user_load_by_mail($mail);
        if(!$account){
          // $response = drupal_http_request($user_info['headimgurl']);
          // if ($response->code == 200){
          //   $file = file_save_data($response->data, 'public://users/'. $user_info['openid'].'_0.jpg');
          // }
          $count = 0;
          while(user_load_by_name($user_name)){
            // $user_name = $user_name.rand(0, 100);
            $user_name = $ori_user_name.'_'.$count;
            $count ++;
          }
          $pass = $user_info['openid'];
          $new_user = array(
            'name' => $user_name,
            'pass' => $pass,//user_password()
            'mail' => $mail,
            'init' => $mail,
            // 'picture'=> $file->fid,
            'status' => 1,
            'data'  => $user_info,
            'roles' => array(
              DRUPAL_AUTHENTICATED_RID => 'authenticated user',
              6 => 'fwh',
            ),
            'field_user_sex' => array(LANGUAGE_NONE => array(array('value' => ($user_info['sex'])%2))),
            'field_recommend' => array(LANGUAGE_NONE => array(array('target_id' => $uid))),

          );
          $account = user_save(null, $new_user);
          if(!$account){
            watchdog('mp_service_pages', '账户创建失败！', array(), WATCHDOG_NOTICE, 'error');
          }
          // watchdog('mp_service_pages', $user_name.'账户创建成功！'.$account->uid, array(), WATCHDOG_NOTICE, 'link');

          $weObj->text('{'.$account->name."}恭喜您接受了的邀请！你们都获得100积分，推荐10人即可参加积分抽奖，奖品有：<a href='http://wx.yongbuzhixi.com/node/331'>kindle，CD，图书...</a>小永透露：中奖率100%[调皮]\n请点击【送大奖】→我的海报！[强]")->reply();
          //add points!
          return;
        }else{
          if($uid == $account->uid){
            $weObj->text("请您分享本图片到朋友圈或发给好友或群组即可邀请他们来参加活动。\n推荐100积分的奖励哦！奖品有：<a href='http://wx.yongbuzhixi.com/node/331'>kindle，CD，图书...</a>\n小永透露：中奖率100%[调皮]"."谢谢参与！")->reply();
          };
          $weObj->text("老朋友您好，此次扫描无效。\n请点击【送大奖】→我的海报，来邀请[新朋友]赚积分赢大奖吧！")->reply();
          return;
        }
      }
    }
    gapushagent('event',array(
       'category'        => 'event',
       'action'          => 'subscribe',
       'label'           => 'wxservice_'.$account->uid,
     ));
    $copyright = copyright($account);
    $weObj->text(variable_get("wechat_follow_message_".$account->uid, '您好，欢迎关注我们！[握手]').$copyright);
  }elseif($event['event']=='WifiConnected'){
    // watchdog('mp_service_pages', 'WifiConnected event trigger!', array(), WATCHDOG_NOTICE, 'link');
    $weObj->text(variable_get("wechat_follow_message_".$account->uid, '您好，欢迎来到我家！[握手]'));
  }elseif($event['event']=='kf_create_session'){
    //TODO
  }
  // watchdog('no track event!', '<pre>'.print_r($event,true), array(), WATCHDOG_NOTICE, 'error');
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
    $ori_user_name = mp_strip_utf8mb4_for_text_fields($user_info['nickname'],'?');
    $user_name = $ori_user_name;
    $user_info['nickname'] = $ori_user_name;
    $count = 0;
    while(user_load_by_name($user_name)){
      // $user_name = $user_name.rand(0, 100);
      $user_name = $ori_user_name.'_'.$count;
      $count ++;
    }
    // $response = drupal_http_request($user_info['headimgurl']);
    // if ($response->code == 200){
    //   $file = file_save_data($response->data, 'public://users/'. $user_name.'.jpg');
    // }
    $pass = date('Ymd');
    $mail = $user_info['openid'].'@wechat.bind';
    $new_user = array(
      'name' => $user_name,
      'pass' => $pass,//user_password()
      'mail' => $mail,
      'init' => $mail,
      // 'picture'=> $file->fid,
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
  // $search =  array('[',']',"'",'"', "收听",'','.','○','o','〇',',',':','|',' ','一',);
  // $replace =  array('','','','','', '', '', '0', '0','0','', '','', '', '',);
  // $keyword = str_replace($search, $replace, $keyword);
  $arr = array(
    '○' =>  '0','〇' =>  '0', '`' =>  '',
    ':' =>  '', ' ' => '', '井' =>  '#',
    '０' => '0', '１' => '1', '２' => '2', '３' => '3', '４' => '4',
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
    '（' => '', '）' => '', '〔' => '', '〕' => '', '【' => '',
    '】' => '', '〖' => '', '〗' => '', '“' => '', '”' => '',
    '‘' => '', '’' => '', '｛' => '', '｝' => '', '《' => '<',
    '》' => '>',
    '％' => '%', '＋' => '+', '—' => '-', '－' => '-', '～' => '-',
    '：' => ':', '。' => '.', '、' => ',', '，' => ',', '、' => '.',
    '；' => ',', '？' => '?', '！' => '!', '…' => '-', '‖' => '',
    '”' => '', '’' => '', '‘' => '', '｜' => '', '〃' => '',
    '　' => ' ','＄'=>'$','＠'=>'@','＃'=>'#','＾'=>'','＆'=>'&','＊'=>'*',
    '＂'=>''
  );

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
    // watchdog('create user '.$mail, 'message', array(), WATCHDOG_NOTICE, 'link');
    // create $user;
    // $response = drupal_http_request($user_info['headimgurl']);
    // if ($response->code == 200){
    //   $file = file_save_data($response->data, 'public://users/'. $user_info['openid'].'.jpg');
    // }
    $ori_user_name = mp_strip_utf8mb4_for_text_fields($user_info['nickname'],'?');
    $user_name = $ori_user_name;
    $user_info['nickname'] = $ori_user_name;
    $count = 0;
    while(user_load_by_name($user_name)){
      // $user_name = $user_name.rand(0, 100);
      $user_name = $ori_user_name.'_'.$count;
      $count ++;
    }
    $pass = date('Ymd');
    $new_user = array(
      'name' => $user_name,
      'pass' => $pass,//user_password()
      'mail' => $mail,
      'init' => $mail,
      // 'picture'=> $file->fid,
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

    $status = COMMENT_PUBLISHED;
    if($nid == '163') $status = COMMENT_NOT_PUBLISHED;
    if($pid != 0) $status = COMMENT_PUBLISHED;
    $comment->status = $status;//COMMENT_PUBLISHED; // We auto-publish this comment
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
    }

  }
}
