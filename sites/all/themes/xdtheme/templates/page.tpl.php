<div class="layer_layout">
	<div class="layer_menu layer">
		<div id="main_menu">
		<?php if (!empty($primary_nav)): ?>
		  <?php print render($primary_nav); ?>
		<?php endif; ?>
    <?php if (!empty($secondary_nav)): ?>
      <?php print render($secondary_nav); ?>
    <?php endif; ?>
    <?php if (!empty($page['navigation'])): ?>
      <?php print render($page['navigation']); ?>
    <?php endif; ?>
		</div>
	</div> 
	<div id="layer_content" class="layer layer_content animAll">
		<div class="main-container <?php print $container_class; ?>">
			<div class="toggleMainMenu animAll">
	        <div class="animAll">
	            <span class="animAll">Menu</span>
	        </div>
	        <span class="menu_tooltip animeSlow">Home</span>
	    </div>

		  <header role="banner" id="page-header">
		    <?php if (!empty($site_slogan)): ?>
		      <p class="lead"><?php print $site_slogan; ?></p>
		    <?php endif; ?>

		    <?php print render($page['header']); ?>
		  </header> <!-- /#page-header -->

		  <?php if (arg(0)=='node'): ?>
		  <div id="wx-header" class="row-fluid ">
		      <h1 class="title"> <?php print $title; ?> </h1>
		      <div class="authors">
		       <?php print render($wx_date); ?>&nbsp;&nbsp;
		       <?php print render($wx_term); ?>&nbsp;&nbsp;
		       <?php print l(variable_get('mp_config_appname_'.$nodeuid, "永不止息"),variable_get('mp_config_default_url_'.$nodeuid, 'http://t.cn/RA1nOGY')); ?>
		     </div>
		  </div>  
		  <?php endif; ?>
		  <div class="row">

		    <?php if (!empty($page['sidebar_first'])): ?>
		      <aside class="col-sm-3" role="complementary">
		        <?php print render($page['sidebar_first']); ?>
		      </aside>  <!-- /#sidebar-first -->
		    <?php endif; ?>

		    <section<?php print $content_column_class; ?>>
          <div id="content-wrapper" class="content-wrapper">
  		      <?php if (!empty($page['highlighted'])): ?>
  		        <div class="highlighted jumbotron"><?php print render($page['highlighted']); ?></div>
  		      <?php endif; ?>
  		      <?php if (!empty($breadcrumb)): print $breadcrumb; endif;?>
  		      <a id="main-content"></a>
  		      <?php print render($title_prefix); ?>
  		      <?php if (!empty($title)): ?>
  		        <h1 class="page-header"><?php print $title; ?></h1>
  		      <?php endif; ?>
  		      <?php print render($title_suffix); ?>
  		      <?php print $messages; ?>
  		      <?php if (!empty($tabs)): ?>
  		        <?php print render($tabs); ?>
  		      <?php endif; ?>
  		      <?php if (!empty($page['help'])): ?>
  		        <?php print render($page['help']); ?>
  		      <?php endif; ?>
  		      <?php if (!empty($action_links)): ?>
  		        <ul class="action-links"><?php print render($action_links); ?></ul>
  		      <?php endif; ?>
  		      <?php print render($page['content']); ?>
          </div>
		    </section>

		    <?php if (!empty($page['sidebar_second'])): ?>
		      <aside class="col-sm-3" role="complementary">
		        <?php print render($page['sidebar_second']); ?>
		      </aside>  <!-- /#sidebar-second -->
		    <?php endif; ?>

		  </div>
		</div>

		<?php if (!empty($page['footer'])): ?>
		  <footer class="footer <?php print $container_class; ?>">
		    <?php print render($page['footer']); ?>

        <div class="row">
          <div class="hideonmobile d-copyright"><p>京ICP备15024539号&nbsp;<img src="https://ss0.bdstatic.com/5aV1bjqh_Q23odCf/static/superman/img/copy_rignt_24.png" style="height:16px; width:13px" /> <a href="http://wx.yongbuzhixi.com/node/373">免责声明</a></p></div>
        </div>
		  </footer>
		<?php endif; ?>
	</div>
</div>

<script type="text/javascript">
	(function($) {
		$('.toggleMainMenu').click(function(e){
			e.preventDefault();
			$('#layer_content').toggleClass('menu-open');
      $("html, body").animate({ scrollTop: "0px" });
		});
    $('.toggleMainMenu').slideDown(800);    

    var lastScrollTop = 0;
    $(window).scroll(function(event){
       var st = $(this).scrollTop();
       if (st > lastScrollTop){
           // downscroll code
           $('.toggleMainMenu').slideUp('fast');
       } else {
          // upscroll code
          $('.toggleMainMenu').slideDown(800);
       }
       lastScrollTop = st;
    });

	}( jQuery ));

</script>
