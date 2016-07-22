<pre><?php
function get_location($url=NULL){
	if($url == NULL)
		$url = $_GET["url"];
	$heads = get_headers($url,TRUE);
  // var_dump($heads);
	$location = FALSE;
	if(isset( $heads['location'] )){
		$location = $heads['location'];
	}
  if(isset( $heads['Location'] )){
    $location = $heads['Location'];
  }
	return $location;
}
echo get_location();
