<?php
/**
 * @file
 * The primary PHP file for this theme.
 */


/**
 * Implements HOOK_preprocess_THEME()
 * @param $variables
 */
function jstheme_preprocess_page(&$vars) {
  $vars['nodeuid'] = 1;
  $vars['nodenid'] = 196;
  $count = 0;
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
      $vars['nodenid'] = $vars['node']->nid;
    // }

  }


  //https://www.drupal.org/node/1031670#comment-4838426
  // $results = rate_get_results('node', $vars['nodenid'], 1);
  // dpm($results);
  drupal_add_js(array('xdtheme' => array('ratecount' => $count,'nodenid'=>$vars['nodenid'],'nodeuid'=>$vars['nodeuid'])), 'setting');
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

function jstheme_preprocess_comment(&$variables) {
  // Let's say you want to have a custom template like comment--custom-TYPE.tpl.php
  // e.g. for an article content type, the template file will be comment--custom-article.tpl.php
  // dpm($variables);
  $variables['theme_hook_suggestions'][] = 'comment__custom_' . $variables['node']->type;
}
function jstheme_preprocess_comment_wrapper(&$variables) {
  // Let's say you want to have a custom template like comment--custom-TYPE.tpl.php
  // e.g. for an article content type, the template file will be comment--custom-article.tpl.php
  // dpm($variables);
  $variables['theme_hook_suggestions'][] = 'comment__wrapper_custom_' . $variables['node']->type;
  $node = $variables['node'];
  if($node->type=='mpwechat' && arg(0)=='gzh'){
      $variables['classes_array'][] = 'hidden';
  }
}
/*theme book links on main bookid for boot*/
function jstheme_process_book_navigation(&$variables) {
  $variables['tree'] = book_children($variables['book_link']);
}

function jstheme_preprocess_node(&$variables) {
  $node = $variables['node'];
  // if($variables['view_mode']=='full' && (isset($node->field_mp3url[LANGUAGE_NONE][0])||isset($node->field_mp3_file[LANGUAGE_NONE][0]['fid'])) ){
  //   drupal_add_css(drupal_get_path('theme', 'jstheme').'/css/fmplayer.css');
  //   drupal_add_js(drupal_get_path('theme', 'jstheme').'/js/fmplayer.min.js');
  // }
  if($variables['view_mode']=='full'){
    drupal_add_js(drupal_get_path('theme', 'jstheme').'/js/page-node-full.js');
  }

  // dpm($node);
  // Display post information only on certain node types. ON GZH view pages!!!
  if (variable_get('node_submitted_' . $node->type, TRUE)) {
    $variables['display_submitted'] = TRUE;
    $name = $variables['name'];
    if(arg(0)=='gzh' || !empty($node->field_wx_openid['und'][0]['value'])){
      // $name = l($node->name,"wxuser/$node->uid");
      $name = str_replace('/user/', '/wxuser/', $name);
    }
    $variables['submitted'] = t('Submitted by !username on !datetime', array('!username' => $name, '!datetime' => $variables['date']));
  }
  else {
    $variables['display_submitted'] = FALSE;
    $variables['submitted'] = '';
  }
}


/**
 * Process variables for user-picture.tpl.php.. ON GZH view pages!!!
 *
 * The $variables array contains the following arguments:
 * - $account: A user, node or comment object with 'name', 'uid' and 'picture'
 *   fields.
 *
 * @see user-picture.tpl.php
 */
function jstheme_preprocess_user_picture(&$variables) {
  $variables['user_picture'] = '';
  if (variable_get('user_pictures', 0)) {
    $account = $variables['account'];
    if (!empty($account->picture)) {
      // @TODO: Ideally this function would only be passed file objects, but
      // since there's a lot of legacy code that JOINs the {users} table to
      // {node} or {comments} and passes the results into this function if we
      // a numeric value in the picture field we'll assume it's a file id
      // and load it for them. Once we've got user_load_multiple() and
      // comment_load_multiple() functions the user module will be able to load
      // the picture files in mass during the object's load process.
      if (is_numeric($account->picture)) {
        $account->picture = file_load($account->picture);
      }
      if (!empty($account->picture->uri)) {
        $filepath = $account->picture->uri;
      }
    }
    elseif (variable_get('user_picture_default', '')) {
      $filepath = variable_get('user_picture_default', '');
    }
    if (isset($filepath)) {
      $alt = t("@user's picture", array('@user' => format_username($account)));
      // If the image does not have a valid Drupal scheme (for eg. HTTP),
      // don't load image styles.
      if (module_exists('image') && file_valid_uri($filepath) && $style = variable_get('user_picture_style', '')) {
        $variables['user_picture'] = theme('image_style', array('style_name' => $style, 'path' => $filepath, 'alt' => $alt, 'title' => $alt));
      }
      else {
        $variables['user_picture'] = theme('image', array('path' => $filepath, 'alt' => $alt, 'title' => $alt));
      }
      // dpm($account);
      // $account = user_load($account->uid);
      // if (!empty($account->uid) && user_access('access user profiles')) {
        // $user_link = "user/$account->uid";
        if(arg(0)=='gzh' || !empty($node->field_wx_openid['und'][0]['value'])){
          $user_link = "wxuser/$account->uid";
          $attributes = array('attributes' => array('title' => t('View user profile.')), 'html' => TRUE);
          $variables['user_picture'] = l($variables['user_picture'], $user_link, $attributes);
        }
      // }
    }
  }
}

