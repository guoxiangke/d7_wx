
<div id="comments" class="<?php print $classes; ?>"<?php print $attributes; ?>>
  <?php print render($content['comments']); ?>

  <?php if ($content['comment_form']): ?>
    <?php print render($content['comment_form']); ?>
  <?php endif; ?>
</div>
<div class="hidden gzh-comment-block">
  <?php echo views_embed_view('gzh', 'block', $node->uid);?>
</div>
