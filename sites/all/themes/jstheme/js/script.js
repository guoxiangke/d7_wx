(function ($) {
  $(document).ready(function(){

  // $('.views-exposed-form').


    text = $('.links .statistics_counter').text();
    var number = parseInt(text.replace(/[^0-9\.]/g, ''), 10);
    $('#statistics_counter').html(number);

   	// number -= Math.floor(Math.random() * (number - 0));
    // number = $('.rate-number-up-down-rating').text();
    // console.log(number);
    $('.praise_num').html(Drupal.settings.xdtheme.ratecount);

    $('#praise').click(function(){
    	$('.icon_praise_gray').toggleClass('praised');
    	if($('.praised').length){
    		$('.praise_num').html(( parseInt($('.praise_num').html())+1));
    	}else{
    		$('.praise_num').html(( parseInt($('.praise_num').html())-1));
    	}
    });

    $('.content p').each(function(){
    if($(this).next('ul').length){
         $(this).addClass('data-ul');
    }
    });
    $('p').click(function(){
        if($(this).next('ul').length){
          if($(this).next('ul').is(':visible')){
            $(this).next('ul').slideUp();
            $(this).toggleClass('data-ul-open');
          }else{
            $(this).next('ul').slideDown();
            $(this).toggleClass('data-ul-open');
          }
        }
      }
    );

  });

  Drupal.behaviors.jstheme = {
    attach: function (context, settings) {
      $('#praise').click(function(){
        $('#rate-button-1').trigger('click');
        $('.rate-widget-1').hide();
      });
      $('.rate-widget-1').hide();


      var lastScrollTop = 0;
      $(window).scroll(function(event){
         var st = $(this).scrollTop();
         if (st > lastScrollTop){
             // downscroll code
             if(st>=49){
              $('#navbar').hide();
              $('.authorinfo .top').css({"top":"0","position": "fixed","background": "#fff","width": "93%","left": "13px","padding-top": "10px"});
             }
         } else {
            console.log('upscroll:'+st)
            // upscroll code
            if(st<30){
              $('#navbar').slideDown(800);
            }
         }
         lastScrollTop = st;
      });


    }
  }


})(jQuery);
