<?php

/**
 * @file
 * Default theme implementation to display a node.
 *
 * Available variables:
 * - $title: the (sanitized) title of the node.
 * - $content: An array of node items. Use render($content) to print them all,
 *   or print a subset such as render($content['field_example']). Use
 *   hide($content['field_example']) to temporarily suppress the printing of a
 *   given element.
 * - $user_picture: The node author's picture from user-picture.tpl.php.
 * - $date: Formatted creation date. Preprocess functions can reformat it by
 *   calling format_date() with the desired parameters on the $created variable.
 * - $name: Themed username of node author output from theme_username().
 * - $node_url: Direct url of the current node.
 * - $display_submitted: Whether submission information should be displayed.
 * - $submitted: Submission information created from $name and $date during
 *   template_preprocess_node().
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. The default values can be one or more of the
 *   following:
 *   - node: The current template type, i.e., "theming hook".
 *   - node-[type]: The current node type. For example, if the node is a
 *     "Blog entry" it would result in "node-blog". Note that the machine
 *     name will often be in a short form of the human readable label.
 *   - node-teaser: Nodes in teaser form.
 *   - node-preview: Nodes in preview mode.
 *   The following are controlled through the node publishing options.
 *   - node-promoted: Nodes promoted to the front page.
 *   - node-sticky: Nodes ordered above other non-sticky nodes in teaser
 *     listings.
 *   - node-unpublished: Unpublished nodes visible only to administrators.
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 *
 * Other variables:
 * - $node: Full node object. Contains data that may not be safe.
 * - $type: Node type, i.e. story, page, blog, etc.
 * - $comment_count: Number of comments attached to the node.
 * - $uid: User ID of the node author.
 * - $created: Time the node was published formatted in Unix timestamp.
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 * - $zebra: Outputs either "even" or "odd". Useful for zebra striping in
 *   teaser listings.
 * - $id: Position of the node. Increments each time it's output.
 *
 * Node status variables:
 * - $view_mode: View mode, e.g. 'full', 'teaser'...
 * - $teaser: Flag for the teaser state (shortcut for $view_mode == 'teaser').
 * - $page: Flag for the full page state.
 * - $promote: Flag for front page promotion state.
 * - $sticky: Flags for sticky post setting.
 * - $status: Flag for published status.
 * - $comment: State of comment settings for the node.
 * - $readmore: Flags true if the teaser content of the node cannot hold the
 *   main body content.
 * - $is_front: Flags true when presented in the front page.
 * - $logged_in: Flags true when the current user is a logged-in member.
 * - $is_admin: Flags true when the current user is an administrator.
 *
 * Field variables: for each field instance attached to the node a corresponding
 * variable is defined, e.g. $node->body becomes $body. When needing to access
 * a field's raw values, developers/themers are strongly encouraged to use these
 * variables. Otherwise they will have to explicitly specify the desired field
 * language, e.g. $node->body['en'], thus overriding any language negotiation
 * rule that was previously applied.
 *
 * @see template_preprocess()
 * @see template_preprocess_node()
 * @see template_process()
 */
?>
<style type="text/css">
  #content-wrapper p{
    margin-bottom: 0;
  }
</style>

<article id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>> <?php print $user_picture; ?> <?php print render($title_prefix); ?>
  <?php if (!$page): ?>
  <h2<?php print $title_attributes; ?>><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h2>
  <?php endif; ?>
  <?php print render($title_suffix); ?>
  <?php if ($display_submitted): ?>
  <div class="submitted"> <?php print $submitted; ?> </div>
  <?php endif; ?>
  <div class="content"<?php print $content_attributes; ?>>
