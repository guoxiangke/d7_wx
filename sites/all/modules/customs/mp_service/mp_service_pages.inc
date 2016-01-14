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
      'page'     => variable_get('mp_config_appname_'.$account->uid, "永不止息").'_'.$account->uid,
      'title'    => '/'.variable_get('mp_config_appid_'.$account->uid, ""),
  ));
  
  $type = $weObj->getRev()->getRevType();
  switch($type){
    case Wechat::MSGTYPE_TEXT:
      _mp_service_process_text($weObj,$account);
      break;
    case Wechat::MSGTYPE_EVENT:
      _mp_service_process_event($weObj,$account);
      // TODO
      // module_invoke_all('wxservice_event_alter', $weObj);
      break;	  
  }
  $weObj->reply();
  exit;
}

function _mp_service_process_text(&$weObj,$account){
	$ori_keyword = trim($weObj->getRevContent());
  if($account->uid == 8 && in_array($ori_keyword, array('hi','jf','cj'))){
    $openid = $weObj->getRev()->getRevFrom();
    $user_info = $weObj->getUserInfo($openid);
    // watchdog('user_info', '<pre>'.print_r($user_info,1), array(), WATCHDOG_NOTICE, 'link');
    $user_name = $user_info['nickname'];
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
        $user_name = $user_info['nickname'].'_'.$count;
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
        // 'field_sex' => 1,2男 ＝》 0 男 1 女
        'field_user_sex' => array(LANGUAGE_NONE => array(array('value' => ($user_info['sex'])%2))),
        'field_headimgurl' => array(LANGUAGE_NONE => array(array('value' => $user_info['headimgurl']))),
        
      );
      $account = user_save(null, $new_user);
      if(!$account){
        // drupal_set_message('账户创建失败！', 'error', FALSE);
        watchdog('mp_service_pages', '账户创建失败！', array(), WATCHDOG_NOTICE, 'error');
      }
        watchdog('mp_service_pages', $user_name.'账户创建成功！'.$account->uid, array(), WATCHDOG_NOTICE, 'link');
        $weObj->text("恭喜您获得100积分，请点击【活动】→二维码\n看见【请稍后再试】\n(小永累趴后)/:shake\n等3秒后再次点击！[强]")->reply();  
        return; 
    }
    if($ori_keyword == 'jf'){//积分查询
      $result = db_select('hd', 'c')
            ->fields('c')
            ->condition('award', 0,'>')
            ->condition('uid', $account->uid)
            ->orderBy('award', 'ESC')
            ->execute();
      $count = 0;
      $count = $result->rowCount();
      $jf = '您还没抽过奖！加油吧！[拳头]';
      if($count){
        $ids = '';
          while($record = $result->fetchAssoc()) {
            $ids .= ','.$record['id'];
          }
        $jf = '您已抽奖'.$count.'次，奖券ID分别是：'.$ids;
      }
      ;
      $weObj->text("您已获得".userpoints_get_current_points($account->uid)."积分，邀请1人100积分！\n满1000积分就可以抽奖1次！\n奖品有：<a href='http://www.amazon.cn/dp/B00KDRNYO4'>kindle，CD，图书...</a>".$jf)->reply();  
        return; 
    }
    if($ori_keyword == 'cj'){//抽奖

        // $weObj->text("您抽奖的ID是 ，谢谢参与，！邀请1人100积分！\n满1000积分就可以再次抽奖啦！\n奖品有：<a href='http://www.amazon.cn/dp/B00KDRNYO4'>kindle，CD，图书...</a>[拳头]")->reply();  
        // return;
      $jf = userpoints_get_current_points($account->uid);
      if($jf<1000){
         $cj = '您积分是'.$jf.'，不足1000，不可抽奖[可怜]，赶快分享二维码邀请朋友吧[拳头]';
         $weObj->text($cj."，谢谢参与，！邀请1人100积分！\n满1000积分就可以再次抽奖啦！\n奖品有：<a href='http://www.amazon.cn/dp/B00KDRNYO4'>kindle，CD，图书...</a>[拳头]")->reply(); 
      }else{
        // 积分--1000
        {     
          $award1 = 4535;
          $award2 = array('2768','215','2532','899','1942','4324','2412','4389','3596','4440','4256','1649','5957','4800','347','2892','189','2508','5028','1700','2071','5132','1580','770','3796','636','4080','24','4686','5171','1107','1454','5386','3639','2352','1327','1962','4763','5715','5558','3203','3971','1206','3160','2771','1553','51','2959','4060','5079');
          
          $award3 = array('4940','1610','3202','1745','553','3059','5279','5834','2609','1669','3264','1475','3297','5485','2985','3062','3247','4042','4669','3494','5597','3539','3807','3301','1499','376','1129','2242','2436','2844','1182','4045','45','2926','4598','3104','2204','4432','5712','3873','1695','1187','1169','4992','671','4154','2054','3918','2195','722','1411','1791','4260','5218','5092','5758','5593','220','2000','2029','3064','3181','73','3109','106','4671','212','2310','3102','5924','182','4797','1110','1350','3788','1781','5504','5841','5698','1698','563','1108','3489','4822','325','2580','4580','5918','2800','579','1946','5863','3760','2019','2971','3865','689','3183','174','3791','3107','356','2588','4217','1706','375','5997','1209','216','5694','2907','778','802','395','5600','1127','2975','4180','1044','5774','4758','2990','5637','2518','5008','2608','382','5697','5790','556','3488','2897','912','75','1113','2617','450','1109','3825','665','803','732','1443','1604','1126','1042','2731','4101','5221','3774','3875','3979','763','3512','496','5771','119','878','5467','5909','1434','2954','2805','2345','3028','3917','4962','3477','5026','2787','4142','5828','3518','5584','1432','4644','625','4162','2744','5846','1936','619','3824','2699','4130','4320','2469','4249','5197','1935','4158','631','4889','962','1917','4879','1937','5394','3904','4723','3535','3732','2240','3118','5164','884','3743','3326','3627','3588','5261','4246','1412','1959','2376','5731','4428','624','4928','363','4781','5251','5743','2533','1168','4621','4469','561','2525','3192','4095','257','5431','1213','5420','314','4956','2745','3941','2544','2006','2187','3955','3964','4562','3686','2391','5186','2613','2753','3966','2170','2004','3709','4703','3171','2330','3731','4854','1826','5111','5793','3039','4530','107','1994','1275','4048','4538','3280','235','2492','1244','4796','177','3635','3982','2790','388','1947','4960','5656','3662','5562','1985','833','3293','839','1195','5118','5949','988','2157','4479','1095','4150','5754','5143','2687','3033','5377','5179','4277','4173','5356','1911','2154','2146','2299','1105','4689','3756','4766','4251','5740','5598','1543','578','793','660','527','1780','2816','5006','2874','966','4759','2016','3653','1792','1393','2832','68','5565','2188','1979','1718','4333','5818','5437','2966','3574','4202','1216','3313','3800','2758','3891','4593','3418','4417','372','233','3422','3246','1199','2181','5262','4852','3972','654','1683','4040','219','3870','18','2202','4295','1754','1638','1260','5327','5840','2476','2640','3640','5233','530','2232','2650','4947','2604','2883','2369','5850','4082','4549','2933','2521','5765','4616','560','5983','2485','1920','4687','4872','3673','132','3000','165','2607','5640','3805','1839','170','36','4489','5116','1372','1485','2489','5453','34','1599','2386','2554','1364','1001','3113','1347','3486','3690','3266','2173','2562','939','2497','2693','3938','2662','5299','3578','466','1138','3747','501','5626','2863','3140','997','4347','5629','4380','1227','2835','934','2591','3835','4046','3937','1321','1736','1202','3493','4297','2140','5990','990','78','2651','288','3655','3116','1425','1402','3617','1051','4264','756','2047','2611','385','991','1612','5331','1925','3166','5971','2138','4486','3340','5350','3755','2877','5801','5488','490','2297','479','2101','1628','2403','302','4793','2373','2440','3279','4079','5779');
        }
        $result = db_select('hd', 'c')
            ->fields('c',array('id'))
            ->condition('uid', 0)
            ->range(0,1)    // Limit the result set by 1 record only
            ->orderRandom() // Sort by random
            ->execute()->fetchAssoc();
        $id = $result['id'];
        $cj = '';
        if($id == $award1) $cj = '一等奖';
        if(in_array($id, $award2)) $cj = '二等奖';
        if(in_array($id, $award3)) $cj = '三等奖';
        db_update('hd')
          ->fields(array(
            'uid' => $account->uid,
            'name' => $account->name,
          ))
          ->condition('id', $id)
          ->execute();

        $params = array(
          'uid' => $account->uid,
          'points' => -1000,
          'operation' => 'Insert',
          'description' => '抽奖ID：'.$id,
        );
        userpoints_userpointsapi($params);
        $weObj->text("您抽奖的ID是".$id.":".$cj."，谢谢参与！邀请1人100积分！\n满1000积分就可以再次抽奖啦！\n奖品有：<a href='http://www.amazon.cn/dp/B00KDRNYO4'>kindle，CD，图书...</a>[拳头]")->reply(); 

      }
      return; 
    }

    $file_path = DRUPAL_ROOT.'/sites/default/files/QR/';
    if (!is_dir($file_path)) {
      mkdir($file_path, 0777, true);
    }
    $qr = $file_path.'QR_'.$account->uid.'.jpg';
    // watchdog('qr', $qr, array(), WATCHDOG_NOTICE, 'link');
    // $qr_url = 'http://121.41.79.122/mp/sites/default/files/QR_'.$account->uid.'.png';
    // if(@get_headers($qr_url)[0] == 'HTTP/1.1 404 Not Found'){
    if(!file_exists($qr)){
      $weObj->text($user_name."小永正在为您定制二维码，等待3秒后再来获取吧！[握手]")->reply();
      $return =  $weObj->getQRCode($account->uid,$type=0,$expire=2592000); 
      $qr_remote = $weObj->getQRUrl($return['ticket']);
      //TODO
      $x = 600;
      $y = 1285;
      $rh = 100;

      $A = dirname(__FILE__).'/images/fwh_small.jpg';
      $B = $qr_remote;
      $im1 = imagecreatefromstring(file_get_contents($A));
      $im2 = imagecreatefromstring(file_get_contents($B));
       
      imagecopymerge($im1, $im2, $x, $y, 0, 0, imagesx($im2), imagesy($im2), $rh);
      // imageGif($im1);return;
      // imageGif($im1,'sites/default/files/test.gif');
      // $x = 60;
      // $y = 1400;
      $x = 60;
      $y = 1350;
      $rh = 100;

      // $A = $im1;
      $B = $user_info['headimgurl'];
      // $im1 = imagecreatefromstring(file_get_contents($A));
      $image = imagecreatefromstring(file_get_contents($B));
      $percent = 0.4;

      // 获取新的尺寸
      // list() = getimagesize($filename);
      $width = imagesx($image);
      $height = imagesy($image);
      $new_width =  $width* $percent;
      $new_height = $height* $percent;

      // 重新取样
      $image_p = imagecreatetruecolor($new_width, $new_height);
      // $image = imagecreatefromjpeg($filename);
      imagecopyresampled($image_p, $image, 0, 0, 0, 0, $new_width, $new_height, $width, $height);

      $im2 = $image_p;//imagecreatefromstring(file_get_contents($B));
       
      imagecopymerge($im1, $im2, $x, $y, 0, 0, imagesx($im2), imagesy($im2), $rh);
      imagejpeg($im1,'sites/default/files/QR/QR_'.$account->uid.'.jpg');
      //END
    }else{
      set_time_limit(0);
      $data= array('media'=>$qr);
      $return = $weObj->uploadMedia($data,'image');//{"type":"TYPE","media_id":"MEDIA_ID","created_at":123456789}
      // watchdog('return', '<pre>'.print_r($return,1), array(), WATCHDOG_NOTICE, 'link');
      if(isset($return['media_id'])){
        $weObj->image($return['media_id'])->reply();
      }else{
        $weObj->text("对不起，请再试一次！[握手]")->reply();  
      }
      return;
    }
    return;
  }
  // getQRUrl($ticket) 获取二维码图片地址
  if(in_array(strlen($ori_keyword),array(1437,72,164,1160,407))){
    //评论留言成功！ 审核后会出现在这里哦！72
    //in_array($account->uid, array(1,8,12))&&
    $weObj->text("对不起，资源有限，[抱拳]\n如果再复制发送，就把你拉黑！[抱拳]\n如果是误会，请末尾加1后再次发送，谢谢体谅，小永敬上[握手]")->reply();//164
    return;
  }
  // watchdog('len23', strlen($ori_keyword), array(), WATCHDOG_NOTICE, 'link');
  $keyword = make_semiangle($ori_keyword);
  if($account->uid == 8 && strpos($ori_keyword,'http://mp.weixin.qq.com/s?__biz=')!==FALSE){
    $openid = $weObj->getRev()->getRevFrom();
    // watchdog('openid', $openid, array(), WATCHDOG_NOTICE, 'link');
    if(in_array($openid, array('oTjEws_LNd8maly0PugxnmFQPdTA','oTjEws-8eAAUqgR4q_ns7pbd0zN8'))){
        $url = url(NULL, array('absolute' => TRUE)) . (variable_get('clean_url', 0) ? '' : '?q=').'grace365';
        $data = array('link' => $keyword);
        $options = array(
            'http' => array(
                'header'  => "Content-type: application/x-www-form-urlencoded\r\n",
                'method'  => 'POST',
                'content' => http_build_query($data),
            ),
        );
        $context  = stream_context_create($options);
        file_get_contents($url, false, $context);
        // watchdog('result', '<pre>'.print_r($result,1), array(), WATCHDOG_NOTICE, 'link');
        $weObj->text("今日<a href='http://wx.yongbuzhixi.com/grace365'>恩典365</a>已发布成功！谢谢您杨弟兄！[握手]")->reply();
        return;
    }
  }


  $search =  array('[',']',"'",'"', "收听",'`','.','○','o','〇',',',':','|',' ','一',);
  $replace =  array('','','','','', '', '', '0', '0','0','', '','', '', '',); 
  $keyword = str_replace($search, $replace, $keyword);
  $keyword = strtolower($keyword);


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
  if(!is_array($weObj->Message(''))){
    module_invoke_all('wxservice_default_msg_alter', $weObj, $keyword,$account);
  }
  if(!is_array($weObj->Message(''))){
    $default_keyword = variable_get('mp_config_default_re_'.$account->uid, "");
    if($default_keyword){
      mp_service_keyword_response($weObj,$default_keyword,$account);
      ga_push_add_event(array(
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
        $data['nickname'] = $user_info['nickname'];
        $data['openid'] = $openid;
        $data['content'] = $keyword;
        $data['time'] = $weObj->getRevCtime(); //1444450304
        $id = $weObj->getRevID();//6203866816598959257
        $re = firebaseset('wechat/'.$id,$data);
        // watchdog('firebaseset', $data['nickname'].$keyword, array(), WATCHDOG_NOTICE, 'link');
        //firebaseset end!
        ga_push_add_event(array(
         'category'        => 'firebaseset',
         'action'          => $ori_keyword,
         'label'           => 'wxservice_'.$account->uid,
        ));
      }else{
        $copyright = copyright($account);
        $weObj->text(variable_get('wechat_default_message_'.$account->uid, "您好，谢谢您的反馈！[握手]").$copyright);
        ga_push_add_event(array(
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
    break;
  }
   // watchdog('SCANinfo', '<pre>'.print_r($event,true), array(), WATCHDOG_NOTICE, 'error');  
  if($account->uid == 8 && $event['event']=='SCAN'){
    $uid = $event['key'];
    // $user = user_load($uid);
    // watchdog('SCANinfo', '<pre>'.print_r($event,true), array(), WATCHDOG_NOTICE, 'error');  
    $openid = $weObj->getRev()->getRevFrom();
    $user_info = $weObj->getUserInfo($openid);
    $user_name = $user_info['nickname'];
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
        $user_name = $user_info['nickname'].'_'.$count;
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
        // 'field_sex' => 1,2男 ＝》 0 男 1 女
        'field_user_sex' => array(LANGUAGE_NONE => array(array('value' => ($user_info['sex'])%2))),
        'field_headimgurl' => array(LANGUAGE_NONE => array(array('value' => $user_info['headimgurl']))),
        'field_recommend' => array(LANGUAGE_NONE => array(array('target_id' => $uid))),
        
      );
      $account = user_save(null, $new_user);
      if(!$account){
        // drupal_set_message('账户创建失败！', 'error', FALSE);
        watchdog('mp_service_pages', '账户创建失败！', array(), WATCHDOG_NOTICE, 'error');
      }
      watchdog('mp_service_pages', $user_name.'账户创建成功！'.$account->uid, array(), WATCHDOG_NOTICE, 'link');
      // $friend_name = db_result(db_query("SELECT name FROM {users} WHERE uid = '%s'", $uid));{".$friend_name."
      $weObj->text("恭喜您和好友都已获得100积分,奖品有：<a href='http://www.amazon.cn/dp/B00KDRNYO4'>kindle，CD，图书...</a>\n点击【活动】→二维码，呼朋唤友，踊跃参与吧[跳跳]")->reply();
      //add points!
      return; 
    }else{
      if($uid == $account->uid){
        $weObj->text("赶快分享本图片到朋友圈、好友、群、QQ即可邀请他们来参加积分有奖活动！\n奖品有：<a href='http://www.amazon.cn/dp/B00KDRNYO4'>kindle，CD，图书...</a>\n呼朋唤友，踊跃参与吧[转圈]")->reply();
      };
        watchdog('老朋友', $account->uid, array(), WATCHDOG_NOTICE, 'error');
      $weObj->text("老朋友您好，此次扫描无效。请点击【活动】→二维码，来邀请新朋友赚积分赢大奖吧！\n奖品有：<a href='http://www.amazon.cn/dp/B00KDRNYO4'>kindle，CD，图书...</a>\n呼朋唤友，踊跃参与吧[转圈]")->reply();
      return;
    }
    return;
  }
  if(!isset($event['key'])){
    ga_push_add_event(array(
       'category'        => 'event',
       'action'          => $event['event'],
       'label'           => 'wxservice_'.$account->uid,
    ));
  }else{
    if($event['event']=='VIEW'){
      //MP menu!
    }else{
      mp_service_keyword_response($weObj,$event['key'],$account);
    }
    if(!is_array($weObj->Message(''))){ 
      ga_push_add_event(array(
         'category'        => 'event_'.$event['event'],
         'action'          =>  $event['key'],
         'label'           => 'wxservice_'.$account->uid,
      ));
    }else{
      if($event['event']=='CLICK'){
        //MP menu!
      }else{
        watchdog('no! track event!', '<pre>'.print_r($event,true), array(), WATCHDOG_NOTICE, 'error');  
      }
    }
  }
	//add default behavior
  if($event['event']=='subscribe'){
    if($account->uid == 8){
      // watchdog($event['key'], strpos($event['key'],'qrscene_'), array(), WATCHDOG_NOTICE, 'link');
      if(isset($event['key']) && strpos($event['key'],'qrscene_')!==FALSE){
        $uid = str_replace('qrscene_', '', $event['key']);
        // $user = user_load($uid);
        // watchdog('SCANinfo', '<pre>'.print_r($event,true), array(), WATCHDOG_NOTICE, 'error');  
        $openid = $weObj->getRev()->getRevFrom();
        $user_info = $weObj->getUserInfo($openid);
        $user_name = $user_info['nickname'];
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
            $user_name = $user_info['nickname'].'_'.$count;
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
            // 'field_sex' => 1,2男 ＝》 0 男 1 女
            'field_user_sex' => array(LANGUAGE_NONE => array(array('value' => ($user_info['sex'])%2))),
            'field_headimgurl' => array(LANGUAGE_NONE => array(array('value' => $user_info['headimgurl']))),
            'field_recommend' => array(LANGUAGE_NONE => array(array('target_id' => $uid))),
            
          );
          $account = user_save(null, $new_user);
          if(!$account){
            // drupal_set_message('账户创建失败！', 'error', FALSE);
            watchdog('mp_service_pages', '账户创建失败！', array(), WATCHDOG_NOTICE, 'error');
          }
          watchdog('mp_service_pages', $user_name.'账户创建成功！'.$account->uid, array(), WATCHDOG_NOTICE, 'link');
            
          $weObj->text('{'.$account->name."}恭喜您接受了的邀请！你们都获得100积分，推荐10人即可参加积分抽奖，奖品有：kindle，CD，图书。。。谢谢参与！")->reply();
          //add points!
          return; 
        }else{
          if($uid == $account->uid){
            $weObj->text("请您分享本图片到朋友圈或发给好友或群组即可邀请他们来参加活动。\n推荐100积分的奖励哦！奖品有：kindle，CD，图书...谢谢参与！")->reply();
          };
          $weObj->text("老朋友您好，此次扫描无效。请点击【活动】→二维码，来邀请新朋友赚积分赢大奖吧！")->reply();
          return;
        }
      }
    }else{
      $copyright = copyright($account);
      $weObj->text(variable_get("wechat_follow_message_".$account->uid, '您好，欢迎关注我们！[握手]').$copyright);
    }
    // [event] => subscribe
    // [key] => qrscene_1079
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
    // watchdog('create user '.$mail, 'message', array(), WATCHDOG_NOTICE, 'link');
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