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
      'bg' => array('download_button' =>1,'url'=>'http://stream.liangyou.net/program/1njcjd-3b2p2q', 'name' =>'普世佳音', 'prefix'=>$prefix['31'],'day'=>1),//1
      'yu' => array('download_button' =>1,'url'=>'http://stream.liangyou.net/program/1njchx-3b2ozu', 'name' =>'绝妙当家', 'prefix'=>$prefix['31'],'day'=>0),//0
      'gv' => array('download_button' =>1,'url'=>'http://stream.liangyou.net/program/1njci3-3b2p06', 'name' =>'生活无国界', 'prefix'=>$prefix['31'],'day'=>0),//0
      'zz' => array('download_button' =>1,'url'=>'http://stream.liangyou.net/program/1njciw-3b2p1s', 'name' =>'零点零距离', 'prefix'=>$prefix['31'],'day'=>5),//1-5
      'se' => array('download_button' =>1,'url'=>'http://www.txly1.net/program/1njci0-3b2p00', 'name' =>'炼爱季节', 'prefix'=>$prefix['31'],'day'=>5),//1-5
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
      'bv' => array('download_button' =>1,'url'=>'http://stream.liangyou.net/program/1njciv-3b2p1q', 'name' =>'灵命日粮', 'prefix'=>$prefix['32'],'day'=>0),//0
      
    // '32' => array(//18100
      'ee' => array('download_button' =>1,'url'=>'http://stream.liangyou.net/program/1njchw-3b2ozs', 'name' =>'拥抱每一天', 'prefix'=>$prefix['32'],'day'=>0),//0
      'bf' => array('download_button' =>1,'url'=>'http://stream.liangyou.net/program/1njci6-3b2p0c', 'name' =>'幸福满家园', 'prefix'=>$prefix['32'],'day'=>6),//6 7
      'ws' => array('download_button' =>1,'url'=>'http://stream.liangyou.net/program/1njci9-3b2p0i', 'name' =>'长夜的牵引', 'prefix'=>$prefix['32'],'day'=>0),//0
      'be' => array('download_button' =>1,'url'=>'http://stream.liangyou.net/program/1njcik-3b2p14', 'name' =>'真道分解', 'prefix'=>$prefix['32'],'day'=>0),//0
      'tr' => array('download_button' =>1,'url'=>'http://stream.liangyou.net/program/1njchv-3b2ozq', 'name' =>'彩虹桥', 'prefix'=>$prefix['32'],'day'=>0),//0
      'ns' => array('download_button' =>1,'url'=>'http://stream.liangyou.net/program/1njciu-3b2p1o', 'name' =>'生命的四季', 'prefix'=>$prefix['32'],'day'=>5),
      'cw' => array('download_button' =>1,'url'=>'http://stream.liangyou.net/program/1njchz-3b2ozy', 'name' =>'齐来颂扬', 'prefix'=>$prefix['32'],'day'=>5),
      'wpb' => array('download_button' =>1,'url'=>'http://stream.liangyou.net/program/1njcim-3b2p18', 'name' =>'圣乐天地', 'prefix'=>$prefix['32'],'day'=>6),
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
  【ir】i-radio爱广播
  【eg】英语世界
  【gt】恩典与真理
  【wa】天路导向
  【bg】普世佳音
  【yu】绝妙当家
  【gv】生活无国界
  【zz】零点零距离
  【se】炼爱季节
  【up】亲情不断电
  【bc】书香园地
  【gn】现代人的希望
  【hg】欢乐卡恰碰
  【yn】爱在人间（云南）
  【im】i关怀心磁场
  【ib】无限飞行号
  【rt】今夜心未眠
  【em】听听90后
  【yr】Yi-radio爱广播
  【bv】灵命日粮
  【ee】拥抱每一天
  【bf】幸福满家园
  【ws】长夜的牵引
  【be】真道分解
  【tr】彩虹桥
  【cw】齐来颂扬
  ----------------------------------------------
  永不止息，需要有你[抱拳][调皮]';
  // ---------Jesus Love You------------
  // 【wpb】圣乐天地
  // 【cwa】天路导向（粤）
}


