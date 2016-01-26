<?php
?>
<!-- Bootstrap -->
<link href="http://cdn.bootcss.com/bootstrap/3.3.2/css/bootstrap.min.css" rel="stylesheet">
<style type="text/css">
	body {
    font: 14px "Helvetica Neue",Helvetica,Arial,"Lucida Grande",sans-serif;
    background: #333;
    color: #fff;
	}
</style>
<div class="container-fluid">
	<div id="player">
		<div class="ctrl">
			<div class="tag">
				<strong>Title</strong>
				<span class="artist">Artist</span>
				<span class="album">Album</span>
			</div>
			<div class="control">
				<div class="left">
					<div class="rewind icon"></div>
					<div class="playback icon"></div>
					<div class="fastforward icon"></div>
				</div>
				<div class="volume right">
					<div class="mute icon left"></div>
					<div class="slider left">
						<div class="pace"></div>
					</div>
				</div>
			</div>
			<div class="pprogress">
				<div class="slider">
					<div class="loaded"></div>
					<div class="pace"></div>
				</div>
				<div class="timer left">0:00</div>
				<div class="right">
					<div class="repeat icon"></div>
					<div class="shuffle icon"></div>
				</div>
			</div>
		</div>
		<div class="row" id="radiopicrow">
			<div class="col-md-6 col-xs-6"><div id="radiopic"></div></div>
			<div class="col-md-6 col-xs-6"><a href="https://mp.weixin.qq.com/s?__biz=MjM5ODQ4NjU4MA==&mid=400462011&idx=1&sn=ea26aacf8317d6dba24b5b339cdf0242&scene=1&srcid=1223NosyF25gZEn8STEnUOqz&key=ac89cba618d2d976ea2bb39169ce8b27d00e57f2c5373fa9ff35a12feaed5678b06c09673fa892ac87e7e33ab4e278a2&ascene=0&uin=MTYyMjI5NjYwMA%3D%3D&devicetype=iMac+MacBookPro11%2C3+OSX+OSX+10.10.5+build(14F1021)&version=11020201&pass_ticket=yUmHU9UKWe7hmJ5vhL7kmwFgzpJEJ7lE4Nnp0Xtz7HaY3IeK3SW6310dOoQEN%2BTO"><div class="cover"></div></a></div>
		</div>
	</div>
	<ul id="playlist"></ul>
	<script type="text/javascript">
		<?php

			$js_radio = array();
		  $ids = explode('#', arg(1));
		  if($ids&&isset($ids['1'])){
		    if(is_numeric($ids['0'])){
		      $result = db_select('hd', 'c')
		        ->fields('c')//
		        ->condition('id', $ids['0'])
		        ->condition('uid', $ids['1'])
		        ->orderBy('award', 'ESC')
		        ->execute()->fetchAssoc();
		      if(!$result) {
		      	$js_radio['title'] = '领奖码不对';
						$js_radio['artist'] = '请确认！';
						$js_radio['cover'] = 'http://ly.yongbuzhixi.com/fm/img/ybzx320.jpg';
						$js_radios[]= $js_radio;
		      }
		    }
		  }
		if($result) {
			if($result['award']==0){//4等级sd卡内容
				 module_load_include('inc', 'mp_liangyou', 'liangyou');
				 $lysd = get_lysd();
				 foreach ($lysd as $title => $sd) {
				 	if(strpos($sd['title'],arg(2)) !== false){
				 		$j=1;
				 		for ($i=$sd['begin']; $i <= $sd['end'] ; $i++) { 
				 			$link = $sd['title'].'/'.str_pad($i, 3,'0',STR_PAD_LEFT).'.mp3';
							$etime = time()+360000; // 授权
							$key = 'ly729';   // token 防盗链密钥
							$path = '/lysd/'.$link; // 图片相对路径
							$sign = substr(md5($key.'&'.$etime.'&'.$path), 12,8).$etime;
							$link = 'http://ly729.b0.upaiyun.com/lysd/'.urlencode($link).'?_upt='.$sign;

							$js_radio['title'] = '第'.$j++.'集';
							$js_radio['artist'] = $sd['title'];
							$js_radio['album'] = $result['name'].' !,这是您的4等奖礼物！<br/>永不止息，需要有你，谢谢参与！';
							$js_radio['cover'] = 'http://ly.yongbuzhixi.com/fm/img/ybzx320.jpg';
							$js_radio['mp3'] = $link;
							$js_radio['ogg'] = '';
							$js_radios[]= $js_radio;
				 		} 
						break;
				 	}
				 }
			}else{//3等级cd
				$pre = 'http://lyradio.b0.upaiyun.com/ybzx/cd/';
				$cds = array(
					'1'=>array('count'=>15,'title'=>'生命改变的祝福'),
					'2'=>array('count'=>10,'title'=>'活出彩虹'),
					'3'=>array('count'=>14,'title'=>'精神健康'),
					'4'=>array('count'=>15,'title'=>'活出彩虹'),
					'5'=>array('count'=>9,'title'=>'千头万绪家中来'),
					'6'=>array('count'=>7,'title'=>'交友恋爱婚姻'),
				);
				$cd = $cds[arg(2)];
				$i=1;
				while ( $i<= $cd['count']) {
						$index = str_pad($i,2,"0",STR_PAD_LEFT);
						$js_radio['title'] = '第'.$index.'集';
						$js_radio['artist'] = $cd['title'];
						$js_radio['album'] = $result['name'].' !,这是您的3等奖礼物！<br/>永不止息，需要有你，谢谢参与！';
						$js_radio['cover'] = 'http://ly.yongbuzhixi.com/fm/img/ybzx320.jpg';
						$js_radio['mp3'] = $pre.urlencode($cd['title']).'/'.$index.'.mp3';
						$js_radio['ogg'] = '';
						$js_radios[]= $js_radio;
					$i++;
				}
			}


		}
			$playlist = json_encode($js_radios);
		?>
	    var playlist = <?php echo $playlist;?>;
	    var autoplay = false;
	</script>
	<script type="text/javascript">
