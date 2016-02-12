<?php
header ("Content-type: image/png");
$x = 600;
$y = 1285;
// $x = 240;
// $y = 70;
$rh = 100;

$A = dirname(__FILE__).'/sites/all/modules/customs/mp_service/images/fwh_small.jpg';
// $A = 'dyh_s.jpg';
$B = 'https://mp.weixin.qq.com/cgi-bin/showqrcode?ticket=gQGx8DoAAAAAAAAAASxodHRwOi8vd2VpeGluLnFxLmNvbS9xL0dFZ1l6MURtdTdmQzBGT05BbWFLAAIEMUmTVgMECAcAAA%3D%3D';
if(isset($_GET['qr'])) $B = $_GET['qr'];
$im1 = imagecreatefromstring(file_get_contents($A));
$im2 = imagecreatefromstring(file_get_contents($B));
 
imagecopymerge($im1, $im2, $x, $y, 0, 0, imagesx($im2), imagesy($im2), $rh);
// imageGif($im1);return;
// imageGif($im1,'sites/default/files/test.gif');
// $x = 60;
// $y = 1400;
$x = 60;
$y = 1350;
$rh = 100;

// $A = $im1;
$B = 'http://wx.qlogo.cn/mmopen/0wRpPfN90ibCJbDUmgAgric9czu1oEIaPrstRgibFDAkcpCH0S5k7TZqzh55F9z0PnntoAz5Tb1oKKoEibm8BI5ibMATviaHLNzRat/0';
if(isset($_GET['avatar'])) $B = $_GET['avatar'];
// $im1 = imagecreatefromstring(file_get_contents($A));
$image = imagecreatefromstring(file_get_contents($B));
$percent = 0.4;

// 获取新的尺寸
// list() = getimagesize($filename);
$width = imagesx($image);
$height = imagesy($image);
$new_width =  $width* $percent;
$new_height = $height* $percent;

// 重新取样
$image_p = imagecreatetruecolor($new_width, $new_height);
// $image = imagecreatefromjpeg($filename);
imagecopyresampled($image_p, $image, 0, 0, 0, 0, $new_width, $new_height, $width, $height);

$im2 = $image_p;//imagecreatefromstring(file_get_contents($B));
 
imagecopymerge($im1, $im2, $x, $y, 0, 0, imagesx($im2), imagesy($im2), $rh);
if(isset($_GET['id'])) {
	imagepng($im1,'sites/default/files/QR_'.$_GET['id'].'.png');
	return;
	// header('location:sites/default/files/test.png');
}
imagepng($im1);return;

// imageGif($im1,'sites/default/files/test.png');
