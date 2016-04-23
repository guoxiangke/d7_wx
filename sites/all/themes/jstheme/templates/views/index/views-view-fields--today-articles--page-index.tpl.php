<?php

/**
 * @file
 * Default simple view template to all the fields as a row.
 *
 * - $view: The view in use.
 * - $fields: an array of $field objects. Each one contains:
 *   - $field->content: The output of the field.
 *   - $field->raw: The raw data for the field, if it exists. This is NOT output safe.
 *   - $field->class: The safe class id to use.
 *   - $field->handler: The Views field handler object controlling this field. Do not use
 *     var_export to dump this object, as it can't handle the recursion.
 *   - $field->inline: Whether or not the field should be inline.
 *   - $field->inline_html: either div or span based on the above flag.
 *   - $field->wrapper_prefix: A complete wrapper containing the inline_html to use.
 *   - $field->wrapper_suffix: The closing tag for the wrapper.
 *   - $field->separator: an optional separator that may appear before a field.
 *   - $field->label: The wrap label text to use.
 *   - $field->label_html: The full HTML of the label to use including
 *     configured element type.
 * - $row: The raw result object from the query, with all data it fetched.
 *
 * @ingroup views_templates
 */
// dpm($fields);
?>
<div class="col-xs-9 col-sm-9">
  <p class=list-top>
    <?php print $fields['type']->wrapper_prefix; ?>
      <?php print $fields['type']->label_html; ?>
      <?php print $fields['type']->content; ?>
    <?php print $fields['type']->wrapper_suffix; ?>

    <?php print $fields['field_term']->wrapper_prefix; ?>
      <?php print $fields['field_term']->label_html; ?>
      <?php print $fields['field_term']->content; ?>
    <?php print $fields['field_term']->wrapper_suffix; ?>
    <span class='time'>
      <?php print $fields['created']->wrapper_prefix; ?>
        <?php print $fields['created']->label_html; ?>
        <?php print $fields['created']->content; ?>
      <?php print $fields['created']->wrapper_suffix; ?>
    </span>
  </p>
  <div class="title">
    <?php print $fields['title']->wrapper_prefix; ?>
      <?php print $fields['title']->label_html; ?>
      <?php print $fields['title']->content; ?>
    <?php print $fields['title']->wrapper_suffix; ?>
  </div>
  <div class=list-footer>
    <?php print $fields['comment_count']->wrapper_prefix; ?>
      <?php print $fields['comment_count']->label_html; ?>
      <?php print $fields['comment_count']->content; ?>
    <?php print $fields['comment_count']->wrapper_suffix; ?>
    · 阅读 <span class="commentcount">255</span> · 喜欢 <span class="favcount">100</span>
  </div>
</div>
<div class="col-xs-3 col-sm-3">
  <?php if($fields['field_image2']->content):?>
  <?php print $fields['field_image2']->wrapper_prefix; ?>
    <?php print $fields['field_image2']->label_html; ?>
    <?php print $fields['field_image2']->content; ?>
  <?php print $fields['field_image2']->wrapper_suffix; ?>
  <?php else:?>
  <?php print $fields['field_image']->wrapper_prefix; ?>
    <?php print $fields['field_image']->label_html; ?>
    <?php print $fields['field_image']->content; ?>
  <?php print $fields['field_image']->wrapper_suffix; ?>
  <?php endif;?>
</div>
