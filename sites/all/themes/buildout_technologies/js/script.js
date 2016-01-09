(function ($) {
  $(document).ready(function(){
    
    text = $('.links .statistics_counter').text();
    var number = parseInt(text, 10);
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
  });
})(jQuery);