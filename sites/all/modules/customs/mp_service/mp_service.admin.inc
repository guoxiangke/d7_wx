<?php
/**
 * wechat setting form
 */
function mp_service_settings_form(){
	global $user;
	$collapsed = FALSE;
	if(variable_get('mp_config_token_'.$user->uid, "")) $collapsed = TRUE;
  $form['config'] = array(
    '#type' => 'fieldset',
    '#title' => '接入信息',
	  '#collapsible' => TRUE,
	  '#collapsed' => $collapsed,
  );
  $form['config']['config_appname'] = array(
    '#type' => 'textfield',
    '#title' => '公众号名称',
    '#description' => '必须和公众平台一致',
    '#default_value' => variable_get('mp_config_appname_'.$user->uid, "永不止息"),
    '#required' => true,
  );
  $desc = '请登陆<a target="_blank" href="https://mp.weixin.qq.com">微信官方公众平台</a> -->开发者中心 -->启用服务器配置-->修改配置-->填写完后，再抄写到这里,提交后会得到URL地址。 URL（服务器地址）最后填写！';
  if (variable_get('mp_config_appid_'.$user->uid, "")) {
    $desc = ' URL（服务器地址）:'.url(NULL, array('absolute' => TRUE)) .'/mp_service/'.$user->uid;
  }
  $form['config']['config_appid'] = array(
    '#type' => 'textfield',
    '#title' => '开发者ID',
    '#description' => $desc,
    '#default_value' => variable_get('mp_config_appid_'.$user->uid, ""),
    '#required' => true,
  );
  $form['config']['config_appsecret'] = array(
    '#type' => 'textfield',
    '#title' => 'AppSecret(应用密钥)',
    // '#description' => 'AppSecret(应用密钥)',
    '#default_value' => variable_get('mp_config_appsecret_'.$user->uid, ""),
    '#required' => true,
  );
  $form['config']['config_token'] = array(
    '#type' => 'textfield',
    '#title' => t('WeChat Token'),
    '#attributes' => array('placeholder'=>'您可以在微信官网随意配置后copy过来！'),
    '#default_value' => variable_get('mp_config_token_'.$user->uid, ""),
    '#required' => true,
  );
  $form['config']['config_appaes'] = array(
    '#type' => 'textfield',
    '#title' => 'EncodingAESKey(消息加解密密钥)',
    // '#description' => t('Account EncodingAESKey'),
    '#default_value' => variable_get('mp_config_appaes_'.$user->uid, ""),
    '#required' => true,
  );
  $form['config']['config_certified'] = array(
    '#type' => 'checkbox',
    '#title' => '已认证',
    '#description' => '(如果您的公众号已认证，请勾选)',
    '#default_value' => variable_get('mp_config_certified_'.$user->uid, ""),
  );
  $form['config']['submit_config'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
    '#submit' => array('wechat_admin_config_submit'),
  );

  $update_menu = FALSE;
  if(variable_get('mp_config_certified_'.$user->uid, "")) $update_menu = TRUE;
  if ($update_menu) {
    $form['update_menu'] = array(
      '#type' => 'fieldset',
      '#title' => '更新菜单',
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
    );
    $form['update_menu']['submit_menu'] = array(
      '#type' => 'submit',
      '#value' => '点击更新',
      '#submit' => array('wechat_admin_update_menu_submit'),
    );
    $form['update_menu']['delete_menu'] = array(
      '#type' => 'submit',
      '#value' => '删除菜单',
      '#submit' => array('wechat_admin_delete_menu_submit'),
    );
  }
	$collapsed = FALSE;
	if(variable_get('wechat_default_message_'.$user->uid, "")) $collapsed = TRUE;
  $form['default_message'] = array(
    '#type' => 'fieldset',
    '#title' => '默认消息',
    '#collapsible' => TRUE,
    '#collapsed' => $collapsed,
  );
  $form['default_message']['default_message'] = array(
    '#type' => 'textarea',
    '#title' => '自动回复信息',
    '#description' => '如果关键词无内容时，自动回复给用户的信息',
    '#default_value' => variable_get('wechat_default_message_'.$user->uid, ""),
    '#required' => false,
    '#attributes' => array('placeholder'=>'您好，谢谢您的反馈！'),
  );
  $form['default_message']['follow_message'] = array(
    '#type' => 'textarea',
    '#title' => '关注时自动回复信息',
    '#description' => '如果不设置回复图文或其他信息',
    '#default_value' => variable_get('wechat_follow_message_'.$user->uid, ""),
    '#required' => false,
    '#attributes' => array('placeholder'=>'您好，欢迎关注我们！'),
  );
  $form['default_message']['copy_message'] = array(
    '#type' => 'textarea',
    '#title' => '附加消息头',
    // '#description' => '',
    '#default_value' => variable_get('wechat_copy_message_'.$user->uid, ""),
    '#required' => false,
    '#attributes' => array('placeholder'=>"本资源由<a href='http://wx.yongbuzhixi.com'>主内公众云</a>提供："),
  );
  $form['default_message']['foot_message'] = array(
    '#type' => 'textarea',
    '#title' => '附加消息尾',
    // '#description' => '',
    '#default_value' => variable_get('wechat_foot_message_'.$user->uid, ""),
    '#required' => false,
    '#attributes' => array('placeholder'=>"回复【】内容给我试试吧[调皮]"),
  );
  $form['default_message']['config_default_re'] = array(
    '#type' => 'textfield',
    '#title' => '自动回复资源',
    '#description' => '必须填写已开启的资源关键词，如【se】炼爱季节',
    '#default_value' => variable_get('mp_config_default_re_'.$user->uid, ""),
    '#attributes' => array('placeholder'=>'se'),
  );
  $form['default_message']['multi_message'] = array(
    '#type' => 'checkbox',
    '#title' => '开启图文回复',
    '#description' => '本功能与自动回复资源互斥！',
    '#default_value' => variable_get('wechat_multi_message_'.$user->uid, ""),
    '#required' => false,

  );
  $form['default_message']['multi_message_count'] = array(
    '#type' => 'textfield',
    '#title' => '图文数量',
    '#description' => '默认回复您当日的？篇图文+置顶的图文？+资源菜单和消息尾部<>与自动回复资源互斥！',
    '#default_value' => variable_get('wechat_multi_message_count_'.$user->uid, "1:1:1"),
    '#required' => false,
    '#attributes' => array('placeholder'=>"1:1:1"),
  );
  $form['default_message']['config_default_url'] = array(
    '#type' => 'textfield',
    '#title' => '图文关注链接',
    '#description' => '比如关于我们，或引导关注公众号官方图文链接',
    '#default_value' => variable_get('mp_config_default_url_'.$user->uid, ""),
    '#attributes' => array('placeholder'=>'http://mp.weixin.qq.com/s?__biz=***'),
  );
  $form['default_message']['submit_message'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
    '#submit' => array('wechat_admin_default_message_submit'),
  );
  // Gather information from hook_libraries_info() in enabled modules.
  foreach (module_implements('rescources_info') as $module) {
    foreach (module_invoke($module, 'rescources_info') as $machine_name => $properties) {
      $options[$properties['name']] = $properties['desc'];
    }
  }
  $form['rescources'] = array(
    '#type' => 'fieldset',
    '#title' => '资源列表',
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  $form['rescources']['rescources_info'] = array(
    '#type' => 'checkboxes',
    '#options' => $options,
    '#default_value' => variable_get('wechat_resources_'.$user->uid, array()),
    '#title' => '开启以下资源',
    '#description' => '用户回复【 】内的关键字，会得到相应的内容。',
  );
  $form['rescources']['submit_rescources'] = array(
    '#type' => 'submit',
    '#value' => t('Update'),
    '#submit' => array('wechat_admin_update_rescources_submit'),
  );
  if(0&&$user->uid==255){
    $form['lts33'] = array(
      '#type' => 'fieldset',
      '#title' => '良院同步播放',
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
    );
    $form['lts33']['jc1'] = array(
      '#type' => 'textfield',
      '#default_value' => variable_get('wechat_resources_lts33_jc1', 'vhe'),
      '#title' => '基础1',
    );
    $form['lts33']['jc2'] = array(
      '#type' => 'textfield',
      '#default_value' => variable_get('wechat_resources_lts33_jc2', 'vhe'),
      '#title' => '基础2',
    );
    $form['lts33']['bk1'] = array(
      '#type' => 'textfield',
      '#default_value' => variable_get('wechat_resources_lts33_bk1', 'vhe'),
      '#title' => '本科1',
    );
    $form['lts33']['bk2'] = array(
      '#type' => 'textfield',
      '#default_value' => variable_get('wechat_resources_lts33_bk2', 'vhe'),
      '#title' => '本科2',
    );
    $form['lts33']['js1'] = array(
      '#type' => 'textfield',
      '#default_value' => variable_get('wechat_resources_lts33_js1', 'vhe'),
      '#title' => '进深1',
    );
    $form['lts33']['js2'] = array(
      '#type' => 'textfield',
      '#default_value' => variable_get('wechat_resources_lts33_js2','vhe'),
      '#title' => '进深2',
    );
    $form['lts33']['submit_lts33'] = array(
      '#type' => 'submit',
      '#value' => t('Update'),
      '#submit' => array('wechat_admin_lts33_rescources_submit'),
    );
  }
  return $form;
}


/**
 * save config
 */
function wechat_admin_update_rescources_submit($form, &$form_state){
  global $user;
  variable_set('wechat_resources_'.$user->uid, $form_state['values']['rescources_info']);
}
function wechat_admin_lts33_rescources_submit($form, &$form_state){
  variable_set('wechat_resources_lts33_bk1', $form_state['values']['jc1']);
  variable_set('wechat_resources_lts33_bk2', $form_state['values']['jc2']);
  variable_set('wechat_resources_lts33_bk1', $form_state['values']['bk1']);
  variable_set('wechat_resources_lts33_bk2', $form_state['values']['bk2']);
  variable_set('wechat_resources_lts33_js1', $form_state['values']['js1']);
  variable_set('wechat_resources_lts33_js2', $form_state['values']['js2']);
}

/**
 * save wechat setting config
 */
function wechat_admin_config_submit($form, &$form_state){
	global $user;
  variable_set('mp_config_appname_'.$user->uid, $form_state['values']['config_appname']);
  // variable_set('mp_config_appmenuid_'.$user->uid, $form_state['values']['config_appmenuid']);
  variable_set('mp_config_token_'.$user->uid, $form_state['values']['config_token']);
  variable_set('mp_config_appid_'.$user->uid, $form_state['values']['config_appid']);
  variable_set('mp_config_appsecret_'.$user->uid, $form_state['values']['config_appsecret']);
  variable_set('mp_config_appaes_'.$user->uid, $form_state['values']['config_appaes']);
  variable_set('mp_config_certified_'.$user->uid, $form_state['values']['config_certified']);
  drupal_set_message('设置成功！您的URL（服务器地址）是：'.url(NULL, array('absolute' => TRUE)) . (variable_get('clean_url', 0) ? '' : '?q=').'mp_service/'.$user->uid, 'error', FALSE);
  drupal_set_message('请拷贝并粘贴到公众平台官网上，选择一种任意加密方式，点击提交！', 'warning', FALSE);
}

/**
 * save config
 */
function wechat_admin_default_message_submit($form, &$form_state){
	global $user;
  variable_set('wechat_default_message_'.$user->uid, $form_state['values']['default_message']);
  variable_set('wechat_follow_message_'.$user->uid, $form_state['values']['follow_message']);
  variable_set('wechat_copy_message_'.$user->uid, $form_state['values']['copy_message']);
  variable_set('wechat_foot_message_'.$user->uid, $form_state['values']['foot_message']);
  variable_set('wechat_multi_message_'.$user->uid, $form_state['values']['multi_message']);
  variable_set('wechat_multi_message_count_'.$user->uid, $form_state['values']['multi_message_count']);
  variable_set('mp_config_default_re_'.$user->uid, $form_state['values']['config_default_re']);
  variable_set('mp_config_default_url_'.$user->uid, $form_state['values']['config_default_url']);
}


/**
 * Drupal menu to wechat menu
 */
function _wechat_menu_item($subval){
  $subelement = array();
  $subelement['name'] = $subval['link']['link_title'];
  if(isset($subval['link']['options']['attributes']['wechat_type'])
      && $subval['link']['options']['attributes']['wechat_type'] == 'click'){
	  $subelement['type'] = 'click';
	  $subelement['key'] = $subval['link']['options']['attributes']['wechat_key'];
  }
  else{
    $subelement['type'] = 'view';
	  $subelement['url'] = $subval['link']['options']['attributes']['wechat_url'];
  }
  return $subelement;
}

/**
 * update wechat menu
 */
function wechat_admin_update_menu_submit($form, &$form_state){
  global $user;
  $menu_arr = _mp_new_menu($user);
  if(empty($menu_arr['button'])){
    drupal_set_message('Empty WeChat Menu', 'error');
  }
  else{
    global $user;
	  $weObj = _mp_service_init_wechat($user);
    if($weObj->createMenu($menu_arr))
  	{
      drupal_set_message(t('Update menu success.'));
  	}
  	else{
  	  drupal_set_message($weObj->errMsg.'-'.$weObj->errCode, 'error');
  	}
  }
  return;
}
function wechat_admin_delete_menu_submit($form, &$form_state){
  global $user;
  $weObj = _mp_service_init_wechat($user);
  if($weObj->deleteMenu())
  {
    drupal_set_message(t('Delete menu success.'));
  }
  else{
    drupal_set_message($weObj->errMsg.'-'.$weObj->errCode, 'error');
  }
  return;
}


function _mp_new_menu($user){
  $tid = variable_get('mp_config_appmenuid_'.$user->uid, "");
  $first_depth_terms = taxonomy_get_tree(3,$tid,1);
  $mp_menu = array();
  foreach ($first_depth_terms as $key => $term) {
    $term = taxonomy_term_load($term->tid);
    $key = $term->field_wechat_menu_url[LANGUAGE_NONE]['0']['value'];
    if (isset($term->field_wechat_menu_key[LANGUAGE_NONE]['0']['target_id'])) {
      $key = 'node'. $term->field_wechat_menu_key[LANGUAGE_NONE]['0']['target_id'];
    }
    $type = $term->field_wechat_menu_type[LANGUAGE_NONE]['0']['value'];
    $arr_key = 'key';
    if($type == 'view') $arr_key = 'url';
    $mp_menu[$term->tid] = array(
      'type' => $type,
      'name' => $term->name,
      $arr_key => $key,
      'weight' => $term->weight,
    );
  }
  $first_depth_terms = taxonomy_get_tree(3,$tid,2);
  foreach ($first_depth_terms as $key => $terms) {
    if ($terms->depth == 1) {
      $term = taxonomy_term_load($terms->tid);
      $key = $term->field_wechat_menu_url[LANGUAGE_NONE]['0']['value'];
      if (isset($term->field_wechat_menu_key[LANGUAGE_NONE]['0']['target_id'])) {
        $key = 'node'. $term->field_wechat_menu_key[LANGUAGE_NONE]['0']['target_id'];
      }
      $type = $term->field_wechat_menu_type[LANGUAGE_NONE]['0']['value'];
      $arr_key = 'key';
      if($type == 'view') $arr_key = 'url';
      $mp_menu[$terms->parents['0']]['sub_button'][]= array(
        'type' => $type,
        'name' => $term->name,
        $arr_key => $key,
      );
    }
  }
  // ksort( $mp_menu);
  $weight = array();
  foreach ($mp_menu as $key => $row)
  {
      $weight[$key] = $row['weight'];
  }
  array_multisort($weight, SORT_ASC, $mp_menu);
  // dpm( $mp_menu);


  // $new_menu = array();
  // foreach ($mp_menu as $key => $value) {
  //   $new_menu[] = $value;
  // }
  $newmenu = array(
    'button' => $mp_menu,
  );
  return $newmenu;



  $bid = 18;
  $node = node_load($bid);
  $mlid = $node->book['mlid'];//510
  $query = db_select('menu_links', 'ml', array('fetch' => PDO::FETCH_ASSOC));
  // $query->fields('ml');
  // $query->addField('ml', 'link_title', 'title');
  $query->addField('ml', 'link_path', 'path');
  $query->addField('ml', 'depth', 'depth');
  $query->addField('ml', 'mlid', 'mlid');
  $query->addField('ml', 'plid', 'plid');
  // $query->addField('ml', 'has_children', 'has_children');
  $query->condition('ml.p1',$mlid);
  $query->condition('ml.depth', 1, '!=');
  $result = $query->execute()->fetchAll();

  // dpm($result);
  $mp_menu = array();
  foreach ($result as $key => $item) {
    $nid = str_replace('node/', '', $item['path']);
    $node = node_load($nid);
    if($item['depth'] == 2){
      $mp_menu[$item['mlid']] = array(
        'type' => $node->field_wechat_menu_type[LANGUAGE_NONE]['0']['value'],
        'name' => $node->title,
        'key' => $node->field_wechat_key_url[LANGUAGE_NONE]['0']['value'],
      );
    }
    if($item['depth'] == 3){
      $mp_menu[$item['plid']]['sub_button'][]= array(
        'type' => $node->field_wechat_menu_type[LANGUAGE_NONE]['0']['value'],
        'name' => $node->title,
        'key' => $node->field_wechat_menu_url[LANGUAGE_NONE]['0']['value'],
      );
    }
  }
  $new_menu = array();
  foreach ($mp_menu as $key => $value) {
    $new_menu[] = $value;
  }
  $newmenu = array(
    'button' => $new_menu,
  );
  return $newmenu;
}



function mp_service_bind_form(){
  global $user;
  $form['config'] = array(
    '#type' => 'fieldset',
    '#title' => '绑定信息',
    '#collapsible' => TRUE,
  );
  $form['config']['config_openid'] = array(
    '#type' => 'checkbox',
    '#title' => '是否绑定',
    '#description' => '请在【微信客户端】点击下面的按钮',
    '#value' => strstr($user->init,'@wechat.bind')?1:0,
    '#attributes' =>array('disabled'=>'disabled'),
  );
  $form['config']['submit_config'] = array(
    '#type' => 'submit',
    '#value' => (strstr($user->init,'@wechat.bind')?'取消':'').'绑定',
    '#submit' => array('mp_service_bind_form_submit'),
  );
  drupal_set_message('test', 'status', FALSE);
  return $form;
}

function mp_service_bind_form_submit($form, &$form_state){
  global $user;
  if ($form_state['values']['config_openid']==1) {
    $user->init = 'unbindwechat';
    user_save($user);
    drupal_set_message('取消绑定成功！', 'status', FALSE);
    drupal_goto('user/'.$user->uid.'/wechat');
  }else{
    drupal_goto('wechat/auth/userinfo');
  }

  // variable_set('mp_config_openid_8_'.$user->uid, $form_state['values']['config_token']);
}
