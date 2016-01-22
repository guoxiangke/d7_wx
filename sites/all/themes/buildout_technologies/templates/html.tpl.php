<!DOCTYPE html>
<!--[if lt IE 7]> <html class="ie6 ie" lang="<?php print $language->language; ?>" dir="<?php print $language->dir; ?>"> <![endif]-->
<!--[if IE 7]>    <html class="ie7 ie" lang="<?php print $language->language; ?>" dir="<?php print $language->dir; ?>"> <![endif]-->
<!--[if IE 8]>    <html class="ie8 ie" lang="<?php print $language->language; ?>" dir="<?php print $language->dir; ?>"> <![endif]-->
<!--[if IE 9]>    <html class="ie9 ie" lang="<?php print $language->language; ?>" dir="<?php print $language->dir; ?>"> <![endif]-->
<!--[if !IE]> --> <html lang="<?php print $language->language; ?>" dir="<?php print $language->dir; ?>"> <!-- <![endif]-->
<head>
  <?php print $head; ?>
  <!-- Set the viewport width to device width for mobile -->
  <meta name="viewport" content="width=device-width, initial-scale=1.0, user-scalable=no">
  <title><?php print $head_title; ?></title>
  <?php print $styles; ?>
  <?php print $scripts; ?>
  <!--[if IE 7]>
  <link rel="stylesheet" href="<?php print base_path() . drupal_get_path('theme', 'open_framework') . '/fontawesome/css/font-awesome-ie7.min.css'; ?>">
  <![endif]-->
  <!-- IE Fix for HTML5 Tags -->
  <!--[if lt IE 9]>
    <script src="<?php print base_path() . drupal_get_path('theme', 'open_framework') . '/js/html5shiv.js'; ?>"></script>
  <![endif]-->
</head>

<body class="<?php print $classes; ?> <?php print $body_bg_type; ?> <?php print $body_bg_classes; ?> <?php print $content_order_classes; ?> <?php print $front_heading_classes; ?> <?php print $breadcrumb_classes; ?> <?php print $border_classes; ?> <?php print $corner_classes; ?>" <?php print $attributes;?> <?php if ($body_bg_classes): ?>style="background: url('<?php print file_create_url(theme_get_setting('body_bg_path')); ?>') repeat top left;" <?php endif; ?>>
  <?php print $page_top; ?>
  <?php print $page; ?>
  <?php print $page_bottom; ?>
  <div class="container">
    <div class="row">
      <div class="hideonmobile d-copyright"><p>京ICP备15024539号&nbsp;<img src="https://ss0.bdstatic.com/5aV1bjqh_Q23odCf/static/superman/img/copy_rignt_24.png" style="height:16px; width:13px" /> <a href="http://wx.yongbuzhixi.com/node/373">免责声明</a></p></div>
    </div>
  </div></body>

</html>
