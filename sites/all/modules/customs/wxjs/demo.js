(function($) {
  jQuery(document).ready(function ($) {
    wx.ready(function () {
      var shareData =  Drupal.settings.wxjs.shareData;
      wx.onMenuShareAppMessage(shareData);
      wx.onMenuShareTimeline(shareData);

    });
  });
}( jQuery ));
