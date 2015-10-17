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
  return array(//$radios = 
  array(
    'title' => '无限飞行号',
    'url' => 'http://www.txly1.net/program/1njcjm-3b2p38',
  ),
  array(
    'title' => 'i关怀心磁场',
    'url' => 'http://www.txly1.net/program/1njchy-3b2ozw',
  ),
  array(
    'title' => '空中辅导',
    'url' => 'http://www.txly1.net/program/1njci2-3b2p04',
  ),
  array(
    'title' => '恋爱季节',
    'url' => 'http://www.txly1.net/program/1njci0-3b2p00',
  ),
  array(
    'title' => '幸福满家园',
    'url' => 'http://www.txly1.net/program/1njci6-3b2p0c',
  ),
  array(
    'title' => '亲情不断电',
    'url' => 'http://www.txly1.net/program/1njcil-3b2p16',
  ),
  array(
    'title' => '欢乐卡恰碰',
    'url' => 'http://www.txly1.net/program/1njci4-3b2p08',
  ),
  array(
    'title' => '绝妙当家',
    'url' => 'http://www.txly1.net/program/1njchx-3b2ozu',
  ),
  array(
    'title' => '生活无国界',
    'url' => 'http://www.txly1.net/program/1njci3-3b2p06',
  ),
  array(
    'title' => '零点零距离',
    'url' => 'http://www.txly1.net/program/1njciw-3b2p1s',
  ),
  array(
    'title' => '书香园地',
    'url' => 'http://www.txly1.net/program/1njci1-3b2p02',
  ),
  array(
    'title' => 'i-Radio爱广播',
    'url' => 'http://www.txly1.net/program/1njchu-3b2ozo',
  ),
  // array(
  //   'title' => 'Yi-Radio爱广播',
  //   'url' => 'http://www.txly1.net/program/1njciv-3b2p1q',
  // ),
  array(
    'title' => '今夜心未眠',
    'url' => 'http://www.txly1.net/program/1njcia-3b2p0k',
  ),
  array(
    'title' => '听听90后',
    'url' => 'http://www.txly1.net/program/1njci7-3b2p0e',
  ),
  array(
    'title' => '彩虹桥',
    'url' => 'http://www.txly1.net/program/1njchv-3b2ozq',
  ),
  array(
    'title' => '现代人的希望',
    'url' => 'http://www.txly1.net/program/1njcif-3b2p0u',
  ),
  array(
    'title' => '生命的四季',
    'url' => 'http://www.txly1.net/program/1njciu-3b2p1o',
  ),
  array(
    'title' => '拥抱每一天',
    'url' => 'http://www.txly1.net/program/1njchw-3b2ozs',
  ),
  array(
    'title' => '灵命日粮',
    'url' => 'http://www.txly1.net/program/1njcht-3b2ozm',
  ),
  array(
    'title' => '真道分解',
    'url' => 'http://www.txly1.net/program/1njcik-3b2p14',
  ),
  array(
    'title' => '圣言盛宴',
    'url' => 'http://www.txly1.net/program/1njci8-3b2p0g',
  ),
  array(
    'title' => '齐来颂扬',
    'url' => 'http://www.txly1.net/program/1njchz-3b2ozy',
  ),
  array(
    'title' => '长夜的牵引',
    'url' => 'http://www.txly1.net/program/1njci9-3b2p0i',
  ),
  array(
    'title' => '真理之光',
    'url' => 'http://www.txly1.net/program/1njcjh-3b2p2y',
  ),
  array(
    'title' => '接棒人',
    'url' => 'http://www.txly1.net/program/1njcj9-3b2p2i',
  ),
  array(
    'title' => '聆听主道',
    'url' => 'http://www.txly1.net/program/1njciy-3b2p1w',
  ),
  array(
    'title' => '空中崇拜',
    'url' => 'http://www.txly1.net/program/1njcir-3b2p1i',
  ),
  array(
    'title' => '善牧良言',
    'url' => 'http://www.txly1.net/program/1njciz-3b2p1y',
  ),
  array(
    'title' => '好牧人',
    'url' => 'http://www.txly1.net/program/1njcix-3b2p1u',
  ),
  array(
    'title' => '经动人心',
    'url' => 'http://www.txly1.net/program/1njcis-3b2p1k',
  ),
  array(
    'title' => '佳美脚踪',
    'url' => 'http://www.txly1.net/program/1njcl2-3b2p64',
  ),
  array(
    'title' => '蓝天绿洲',
    'url' => 'http://www.txly1.net/program/1njcit-3b2p1m',
  ),
  array(
    'title' => '给力人生',
    'url' => 'http://www.txly1.net/program/1njcj7-3b2p2e',
  ),
  array(
    'title' => '空中门训',
    'url' => 'http://www.txly1.net/program/1njcja-3b2p2k',
  ),
  array(
    'title' => '生根建造',
    'url' => 'http://www.txly1.net/program/1njcj5-3b2p2a',
  ),
  array(
    'title' => '信仰百宝箱',
    'url' => 'http://www.txly1.net/program/1njcj8-3b2p2g',
  ),
  array(
    'title' => '生活之光',
    'url' => 'http://www.txly1.net/program/1njcjc-3b2p2o',
  ),
  array(
    'title' => '生命的福音',
    'url' => 'http://www.txly1.net/program/1njcjb-3b2p2m',
  ),
  // array(
  //   'title' => '无愧的工人',
  //   'url' => 'http://www.txly1.net/program/1njcj4-3b2p28',
  // ),
  array(
    'title' => '良友圣经学院（基础课程）',
    'url' => 'http://www.txly1.net/program/1njck8-3b2p4g',
  ),
  array(
    'title' => '良友圣经学院（本科文凭课程）（第一套）',
    'url' => 'http://www.txly1.net/program/1njck9-3b2p4i',
  ),
  array(
    'title' => '良友圣经学院（本科文凭课程）（第二套）',
    'url' => 'http://www.txly1.net/program/1njcka-3b2p4k',
  ),
  array(
    'title' => '良友圣经学院（进深文凭课程）（第一套）',
    'url' => 'http://www.txly1.net/program/1njckb-3b2p4m',
  ),
  array(
    'title' => '良友圣经学院（进深文凭课程）（第二套）',
    'url' => 'http://www.txly1.net/program/1njckc-3b2p4o',
  ),
  array(
    'title' => '晨曦讲座',
    'url' => 'http://www.txly1.net/program/1njcji-3b2p30',
  ),
  array(
    'title' => '天路导向',
    'url' => 'http://www.txly1.net/program/1njcj3-3b2p26',
  ),
  array(
    'title' => '天路导向（粤语）',
    'url' => 'http://www.txly1.net/program/1njcj2-3b2p24',
  ),
  array(
    'title' => '恩典与真理（回民）',
    'url' => 'http://www.txly1.net/program/1njcj0-3b2p20',
  ),
  array(
    'title' => '爱在人间（云南话）',
    'url' => 'http://www.txly1.net/program/1njcj1-3b2p22',
  ),
  );
}

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
【609】生活无国界
【610】零点零距离
【611】书香园地
【612】i-Radio爱广播
【613】今夜心未眠
【614】听听90后
【615】彩虹桥
【616】现代人的希望
【617】生命的四季
【618】拥抱每一天
【619】灵命日粮
【620】真道分解
【621】圣言盛宴
【622】齐来颂扬
【623】长夜的牵引
【624】真理之光
【625】接棒人
【626】聆听主道
【627】空中崇拜
【628】善牧良言
【629】好牧人
【630】经动人心
【631】佳美脚踪
【632】蓝天绿洲
【633】给力人生
【634】空中门训
【635】生根建造
【636】信仰百宝箱
【637】生活之光
【638】生命的福音
【639】良友圣经学院（基础课程）
【640】良友圣经学院（本科1）
【641】良友圣经学院（本科2）
【642】良友圣经学院（进深1）
【643】良友圣经学院（进深2）
【644】晨曦讲座
【645】天路导向
【646】天路导向（粤语）
【647】恩典与真理（回民）
【648】爱在人间（云南话）';
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