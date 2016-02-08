<?php
/**
 * @file
 * The primary PHP file for this theme.
 */


/**
 * Implements HOOK_preprocess_THEME()
 * @param $variables
 */
function xdtheme_preprocess_page(&$vars) {
  $vars['nodeuid'] = 1;
  if (isset($vars['node'])) {
    $vars['theme_hook_suggestions'][] = 'page__'. str_replace('_', '--', $vars['node']->type);
    // if($vars['node']->type == 'article' || $vars['node']->type == 'fm77' ){
      $wx_author = '';
      if(isset($vars['node']->field_user_name[LANGUAGE_NONE]))
        $wx_author = $vars['node']->field_user_name[LANGUAGE_NONE][0]['value'];
      $vars['wx_date'] = date('Y-m-d',$vars['node']->created);
      if($vars['node']->type == 'article'){
        $term = taxonomy_term_load($vars['node']->field_term[LANGUAGE_NONE][0]['tid']);
        $term_name = $term->name;
      }
      $vars['wx_term'] = $wx_author == '未知'?$term_name:$wx_author;
      $vars['nodeuid'] = $vars['node']->uid;
    // }
  }
}
/**
* Previous / Next function for nodes, ordered by node creation date
*
* @param $current_node: node object or node id
* @param $node_types:  array of node types to query
*
* @return array
* 
*/
function dale_prev_next_node($current_node = NULL, $node_types = array()) {
    // make node object if only node id given
    if (!is_object($current_node)) { $current_node = node_load($current_node->nid); }

    // make an array if string value was given
    if (!is_array($node_types)) { $node_types = array($node_types); }

    // previous
    $prev = db_select('node', 'n')
    ->fields('n',array('nid','title','created'))
    ->condition('n.status', 1,'=')
    ->condition('n.type', $node_types,'IN')
    ->condition('n.created', $current_node->created,'<')
    ->orderBy('created','DESC')
    ->range(0,1)
    ->execute()
    ->fetchAssoc();

    // next or false if none
    $next = db_select('node', 'n')
    ->fields('n',array('nid','title','created'))
    ->condition('n.status', 1,'=')
    ->condition('n.type', $node_types,'IN')
    ->condition('n.created', $current_node->created,'>')
    ->orderBy('created','ASC')
    ->range(0,1)
    ->execute()
    ->fetchAssoc();

    return array('prev' => $prev, 'next' => $next);
}

function xdtheme_preprocess_comment(&$variables) {
  // Let's say you want to have a custom template like comment--custom-TYPE.tpl.php
  // e.g. for an article content type, the template file will be comment--custom-article.tpl.php
  // dpm($variables);
  $variables['theme_hook_suggestions'][] = 'comment__custom_' . $variables['node']->type;
}
function xdtheme_preprocess_comment_wrapper(&$variables) {
  // Let's say you want to have a custom template like comment--custom-TYPE.tpl.php
  // e.g. for an article content type, the template file will be comment--custom-article.tpl.php
  // dpm($variables);
  $variables['theme_hook_suggestions'][] = 'comment__wrapper_custom_' . $variables['node']->type;
}