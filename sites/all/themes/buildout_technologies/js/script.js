(function ($) {
  $(document).ready(function(){
    
    text = $('.links .statistics_counter').text();
    var number = parseInt(text.replace(/[^0-9\.]/g, ''), 10);
    $('#statistics_counter').html(number);

   	number -= Math.floor(Math.random() * (number - 0));
    $('.praise_num').html(number);

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
        if($(this).next('ul').length && $(this).next('ul').is(':visible')){
          $(this).next('ul').slideUp();
          $(this).toggleClass('data-ul-open');
        }else{
          $(this).next('ul').slideDown();
          $(this).toggleClass('data-ul-open');
        }
      }
    );

  });
})(jQuery);