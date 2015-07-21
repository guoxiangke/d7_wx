<?php

/**
 * Implements HOOK_preprocess_THEME()
 * @param $variables
 */
function buildout_technologies_preprocess_page(&$vars) {
  if (isset($vars['node'])) {
    $vars['theme_hook_suggestions'][] = 'page__'. str_replace('_', '--', $vars['node']->type);
    if($vars['node']->type == 'article'){
      $wx_author = '';
      if(isset($vars['node']->field_user_name[LANGUAGE_NONE]))
        $wx_author = $vars['node']->field_user_name[LANGUAGE_NONE][0]['value'];
      $vars['wx_date'] = date('Y-m-d',$vars['node']->created);
      $term = taxonomy_term_load($vars['node']->field_term[LANGUAGE_NONE][0]['tid']);
      $term_name = $term->name;
      $vars['wx_term'] = $wx_author == '未知'?$term_name:$wx_author;
    }
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