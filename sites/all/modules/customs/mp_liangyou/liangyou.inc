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
      'ir' => array('download_button' =>1,'url'=>'http://stream.liangyou.net/program/1njchu-3b2ozo', 'name' =>'i-radio爱广播', 'prefix'=>$prefix['31'],'day'=>0),//0
      // 'eg' => array('download_button' =>1,'url'=>'http://stream.liangyou.net/program/1njcjg-3b2p2w', 'name' =>'英语世界', 'prefix'=>$prefix['31'],'day'=>2),//2
      'gt' => array('download_button' =>1,'url'=>'http://stream.liangyou.net/program/1njcj0-3b2p20', 'name' =>'恩典与真理', 'prefix'=>$prefix['31'],'day'=>0),//0
      'wa' => array('download_button' =>1,'url'=>'http://stream.liangyou.net/program/1njcj3-3b2p26', 'name' =>'天路导向', 'prefix'=>$prefix['31'],'day'=>6),//6,7
      'cwa' => array('download_button' =>1,'url'=>'http://stream.liangyou.net/program/1njcj2-3b2p24', 'name' =>'天路导向（粤）', 'prefix'=>$prefix['31'],'day'=>6),//6,7
      // 'bg' => array('download_button' =>1,'url'=>'http://stream.liangyou.net/program/1njcjd-3b2p2q', 'name' =>'普世佳音', 'prefix'=>$prefix['31'],'day'=>1),//1
      'yu' => array('download_button' =>1,'url'=>'http://stream.liangyou.net/program/1njchx-3b2ozu', 'name' =>'绝妙当家', 'prefix'=>$prefix['31'],'day'=>0),//0
      'gv' => array('download_button' =>1,'url'=>'http://stream.liangyou.net/program/1njci3-3b2p06', 'name' =>'生活无国界', 'prefix'=>$prefix['31'],'day'=>0),//0
      'zz' => array('download_button' =>1,'url'=>'http://stream.liangyou.net/program/1njciw-3b2p1s', 'name' =>'零点零距离', 'prefix'=>$prefix['31'],'day'=>5),//1-5
      'se' => array('download_button' =>1,'url'=>'http://www.txly1.net/program/1njci0-3b2p00', 'name' =>'炼爱季节', 'prefix'=>$prefix['31'],'day'=>5),//1-5
      'up' => array('download_button' =>1,'url'=>'http://stream.liangyou.net/program/1njcil-3b2p16', 'name' =>'亲情不断电', 'prefix'=>$prefix['31'],'day'=>5),//1-5
      'bc' => array('download_button' =>1,'url'=>'http://stream.liangyou.net/program/1njci1-3b2p02', 'name' =>'书香园地', 'prefix'=>$prefix['31'],'day'=>5),//1-5
      'fc' => array('download_button' =>1,'url'=>'http://www.txly1.net/program/1njcm0-3b2p80', 'name' =>'微播出炉', 'prefix'=>$prefix['31'],'day'=>5),//1-5
      'gn' => array('download_button' =>1,'url'=>'http://stream.liangyou.net/program/1njcif-3b2p0u', 'name' =>'现代人的希望', 'prefix'=>$prefix['31'],'day'=>0),//0
      'hg' => array('download_button' =>1,'url'=>'http://stream.liangyou.net/program/1njci4-3b2p08', 'name' =>'欢乐卡恰碰', 'prefix'=>$prefix['31'],'day'=>0),//0
      'yn' => array('download_button' =>1,'url'=>'http://stream.liangyou.net/program/1njcj1-3b2p22', 'name' =>'爱在人间（云南）', 'prefix'=>$prefix['31'],'day'=>0),//0
      'im' => array('download_button' =>1,'url'=>'http://stream.liangyou.net/program/1njchy-3b2ozw', 'name' =>'i关怀心磁场', 'prefix'=>$prefix['31'],'day'=>5),//1-5
      'ib' => array('download_button' =>1,'url'=>'http://stream.liangyou.net/program/1njcjm-3b2p38', 'name' =>'无限飞行号', 'prefix'=>$prefix['31'],'day'=>0),//0
      'rt' => array('download_button' =>1,'url'=>'http://stream.liangyou.net/program/1njcia-3b2p0k', 'name' =>'今夜心未眠', 'prefix'=>$prefix['31'],'day'=>6),//6,7
      'ls' => array('download_button' =>1,'url'=>'http://stream.liangyou.net/program/1njci7-3b2p0e', 'name' =>'燃亮的一生', 'prefix'=>$prefix['31'],'day'=>6),//6,7
      // 'yr' => array('download_button' =>1,'url'=>'http://stream.liangyou.net/program/1njciv-3b2p1q', 'name' =>'Yi-radio爱广播', 'prefix'=>$prefix['31'],'day'=>0),//0
      'bv' => array('download_button' =>1,'url'=>'http://stream.liangyou.net/program/1njciv-3b2p1q', 'name' =>'灵命日粮', 'prefix'=>$prefix['32'],'day'=>0),//0
      'mw' => array('download_button' =>1,'url'=>'http://www.txly1.net/program/1njcly-3b2p7w', 'name' =>'旷野吗哪', 'prefix'=>$prefix['32'],'day'=>0),//0
      
    // '32' => array(//18100
      'ee' => array('download_button' =>1,'url'=>'http://stream.liangyou.net/program/1njchw-3b2ozs', 'name' =>'拥抱每一天', 'prefix'=>$prefix['32'],'day'=>0),//0
      'bf' => array('download_button' =>1,'url'=>'http://stream.liangyou.net/program/1njci6-3b2p0c', 'name' =>'幸福满家园', 'prefix'=>$prefix['32'],'day'=>6),//6 7
      'ws' => array('download_button' =>1,'url'=>'http://stream.liangyou.net/program/1njci9-3b2p0i', 'name' =>'长夜的牵引', 'prefix'=>$prefix['32'],'day'=>0),//0
      'be' => array('download_button' =>1,'url'=>'http://stream.liangyou.net/program/1njcik-3b2p14', 'name' =>'真道分解', 'prefix'=>$prefix['32'],'day'=>0),//0
      'tr' => array('download_button' =>1,'url'=>'http://stream.liangyou.net/program/1njchv-3b2ozq', 'name' =>'彩虹桥', 'prefix'=>$prefix['32'],'day'=>0),//0
      'ns' => array('download_button' =>1,'url'=>'http://stream.liangyou.net/program/1njciu-3b2p1o', 'name' =>'生命的四季', 'prefix'=>$prefix['32'],'day'=>5),
      'cw' => array('download_button' =>1,'url'=>'http://stream.liangyou.net/program/1njchz-3b2ozy', 'name' =>'齐来颂扬', 'prefix'=>$prefix['32'],'day'=>5),
      // 'wpb' => array('download_button' =>1,'url'=>'http://stream.liangyou.net/program/1njcim-3b2p18', 'name' =>'圣乐天地', 'prefix'=>$prefix['32'],'day'=>6),
    );
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
function ly_get_menu(){
  // $audios =  liangyou_audio_list();
  // foreach($audios as $key=>$audio){
  // $menu .= '<br/>【'.$key.'】'.$audio['name'];
  // }
  // dvm($menu);
  return '▶节目单
  ----------------------------------------------
  【mp】这一刻，清心
  【tg】施恩座前
  【ns】生命的四季
  【ds】晨曦讲座
  【cc】空中辅导
  【ir】爱广播
  【fc】微播出炉
  【gt】恩典与真理
  【wa】天路导向
  【yu】绝妙当家
  【gv】生活无国界
  【zz】零点零距离
  【se】炼爱季节
  【up】亲情不断电
  【bc】书香园地
  【gn】现代人的希望
  【hg】欢乐卡恰碰
  【yn】爱在人间（云南）
  【im】关怀心磁场
  【ib】无限飞行号
  【rt】今夜心未眠
  【ls】燃亮的一生
  【bv】旷野吗哪
  【ee】拥抱每一天
  【bf】幸福满家园
  【ws】长夜的牵引
  【be】真道分解
  【tr】彩虹桥
  【cw】齐来颂扬
  ----------------------------------------------
  永不止息，需要有你[抱拳][调皮]';
  // ---------Jesus Love You------------
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
function ly_stream_menu(){
  return '▶节目单
  ----------------------------------------------
  【601】无限飞行号
  【602】i关怀心磁场
  【603】空中辅导
  【604】恋爱季节
  【605】幸福满家园
  【606】亲情不断电
  【607】欢乐卡恰碰
  【608】绝妙当家
  【609】微播出炉
  【610】生活无国界
  【611】零点零距离
  【612】书香园地
  【613】i-Radio爱广播
  【614】今夜心未眠
  【615】彩虹桥
  【616】长夜的牵引
  【617】现代人的希望
  【618】生命的四季
  【619】拥抱每一天
  【620】旷野吗哪
  【621】真道分解
  【622】圣言盛宴
  【623】齐来颂扬
  【624】施恩座前
  【625】真理之光
  【626】接棒人
  【627】聆听主道
  【628】空中崇拜
  【629】善牧良言
  【630】好牧人
  【631】经动人心
  【632】佳美脚踪
  【633】蓝天绿洲
  【634】给力人生
  【635】空中门训
  【636】生根建造
  【637】信仰百宝箱
  【638】生活之光
  【639】生命的福音
  【640】这一刻，清心
  【641】良院（基础课程）
  【642】良院（本科一套）
  【643】良院（本科二套）
  【644】良院（进深一套）
  【645】良院（进深二套）
  【646】晨曦讲座
  【647】良院精选
  【648】天路导向
  【649】天路导向（粤语）
  【650】恩典与真理（回民）
  【651】爱在人间（云南话）
  【652】燃亮的一生';
}
/**
 * 良友圣经学院
 */
function get_ly_mav(){
  return array(
    'c1'=>array(
      'link'=>'c义工/001动员、恩赐与训练/mavmg030.mp3',
      'count'=>30,
      'title'=>'动员、恩赐与训练',
    ),
    'c2'=>array(
      'link'=>'c义工/002认识教会/maveg024.mp3',
      'count'=>24,
      'title'=>'认识教会',
    ),
    'd1'=>array(
      'link'=>'d基础课程/001耶稣生平/mavls024.mp3',
      'count'=>24,
      'title'=>'耶稣生平',
    ),
    'd2'=>array(
      'link'=>'d基础课程/002旧约浅说/mavko024.mp3',
      'count'=>24,
      'title'=>'旧约浅说',
    ),
    'd3'=>array(
      'link'=>'d基础课程/003新约浅说/mavkn024.mp3',
      'count'=>24,
      'title'=>'新约浅说',
    ),
    'd4'=>array(
      'link'=>'d基础课程/004婚姻与家庭/mavmf024.mp3',
      'count'=>24,
      'title'=>'婚姻与家庭',
    ),
    'd5'=>array(
      'link'=>'d基础课程/005基要真理/mavfb024.mp3',
      'count'=>24,
      'title'=>'基要真理',
    ),
    'd6'=>array(
      'link'=>'d基础课程/006基本研经法/mavbm024.mp3',
      'count'=>24,
      'title'=>'基本研经法',
    ),
    'd7'=>array(
      'link'=>'d基础课程/007团队事奉/mavsm018.mp3',
      'count'=>18,
      'title'=>'团队事奉',
    ),
    'd8'=>array(
      'link'=>'d基础课程/008初信造就/mavnb024.mp3',
      'count'=>24,
      'title'=>'初信造就',
    ),
    'd9'=>array(
      'link'=>'d基础课程/009信仰与生活/mavfl024.mp3',
      'count'=>24,
      'title'=>'信仰与生活',
    ),
    'e1'=>array(
      'link'=>'e本科课程/001青少年事工/mavym024.mp3',
      'count'=>24,
      'title'=>'青少年事工',
    ),
    'e2'=>array(
      'link'=>'e本科课程/002路加福音/mavlu030.mp3',
      'count'=>30,
      'title'=>'路加福音',
    ),
    'e3'=>array(
      'link'=>'e本科课程/003诗歌智慧书1/mavpb030.mp3',
      'count'=>30,
      'title'=>'诗歌智慧书1',
    ),
    'e4'=>array(
      'link'=>'e本科课程/004诗歌智慧书2/mavpk030.mp3',
      'count'=>30,
      'title'=>'诗歌智慧书2',
    ),
    'e5'=>array(
      'link'=>'f进深/001旧约神学/mavog024.mp3',
      'count'=>24,
      'title'=>'旧约神学',
    ),
    'e6'=>array(
      'link'=>'e本科课程/005讲道实习/mavjd024.mp3',
      'count'=>24,
      'title'=>'讲道实习',
    ),
    'e7'=>array(
      'link'=>'e本科课程/006讲道学/mavho024.mp3',
      'count'=>24,
      'title'=>'讲道学',
    ),
    'e8'=>array(
      'link'=>'e本科课程/007解经与研经/mavle024.mp3',
      'count'=>24,
      'title'=>'解经与研经',
    ),
    'e9'=>array(
      'link'=>'e本科课程/008苦难与罪恶/mavss012.mp3',
      'count'=>12,
      'title'=>'苦难与罪恶',
    ),
    'b1'=>array(
      'link'=>'e本科课程/009罗马书/mavrs030.mp3',
      'count'=>30,
      'title'=>'罗马书',
    ),
    'b2'=>array(
      'link'=>'e本科课程/010约翰福音/mavjo030.mp3',
      'count'=>30,
      'title'=>'约翰福音',
    ),
    'b3'=>array(
      'link'=>'e本科课程/011神迹奇事/mavsw024.mp3',
      'count'=>24,
      'title'=>'神迹奇事',
    ),
    'b4'=>array(
      'link'=>'e本科课程/012灵修默想与应用/mavdm024.mp3',
      'count'=>24,
      'title'=>'灵修默想与应用',
    ),
    'b5'=>array(
      'link'=>'e本科课程/013本土差传/mavom018.mp3',
      'count'=>18,
      'title'=>'本土差传',
    ),
    'b6'=>array(
      'link'=>'e本科课程/014普通书信/mavge024.mp3',
      'count'=>24,
      'title'=>'普通书信',
    ),
    'b7'=>array(
      'link'=>'e本科课程/015旧约综览/mavjy030.mp3',
      'count'=>30,
      'title'=>'旧约综览',
    ),
    'b8'=>array(
      'link'=>'e本科课程/016旧约历史书1/mavoh030.mp3',
      'count'=>30,
      'title'=>'旧约历史书1',
    ),
    'b9'=>array(
      'link'=>'e本科课程/017旧约历史书2/mavoi030.mp3',
      'count'=>30,
      'title'=>'旧约历史书2',
    ),
    'a1'=>array(
      'link'=>'e本科课程/018新约综览/mavxy030.mp3',
      'count'=>30,
      'title'=>'新约综览',
    ),
    'a2'=>array(
      'link'=>'e本科课程/019基督工人操守/mavcw024.mp3',
      'count'=>24,
      'title'=>'基督工人操守',
    ),
    'a3'=>array(
      'link'=>'e本科课程/020教导与牧养/mavtp018.mp3',
      'count'=>18,
      'title'=>'教导与牧养',
    ),
    'a4'=>array(
      'link'=>'e本科课程/021教会行政/mavca024.mp3',
      'count'=>24,
      'title'=>'教会行政',
    ),
    'a5'=>array(
      'link'=>'e本科课程/022教会增长/mavcg024.mp3',
      'count'=>24,
      'title'=>'教会增长',
    ),
    'a6'=>array(
      'link'=>'e本科课程/023教会历史/mavch030.mp3',
      'count'=>30,
      'title'=>'教会历史',
    ),
    'a7'=>array(
      'link'=>'e本科课程/024摩西五经/mavph030.mp3',
      'count'=>30,
      'title'=>'摩西五经',
    ),
    'a8'=>array(
      'link'=>'e本科课程/025探访事工/mavvm006.mp3',
      'count'=>6,
      'title'=>'探访事工',
    ),
    'a9'=>array(
      'link'=>'e本科课程/026异端与极端/mavhx030.mp3',
      'count'=>30,
      'title'=>'异端与极端',
    ),
    'f1'=>array(
      'link'=>'e本科课程/027差传导论/mavmi024.mp3',
      'count'=>24,
      'title'=>'差传导论',
    ),
    'f2'=>array(
      'link'=>'e本科课程/028婚姻辅导/mavmc030.mp3',
      'count'=>30,
      'title'=>'婚姻辅导',
    ),
    'f3'=>array(
      'link'=>'e本科课程/029基督教教义/mavcd030.mp3',
      'count'=>30,
      'title'=>'基督教教义',
    ),
    'f4'=>array(
      'link'=>'e本科课程/030基督教伦理学/mavce024.mp3',
      'count'=>24,
      'title'=>'基督教伦理学',
    ),
    'f5'=>array(
      'link'=>'e本科课程/031基督化家庭/mavcf024.mp3',
      'count'=>24,
      'title'=>'基督化家庭',
    ),
    'f6'=>array(
      'link'=>'e本科课程/032圣经背景/mavbj024.mp3',
      'count'=>24,
      'title'=>'圣经背景',
    ),
    'f7'=>array(
      'link'=>'e本科课程/033圣经教师训练/mavtb024.mp3',
      'count'=>24,
      'title'=>'圣经教师训练',
    ),
    'f8'=>array(
      'link'=>'e本科课程/034圣灵论/mavpn024.mp3',
      'count'=>24,
      'title'=>'圣灵论',
    ),
    'f9'=>array(
      'link'=>'e本科课程/035团契生活/mavfe024.mp3',
      'count'=>24,
      'title'=>'团契生活',
    ),
    'c3'=>array(
      'link'=>'e本科课程/036启示录（第八届）/mavrt030.mp3',
      'count'=>30,
      'title'=>'启示录',
    ),
    'c4'=>array(
      'link'=>'e本科课程/037先知书1（第八届）/mavop030.mp3',
      'count'=>30,
      'title'=>'先知书1',
    ),
    'c5'=>array(
      'link'=>'e本科课程/038先知书2（第八届）/mavor030.mp3',
      'count'=>30,
      'title'=>'先知书2',
    ),
    'c6'=>array(
      'link'=>'e本科课程/039保罗书信1/mavpa030.mp3',
      'count'=>30,
      'title'=>'保罗书信1',
    ),
    'c7'=>array(
      'link'=>'e本科课程/040保罗书信2/mavpu030.mp3',
      'count'=>30,
      'title'=>'保罗书信2',
    ),
    'c8'=>array(
      'link'=>'e本科课程/041使徒行传/mavas030.mp3',
      'count'=>30,
      'title'=>'使徒行传',
    ),
    'c9'=>array(
      'link'=>'e本科课程/042教牧学/mavpt024.mp3',
      'count'=>24,
      'title'=>'教牧学',
    ),
  );
  //f进深/002诗篇精选/mavse030.mp3
  //g林慈信牧师在新加坡教导加尔文《基督教要义》2008年/Calvin_B4_L109.mp3
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