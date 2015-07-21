<?php
function get_location($url=NULL){
	if($url == NULL)
		$url = $_GET["url"];
	$heads = get_headers($url,TRUE);
	$location = FALSE;
	if(isset( $heads['location'] )){
		$location = $heads['location'];
	}
	return $location;	
}
echo get_location();