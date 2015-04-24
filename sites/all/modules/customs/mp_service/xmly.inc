<?php
/**
 * 喜马拉雅 专辑节目！
 */
function xmly_radio_menu(){
	return array(
		'xl' => array(
			'title'	=>'喜乐的心',
			'url'	=> 'http://www.ximalaya.com/4816433/album/247856',
		),
		'sl' => array(
			'title'	=>'黑门山路',
			'url'	=> 'http://www.ximalaya.com/4816433/album/253230',
		),
		'xwz' => array(
			'title'	=>'小王子',
			'url'	=> 'http://www.ximalaya.com/1288726/album/240506',
		),
	);
}

function xmly_get_radio($keyword){
	//xl109
	preg_match('/^[a-z]+/', $keyword, $matches);
	if (!isset($matches[0])) {
		return FALSE;
	}
	$check_keyword = $matches[0];//xl
	$resources = xmly_radio_menu();
	$keywords = array_keys($resources);
  if(!in_array($check_keyword, $keywords)){
    return FALSE;
  }
  $url = $resources[$check_keyword]['url'];
	$check_keyword_length = strlen($check_keyword);//2
  $offday = (int) substr($keyword, $check_keyword_length);//109

  //set if page>1
  if ($offday>100) {
  	$page = $offday%100 +1;
  	$url = $url.'?page='.$page;
  }
  //begin form 20150326
  if(!is_numeric($offday)){
    // $offday = 0;
    $offday = date('z')-84;
  }
  $html = file_get_html($url);
  // foreach($html->find('.album_soundlist  li') as $e){
  //   $audio[] =  $e->sound_id;
  //   // break;
  // }
  $sound_ids = $html->find('.personal_body',0)->attr['sound_ids'];
  $audio = explode(',', $sound_ids);
  $result = FALSE;
  $counts = count($audio);
  if ($counts!=0) { 
	  $url = "http://www.ximalaya.com/tracks/".$audio[$offday].".json";
	  $html = file_get_html($url)->outertext;
	  $audio =  drupal_json_decode($html);
	  $musicurl = "http://fdfs.xmcdn.com/".$audio['play_path_32'];
	  $hgmusicurl = "http://fdfs.xmcdn.com/".$audio['play_path_64'];
	  $title = $resources[$check_keyword]['title'].'('.$offday.')';
	  if($offday==0)
	  	$title =  $resources[$check_keyword]['title'];
	  $result = array(
	  	'keyword'			=>	$check_keyword,
	  	'title'				=>	$title,
	  	'musicurl'		=>	$hgmusicurl,
	  	'hgmusicurl'	=>	$hgmusicurl,
	  );
  }
  return $result; 
}