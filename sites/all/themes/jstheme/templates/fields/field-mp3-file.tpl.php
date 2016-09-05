<div class="ybzx-audio-wrapper">
        <div id="ybzx-wave-player" class="audio state-stop" role="application" aria-label="media player">
            <div class="play-control control">
                <button class="play button" role="button" aria-label="play" tabindex="0"></button>
            </div>
            <div class="bar">
                <div class="seek-bar seek-bar-display loaded" style="width: 0%;"></div>
                <div class="seek-bar pprogress" style="width: 100%;">
                    <div class="play-bar" style="width: 0%; overflow: hidden;">
                    </div>
                    <div class="details">
                        <span class="title" aria-label="title">永不止息 - 需要有你</span>
                    </div>
                    <div id="waveform" class="slider"></div>
                    <div class="timing">
                        <span class="duration" role="timer" aria-label="duration">0:00</span>
                    </div>
                </div>
            </div>
            <div class="no-solution" style="display: none;">出错啦<br>请使用谷歌浏览器</div>
            <div id="player" style="display: none;">
            </div>
        </div>
        <div id="playlist" style="display: none;"></div>
    </div>
    <script>
        var playlist = [
                {
                    title: 'FM77',
                    artist: '',
                    album: '',
                    cover:'',
                    mp3: "<?php echo file_create_url($variables['mp3']['uri']);?>",
                    ogg: ''
                }
            ];
        var autoplay = false;
        var continous = true;//loop
        //wave begin know issues:
        //FIX XXXmp3 loaded twice....XXXX
        //mp3 link must use CORS headers.
        var wavesurfer = WaveSurfer.create({
            container: '#waveform',
            hideScrollbar:true,
            progressColor: '#00aef6',
            waveColor: '#0082b2',
            barWidth: 1,
        });
    </script>
