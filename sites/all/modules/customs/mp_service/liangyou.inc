<?php
function liangyou_audio_list(){
  $prefix['31'] = 'http://liangyou2.nissigz.com:15200/';
  $prefix['32'] = 'http://liangyou.nissigz.com:18100/';
  $radios_list = array(
    // 福音节目-适合所有人士
    // '31' => array(//15200

      'mp' => array('download_button' =>0,'url'=>'??', 'name' =>'这一刻，清心', 'prefix'=>$prefix['31'],'day'=>6),
      'tg' => array('download_button' =>0,'url'=>'??', 'name' =>'施恩座前', 'prefix'=>$prefix['31'],'day'=>0),//0
      'ns' => array('download_button' =>1,'url'=>'http://stream.liangyou.net/program/1njcji-3b2p30', 'name' =>'生命的四季', 'prefix'=>$prefix['32'],'day'=>0),//0
      'ds' => array('download_button' =>1,'url'=>'http://stream.liangyou.net/program/1njcji-3b2p30', 'prefix'=>$prefix['31'],'name' =>'晨曦讲座'),

      'cc' => array('download_button' =>1,'url'=>'http://stream.liangyou.net/program/1njcji-3b2p30', 'prefix'=>$prefix['32'],'name' =>'空中辅导'),
      '520' => array('download_button' =>0,'url'=>'http://stream.liangyou.net/channel/65837e3587', 'name' =>'良友直播'),
      'ir' => array('download_button' =>1,'url'=>'http://stream.liangyou.net/program/1njchu-3b2ozo', 'name' =>'i-radio爱广播', 'prefix'=>$prefix['31'],'day'=>0),//0
      'eg' => array('download_button' =>1,'url'=>'http://stream.liangyou.net/program/1njcjg-3b2p2w', 'name' =>'英语世界', 'prefix'=>$prefix['31'],'day'=>2),//2
      'gt' => array('download_button' =>1,'url'=>'http://stream.liangyou.net/program/1njcj0-3b2p20', 'name' =>'恩典与真理', 'prefix'=>$prefix['31'],'day'=>0),//0
      'wa' => array('download_button' =>1,'url'=>'http://stream.liangyou.net/program/1njcj3-3b2p26', 'name' =>'天路导向', 'prefix'=>$prefix['31'],'day'=>6),//6,7
      'cwa' => array('download_button' =>1,'url'=>'http://stream.liangyou.net/program/1njcj2-3b2p24', 'name' =>'天路导向（粤）', 'prefix'=>$prefix['31'],'day'=>6),//6,7
      'bg' => array('download_button' =>1,'url'=>'http://stream.liangyou.net/program/1njcjd-3b2p2q', 'name' =>'普世佳音', 'prefix'=>$prefix['31'],'day'=>1),//1
      'yu' => array('download_button' =>1,'url'=>'http://stream.liangyou.net/program/1njchx-3b2ozu', 'name' =>'绝妙当家', 'prefix'=>$prefix['31'],'day'=>0),//0
      'gv' => array('download_button' =>1,'url'=>'http://stream.liangyou.net/program/1njci3-3b2p06', 'name' =>'生活无国界', 'prefix'=>$prefix['31'],'day'=>0),//0
      'zz' => array('download_button' =>1,'url'=>'http://stream.liangyou.net/program/1njciw-3b2p1s', 'name' =>'零点零距离', 'prefix'=>$prefix['31'],'day'=>5),//1-5
      'se' => array('download_button' =>1,'url'=>'http://stream.liangyou.net/program/1njci0-3b2p00', 'name' =>'恋爱季节', 'prefix'=>$prefix['31'],'day'=>5),//1-5
      'up' => array('download_button' =>1,'url'=>'http://stream.liangyou.net/program/1njcil-3b2p16', 'name' =>'亲情不断电', 'prefix'=>$prefix['31'],'day'=>5),//1-5
      'bc' => array('download_button' =>1,'url'=>'http://stream.liangyou.net/program/1njci1-3b2p02', 'name' =>'书香园地', 'prefix'=>$prefix['31'],'day'=>5),//1-5
      'gn' => array('download_button' =>1,'url'=>'http://stream.liangyou.net/program/1njcif-3b2p0u', 'name' =>'现代人的希望', 'prefix'=>$prefix['31'],'day'=>0),//0
      'hg' => array('download_button' =>1,'url'=>'http://stream.liangyou.net/program/1njci4-3b2p08', 'name' =>'欢乐卡恰碰', 'prefix'=>$prefix['31'],'day'=>0),//0
      'yn' => array('download_button' =>1,'url'=>'http://stream.liangyou.net/program/1njcj1-3b2p22', 'name' =>'爱在人间（云南）', 'prefix'=>$prefix['31'],'day'=>0),//0
      'im' => array('download_button' =>1,'url'=>'http://stream.liangyou.net/program/1njchy-3b2ozw', 'name' =>'i关怀心磁场', 'prefix'=>$prefix['31'],'day'=>5),//1-5
      'ib' => array('download_button' =>1,'url'=>'http://stream.liangyou.net/program/1njcjm-3b2p38', 'name' =>'无限飞行号', 'prefix'=>$prefix['31'],'day'=>0),//0
      'rt' => array('download_button' =>1,'url'=>'http://stream.liangyou.net/program/1njcia-3b2p0k', 'name' =>'今夜心未眠', 'prefix'=>$prefix['31'],'day'=>6),//6,7
      'em' => array('download_button' =>1,'url'=>'http://stream.liangyou.net/program/1njci7-3b2p0e', 'name' =>'听听90后', 'prefix'=>$prefix['31'],'day'=>6),//6,7
      'yr' => array('download_button' =>1,'url'=>'http://stream.liangyou.net/program/1njciv-3b2p1q', 'name' =>'Yi-radio爱广播', 'prefix'=>$prefix['31'],'day'=>0),//0
      
    // '32' => array(//18100
      // 栽培节目-适合基督徒http://stream.liangyou.net/program/1njcht-3b2ozm
      // 'bv' => array('download_button' =>1,'url'=>'http://stream.liangyou.net/program/1njcht-3b2ozm', 'name' =>'灵命日粮', 'prefix'=>$prefix['32'],'day'=>0),//0
      'ee' => array('download_button' =>1,'url'=>'http://stream.liangyou.net/program/1njchw-3b2ozs', 'name' =>'拥抱每一天', 'prefix'=>$prefix['32'],'day'=>0),//0
      'bf' => array('download_button' =>1,'url'=>'http://stream.liangyou.net/program/1njci6-3b2p0c', 'name' =>'幸福满家园', 'prefix'=>$prefix['32'],'day'=>6),//6 7
      'ws' => array('download_button' =>1,'url'=>'http://stream.liangyou.net/program/1njci9-3b2p0i', 'name' =>'长夜的牵引', 'prefix'=>$prefix['32'],'day'=>0),//0
      'be' => array('download_button' =>1,'url'=>'http://stream.liangyou.net/program/1njcik-3b2p14', 'name' =>'真道分解', 'prefix'=>$prefix['32'],'day'=>0),//0
      'tr' => array('download_button' =>1,'url'=>'http://stream.liangyou.net/program/1njchv-3b2ozq', 'name' =>'彩虹桥', 'prefix'=>$prefix['32'],'day'=>0),//0
      'ns' => array('download_button' =>1,'url'=>'http://stream.liangyou.net/program/1njciu-3b2p1o', 'name' =>'生命的四季', 'prefix'=>$prefix['32'],'day'=>5),
      'cw' => array('download_button' =>1,'url'=>'http://stream.liangyou.net/program/1njchz-3b2ozy', 'name' =>'齐来颂扬', 'prefix'=>$prefix['32'],'day'=>5),
      'wpb' => array('download_button' =>1,'url'=>'http://stream.liangyou.net/program/1njcim-3b2p18', 'name' =>'圣乐天地', 'prefix'=>$prefix['32'],'day'=>6),
      // 'bv' => '空中辅导',
      // 'bv' => '无愧的工人',
      // 'bv' => '有问必答',
      // 'bv' => '生命指南针',
      // 'bv' => '蓝天绿洲',
      // 'bv' => '圣乐天地 ',
      // 'bv' => '好牧人',
      // 'bv' => '善牧良言',
      // 'bv' => '经动人心',
      // 'bv' => '信仰百宝箱',
      // 'bv' => '生命的福音',
      // 'bv' => '听听女人心',
      // 'bv' => '生根建造',
      // 'bv' => '聆听主道',
      // 'bv' => '圣言盛宴',
      // 'bv' => '真理之光',
      // 'wpb' => '圣乐天地 - 古典圣诗',http://liangyou.nissigz.com:18100/wpb/wpb140301.mp3
      // 'bv' => '空中崇拜',
      // 'bv' => '给力人生',
      // 'bv' => '空中门训',
      // 'bv' => '生活之光',

      // 'nissigz3' = array(
      //  // 训练节目-适合事奉人员
      //  // 接棒人
      //  // 
      //  // 申命记
      //  // 教牧辅导
      //  // 事奉装备
      //  // 基督教教义
      //  // 基督教伦理学
      //  // 圣诞节特辑
      //  // 新约神学
      //  ),
    );
  return $radios_list;
}