function ly_stream_source(){
  return array( 
    'http://www.txly1.net/program/1njchx-3b2ozu',
    'http://www.txly1.net/program/1njci3-3b2p06',
    'http://www.txly1.net/program/1njciw-3b2p1s',
    'http://www.txly1.net/program/1njci1-3b2p02',
    'http://www.txly1.net/program/1njcia-3b2p0k',
    'http://www.txly1.net/program/1njci7-3b2p0e',
    'http://www.txly1.net/program/1njchu-3b2ozo',
    'http://www.txly1.net/program/1njchy-3b2ozw',
    'http://www.txly1.net/program/1njci2-3b2p04',
    'http://www.txly1.net/program/1njcjm-3b2p38',
    'http://www.txly1.net/program/1njci0-3b2p00',
    'http://www.txly1.net/program/1njci6-3b2p0c',
    'http://www.txly1.net/program/1njcil-3b2p16',
    'http://www.txly1.net/program/1njci4-3b2p08',
    'http://www.txly1.net/program/1njcif-3b2p0u',
    'http://www.txly1.net/program/1njcjb-3b2p2m',
    'http://www.txly1.net/program/1njclc-3b2p6o',
    'http://www.txly1.net/program/1njcld-3b2p6q',
    'http://www.txly1.net/program/1njcl2-3b2p64',
    'http://www.txly1.net/program/1njciu-3b2p1o',
    'http://www.txly1.net/program/1njchw-3b2ozs',
    'http://www.txly1.net/program/1njcht-3b2ozm',
    'http://www.txly1.net/program/1njcir-3b2p1i',
    'http://www.txly1.net/program/1njcjh-3b2p2y',
    'http://www.txly1.net/program/1njcj5-3b2p2a',
    'http://www.txly1.net/program/1njcj8-3b2p2g',
    'http://www.txly1.net/program/1njcj7-3b2p2e',
    'http://www.txly1.net/program/1njcja-3b2p2k',
    'http://www.txly1.net/program/1njcis-3b2p1k',
    'http://www.txly1.net/program/1njcik-3b2p14',
    'http://www.txly1.net/program/1njciy-3b2p1w',
    'http://www.txly1.net/program/1njci8-3b2p0g',
    'http://www.txly1.net/program/1njciz-3b2p1y',
    'http://www.txly1.net/program/1njcix-3b2p1u',
    'http://www.txly1.net/program/1njcjc-3b2p2o',
    'http://www.txly1.net/program/1njcj9-3b2p2i',
    'http://www.txly1.net/program/1njcj4-3b2p28',
    'http://www.txly1.net/program/1njcji-3b2p30',
    'http://www.txly1.net/program/1njclb-3b2p6m',
    'http://www.txly1.net/program/1njck8-3b2p4g',
    'http://www.txly1.net/program/1njck9-3b2p4i',
    'http://www.txly1.net/program/1njcka-3b2p4k',
    'http://www.txly1.net/program/1njckb-3b2p4m',
    'http://www.txly1.net/program/1njckc-3b2p4o',
    'http://www.txly1.net/program/1njchz-3b2ozy',
    'http://www.txly1.net/program/1njchv-3b2ozq',
    'http://www.txly1.net/program/1njci9-3b2p0i',
    'http://www.txly1.net/program/1njcit-3b2p1m',
    'http://www.txly1.net/program/1njcj3-3b2p26',
    'http://www.txly1.net/program/1njcj2-3b2p24',
    'http://www.txly1.net/program/1njcj0-3b2p20',
    'http://www.txly1.net/program/1njcj1-3b2p22',
  );
}

function ly_stream_menu(){
  return '▶节目单
  ----------------------------------------------
601 绝妙当家
602 生活无国界
603 零点零距离
604 书香园地
605 今夜心未眠
606 听听90后
607 i-Radio爱广播
608 i关怀心磁场
609 空中辅导
610 无限飞行号
611 恋爱季节
612 幸福满家园
613 亲情不断电
614 欢乐卡恰碰
615 现代人的希望
616 生命的福音
617 施恩座前
618 这一刻，清心
619 佳美脚踪
620 生命的四季
621 拥抱每一天
622 灵命日粮
623 空中崇拜
624 真理之光
625 生根建造
626 信仰百宝箱
627 给力人生
628 空中门训
629 经动人心
630 真道分解
631 聆听主道
632 圣言盛宴
633 善牧良言
634 好牧人
635 生活之光
636 接棒人
637 无愧的工人
638 晨曦讲座
639 良院精选
640 良友圣经学院（基础课程）
641 良友圣经学院（本科文凭课程）（第一套）
642 良友圣经学院（本科文凭课程）（第二套）
643 良友圣经学院（进深文凭课程）（第一套）
644 良友圣经学院（进深文凭课程）（第二套）
645 齐来颂扬
646 彩虹桥
647 长夜的牵引
648 蓝天绿洲
649 天路导向
650 天路导向（粤语）
651 恩典与真理（回民广播）
652 爱在人间（云南话）';
}