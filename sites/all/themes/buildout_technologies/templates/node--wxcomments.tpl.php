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
 * - $node_url: Direct URL of the current node.
 * - $display_submitted: Whether submission information should be displayed.
 * - $submitted: Submission information created from $name and $date during
 *   template_preprocess_node().
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. The default values can be one or more of the
 *   following:
 *   - node: The current template type; for example, "theming hook".
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
 * - $type: Node type; for example, story, page, blog, etc.
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
 * - $view_mode: View mode; for example, "full", "teaser".
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
 * variable is defined; for example, $node->body becomes $body. When needing to
 * access a field's raw values, developers/themers are strongly encouraged to
 * use these variables. Otherwise they will have to explicitly specify the
 * desired field language; for example, $node->body['en'], thus overriding any
 * language negotiation rule that was previously applied.
 *
 * @see template_preprocess()
 * @see template_preprocess_node()
 * @see template_process()
 *
 * @ingroup themeable
 */
?>
<?php 

	// $file = file_load($node->field_image[LANGUAGE_NONE][0]['fid']);
	// $image = image_load($file->uri);
	// $image_style = array(
	//   'file' => array(
	//     '#theme' => 'image_style',
	//     '#style_name' => 'large',
	//     '#path' => $image->source,
	//     '#width' => $image->info['width'],
	//     '#height' => $image->info['height'],
	//   ),
	// );wxcommentswxcomments
	// echo drupal_render($image_style);

?>
<style type="text/css">
	body{
		font-size: 12px;
	}
	body .field-name-comment-body{
		font-size: 14px;
	}
	h3 a{
		font-size: 14px;
	}	
	.comment-wrapper{
		padding: 15px;
	}
	.node .submitted{
		margin-bottom: 0;
	}
	.comment-container{
		border-bottom: 1px dotted #666;
	}
	#comments{
		padding-top: 0px;
		margin-top: 0px;
	}
	.page-node .content-body .field-name-comment-body{
		margin-bottom: 0;
	}
	.comment-padding{
		padding-top: 5px;
	}
	.col-xs-10 .content{
		padding: 0;
    background-color: #b2e281;
    display: inline-block;
    text-align: left;
    font-size: 14px;
    border-radius: 3px;
    -moz-border-radius: 3px;
    -webkit-border-radius: 3px;
	}
	.col-xs-10 .content:before{
    content: "";
    position: absolute;
    top: 15px;
    left: 6px;
    border-style: solid;
    border-width: 8px 10px 8px 0;
    border-color: transparent #b2e281;
    display: block;
    width: 0;
    z-index: 1;
	}
	.img-circle img{
	    border-radius: 50%;
	    width: 50px;
	}
	.node-wxcomments{
		position: relative;
    height: 100%;
    overflow: hidden;
    font-family: 'Helvetica Neue', Helvetica, 'Hiragino Sans GB', 'Microsoft YaHei', 微软雅黑, Arial, sans-serif;
	}
	.col-xs-10{
	  position: relative;
	}
	.comment-desc{
		padding: 8px 36px;
		border-top: 1px solid #999;
		border-bottom: 1px solid #999;
		font-size: 14px;
	}
	.desc-wrapper{
		padding: 10px 20px;
	}
	#collapsebody{
		border: 1px solid #999;
		padding: 10px;
		border-radius: 5px;	
		position: relative;    
		padding-bottom: 5px;
	}
	.desc-wrapper .title{
		position: relative;
    top: 20px;
    background: #FFF;
    display: block;
    width: 15%;
    z-index: 10;
    left: 22px;
    color: green;
   	font-weight: bold;
	}
	.desc-wrapper{
    background: #FFF;
	}
	#comments{
		background-color: #eee;
	}
	.page-node .content-body .field{
		margin-bottom: 0;
	}

	.indented .col-xs-10 .content{
		background-color: #fff;
	}
	.indented .col-xs-10 .content:before{
		border-color: transparent #fff;
	}
	div[class|="edit-author"],#edit-author--2,.form-item-comment-body-und-0-value label{
		display: none;
	}

	.desc-wrapper .comment-desc {
		background:url(../<?php echo drupal_get_path('theme', 'buildout_technologies').'/images/gsj.png'; ?>) no-repeat center left;

    background-size: 38px 38px;
	}
	.col-xs-10 pre {
		display: block; */
     padding: 0px; 
    margin: 0;
    font-size: 12px;
    /* line-height: 20px; */
    /* word-break: break-all; */
    word-wrap: break-word;
    white-space: pre;
    white-space: pre-wrap;
     background:transparent; 
    border:none;
    -webkit-border-radius: none;
    -moz-border-radius: none;
     border-radius: none; 
	}
	.col-xs-10 ul.links{
		display: block;
	}
	.comment .col-xs-2{
		padding-right: 0;
	}

</style>
<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

  <?php print $user_picture; ?>

  <?php print render($title_prefix); ?>
  <?php if (!$page): ?>
    <h2<?php print $title_attributes; ?>><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h2>
  <?php endif; ?>
  <?php print render($title_suffix); ?>

  <?php if ($display_submitted): ?>
    <div class="submitted">
      <?php print $submitted; ?>
    </div>
  <?php endif; ?>

  <div class="content"<?php print $content_attributes; ?>>
  	<?php
      // We hide the comments and links now so that we can render them later.
      hide($content['comments']);
      hide($content['links']);
      print render($content);
  	?>
  	<div class="desc-wrapper">
	    <div class="comment-desc"  data-toggle="collapse" data-target="#collapseExample" aria-expanded="false" aria-controls="collapseExample"><span>微信回复【内容@<?php echo $node->nid;?>】 即可留言！</span></div>

	    <div class="collapse" id="collapseExample">
	    	<p class='title'>话题介绍</p>	
	    	<p id='collapsebody'><?php echo $node->body[LANGUAGE_NONE][0]['safe_value'];?>
	    	</p>
	    </div>
    </div>
  </div>

  <?php print render($content['comments']); ?>

  <?php //print render($content['links']); ?>

</div>
