<?php
function ybread_page(){
	date_default_timezone_set('Asia/Shanghai');
	$content_type = 'lingming';
	// get latest node.
	$query = "SELECT n.nid nid, n.created created FROM {node} n  WHERE n.type = :type order by n.created desc limit 0,1";
	$result = db_query($query, array(':type' => $content_type))->fetch();
	// dvm($result->nid);
  //dvm(12*60*60);
	$now = 0;
	$last = 0;
  if(isset($result->nid)){
	  $now = date('z');
	  $hour = date('G',time());
	  $last = date('z',$result->created);
  }
  if(($now - $last >= 1 && $hour >= 6)|| !isset($result->nid)) {
	  $html = file_get_html('http://simplified-odb.org/today/');
	  watchdog('ybread-hour1', $hour, array(), WATCHDOG_NOTICE, 'link');
	  watchdog('ybread-now1', $now - $last, array(), WATCHDOG_NOTICE, 'link');
		// get title
		$node = new stdClass();
		$node->type = $content_type;
		node_object_prepare($node);
		$node->uid = '1'; //uid of love.
		//get title
	  $node->title = trim($html->find('h2.entry-title', 0)->plaintext);
	  if(isset($result->nid)){
	  	$temp_nid = $result->nid;
			$temp_node = node_load($temp_nid);
			if($temp_node->title != $node->title){	
			  // get body
			  $tempbody = $html->find('.entry-content', 0);
			  $body = $html->find('.verse-box', 0)->outertext;
			  $body .= $html->find('.entry-content .post-content', 0)->plaintext;
			  $body .= $html->find('.entry-content .poem-box', 0)->outertext;
			  $body .= $html->find('.entry-content .thought-box', 0)->outertext;
			  $node->body[LANGUAGE_NONE][0]['value'] = $body;//trim($tempbody->plaintext);
			  $node->language = LANGUAGE_NONE;
			 	// Try to set your custom field
			  // $html = file_get_html('http://ya-mi.org/');
			  $picture = $html->find('#content .entry-thumbnail img', 0);
			  $pic_url = $picture->attr['src'];
		    $response = drupal_http_request($pic_url);
		    if ($response->code == 200){
		      $file = file_save_data($response->data, 'public://lingming/'.date('Ymd').'.jpg');
		    }
				$node->field_image[LANGUAGE_NONE][0]['fid']=$file->fid;
				$node->field_image[LANGUAGE_NONE][0]['alt']=trim($html->find('.entry-content .thought-box', 0)->plaintext);
				// $node->body[LANGUAGE_NONE][0]['summary'] = trim($html->find('.entry-content .thought-box', 0)->plaintext);
			  $node->body[LANGUAGE_NONE][0]['value'] = $node->body[LANGUAGE_NONE][0]['value'];
			  $node->body[LANGUAGE_NONE][0]['format'] = 'full_html';
			  $node->field_mp3url[LANGUAGE_NONE][0]['value'] = 'http://cdn.rbcintl.org/odb/zht/zht-odb-'.date("Y").'-'.date("m").'-'.date("d").'.mp3';
			  // dpm($node);
			  node_save($node);
		  	$nid = $node->nid;
		  	watchdog('ybread', 'created lingming '.$nid, array(), WATCHDOG_NOTICE, 'link');
			}
	  }
  }else{
  	$nid = $result->nid;
		$node = node_load($nid);
  }
	$node = node_load($nid);
  $node_view = node_view($node); //drupal_render($node_view).;
  return drupal_render($node_view);
}

