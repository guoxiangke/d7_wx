(function($) {
  jQuery(document).ready(function ($) {//调用微信JS api 支付
    //@see WxpayAPI_php_v3/example/jsapi.php
    function jsApiCall()
    {
      WeixinJSBridge.invoke(
        'getBrandWCPayRequest',
        {
           "appId": Drupal.settings.wxpay.jsApiParameters.appId,     //公众号名称，由商户传入
           "timeStamp": Drupal.settings.wxpay.jsApiParameters.timeStamp,         //时间戳，自1970年以来的秒数
           "nonceStr": Drupal.settings.wxpay.jsApiParameters.nonceStr, //随机串
           "package": Drupal.settings.wxpay.jsApiParameters.package,
           "signType": Drupal.settings.wxpay.jsApiParameters.signType,         //微信签名方式：
           "paySign": Drupal.settings.wxpay.jsApiParameters.paySign, //微信签名
       },
        function(res){
          if(res.err_msg == "get_brand_wcpay_request: ok" ) {
             console.log('sucess!thanks!');
             window.location.href="https://www.yongbuzhixi.com/thanks";
          }
          if(res.err_msg == "get_brand_wcpay_request: cancel" ) {
            alert('back!');
            window.history.go(-1); return false;
          }
          // WeixinJSBridge.log(res.err_msg);
          // alert(res.err_code+ '-' +res.err_desc+ '-' +res.err_msg);
        }
      );
    }

    function callpay()
    {
      if (typeof WeixinJSBridge == "undefined"){
          if( document.addEventListener ){
              document.addEventListener('WeixinJSBridgeReady', jsApiCall, false);
          }else if (document.attachEvent){
              document.attachEvent('WeixinJSBridgeReady', jsApiCall);
              document.attachEvent('onWeixinJSBridgeReady', jsApiCall);
          }
      }else{
          jsApiCall();
      }
    }

    var needAddress = 0;
    if(needAddress){
      //获取共享地址
      function editAddress()
      {
        WeixinJSBridge.invoke(
          'editAddress',
          Drupal.settings.wxpay.editAddress,
          function(res){
            var value1 = res.proviceFirstStageName;
            var value2 = res.addressCitySecondStageName;
            var value3 = res.addressCountiesThirdStageName;
            var value4 = res.addressDetailInfo;
            var tel = res.telNumber;

            alert(value1 + value2 + value3 + value4 + ":" + tel);
          }
        );
      }

      window.onload = function(){
        if (typeof WeixinJSBridge == "undefined"){
            if( document.addEventListener ){
                document.addEventListener('WeixinJSBridgeReady', editAddress, false);
            }else if (document.attachEvent){
                document.attachEvent('WeixinJSBridgeReady', editAddress);
                document.attachEvent('onWeixinJSBridgeReady', editAddress);
            }
        }else{
          editAddress();
        }
      };
    }

    $('#payit').click(function(e){
      e.preventDefault();
      console.log(Drupal.settings.wxpay.jsApiParameters);
      callpay();
    });

  });
}( jQuery ));
