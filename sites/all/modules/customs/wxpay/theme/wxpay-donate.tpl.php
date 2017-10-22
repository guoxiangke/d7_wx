<?php

/**
 * @file
 * Default theme implementation to display a single Drupal page.
 *
 * The doctype, html, head and body tags are not in this template. Instead they
 * can be found in the html.tpl.php template in this directory.
 *
 * Available variables:
 *
 * General utility variables:
 * - $base_path: The base URL path of the Drupal installation. At the very
 *   least, this will always default to /.
 * - $directory: The directory the template is located in, e.g. modules/system
 *   or themes/bartik.
 * - $is_front: TRUE if the current page is the front page.
 * - $logged_in: TRUE if the user is registered and signed in.
 * - $is_admin: TRUE if the user has permission to access administration pages.
 *
 * Site identity:
 * - $front_page: The URL of the front page. Use this instead of $base_path,
 *   when linking to the front page. This includes the language domain or
 *   prefix.
 * - $logo: The path to the logo image, as defined in theme configuration.
 * - $site_name: The name of the site, empty when display has been disabled
 *   in theme settings.
 * - $site_slogan: The slogan of the site, empty when display has been disabled
 *   in theme settings.
 *
 * Navigation:
 * - $main_menu (array): An array containing the Main menu links for the
 *   site, if they have been configured.
 * - $secondary_menu (array): An array containing the Secondary menu links for
 *   the site, if they have been configured.
 * - $breadcrumb: The breadcrumb trail for the current page.
 *
 * Page content (in order of occurrence in the default page.tpl.php):
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title: The page title, for use in the actual HTML content.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 * - $messages: HTML for status and error messages. Should be displayed
 *   prominently.
 * - $tabs (array): Tabs linking to any sub-pages beneath the current page
 *   (e.g., the view and edit tabs when displaying a node).
 * - $action_links (array): Actions local to the page, such as 'Add menu' on the
 *   menu administration interface.
 * - $feed_icons: A string of all feed icons for the current page.
 * - $node: The node object, if there is an automatically-loaded node
 *   associated with the page, and the node ID is the second argument
 *   in the page's path (e.g. node/12345 and node/12345/revisions, but not
 *   comment/reply/12345).
 *
 * Regions:
 * - $page['help']: Dynamic help text, mostly for admin pages.
 * - $page['highlighted']: Items for the highlighted content region.
 * - $page['content']: The main content of the current page.
 * - $page['sidebar_first']: Items for the first sidebar.
 * - $page['sidebar_second']: Items for the second sidebar.
 * - $page['header']: Items for the header region.
 * - $page['footer']: Items for the footer region.
 *
 * @see template_preprocess()
 * @see template_preprocess_page()
 * @see template_process()
 * @see html.tpl.php
 *
 * @ingroup themeable
 */
?>
<script>
(function($){
  jQuery(document).ready(function ($) {//调用微信JS api 支付
    $('#input').bind('keyup mouseup', function () {
        link = '/wxpay/node/1289?fee='+$(this).val()+'00';     
        $('form').attr('action',link)
    });

    $('#submit').click(function(e){
      if($('#input').val()){
        // link = '/wxpay/node/1289?fee='+$('#input').val()+'00';
        // console.log(link);
        // $(location).attr('href', link)
        // location.href(link);
      }else{
        e.preventDefault();
        alert('请选择一个支持金额或输入金额!');
      }
    });

  });
})(jQuery);
</script>
<div class="wx-donate">
<style>
.wx-donate{
  text-align: center;
}
.wx-donate img {
  max-width: 300px;
}
  #payit{
    margin-top: 60%;
    margin-left: 10px;
    margin-right: 10px;
  }
  .weui_btn_primary {
    background-color: #04BE02;
  }
  .weui_btn {
    position: relative;
    display: block;
    margin-left: auto;
    margin-right: auto;
    padding-left: 14px;
    padding-right: 14px;
    box-sizing: border-box;
    font-size: 18px;
    text-align: center;
    text-decoration: none;
    color: #FFFFFF;
    line-height: 2.33333333;
    border-radius: 5px;
    -webkit-tap-highlight-color: rgba(0, 0, 0, 0);
    overflow: hidden;
    max-width: 80%;
}
#input{
  width: 70%;
  border-color:  #04BE02;
  height: 50px;
  font-size: 35px;
  text-align: center;
  font-family: 'Times New Roman';
}
</style>
<br><br>
  <p>永不止息，需要有你</p><p>小永携全体主内佳人感谢您对单身事工的支持！</p>
  <a href="/wxpay/node/1289?fee=5000" data-amount="50" class="wxpay_link"><span class="weui_btn weui_btn_primary">微信支付50元</span></a>
  <br><br>
  <a href="/wxpay/node/1289?fee=10000" data-amount="100" class="wxpay_link"><span class="weui_btn weui_btn_primary">微信支付100元</span></a>
  <br><br>
  <a href="/wxpay/node/1289?fee=50000" data-amount="500" class="wxpay_link"><span class="weui_btn weui_btn_primary">微信支付500元</span></a>
  <br><br>  <br><br>
  <form action="#" id="wxpay">
  <label for="input">其他金额：</label><br>
  <input type="number" min="10.00" id="input" name="fee" placeholder="20.00" step="0.01">
  <br><br>
  <input class="weui_btn weui_btn_primary wxpay" type="submit" id="submit"  value="确定支付">
  </form>
  <br><br>
  <p>⬇️有问题？按住它⬇️</p>
  <img src="https://www.yongbuzhixi.com/sites/default/files/seeking/qr/wechatimg9_0.jpeg" alt="" width="100%">
</div>