function liangyou_audio_respond($wechatObj,$keyword,$radios_list)
{ //bc1
      $temp_key = substr($keyword, 0,2);
      if(in_array($temp_key, array_keys($radios_list))) {

        $offset = 0;
        if(strlen($keyword)>2) {
          $offset = substr($keyword, 2,1);
          if(!is_numeric($offset)) $offset = 0;
          $keyword = substr($keyword, 0,2);
        }
  $prefix['31'] = 'http://liangyou2.nissigz.com:15200/';
  $prefix['32'] = 'http://liangyou.nissigz.com:18100/';

        $title = $radios_list[$keyword]['name'];//'英语世界';
        $title = "【".$keyword."】".$title;
        $string = date('ymd',time()-$offset*24*60*60); 
        $url = $radios_list[$keyword]['prefix'].$keyword.'/'.$keyword.$string.'.mp3';
        // watchdog('url', $radios_list[$keyword]['prefix'], array(), WATCHDOG_NOTICE, 'link'); 
        $musicurl = $url;
        // if(!remote_file_exists($musicurl)){
        //   $wechatObj->text("对不起，小永发现".$title."还没准备好，请稍后再试[微笑]！")->reply();
        //   return;
        // }
        $week_day = date('N', time());
        $desc = "公众号:永不止息 ".date("n月d日-周").$week_day;
        if($offset) {
          $desc = "公众号:永不止息 历史节目-".$offset;
        }      
        $hgmusicurl = $musicurl;
        $wechatObj->music($title, $desc, $musicurl, $hgmusicurl)->reply();exit;

         // $Title = $radios_list[$keyword]['name'];
         // $Url = $radios_list[$keyword]['url'];
           
         //    $img = array(
         //      'Title'=> $Title,
         //      'Description'=>"点击收听！\n永不止息，需要有你！\n可以在浏览器中打开链接进入后台播放！",
         //      'PicUrl'=>"https://farm1.staticflickr.com/62/161998768_677038139b.jpg",
         //      'Url'=> $Url
         //    );
         //    $news[] = $img;         
         //    $wechatObj->news($news)->reply(); exit;
        // $offset = 0;
        // if(strlen($keyword)>2) {
        //   $offset = substr($keyword, 2,1);
        //   if(!is_numeric($offset)) $offset = 0;
        //   $keyword = substr($keyword, 0,2);
        // }
        // $url = ly_get_download_url($keyword,$offset);
        
        // $title = $radios_list[$keyword]['name'];//'英语世界';
        // $title = "【".$keyword."】".$title;
        // // $string = date('ymd',time()-$offset*24*60*60);
        // $musicurl = $url;
        // $week_day = date('N', time());
        // $desc = "公众号:永不止息 ".date("n月d日-周").$week_day;
        // if($offset) {
        //   $desc = "公众号:永不止息 历史节目-".$offset;
        // }        
        // $hgmusicurl = $musicurl;
        // $wechatObj->music($title, $desc, $musicurl, $hgmusicurl)->reply();
        exit;

      }
}