/**
 * Preprocess function for the number_up_down template.
 */
function jstheme_preprocess_rate_template_number_up_down(&$variables) {
  extract($variables);

  $up_classes = 'glyphicon glyphicon-thumbs-up pull-left';
  $down_classes = 'glyphicon glyphicon-thumbs-down';
  if (isset($results['user_vote'])) {
    switch ($results['user_vote']) {
      case $links[0]['value']:
        $up_classes .= ' rate-voted';
        break;
      case $links[1]['value']:
        $down_classes .= ' rate-voted';
        break;
    }
  }

  $variables['up_button'] = theme('rate_button', array('text' =>'', 'href' => $links[0]['href'], 'class' => $up_classes));
  $variables['down_button'] = theme('rate_button', array('text' =>'', 'href' => $links[1]['href'], 'class' => $down_classes));
  if ($results['rating'] > 0) {
    $score = '+' . $results['rating'];
    $score_class = 'positive';
  }
  elseif ($results['rating'] < 0) {
    $score = $results['rating'];
    $score_class = 'negative';
  }
  else {
    $score = 0;
    $score_class = 'neutral';
  }
  $variables['score'] = $score;
  $variables['score_class'] = $score_class;

  $info = array();
  if ($mode == RATE_CLOSED) {
    $info[] = t('Voting is closed.');
  }
  if ($mode != RATE_COMPACT && $mode != RATE_COMPACT_DISABLED) {
    if (isset($results['user_vote'])) {
      $info[] = t('You voted \'@option\'.', array('@option' => $results['user_vote'] == 1 ? $links[0]['text'] : $links[1]['text']));
    }
  }
  $variables['info'] = implode(' ', $info);
}

function jstheme_field__field_mp3_file($vars){

  if(isset($vars['items'][0]['field_mp3_file']['und'][0]['#value'])){
    $mp3 = $vars['items'][0]['field_mp3_file']['und'][0]['#value'];
    $output = theme('field_mp3_file', array('mp3' => $mp3));

    drupal_add_css(drupal_get_path('theme', 'jstheme').'/fmplayer/fmplayer.css');
    drupal_add_js(drupal_get_path('theme', 'jstheme').'/fmplayer/jquery-ui-v1.9.2.min.js');
    drupal_add_js(drupal_get_path('theme', 'jstheme').'/fmplayer/wavesurfer.min.js');
    drupal_add_js(drupal_get_path('theme', 'jstheme').'/fmplayer/fmplayer.wave.min.js', array('type' => 'file', 'scope' => 'footer'));
    return $output;
  }
}

function jstheme_field__field_mp3url($vars){
  if(isset($vars['items'][0]['field_mp3url']['und'][0]['value']['#value'])){
    $mp3['url'] = $vars['items'][0]['field_mp3url']['und'][0]['value']['#value'];
    //TODO: if(isCDN)
    drupal_add_css(drupal_get_path('theme', 'jstheme').'/fmplayer/fmplayer.css');
    drupal_add_js(drupal_get_path('theme', 'jstheme').'/fmplayer/jquery-ui-v1.9.2.min.js');
    // drupal_add_js(drupal_get_path('theme', 'jstheme').'/fmplayer/wavesurfer.min.js');
    drupal_add_js(drupal_get_path('theme', 'jstheme').'/fmplayer/fmplayer.nowave.min.js', array('type' => 'file', 'scope' => 'footer'));
    $output = theme('field_mp3url', array('mp3' => $mp3));
    return $output;
  }
}
/**
 * Implements hook_theme().
 */
function jstheme_theme() {
  $theme_path = drupal_get_path('theme', 'jstheme');
  return array(
    'field_mp3_file' => array(
      'variables' => array('mp3' => NULL),
      'template' => 'field-mp3-file',
      'path' => $theme_path . '/templates/fields',
    ),
    'field_mp3url' => array(
      'variables' => array('mp3' => NULL),
      'template' => 'field-mp3url',
      'path' => $theme_path . '/templates/fields',
    ),
  );
}
