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
  <link rel="apple-touch-icon" sizes="57x57" href="/ico/apple-icon-57x57.png">
  <link rel="apple-touch-icon" sizes="60x60" href="/ico/apple-icon-60x60.png">
  <link rel="apple-touch-icon" sizes="72x72" href="/ico/apple-icon-72x72.png">
  <link rel="apple-touch-icon" sizes="76x76" href="/ico/apple-icon-76x76.png">
  <link rel="apple-touch-icon" sizes="114x114" href="/ico/apple-icon-114x114.png">
  <link rel="apple-touch-icon" sizes="120x120" href="/ico/apple-icon-120x120.png">
  <link rel="apple-touch-icon" sizes="144x144" href="/ico/apple-icon-144x144.png">
  <link rel="apple-touch-icon" sizes="152x152" href="/ico/apple-icon-152x152.png">
  <link rel="apple-touch-icon" sizes="180x180" href="/ico/apple-icon-180x180.png">
  <link rel="icon" type="image/png" sizes="192x192"  href="/ico/android-icon-192x192.png">
  <link rel="icon" type="image/png" sizes="32x32" href="/ico/favicon-32x32.png">
  <link rel="icon" type="image/png" sizes="96x96" href="/ico/favicon-96x96.png">
  <link rel="icon" type="image/png" sizes="16x16" href="/ico/favicon-16x16.png">
  <link rel="manifest" href="/ico/manifest.json">
  <meta name="msapplication-TileColor" content="#ffffff">
  <meta name="msapplication-TileImage" content="/ico/ms-icon-144x144.png">
  <meta name="theme-color" content="#ffffff">
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

<body class="<?php print $classes; ?>" <?php print $attributes;?>>
  <?php print $page_top; ?>
  <?php print $page; ?>
  <?php print $page_bottom; ?>
  <div class="container visible-lg-block">
    <div class="row">
      <div class="d-copyright"><div>京ICP备15024539号&nbsp;<img src="/<?php echo drupal_get_path('theme', 'jstheme');?>/images/copy_rignt_24.png" style="height:16px; width:13px" /> <a href="http://wx.yongbuzhixi.com/node/373">免责声明</a></div></div>
    </div>
  </div>
  <!-- Google Analytics -->
  <script>
  window.ga=window.ga||function(){(ga.q=ga.q||[]).push(arguments)};ga.l=+new Date;
  ga('create', 'UA-36975988-2', 'auto');
  ga('send', 'pageview');
  </script>
  <!-- End Google Analytics -->
</body>
</html>
