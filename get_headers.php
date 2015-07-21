<?php
$url = $_GET["url"];
echo serialize(get_headers($url,TRUE));
