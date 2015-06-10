<?php
/**
 * resouce form 
 * http://portal.swtychina.com/web/guest/new
 * $keyword = ty ty1 ty2
 */
function wx_swty_resource_response($keyword) {
	watchdog('swty', $keyword, array(), WATCHDOG_NOTICE, 'link');
	$offset = 0;
	/////
		if(strlen($keyword)>2) {
          $offset = substr($keyword, 2,1);
          if(!is_numeric($offset)) $offset = 0;
        }

        $url = 'http://swtychina.com/gb/portal/audio.aspx?category=swty';
        $html = file_get_html($url);
        $i = 0;
		foreach($html->find('#GridView1 tr') as $tr) {

		    foreach($tr->find('td') as $td) {
		    	$i++;
		    	//uri
		    	if($i == ($offset)*5 + 3 ){
		    		// dpm($td->outertext);
		    		$url = $td->find('a',0)->href;
		    		$musicurl = 'http://swtychina.com/gb/'. str_replace('../', '', $url);
	    		  $live_radio = unserialize(drupal_http_request("http://mp.yongbuzhixi.com/get_headers.php?url=$musicurl")->data);
	    		    
    				$musicurl = $live_radio['Location'];
		    		// ../audio/20140724/2363/download.aspx
		    		//http://swtychina.com/gb/audio/20140731/2369/download.aspx
				}
				//date
				if($i == ($offset)*5 + 1 ){
		    		$week_day = $td->plaintext;

				}
				//title
				if($i == ($offset)*5 + 5 ){
		    		// dpm($td->plaintext);
		    		$title = $td->plaintext;
        			$title = $title;
				}
		   	}
	}       
      $desc = "公众号:永不止息 ".$week_day;
      $hgmusicurl = $musicurl;
      // $wechatObj->music($title, $desc, $musicurl, $hgmusicurl)->reply();
      // exit;
      $resources= array(
			'type'	=>	'music',
			'obj'		=> array(
				'title'	=> $title,
				'desc'	=>	$desc,
				'musicurl'	=>	$musicurl,
				'hgmusicurl'	=>	$musicurl,
			),
		);
      // watchdog('swty', '$resources<per>'.print_r($resources,true), array(), WATCHDOG_NOTICE, 'link');
    return $resources;
  /////
}