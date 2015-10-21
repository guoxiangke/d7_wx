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
	  $now = date('d',time());
	  $hour = date('G',time());
	  $last = date('d',$result->created);
  }
  if(($now - $last >= 1 && $hour >= 7)|| !isset($result->nid)) {
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

	  $node->body[LANGUAGE_NONE][0]['value'] = $node->body[LANGUAGE_NONE][0]['value'];
	  $node->body[LANGUAGE_NONE][0]['format'] = 'full_html';
	  // dpm($node);
	  node_save($node);
  }else{
  	$nid = $result->nid;
		$node = node_load($nid);
  }
  $player ='<div class="ybread-player"><audio controls>
  <source src="http://cdn.rbcintl.org/odb/zht/zht-odb-2015-10-21.mp3" type="audio/mpeg">
Your browser does not support the audio element.
</audio>
				<p style="color:#666">信息来源： http://simplified-odb.org </p></div>';

  $node_view = node_view($node); //drupal_render($node_view).;
  return drupal_render($node_view).$player;
}
