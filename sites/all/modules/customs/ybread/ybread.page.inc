<?php
function ybread_page(){
	date_default_timezone_set('Asia/Shanghai');
	$content_type = 'lingming';
	// get latest node.
	$query = "SELECT n.nid nid, n.created created FROM {node} n  WHERE n.type = :type order by n.created desc limit 0,1";
	$result = db_query($query, array(':type' => $content_type))->fetch();
	// dvm($result);
  //dvm(12*60*60);
	$now = 0;
	$last = 0;
  if(isset($result->nid)){
	  $now = time();
	  $hour = date('G',time());
	  $last = $result->created;
  }
  if(($now - $last >= 86400 && $hour >= 7)|| !isset($result->nid)) {
	  $html = file_get_html('http://simplified-odb.org/today/');
		// get title
		$node = new stdClass();
		$node->uid = '1'; //uid of love.
		$node->type = $content_type;
		node_object_prepare($node);
		//get title
	  $node->title = trim($html->find('h2.entry-title', 0)->plaintext);
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
	// dvm($result);
  //dvm(12*60*60);
	$now = 0;
	$last = 0;
  if(isset($result->nid)){
	  $now = time();
	  $hour = date('G',time());
	  $last = $result->created;
  }
  if(($now - $last >= 86400 && $hour >= 7)|| !isset($result->nid)) {
	  // $html = file_get_html('http://weixin.sogou.com/gzh?openid=oIWsFt3LUmIt28CCZixINHL0eNPY&ext=4egMG4BCzZ-ODkRsm_cCgnSwi3ZaUFuqD5CbohToE4Rg_S2Vv9HpCIIvSYPQiJXZ');
  	//from sogou get listlink
	  if(1){
		  $time = time();
		  // Create a stream
			$opts = array(
			  'http'=>array(
			    'method'=>"GET",
			    'header'=>"user_agent:Mozilla/5.0 (Macintosh; Intel Mac OS X 10_10_5) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/47.0.2526.106 Safari/537.36\r\n".
								    "X-Requested-With:XMLHttpRequest\r\n".
								    "Accept:text/javascript, application/javascript, application/ecmascript, application/x-ecmascript, */*; q=0.01\r\n".
								    "Accept-Encodin:gzip, deflate, sdch\r\n".
								    "Accept-Language::en-US,en;q=0.8,zh-CN;q=0.6,zh;q=0.4,fr;q=0.2,es;q=0.2,zh-TW;q=0.2,pt;q=0.2\r\n".
								    "Cache-Control:max-age=0\r\n".
								    "Connection:keep-alive\r\n".
								    'Cookie:SUID=51F0FE774418920A000000005590C8FC; SUV=00FD783AB6FF18045590C900AA2FB140; CXID=EFC1D6805B62E4966E645FB8F6EB72F6; usid=cD0HHCecOlKKhz5m; weixinIndexVisited=1; ABTEST=8|1450693883|v1; ad=dWGdjZllll2QqY$alllllVzxdBllllllavG3fklllltlllll4ylll5@@@@@@@@@@; SNUID=7A25E49AAEAA869C25C115AAAFCB0476; sct=25; IPLOC=US'."\r\n".
								    "Host:weixin.sogou.com\r\n".
								    "Referer:http://weixin.sogou.com/gzh?openid=oIWsFt3LUmIt28CCZixINHL0eNPY&ext=4egMG4BCzZ-ODkRsm_cCgnSwi3ZaUFuqD5CbohToE4Rg_S2Vv9HpCIIvSYPQiJXZ\r\n".
								    "X-Requested-With:XMLHttpRequest\r\n"
			  )
			);
			$context = stream_context_create($opts);
	 		$xmls = file_get_contents('http://weixin.sogou.com/gzhjs?openid=oIWsFt3LUmIt28CCZixINHL0eNPY&ext=4egMG4BCzZ-ODkRsm_cCgnSwi3ZaUFuqD5CbohToE4Rg_S2Vv9HpCIIvSYPQiJXZ&cb=sogou.weixin_gzhcb&page=1&gzhArtKeyWord=&tsn=0&t='.($time+64).'&_='.$time, false, $context);
	 		// dpm($xmls);
		  $search =  array('sogou.weixin_gzhcb(',')');
		  $replace =  array('', ''); 
		  $xmls = str_replace($search, $replace, $xmls);
		  $xmls = json_decode($xmls);
		  $link = FALSE;
		  foreach ($xmls->items as $key => $xml) {
		  	if(strpos($xml,'〔恩典365〕') !== false && strpos($xml,date('Y.n.j')) !== false ){
		  		$xml = str_replace('<?xml version="1.0" encoding="gbk"?>', '', $xml);
		  		// dpm($xml);
		  		$xml = simplexml_load_string($xml);
		  		foreach($xml->item->display->url as $val) {
				   $link = "http://weixin.sogou.com{$val}";
				  }
		  		// dpm($link);
		  	}
		  }
		}
		//get real item link
		if(1){
			// $link = 'http://weixin.sogou.com/websearch/art.jsp?sg=CBf80b2xkgYkvBuUSttzxZnRhlCTLLS_HWIEERNZwWhjxrvEUTyjUheXIaawsDexsy76rQaRMpkM625TlCV2yN_McVHWFp71CSUYruJ8CBUS2DzH1QBD6xVcwr37NDya5jEIo3GsVujznu4WdTDBMWH57fuM2F1D&url=p0OVDH8R4SHyUySb8E88hkJm8GF_McJfBfynRTbN8wicBvTmB9mzqxuAY9-9VgfOjN76mWe92Um62qxW2WBwUWQ3JxMQ3374-slRUIwesNMQcq693Hi-Ku7rjsW45iILLIVl7_3MJgFYy-5x5In7jJFmExjqCxhpkyjFvwP6PuGcQ64lGQ2ZDMuqxplQrsbk';
			$curl_handle=curl_init();
			curl_setopt($curl_handle, CURLOPT_HTTPHEADER, array(
			'user_agent:Mozilla/5.0 (Macintosh; Intel Mac OS X 10_10_5) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/47.0.2526.106 Safari/537.36',
			'Upgrade-Insecure-Requests:1',
			'Accept:text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8',
			'Accept-Encodin:gzip, deflate, sdch',
			'Accept-Language::en-US,en;q=0.8,zh-CN;q=0.6,zh;q=0.4,fr;q=0.2,es;q=0.2,zh-TW;q=0.2,pt;q=0.2',
			'Connection:keep-alive',
			'Cookie:SUID=51F0FE774418920A000000005590C8FC; SUV=00FD783AB6FF18045590C900AA2FB140; CXID=EFC1D6805B62E4966E645FB8F6EB72F6; usid=cD0HHCecOlKKhz5m; weixinIndexVisited=1; ABTEST=8|1450693883|v1; ad=dWGdjZllll2QqY$alllllVzxdBllllllavG3fklllltlllll4ylll5@@@@@@@@@@; SNUID=7A25E49AAEAA869C25C115AAAFCB0476; sct=25; IPLOC=US',
			'Host:weixin.sogou.com',
			));
			curl_setopt($curl_handle, CURLOPT_URL,$link);
			curl_setopt($curl_handle, CURLOPT_CONNECTTIMEOUT, 2);
			curl_setopt($curl_handle, CURLOPT_RETURNTRANSFER, 1);
			curl_setopt($curl_handle, CURLOPT_USERAGENT, 'Mozilla/5.0 (Macintosh; Intel Mac OS X 10_10_5) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/47.0.2526.106 Safari/537.36');
			$query = curl_exec($curl_handle);

			$response = curl_exec($curl_handle);

			$search =  array('The URL has moved <a href="','">here</a>');
			$replace =  array('', ''); 
			$real_link = str_replace($search, $replace, $response);
			// dpm($response);//The URL has moved <a href="http://mp.weixin.qq.com/s?__biz=MzA5NTI4MzM2Mg==&mid=416527632&idx=1&sn=386b1dbcbf9edf1ce15da54bd48e01fd&3rd=MzA3MDU4NTYzMw==&scene=6#rd">here</a>
			curl_close($curl_handle);
			// dpm($real_link);

			// $real_link = 'http://mp.weixin.qq.com/s?__biz=MzA5NTI4MzM2Mg==&mid=416527632&idx=1&sn=386b1dbcbf9edf1ce15da54bd48e01fd&3rd=MzA3MDU4NTYzMw==&scene=6#rd';
		  $html = file_get_html($real_link);
		  $voice_url = 'https://res.wx.qq.com/voice/getvoice?mediaid='.$html->find('[voice_encode_fileid]',0)->attr['voice_encode_fileid'];
			// dpm($voice_url);
		  // $video_url = $html->find('.video_iframe',0);
		  // dpm($video_url);
		}



	  $link = 'http://www.ed365.cn/a/list_9_1.html';
	  // $url="http://yiiblog.info/blog/index.php";
		// $html = iconv("gb2312", "utf-8",file_get_contents($link));
		$html = file_get_contents($link);
		$html = str_replace('gb2312', 'utf-8', $html);
		
		$html = iconv("gb2312", "utf-8//IGNORE",$html);
		
		$html = str_get_html($html);
		// dpm($html); return '';
		$real_ed365_link = FALSE;
		foreach($html->find('.xiaohua-data a') as $e) {
			$search = date('Ymd').'恩典365';
			if(strpos($e->title, $search)!==false){
				$title = $e->title;
				$real_ed365_link = $e->href;
				break;
			}
		}
		// dpm($real_ed365_link);
		//get video&body!
		if($real_ed365_link){
			$html = file_get_html('http://www.ed365.cn'.$real_ed365_link);
			$video_url = $html->find('.content iframe',0)->src;
			
		
			// $html = file_get_contents($link);
			$html = str_replace('gb2312', 'utf-8', $html->outertext);
			$html = iconv("gb2312", "utf-8//IGNORE",$html);
			$html = str_get_html($html);
			$body = $html->find('.content',0)->plaintext;
			$html = substr($body, 0,strpos($body, '以上视频由天声传播协会录制'));

		  $search =  array('&nbsp;','&ldquo;','&rdquo;','&hellip;','&mdash;','ζ','涫碘',);
		  $replace =  array('', '“','”','…','—','…','其实', ); 
		  $html = str_replace($search, $replace, $html);
			$title = str_replace('(附文字版)', '', $title);
			$ori_title = $title;
			$title = str_replace(date('Ymd'), '', $title);
			
			$body = $html;
			// dpm($video_url);
			// dpm($body);
			// dpm($title);
			
		}

		

		// get title
		$node = new stdClass();
		$node->uid = '1'; //uid of love.
		$node->type = $content_type;
		node_object_prepare($node);
		//get title
	  $node->title = $title;
	  $node->body[LANGUAGE_NONE][0]['value'] = $body;//trim($tempbody->plaintext);
	  $node->field_mp3url[LANGUAGE_NONE][0]['value']=$voice_url;
	  $node->field_video_url[LANGUAGE_NONE][0]['value']=$video_url;
	  $node->field_title[LANGUAGE_NONE][0]['value']=$ori_title;
	  $node->language = LANGUAGE_NONE;
	  $node->body[LANGUAGE_NONE][0]['format'] = 'full_html';
	  // dpm($node);
	  node_save($node);
  	$nid = $node->nid;
  }else{
  	$nid = $result->nid;
		$node = node_load($nid);
  }
  $player ='请记住我们的网址：http://wx.yongbuzhixi.com/grace365 每早7点后自动同步更新哦！';
	$node = node_load($nid);
  $node_view = node_view($node); //drupal_render($node_view).;
  return drupal_render($node_view).$player;
}