function ly_get_download_urls($key = '',$offday = '0'){
  $radios_list = liangyou_audio_list();
  // dpm($radios_list);
  // $key ='ws';
  $live_radios = array();
  foreach ($radios_list as $keyword=>$value) {
    if($key!='') {
      if($key!=$keyword) continue;
    }     
    $url = $radios_list[$keyword]['url'];
    // dpm($url);
    $html = file_get_html($url);
    if($radios_list[$keyword]['download_button']) {
      foreach($html->find('a.download_button') as $e) 
        $audio_urls[] = $e->href;
    }else {
      $pattern = '/download_mp3:"http:\/\/stream.liangyou.net\/get_download\/\w+-\w+/';
      preg_match_all ($pattern, $html, $matches);
      // dpm($matches[0]);
      foreach($matches[0] as $value){
        $audio_urls[] = str_replace('download_mp3:"', '', $value);
      }
    }
      

   
    // dpm($audio_urls);
    $count = -1;
    foreach ($audio_urls as $url) {
      $count++;
      // $live_radios[] = get_location($url);
      $live_radios[$keyword][] = drupal_http_request("http://yongbuzhixi.duapp.com/get_location.php?url=$url")->data;//http://115.29.41.155/wp-login/wp_login/get_location.php?url=
      if($offday == $count) {
        break;
      }
    }
    // break;
  }
  // dpm($live_radios);
  return $live_radios;
}

function ly_get_download_url($key = 'ws',$offday = '0'){
  $donws =  ly_get_download_urls($key,$offday);
  // dpm($donws[$key][$offday]);
  return $donws[$key][$offday];
}

// get_download_url('ws',0);
// $uri = get_download_url('ws',1);