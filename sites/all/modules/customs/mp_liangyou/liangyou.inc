<?php
function liangyou_audio_list(){
  $prefix['31'] = 'http://liangyou.nissigz.com/';
  $prefix['32'] = 'http://liangyou2.nissigz.com/';
  $prefix['33'] = 'http://liangyou3.nissigz.com/';
  $radios_list = array(
      'ir' => array('download_button' =>1,'url'=>'http://www.txly1.net/program/1njchu-3b2ozo', 'name' =>'爱广播', 'prefix'=>$prefix['32'],'day'=>0),
      'gt' => array('download_button' =>1,'url'=>'http://www.txly1.net/program/1njcj0-3b2p20', 'name' =>'恩典与真理', 'prefix'=>$prefix['32'],'day'=>0),//0
      'wa' => array('download_button' =>1,'url'=>'http://www.txly1.net/program/1njcj3-3b2p26', 'name' =>'天路导向', 'prefix'=>$prefix['32'],'day'=>67),
      // 'cwa' => array('download_button' =>1,'url'=>'http://stream.liangyou.net/program/1njcj2-3b2p24', 'name' =>'天路导向（粤）', 'prefix'=>$prefix['32'],'day'=>67),
      'yu' => array('download_button' =>1,'url'=>'http://www.txly1.net/program/1njchx-3b2ozu', 'name' =>'绝妙当家', 'prefix'=>$prefix['32'],'day'=>0),//0
      'gv' => array('download_button' =>1,'url'=>'http://www.txly1.net/program/1njci3-3b2p06', 'name' =>'生活无国界', 'prefix'=>$prefix['32'],'day'=>0),//0
      'zz' => array('download_button' =>1,'url'=>'http://www.txly1.net/program/1njciw-3b2p1s', 'name' =>'零点零距离', 'prefix'=>$prefix['32'],'day'=>5),//1-5
      'se' => array('download_button' =>1,'url'=>'http://www.txly1.net/program/1njci0-3b2p00', 'name' =>'炼爱季节', 'prefix'=>$prefix['32'],'day'=>5),//1-5   
      'up' => array('download_button' =>1,'url'=>'http://www.txly1.net/program/1njci6-3b2p0c', 'name' =>'亲情不断电', 'prefix'=>$prefix['32'],'day'=>5),//1-5
      'bc' => array('download_button' =>1,'url'=>'http://www.txly1.net/program/1njci1-3b2p02', 'name' =>'书香园地', 'prefix'=>$prefix['32'],'day'=>5),//1-5

      'gn' => array('download_button' =>1,'url'=>'http://www.txly1.net/program/1njcif-3b2p0u', 'name' =>'现代人的希望', 'prefix'=>$prefix['32'],'day'=>0),//0
      'hg' => array('download_button' =>1,'url'=>'http://www.txly1.net/program/1njci4-3b2p08', 'name' =>'欢乐卡恰碰', 'prefix'=>$prefix['32'],'day'=>0),//0
      // 'ynf' => array('download_button' =>1,'url'=>'http://stream.liangyou.net/program/1njcj1-3b2p22', 'name' =>'爱在人间（云南）', 'prefix'=>$prefix['32'],'day'=>0),//0
      'im' => array('download_button' =>1,'url'=>'http://www.txly1.net/program/1njchy-3b2ozw', 'name' =>'i关怀心磁场', 'prefix'=>$prefix['32'],'day'=>5),//1-5
      'ib' => array('download_button' =>1,'url'=>'http://www.txly1.net/program/1njcjm-3b2p38', 'name' =>'无限飞行号', 'prefix'=>$prefix['32'],'day'=>0),//0
      'rt' => array('download_button' =>1,'url'=>'http://www.txly1.net/program/1njcia-3b2p0k', 'name' =>'今夜心未眠', 'prefix'=>$prefix['32'],'day'=>67),//6,7
      'mp' => array('download_button' =>1,'url'=>'http://www.txly1.net/program/1njcld-3b2p6q', 'name' =>'这一刻，清心', 'prefix'=>$prefix['32'],'day'=>67),//6,7
      'tg' => array('download_button' =>1,'url'=>'http://www.txly1.net/program/1njclc-3b2p6o', 'name' =>'施恩座前', 'prefix'=>$prefix['32'],'day'=>0),//0
      'ls' => array('download_button' =>1,'url'=>'http://www.txly1.net/program/1njclz-3b2p7y', 'name' =>'燃亮的一生', 'prefix'=>$prefix['32'],'day'=>67),
    
      'fc' => array('download_button' =>1,'url'=>'http://www.txly1.net/program/1njcm0-3b2p80', 'name' =>'微播出炉', 'prefix'=>$prefix['32'],'day'=>5),//1-5

      ///////良友知音站栽培节目 - 适合基督徒
      'ns' => array('download_button' =>1,'url'=>'http://www.txly1.net/program/1njciu-3b2p1o', 'name' =>'生命的四季', 'prefix'=>$prefix['33'],'day'=>0),//0
      'be' => array('download_button' =>1,'url'=>'http://www.txly1.net/program/1njcik-3b2p14', 'name' =>'真道分解', 'prefix'=>$prefix['33'],'day'=>0),//0
      'cc' => array('download_button' =>1,'url'=>'http://www.txly1.net/program/1njci2-3b2p04', 'name' =>'空中辅导', 'prefix'=>$prefix['33'],'day'=>0),
      'bf' => array('download_button' =>1,'url'=>'http://stream.liangyou.net/program/1njci6-3b2p0c', 'name' =>'幸福满家园', 'prefix'=>$prefix['33'], 'day'=>67),
      'ee' => array('download_button' =>1,'url'=>'http://www.txly1.net/program/1njchw-3b2ozs', 'name' =>'拥抱每一天', 'prefix'=>$prefix['33'],'day'=>0),//0
      'tr' => array('download_button' =>1,'url'=>'http://www.txly1.net/program/1njchv-3b2ozq', 'name' =>'彩虹桥', 'prefix'=>$prefix['33'],'day'=>0),//0
      'cw' => array('download_button' =>1,'url'=>'http://www.txly1.net/program/1njchz-3b2ozy', 'name' =>'齐来颂扬', 'prefix'=>$prefix['33'],'day'=>5),
      'hd' => array('download_button' =>1,'url'=>'http://www.txly1.net/program/1njcit-3b2p1m', 'name' =>'蓝天绿洲', 'prefix'=>$prefix['33'],'day'=>67),//6 7
      'hd' => array('download_button' =>1,'url'=>'http://www.txly1.net/program/1njcix-3b2p1u', 'name' =>'好牧人', 'prefix'=>$prefix['33'],'day'=>7),//7
      'hd' => array('download_button' =>1,'url'=>'http://www.txly1.net/program/1njciz-3b2p1y', 'name' =>'善牧良言', 'prefix'=>$prefix['33'],'day'=>7),//only 5！！！
      'ba' => array('download_button' =>1,'url'=>'http://www.txly1.net/program/1njcis-3b2p1k', 'name' =>'经动人心', 'prefix'=>$prefix['33'],'day'=>7),//7
      //信仰百宝箱 135
      'ws' => array('download_button' =>1,'url'=>'http://www.txly1.net/program/1njci9-3b2p0i', 'name' =>'长夜的牵引', 'prefix'=>$prefix['33'],'day'=>0),//0
      'bv' => array('download_button' =>1,'url'=>'http://www.txly1.net/program/1njcly-3b2p7w', 'name' =>'灵命日粮', 'prefix'=>$prefix['33'],'day'=>0),//0
      'mw' => array('download_button' =>1,'url'=>'http://www.txly1.net/program/1njcly-3b2p7w', 'name' =>'旷野吗哪', 'prefix'=>$prefix['33'],'day'=>0),//0

      ///////
      'pb' => array('download_button' =>1,'url'=>'http://www.txly1.net/program/1njcj9-3b2p2i', 'name' =>'接棒人', 'prefix'=>$prefix['32'],'day'=>5),//1-5
      'ds' => array('download_button' =>1,'url'=>'http://www.txly1.net/program/1njcji-3b2p30', 'prefix'=>$prefix['32'],'name' =>'晨曦讲座','day'=>0),
      'vx' => array('download_button' =>1,'url'=>'http://www.txly1.net/program/1njclb-3b2p6m', 'name' =>'良院精选', 'prefix'=>$prefix['32'],'day'=>7),//7
  );
  // foreach($radios_list as $key=>$audio){
  // $menu .= '<br/>【'.$key.'】'.$audio['name'];
  // }
  // dvm($menu);
  return $radios_list;

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



function ly_stream_source(){
  // $url = 'http://www.729ly.net/Template/Shared/npage/stream/instant_listen_page_20151025.html';
  // $html = file_get_html($url);
  // // find all link
  // $links = array();
  // foreach($html->find('a') as $e) {
  //   if(strstr($e->href,'http://www.txly1.net/program/'))
  //     $links[$e->title] = $e->href;
  // }
  // return $links;
  // dpm($links);

  return  array(
    '无限飞行号' => 'http://www.txly1.net/program/1njcjm-3b2p38',
    'i关怀心磁场' => 'http://www.txly1.net/program/1njchy-3b2ozw',
    '空中辅导' => 'http://www.txly1.net/program/1njci2-3b2p04',
    '恋爱季节' => 'http://www.txly1.net/program/1njci0-3b2p00',
    '幸福满家园' => 'http://www.txly1.net/program/1njci6-3b2p0c',
    '亲情不断电' => 'http://www.txly1.net/program/1njcil-3b2p16',
    '欢乐卡恰碰' => 'http://www.txly1.net/program/1njci4-3b2p08',
    '绝妙当家' => 'http://www.txly1.net/program/1njchx-3b2ozu',
    '微播出炉' => 'http://www.txly1.net/program/1njcm0-3b2p80',
    '生活无国界' => 'http://www.txly1.net/program/1njci3-3b2p06',
    '零点零距离' => 'http://www.txly1.net/program/1njciw-3b2p1s',
    '书香园地' => 'http://www.txly1.net/program/1njci1-3b2p02',
    '爱广播' => 'http://www.txly1.net/program/1njchu-3b2ozo',
    '今夜心未眠' => 'http://www.txly1.net/program/1njcia-3b2p0k',
    '彩虹桥' => 'http://www.txly1.net/program/1njchv-3b2ozq',
    '长夜的牵引' => 'http://www.txly1.net/program/1njci9-3b2p0i',
    '现代人的希望' => 'http://www.txly1.net/program/1njcif-3b2p0u',
    '生命的四季' => 'http://www.txly1.net/program/1njciu-3b2p1o',
    '拥抱每一天' => 'http://www.txly1.net/program/1njchw-3b2ozs',
    '旷野吗哪' => 'http://www.txly1.net/program/1njcly-3b2p7w',
    '真道分解' => 'http://www.txly1.net/program/1njcik-3b2p14',
    '圣言盛宴' => 'http://www.txly1.net/program/1njci8-3b2p0g',
    '齐来颂扬' => 'http://www.txly1.net/program/1njchz-3b2ozy',
    '施恩座前' => 'http://www.txly1.net/program/1njclc-3b2p6o',
    '真理之光' => 'http://www.txly1.net/program/1njcjh-3b2p2y',
    '接棒人' => 'http://www.txly1.net/program/1njcj9-3b2p2i',
    '聆听主道' => 'http://www.txly1.net/program/1njciy-3b2p1w',
    '空中崇拜' => 'http://www.txly1.net/program/1njcir-3b2p1i',
    '善牧良言' => 'http://www.txly1.net/program/1njciz-3b2p1y',
    '好牧人' => 'http://www.txly1.net/program/1njcix-3b2p1u',
    '经动人心' => 'http://www.txly1.net/program/1njcis-3b2p1k',
    '佳美脚踪' => 'http://www.txly1.net/program/1njcl2-3b2p64',
    '蓝天绿洲' => 'http://www.txly1.net/program/1njcit-3b2p1m',
    '给力人生' => 'http://www.txly1.net/program/1njcj7-3b2p2e',
    '空中门训' => 'http://www.txly1.net/program/1njcja-3b2p2k',
    '生根建造' => 'http://www.txly1.net/program/1njcj5-3b2p2a',
    '信仰百宝箱' => 'http://www.txly1.net/program/1njcj8-3b2p2g',
    '生活之光' => 'http://www.txly1.net/program/1njcjc-3b2p2o',
    '生命的福音' => 'http://www.txly1.net/program/1njcjb-3b2p2m',
    '这一刻，清心' => 'http://www.txly1.net/program/1njcld-3b2p6q',
    '良院（基础课程）' => 'http://www.txly1.net/program/1njck8-3b2p4g',
    '良院（本科一套）' => 'http://www.txly1.net/program/1njck9-3b2p4i',
    '良院（本科二套）' => 'http://www.txly1.net/program/1njcka-3b2p4k',
    '良院（进深一套）' => 'http://www.txly1.net/program/1njckb-3b2p4m',
    '良院（进深二套）' => 'http://www.txly1.net/program/1njckc-3b2p4o',
    '晨曦讲座' => 'http://www.txly1.net/program/1njcji-3b2p30',
    '良院精选' => 'http://www.txly1.net/program/1njclb-3b2p6m',
    '天路导向' => 'http://www.txly1.net/program/1njcj3-3b2p26',
    '天路导向（粤语）' => 'http://www.txly1.net/program/1njcj2-3b2p24',
    '恩典与真理（回民）' => 'http://www.txly1.net/program/1njcj0-3b2p20',
    '爱在人间（云南话）' => 'http://www.txly1.net/program/1njcj1-3b2p22',
    '燃亮的一生' => 'http://www.txly1.net/program/1njclz-3b2p7y',
  );
}

// $url = 'http://www.729ly.net/Template/Shared/npage/stream/instant_listen_page_20151025.html';
// $html = file_get_html($url);
// // find all link
// $links = array();
// $count = 601;
// foreach($html->find('a') as $e) {
//   if(strstr($e->href,'http://www.txly1.net/program/'))
//     $links[] ='【'. ($count++) .'】' . $e->title;
// }
// dvm($links);
/**
 * 良友圣经学院
 */
function get_ly_mav(){
  return array(
    'a1'=>array(
      'prefex'  => 'mavst0',
      'count'=>24,
      'title'=>'主日学教学法',
      'level'=>'1',//本科课程
      'pdf' => '1',//本科课程/主日学教学法/主日学教学法.pdf=level+title+pdf
    ),
    'a2'=>array(
      'prefex'  => 'mavop0',
      'count'=>30,
      'title'=>'先知书I',
      'level'=>'1',
      'pdf' => '1'
    ),
    'a3'=>array(
      'prefex'  => 'mavor0',
      'count'=>30,
      'title'=>'先知书II',
      'level'=>'1',
      'pdf' => '1'
    ),
    'a4'=>array(
      'prefex'  => 'mavrt0',
      'count'=>30,
      'title'=>'启示录',
      'level'=>'1',
      'pdf' => '1'
    ),
    'a5'=>array(
      'prefex'  => 'mavfe0',
      'count'=>24,
      'title'=>'团契生活',
      'level'=>'1',
      'pdf' => '1'
    ),
    'a6'=>array(
      'prefex'  => 'mavpn1',
      'count'=>24,
      'title'=>'圣灵论',
      'level'=>'1',
      'pdf' => '1'
    ),
    'a7'=>array(
      'prefex'  => 'mavtb0',
      'count'=>24,
      'title'=>'圣经教师训练',
      'level'=>'1',
      'pdf' => '1'
    ),
    'a8'=>array(
      'prefex'  => 'mavbi0',
      'count'=>24,
      'title'=>'圣经背景',
      'level'=>'1',
      'pdf' => '1'
    ),
    'a9'=>array(
      'prefex'  => 'mavcw0',
      'count'=>24,
      'title'=>'基督工人操守',
      'level'=>'1',
      'pdf' => '1'
    ),
    'b1'=>array(
      'prefex'  => 'mavcs0',
      'count'=>24,
      'title'=>'基督教与科学',
      'level'=>'1',
      'pdf' => '1'
    ), 
    'b2'=>array(
      'prefex'  => 'mavcd0',
      'count'=>30,
      'title'=>'基督教教义',
      'level'=>'1',
      'pdf' => '2'
    ),
    'b3'=>array(
      'prefex'  => 'mavmc0',
      'count'=>30,
      'title'=>'婚姻辅导',
      'level'=>'1',
      'pdf' => '1'
    ), 
    'b4'=>array(
      'prefex'  => 'mavoe1',
      'count'=>6,
      'title'=>'学习锦囊',
      'level'=>'1',
      'pdf' => '0'//To change name!!-1本科课程/学习锦囊/第十一届课程概览.pdf
    ), 
    'b5'=>array(
      'prefex'  => 'mavhx0',
      'count'=>30,
      'title'=>'异端与极端',
      'level'=>'1',
      'pdf' => '1'
    ),  
    'b6'=>array(
      'prefex'  => 'mavch0',
      'count'=>30,
      'title'=>'教会历史',
      'level'=>'1',
      'pdf' => '1'
    ),   
    'b7'=>array(
      'prefex'  => 'mavcm0',
      'count'=>24,
      'title'=>'教会复兴运动',
      'level'=>'1',
      'pdf' => '1'
    ),  
    'b8'=>array(
      'prefex'  => 'mavca0',
      'count'=>24,
      'title'=>'教会行政',
      'level'=>'1',
      'pdf' => '1'
    ),     
    'b9'=>array(
      'prefex'  => 'mavnt0',
      'count'=>30,
      'title'=>'新约综览',
      'level'=>'1',
      'pdf' => '2'
    ),    //本科课程/新约综览/新约综览考题.doc //本科课程/新约综览/新约综览考题.pdf
    'c1'=>array(
      'prefex'  => 'mavot0',
      'count'=>30,
      'title'=>'旧约综览',
      'level'=>'1',
      'pdf' => '2'
    ), 
    'c2'=>array(
      'prefex'  => 'mavge0',
      'count'=>30,
      'title'=>'普通书信',
      'level'=>'1',
      'pdf' => '1'
    ),
    'c3'=>array(
      'prefex'  => 'mavom0',
      'count'=>18,
      'title'=>'本土差传',
      'level'=>'1',
      'pdf' => '1'
    ),
    'c4'=>array(
      'prefex'  => 'mavsw0',
      'count'=>24,
      'title'=>'神迹奇事',
      'level'=>'1',
      'pdf' => '1'
    ),
    'c5'=>array(
      'prefex'  => 'mavrs0',
      'count'=>30,
      'title'=>'罗马书',
      'level'=>'1',
      'pdf' => '1'
    ),
    'c6'=>array(
      'prefex'  => 'mavhe0',
      'count'=>24,
      'title'=>'解经与研经',
      'level'=>1,
      'pdf' => 2,
    ),
    'c7'=>array(
      'prefex'  => 'mavpb0',
      'count'=>30,
      'title'=>'诗歌智慧书I',
      'level'=>1,
      'pdf' => 1,
    ), 
    'c8'=>array(
      'prefex'  => 'mavpk0',
      'count'=>30,
      'title'=>'诗歌智慧书II',
      'level'=>1,
      'pdf' => 1,
    ),
    'c9'=>array(
      'prefex'  => 'mavlu0',
      'count'=>30,
      'title'=>'路加福音',
      'level'=>1,
      'pdf' => 1,
    ), 
    'd1'=>array(
      'prefex'  => 'mavym0',
      'count'=>24,
      'title'=>'青少年事工',
      'level'=>1,
      'pdf' => 1,
    ), 
        // 本科课程/2015毕业周特辑/mavsp328.mp3
        // 本科课程/2015毕业周特辑/mavsp329.mp3
        // 本科课程/2015毕业周特辑/mavsp330.mp3
        // 本科课程/2015毕业周特辑/mavsp331.mp3
        // 本科课程/2015毕业周特辑/mavsp332.mp3
        // 本科课程/2015毕业周特辑/mavsp333.mp3
        // 本科课程/33周年院庆培灵会/mavsp334.mp3
        // 本科课程/33周年院庆培灵会/mavsp335.mp3
        // 本科课程/33周年院庆培灵会/mavsp336.mp3
        // 本科课程/33周年院庆培灵会/mavsp337.mp3
        // 本科课程/33周年院庆培灵会/mavsp338.mp3
        // 本科课程/33周年院庆培灵会/mavsp339.mp3
        // 本科课程/本科2015开学周特辑/mavsp340.mp3
        // 本科课程/本科2015开学周特辑/mavsp341.mp3
        // 本科课程/本科2015开学周特辑/mavsp342.mp3
        // 本科课程/本科2015开学周特辑/mavsp343.mp3
        // 本科课程/本科2015开学周特辑/mavsp344.mp3
        // 本科课程/本科2015开学周特辑/mavsp345.mp3
    //level=2 进深课程
    'e1'=>array(
      'prefex'  => 'mavee0',
      'count'=>24,
      'title'=>'以弗所书',
      'level'=>2,
      'pdf' => 1,
    ), 
    'e2'=>array(
      'prefex'  => 'mavis0',
      'count'=>30,
      'title'=>'以赛亚书',
      'level'=>2,
      'pdf' => 1,
    ),
    'e3'=>array(
      'prefex'  => 'mavda0',
      'count'=>24,
      'title'=>'但以理书',
      'level'=>2,
      'pdf' => 1,
    ),  
    'e4'=>array(
      'prefex'  => 'mavgs1',
      'count'=>24,
      'title'=>'创世记',
      'level'=>2,
      'pdf' => 1,
    ),
    'e5'=>array(
      'prefex'  => 'mavga0',
      'count'=>24,
      'title'=>'加拉太书',
      'level'=>2,
      'pdf' => 1,
    ),    
    'e6'=>array(
      'prefex'  => 'mavdr0',
      'count'=>18,
      'title'=>'启示论',
      'level'=>2,
      'pdf' => 1,
    ),  
    'e7'=>array(
      'prefex'  => 'mavic0',
      'count'=>24,
      'title'=>'哥林多前书',
      'level'=>2,
      'pdf' => 1,
    ),  
    'e8'=>array(
      'prefex'  => 'mavio0',
      'count'=>24,
      'title'=>'哥林多后书',
      'level'=>2,
      'pdf' => 1,
    ),       
    'e9'=>array(
      'prefex'  => 'mavbl0',
      'count'=>24,
      'title'=>'圣经文学导论',
      'level'=>2,
      'pdf' => 1,
    ),        
    'f1'=>array(
      'prefex'  => 'mavbt0',
      'count'=>24,
      'title'=>'圣经神学',
      'level'=>2,
      'pdf' => 1,
    ),                
    'f2'=>array(
      'prefex'  => 'mavcy1',
      'count'=>24,
      'title'=>'基督论',
      'level'=>2,
      'pdf' => 1,
    ),                    
    'f3'=>array(
      'prefex'  => 'mavso1',
      'count'=>24,
      'title'=>'崇拜学',
      'level'=>2,
      'pdf' => 1,
    ),                        
    'f4'=>array(
      'prefex'  => 'mavmg0',
      'count'=>24,
      'title'=>'差传神学',
      'level'=>2,
      'pdf' => 1,
    ),                             
    'f5'=>array(
      'prefex'  => 'mavhb1',
      'count'=>24,
      'title'=>'希伯来书',
      'level'=>2,
      'pdf' => 1,
    ),                                    
    'f6'=>array(
      'prefex'  => 'mavsn0',
      'count'=>24,
      'title'=>'救恩论',
      'level'=>2,
      'pdf' => 1,
    ),                                            
    'f7'=>array(
      'prefex'  => 'mavey0',
      'count'=>24,
      'title'=>'教会论',
      'level'=>2,
      'pdf' => 1,
    ),                                                   
    'f8'=>array(
      'prefex'  => 'mavps1',
      'count'=>24,
      'title'=>'教牧书信',
      'level'=>2,
      'pdf' => 1,
    ),                                                    
    'f9'=>array(
      'prefex'  => 'mavpt0',
      'count'=>24,
      'title'=>'教牧学',
      'level'=>2,
      'pdf' => 1,
    ),                                                  
    'g1'=>array(
      'prefex'  => 'mavpc0',
      'count'=>24,
      'title'=>'教牧辅导',
      'level'=>2,
      'pdf' => 1,
    ),   //进深课程/教牧辅导/婚前辅导手册.pdf                                              
    'g2'=>array(
      'prefex'  => 'mavng1',
      'count'=>24,
      'title'=>'新约神学',
      'level'=>2,
      'pdf' => 1,
    ),   
    'g3'=>array(
      'prefex'  => 'mavog0',
      'count'=>24,
      'title'=>'旧约神学',
      'level'=>2,
      'pdf' => 1,
    ),     
    'g3'=>array(
      'prefex'  => 'mavet0',
      'count'=>24,
      'title'=>'末世论',
      'level'=>2,
      'pdf' => 1,
    ),    
    'g4'=>array(
      'prefex'  => 'mavhh0',
      'count'=>24,
      'title'=>'进深讲道学',
      'level'=>2,
      'pdf' => 1,
    ),    
    'g5'=>array(
      'prefex'  => 'maveh1',
      'count'=>24,
      'title'=>'释经与讲道',
      'level'=>2,
      'pdf' => 1,
    ),      
    'g6'=>array(
      'prefex'  => 'mavla0',
      'count'=>24,
      'title'=>'领袖训练I',
      'level'=>2,
      'pdf' => 1,
    ),       
    'g7'=>array(
      'prefex'  => 'mavlb0',
      'count'=>24,
      'title'=>'领袖训练II',
      'level'=>2,
      'pdf' => 1,
    ),
  );
}

function get_lysd(){
  return array(
    '真我大看台'=>array(
      'title'=>'01-真我大看台',
      'begin'=>1,
      'end'=>21,
    ),
    '迎战压力'=>array(
      'title'=>'02-迎战压力',
      'begin'=>22,
      'end'=>30,
    ),
    '飞越忧郁的漩涡'=>array(
      'title'=>'03-飞越忧郁的漩涡',
      'begin'=>31,
      'end'=>31,
    ),
    '精神健康'=>array(
      'title'=>'04-精神健康',
      'begin'=>32,
      'end'=>45,
    ),
    '活出彩虹'=>array(
      'title'=>'05-活出彩虹',
      'begin'=>46,
      'end'=>55,
    ),
    '如何面对死亡'=>array(
      'title'=>'06-如何面对死亡',
      'begin'=>56,
      'end'=>61,
    ),
    '职场生涯纵横谈'=>array(
      'title'=>'07-职场生涯纵横谈',
      'begin'=>62,
      'end'=>71,
    ),
    '职场智慧'=>array(
      'title'=>'08-职场智慧',
      'begin'=>72,
      'end'=>91,
    ),
    '青年成长二部曲'=>array(
      'title'=>'09-青年成长二部曲',
      'begin'=>92,
      'end'=>101,
    ),
    '恋爱之道'=>array(
      'title'=>'10-恋爱之道',
      'begin'=>102,
      'end'=>106,
    ),
    '智慧有情人'=>array(
      'title'=>'11-智慧有情人',
      'begin'=>107,
      'end'=>115,
    ),
    '成功婚姻'=>array(
      'title'=>'12-成功婚姻',
      'begin'=>116,
      'end'=>125,
    ),
    '做个棒父母'=>array(
      'title'=>'13-做个棒父母',
      'begin'=>126,
      'end'=>131,
    ),
    '千头万绪家中来'=>array(
      'title'=>'14-千头万绪家中来',
      'begin'=>132,
      'end'=>140,
    ),
    '幸福三部曲'=>array(
      'title'=>'15-幸福三部曲',
      'begin'=>141,
      'end'=>178,
    ),// http://ly729.b0.upaiyun.com/lysd/001.mp3
    '让爱住你家'=>array(
      'title'=>'16-让爱住你家',
      'begin'=>179,
      'end'=>179,
    ),
  );
}

function get_ly_jckc(){
  return $jckc = array(//基础课程
    '1'  =>  array(
      'title' =>  '事奉装备',
      'pdf' => 1,
      'max' => 24,
      'legth' =>3,
      'prefex'  => 'mavpr0',
      'order' =>'1',
    ),
    '2'  =>  array(
      'title' =>  '信仰与生活',
      'pdf' => 1,
      'max' => 24,
      'legth' =>3,
      'prefex'  => 'mavfl0',
      'order' =>'2',
    ),
    '3'  =>  array(
      'title' =>  '基本研经法',
      'pdf' => 1,
      'max' => 24,
      'legth' =>3,
      'prefex'  => 'mavbm0',
      'order' =>'3',
    ),
    '4'  =>  array(
      'title' =>  '基要真理',
      'pdf' => 1,
      'max' => 24,
      'legth' =>3,
      'prefex'  => 'mavfb0',
      'order' =>'4',
    ),
    '5'  =>  array(
      'title' =>  '婚姻与家庭',
      'pdf' => 1,
      'max' => 24,
      'legth' =>3,
      'prefex'  => 'mavmf1',
      'order' =>'5',
    ),
    '6'  =>  array(
      'title' =>  '新约浅说',
      'pdf' => 1,
      'max' => 24,
      'legth' =>3,
      'prefex'  => 'mavkn0',
      'order' =>'6',
    ),
    '7'  =>  array(
      'title' =>  '旧约浅说',
      'pdf' => 1,
      'max' => 24,
      'legth' =>3,
      'prefex'  => 'mavko0',
      'order' =>'7',
    ),
    '8'  =>  array(
      'title' =>  '耶稣生平',
      'pdf' => 1,
      'max' => 24,
      'legth' =>3,
      'prefex'  => 'mavls0',
      'order' =>'8',
    ),
  );
}