(function($){
	   /**
		 * Created by YD on 5/7/15.
		 * Base on Jquery
		 */
		var ele ;

		//初始角度
		var degree = 0;

		//单次旋转
		function singleRotate() {
		    //一次增加50度
		    degree = degree + 25 * Math.PI / 180;
		    ele.css("transform","rotate("+degree+"deg)");
		}
		//自定义函数
		$.fn.extend({
		    rotate: function () {
		        ele = this ;
		        setInterval(singleRotate,20);
		    }
		});

	// Settings
	var repeat = localStorage.repeat || 0,
		shuffle = localStorage.shuffle || 'false',
		continous = true,
		autoplay = true,
		playlist = window.playlist;

	// Load playlist
	for (var i=0; i<playlist.length; i++){
		var item = playlist[i];
		$('#playlist').append('<li>'+item.artist+' - '+item.title+'</li>');
	}

	var time = new Date(),
		currentTrack = shuffle === 'true' ? time.getTime() % playlist.length : 0,
		trigger = false,
		audio, timeout, isPlaying, playCounts;

	var play = function(){
		audio.play();
		$('.playback').addClass('playing');
		timeout = setInterval(updateProgress, 500);
		isPlaying = true;
	}

	var pause = function(){
		audio.pause();
		$('.playback').removeClass('playing');
		clearInterval(updateProgress);
		isPlaying = false;
	}

	// Update progress
	var setProgress = function(value){
		var currentSec = parseInt(value%60) < 10 ? '0' + parseInt(value%60) : parseInt(value%60),
			ratio = value / audio.duration * 100;

		$('.timer').html(parseInt(value/60)+':'+currentSec);
		$('.pprogress .pace').css('width', ratio + '%');
		$('.pprogress .slider a').css('left', ratio + '%');
	}

	var updateProgress = function(){
		setProgress(audio.currentTime);
	}

	// Progress slider
	$('.pprogress .slider').slider({step: 0.1, slide: function(event, ui){
		$(this).addClass('enable');
		setProgress(audio.duration * ui.value / 100);
		clearInterval(timeout);
	}, stop: function(event, ui){
		audio.currentTime = audio.duration * ui.value / 100;
		$(this).removeClass('enable');
		timeout = setInterval(updateProgress, 500);
	}});

	// Volume slider
	var setVolume = function(value){
		audio.volume = localStorage.volume = value;
		$('.volume .pace').css('width', value * 100 + '%');
		$('.volume .slider a').css('left', value * 100 + '%');
	}

	var volume = localStorage.volume || 0.5;
	$('.volume .slider').slider({max: 1, min: 0, step: 0.01, value: volume, slide: function(event, ui){
		setVolume(ui.value);
		$(this).addClass('enable');
		$('.mute').removeClass('enable');
	}, stop: function(){
		$(this).removeClass('enable');
	}}).children('.pace').css('width', volume * 100 + '%');

	$('.mute').click(function(){
		if ($(this).hasClass('enable')){
			setVolume($(this).data('volume'));
			$(this).removeClass('enable');
		} else {
			$(this).data('volume', audio.volume).addClass('enable');
			setVolume(0);
		}
	});

	// Switch track
	var switchTrack = function(i){
		if (i < 0){
			track = currentTrack = playlist.length - 1;
		} else if (i >= playlist.length){
			track = currentTrack = 0;
		} else {
			track = i;
		}

		$('audio').remove();
		loadMusic(track);
		if (isPlaying == true) play();
	}

	// Shuffle
	var shufflePlay = function(){
		var time = new Date(),
			lastTrack = currentTrack;
		currentTrack = time.getTime() % playlist.length;
		if (lastTrack == currentTrack) ++currentTrack;
		switchTrack(currentTrack);
	}

	// Fire when track ended
	var ended = function(){
		pause();
		audio.currentTime = 0;
		playCounts++;
		if (continous == true) isPlaying = true;
		if (repeat == 1){
			play();
		} else {
			if (shuffle === 'true'){
				shufflePlay();
			} else {
				if (repeat == 2){
					switchTrack(++currentTrack);
				} else {
					if (currentTrack < playlist.length) switchTrack(++currentTrack);
				}
			}
		}
	}

	var beforeLoad = function(){
		var endVal = this.seekable && this.seekable.length ? this.seekable.end(0) : 0;
		$('.pprogress .loaded').css('width', (100 / (this.duration || 1) * endVal) +'%');
	}

	// Fire when track loaded completely
	var afterLoad = function(){
		if (autoplay == true) play();
		$('.cover img').rotate();	
	}

	// Load track
	var loadMusic = function(i){
		var item = playlist[i],
			newaudio = $('<audio>').html('<source src="'+item.mp3+'"><source src="'+item.ogg+'">').appendTo('#player');
		
		$('.cover').html('<img src="'+item.cover+'" alt="'+item.album+'">');
		$('.tag').html('<strong>'+item.title+'</strong><span class="artist">'+item.artist+'</span><span class="album">'+item.album+'</span>');
		$('#playlist li').removeClass('playing').eq(i).addClass('playing');
		audio = newaudio[0];
		audio.volume = $('.mute').hasClass('enable') ? 0 : volume;
		audio.addEventListener('progress', beforeLoad, false);
		audio.addEventListener('durationchange', beforeLoad, false);
		audio.addEventListener('canplay', afterLoad, false);
		audio.addEventListener('ended', ended, false);
		var degree = 0;
	}

	loadMusic(currentTrack);
	$('.playback').on('click', function(){
		if ($(this).hasClass('playing')){
			pause();
		} else {
			play();
		}
	});
	$('.rewind').on('click', function(){
		if (shuffle === 'true'){
			shufflePlay();
		} else {
			switchTrack(--currentTrack);
		}
	});
	$('.fastforward').on('click', function(){
		if (shuffle === 'true'){
			shufflePlay();
		} else {
			switchTrack(++currentTrack);
		}
	});
	$('#playlist li').each(function(i){
		var _i = i;
		$(this).on('click', function(){
			switchTrack(_i);
		});
	});

	if (shuffle === 'true') $('.shuffle').addClass('enable');
	if (repeat == 1){
		$('.repeat').addClass('once');
	} else if (repeat == 2){
		$('.repeat').addClass('all');
	}

	$('.repeat').on('click', function(){
		if ($(this).hasClass('once')){
			repeat = localStorage.repeat = 2;
			$(this).removeClass('once').addClass('all');
		} else if ($(this).hasClass('all')){
			repeat = localStorage.repeat = 0;
			$(this).removeClass('all');
		} else {
			repeat = localStorage.repeat = 1;
			$(this).addClass('once');
		}
	});

	$('.shuffle').on('click', function(){
		if ($(this).hasClass('enable')){
			shuffle = localStorage.shuffle = 'false';
			$(this).removeClass('enable');
		} else {
			shuffle = localStorage.shuffle = 'true';
			$(this).addClass('enable');
		}
	});

})(jQuery);
	</script>
	<div style="text-align:center;margin:50px 0; font:normal 14px/24px 'MicroSoft YaHei';">
	</div>
</div>