<style type="text/css">

    @charset "UTF-8"; @font-face {
        font-family: flat-audio;
        src: url(font/flat-audio.eot);
        src: url(font/flat-audio.eot#iefix) format('embedded-opentype'),url("data:font/woff;base64,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") format('woff'),url(font/flat-audio.ttf) format('truetype'),url(font/flat-audio.svg#flat-audio) format('svg');
        font-weight: 400;
        font-style: normal
    }

    .audio {
        position: relative;
        font-family: 'Source Sans Pro',sans-serif;
        text-align: left;
        min-width: 320px;
        max-width: 1280px;
        width: 100%;
        height: 64px;
        -webkit-tap-highlight-color: rgba(0,0,0,0);
        -webkit-touch-callout: none;
        -webkit-user-select: none;
        -khtml-user-select: none;
        -moz-user-select: none;
        -ms-user-select: none;
        user-select: none;
        color: #fff
    }

    .audio,.audio * {
        margin: 0;
        padding: 0;
        border: 0;
        font-size: 0;
        line-height: 0
    }

    .audio :focus {
        outline: 0
    }

    .audio button::-moz-focus-inner {
        border: 0
    }

    .control {
        position: absolute;
        top: 0;
        width: 64px;
        height: 100%;
        background-color: #00aef6
    }

    .play-control {
        left: 0
    }

    .button {
        display: block;
        text-decoration: none;
        width: 64px;
        height: 100%;
        font-size: 32px;
        line-height: 64px;
        text-align: center;
        background: 0 0;
        cursor: pointer;
        color: #fff
    }

    .button:focus {
        color: #e5f7ff
    }

    .button:before {
        display: block;
        font-family: flat-audio;
        font-style: normal;
        font-weight: 400;
        text-decoration: none;
        font-variant: normal;
        text-transform: none;
        speak: none;
        width: 64px;
        line-height: 64px;
        text-align: center;
        opacity: 1
    }

    .audio.state-playing .play:before {
        content: '\2016'
    }

    .play:before {
        content: '\25b6'
    }

    .bar {
        position: absolute;
        top: 0;
        left: 64px;
        right: 0;
        height: 100%;
        background-color: #000;
    }

    .seek-bar.seek-bar-display {
        min-width: 0;
        background-color: #00aef6;
        height: 3px;
        z-index: 1;
    }

    .seek-bar {
        position: absolute;
        bottom: 0;
        left: 0;
        min-width: 100%;
        height: 100%;
        /*cursor: pointer*/
    }

    .play-bar {
        position: absolute;
        top: 0;
        left: 0;
        width: 0;
        height: 100%;
        background-color: #0082b2
    }

    .details,.timing {
        position: absolute;
        top: 0;
        left: 0;
        right: 0;
        height: 100%;
        padding: 0 12px;
        font-size: 16px;
        line-height: 64px
    }

    .timing {
        text-align: right
    }

    .title,.duration {
        font-size: 14px;
        line-height: 64px
    }

    .no-solution {
        position: absolute;
        top: 0;
        left: 64px;
        right: 0;
        height: 48px;
        padding: 8px 0;
        line-height: 24px;
        font-size: 16px;
        text-align: center;
        display: none;
        color: #000;
        background-color: #b28282
    }
    .demo-wrapper {
        margin: 0 auto;
        min-width: 320px;
        max-width: 800px;
        width: 100%;
        -webkit-box-sizing: border-box;
        -khtml-box-sizing: border-box;
        -moz-box-sizing: border-box;
        -ms-box-sizing: border-box;
        box-sizing: border-box
    }

    .demo-title {
        font: 32px 'Source Sans Pro',sans-serif;
        text-align: center
    }

    .demo-text {
        font: 15px 'Source Sans Pro',sans-serif;
        text-align: center
    }

    .demo-text-first {
        margin-top: 48px
    }

    .demo-text-last {
        padding-bottom: 48px
    }

    .demo-text a {
        color: #c3307d;
        text-decoration: underline
    }

    .demo-text a:hover {
        text-decoration: none
    }

</style>


    <?php
      if(isset($node->field_mp3url[LANGUAGE_NONE][0])){
    ?>    
   <div class="audio-wrapper">
        <div id="demo" class="audio state-playing" role="application" aria-label="media player">
            <div class="play-control control">
                <button class="play button" role="button" aria-label="play" tabindex="0"></button>
            </div>
            <div class="bar">
                <div class="seek-bar seek-bar-display loaded" style="width: 0%;"></div>
                <div class="seek-bar" style="width: 100%;">
                    <div class="play-bar" style="width: 0%; overflow: hidden;">
                    </div>
                    <div class="details">
                        <span class="title" aria-label="title">永不止息 - 需要有你</span>
                    </div>
                    <div class="timing">
                        <span class="duration" role="timer" aria-label="duration">0:00</span>
                    </div>
                </div>
            </div>
            <div class="no-solution" style="display: none;">出错啦<br>请使用谷歌浏览器</div>
            <div id="player" class="playercount" style="display: none;">
            </div>
        </div>
        <div id="playlist" style="display: none;"></div>
    </div>
    <script type="text/javascript">
    var playlist = [
            {
                title: 'FM77 <?php echo $node->title;?>',
                artist: '',
                album: '',
                cover:'',
                mp3: '<?php echo $node->field_mp3url[LANGUAGE_NONE][0]["value"];?>',
                ogg: ''
            }
        ];
    </script>
    <?php
      }
      // We hide the comments and links now so that we can render them later.
      hide($content['comments']);
      hide($content['links']);
      print render($content);
    ?>
  </div>
  <?php print render($content['links']); ?>
  <?php if($view_mode == 'full'):?>
    <?php 
    	$relate_node = dale_prev_next_node($node, array('fm77'));
    	if($relate_node['prev']){
    		$prev = l('« 上一篇','node/'.$relate_node['prev']['nid']);
    	}else{
    		$prev = '<a href="###">没有了</a>';
    	}
    	if($relate_node['next']){
    		$next = l('下一篇 »','node/'.$relate_node['next']['nid']);
    	}else{
    		$next = '<a href="###">没有了</a>';
    	}
    ?>
    <div class="row-fluid prev-next-post"> 
      <div class="span6 previous"> 
        <div class="group"><?php echo $prev;?></div>
      </div>

      <div class="span6 next"> 
        <div class="group"><?php echo $next;?></div>
      </div>
    </div>
  <?php endif;?>
  <?php print render($content['comments']); ?> 
</article>
<script type="text/javascript">
    (function($){
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

        $('.timing .duration').html(parseInt(value/60)+':'+currentSec);
        $('.play-bar').css('width', ratio + '%');
        // $('.pprogress .slider a').css('left', ratio + '%');
    }

    var updateProgress = function(){
        setProgress(audio.currentTime);
    }

    // Progress slider
    // $('.pprogress .slider').slider({step: 0.1, slide: function(event, ui){
    //  $(this).addClass('enable');
    //  setProgress(audio.duration * ui.value / 100);
    //  clearInterval(timeout);
    // }, stop: function(event, ui){
    //  audio.currentTime = audio.duration * ui.value / 100;
    //  $(this).removeClass('enable');
    //  timeout = setInterval(updateProgress, 500);
    // }});

    // Volume slider
    var setVolume = function(value){
        audio.volume = localStorage.volume = value;
        $('.volume .pace').css('width', value * 100 + '%');
        $('.volume .slider a').css('left', value * 100 + '%');
    }

    var volume = localStorage.volume || 0.5;
    // $('.volume .slider').slider({max: 1, min: 0, step: 0.01, value: volume, slide: function(event, ui){
    //  setVolume(ui.value);
    //  $(this).addClass('enable');
    //  $('.mute').removeClass('enable');
    // }, stop: function(){
    //  $(this).removeClass('enable');
    // }}).children('.pace').css('width', volume * 100 + '%');

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
        // var endVal = this.seekable && this.seekable.length ? this.seekable.end(0) : 0;
        // $('.loaded').css('width', (100 / (this.duration || 1) * endVal) +'%');
          var buffered = audio.buffered;
      var loaded;
      // var played;

      if (buffered.length) {
        loaded = 100 * buffered.end(0) / audio.duration;
        // played = 100 * audio2.currentTime / audio2.duration;
        $('.loaded').attr('style','width: ' + loaded.toFixed(0) + '%');
        
      }
    }

    // Fire when track loaded completely
    var afterLoad = function(){
        if (autoplay == true) play();
        // $('.cover img').rotate();    
    }

    // Load track
    var loadMusic = function(i){
        var item = playlist[i],
            newaudio = $('<audio>').html('<source src="'+item.mp3+'"><source src="'+item.ogg+'">').appendTo('#player');
        $('.details .title').html(item.title);

        $('.cover').html('<img src="'+item.cover+'" alt="'+item.album+'">');
        $('.tag').html('<strong>'+item.title+'</strong><span class="artist">'+item.artist+'</span><span class="album">'+item.album+'</span>');

        $('.audio').removeClass('state-playing').eq(i).addClass('state-playing');
        audio = newaudio[0];
        audio.volume = $('.mute').hasClass('enable') ? 0 : volume;
        audio.addEventListener('progress', beforeLoad, false);
        audio.addEventListener('durationchange', beforeLoad, false);
        audio.addEventListener('canplay', afterLoad, false);
        audio.addEventListener('ended', ended, false);
    }

    loadMusic(currentTrack);
    $('.play-control button').on('click', function(){
        console.log('click');
        if ($(this).parents('.audio').hasClass('state-playing')){
            $(this).parents('.audio').removeClass('state-playing');
            pause();
        } else {
            $(this).parents('.audio').addClass('state-playing');
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

