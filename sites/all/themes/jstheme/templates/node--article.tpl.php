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
<?php if(!empty($body)): ?>
<article id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
  <header class="authorinfo">
  <?php if ($display_submitted): ?>
  <div class="clearfix top">
    <?php print $user_picture; ?>
    <div class="submitted"><span class="label">来源</span><?php print $submitted; ?> </div>

    <?php $wxfocuslink = variable_get('mp_config_default_url_'.$uid, "");
      if($wxfocuslink):
    ?>
    <div class="btn btn-small btn-success followwx">
      <a href="<?php echo $wxfocuslink;?>"><i class="glyphicon glyphicon-share-alt"></i><span>添加关注</span></a>
    </div>
    <?php endif;?>
  </div>
  <?php endif; ?>
  <?php if(1||$page): ?>
    <?php print render($title_prefix); ?>
    <h2 class="page-header"><?php print $title; ?></h2>
    <?php print render($title_suffix); ?>
  <?php endif; ?>
  </header>
  <div class="content"<?php print $content_attributes; ?>>
    <?php
      //

      $field_updated  = db_query('SELECT field_updated_value FROM {field_data_field_updated} WHERE entity_id = :nid', array(':nid' => $node->nid))->fetchField();

      if(isset($node->book['bid'])){
        if($node->book['bid'] =='183'){
          echo '<img typeof="foaf:Image" src="/sites/default/files/styles/sc900_500/public/field/image/22791549504_048814b027_k.jpg?itok=ST4XuKTu" width="900" height="500" alt="">';
          hide($content['field_image']);
        }
      }else{
        if($field_updated != '1'){
          print render($content['field_image']);
        }else{
          hide($content['field_image']);
        }
      }
  if($view_mode=='full' && isset($node->field_video_url[LANGUAGE_NONE][0])){
    $vid = $node->field_video_url[LANGUAGE_NONE][0]['value'];
    if(!(isset($node->field_video_position[LANGUAGE_NONE][0]['value']) && $node->field_video_position[LANGUAGE_NONE][0]['value']==1)){
  ?>
  <iframe id='video_top' frameborder="0" width="100%" height="250px" src="https://v.qq.com/iframe/player.html?vid=<?php echo $vid;?>&tiny=0&auto=0" allowfullscreen></iframe>
  <script>
    (function($){
      $(document).ready(function(){
        if($('#video').length){
          var html = $('<div>').append($('#video_top').clone()).remove().html()
          $('#video_top').remove();
          $('#video').html(html);
        }
      });
    })(jQuery)
  </script>
  <?php
    }
  }
      // We hide the comments and links now so that we can render them later.
      hide($content['comments']);
      hide($content['links']);
      hide($content['field_image']);
      print render($content);
      if($view_mode=='full' && isset($node->field_video_url[LANGUAGE_NONE][0])){
        $vid = $node->field_video_url[LANGUAGE_NONE][0]['value'];
        if((isset($node->field_video_position[LANGUAGE_NONE][0]['value']) && $node->field_video_position[LANGUAGE_NONE][0]['value']==1)){
      ?>
      <iframe frameborder="0" width="100%" height="250px" src="https://v.qq.com/iframe/player.html?vid=<?php echo $vid;?>&tiny=0&auto=0" allowfullscreen></iframe>
      <?php
        }
      }
      ?>
  </div>
  <?php print render($content['links']); ?>
  <?php if($view_mode == 'full'):?>
    <?php
      include('prev-next-post.php');
      include('wx_bottom.php');
    ?>
  <?php endif;?>
  <?php print render($content['comments']); ?>
</article>
<?php endif; ?>