function grace365_page(){
	date_default_timezone_set('Asia/Shanghai');
	$content_type = 'grace365';
	// get latest node.
	$query = "SELECT n.nid nid, n.created created FROM {node} n  WHERE n.type = :type order by n.created desc limit 0,1";
	$result = db_query($query, array(':type' => $content_type))->fetch();
	$nid = 269;
	if(isset($result->nid)) $nid = $result->nid;
	// dvm($result);
  //dvm(12*60*60);
	$now = date('z');
	$last = 0;
	$hour = date('G',time());
  if(isset($result->nid)){
	  $last = date('z',$result->created);
  }
  if(isset($_POST['link']))
  if(($now - $last >= 1 && $_POST['link']) || !isset($result->nid)) {
	  watchdog('ybread-hour', $hour, array(), WATCHDOG_NOTICE, 'link');
	  watchdog('ybread-now', $now - $last, array(), WATCHDOG_NOTICE, 'link');
		// $link = 'http://mp.weixin.qq.com/s?__biz=MzA5NTI4MzM2Mg==&mid=416574017&idx=1&sn=cd31b45978a42bd5265e2aa91a752986&3rd=MzA3MDU4NTYzMw==&scene=6#rd';
		$link = $_POST['link'];
		// watchdog('POSTlink', $link, array(), WATCHDOG_NOTICE, 'link');
		$html = file_get_contents($link);
		$html = str_get_html($html);
		$ori_title = $html->find('title',0)->plaintext;
		$search =  array('&nbsp;','〔恩典365〕','(附文字版)','/','【恩典365】');
	  $replace =  array(' ','','','','',); 
	  $title = str_replace($search, $replace, $ori_title);
 		if(isset($result->nid)){
	  	$temp_nid = $result->nid;
			$temp_node = node_load($temp_nid);
			if($temp_node->title != $title){
				//https://v.qq.com/iframe/player.html?vid=r01794fedmo&width=790&height=592.5&auto=0
				$video_url = $html->find('.video_iframe',0)->getAttribute('data-src');
				preg_match('/vid=\S+?&/',$video_url,$video_url);
			  $video_url = 'https://v.qq.com/iframe/player.html?'.str_replace('&', '', $video_url[0]);
				// dpm($video_url);//https://v.qq.com/iframe/player.html?vid=r01794fedmo
				
				$voice_url = 'http://res.wx.qq.com/voice/getvoice?mediaid='.$html->find('mpvoice',0)->voice_encode_fileid;
				// watchdog('voice_url', '<pre>'.print_r($voice_url,1), array(), WATCHDOG_NOTICE, 'link');
				// watchdog('ori_title', '<pre>'.print_r($ori_title,1), array(), WATCHDOG_NOTICE, 'link');

				$body = $html->find('#js_content',0)->outertext;
				$body = strip_tags($body,'<span><p><section>');
				$body = preg_replace('/style="(.*?)"/', '', $body);
				$body = preg_replace('/class="(.*?)"/', '', $body);
				$body = preg_replace('/label="(.*?)"/', '', $body);
				
				$begin = strpos($body, '恩典365 365天') + strlen('恩典365 365天 ');
				if(!$begin){
					watchdog('ybread', 'no 365', array(), WATCHDOG_NOTICE, 'link');
					return 'error!';
				} 
				$end = strpos($body, '恩典365微信公众');
				$body = substr($body,$begin,$end-$begin);
				// get title
				$node = new stdClass();
				$node->type = $content_type;
				node_object_prepare($node);
				//get title
				$node->uid = '1'; //uid of love.
			  $node->title = $title;
			  $node->body[LANGUAGE_NONE][0]['value'] = $body;//trim($tempbody->plaintext);
			  $node->field_mp3url[LANGUAGE_NONE][0]['value']=$voice_url;
			  $node->field_video_url[LANGUAGE_NONE][0]['value']=$video_url;
			  // $node->field_title[LANGUAGE_NONE][0]['value']=$ori_title;
			  $node->language = LANGUAGE_NONE;
			  $node->body[LANGUAGE_NONE][0]['format'] = 'full_html';
			  // dpm($node);
			  node_save($node);
		  	$nid = $node->nid;
		  	watchdog('ybread', 'created 365 '.$nid, array(), WATCHDOG_NOTICE, 'link');
			}
		}
  }
	$node = node_load($nid);
  $node_view = node_view($node); //drupal_render($node_view).;
  return drupal_render($node_view);
}
