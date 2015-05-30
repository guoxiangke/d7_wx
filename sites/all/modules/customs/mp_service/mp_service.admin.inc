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
    '#title' => t('WeChat Config'),
	  '#collapsible' => TRUE,
	  '#collapsed' => $collapsed,
  );
  $form['config']['config_token'] = array(
    '#type' => 'textfield',
    '#title' => t('WeChat Token'),
    '#description' => t('WeChat Account Token'),
    '#default_value' => variable_get('mp_config_token_'.$user->uid, ""),
    '#required' => true,
  );
  $form['config']['config_appid'] = array(
    '#type' => 'textfield',
    '#title' => t('AppID'),
    '#description' => t('Account APPID'),
    '#default_value' => variable_get('mp_config_appid_'.$user->uid, ""),
    '#required' => true,
  );
  $form['config']['config_appsecret'] = array(
    '#type' => 'textfield',
    '#title' => t('AppSecret'),
    '#description' => t('Account AppSecret'),
    '#default_value' => variable_get('mp_config_appsecret_'.$user->uid, ""),
    '#required' => true,
  );
  $form['config']['config_appaes'] = array(
    '#type' => 'textfield',
    '#title' => t('EncodingAESKey'),
    '#description' => t('Account EncodingAESKey'),
    '#default_value' => variable_get('mp_config_appaes_'.$user->uid, ""),
    '#required' => true,
  );
  $form['config']['submit_config'] = array(
    '#type' => 'submit',
    '#value' => t('save'),
    '#submit' => array('wechat_admin_config_submit'),
  );

	$collapsed = FALSE;
	if(variable_get('wechat_default_message_'.$user->uid, "")) $collapsed = TRUE;
  $form['default_message'] = array(
    '#type' => 'fieldset',
    '#title' => t('Auto reply'),
    '#collapsible' => TRUE,
    '#collapsed' => $collapsed,
  );
  $form['default_message']['default_message'] = array(
    '#type' => 'textarea',
    '#title' => t('Auto reply message'),
    '#description' => t('The WeChat module will send this message to user if no other Modules '),
    '#default_value' => variable_get('wechat_default_message_'.$user->uid, "hello, I'm wechat"),
    '#required' => true,
  );
  $form['default_message']['follow_message'] = array(
    '#type' => 'textarea',
    '#title' => t('Auto reply message after follow.'),
    '#description' => '',
    '#default_value' => variable_get('wechat_follow_message_'.$user->uid, "hello, I'm wechat"),
    '#required' => false,
  );
  $form['default_message']['submit_message'] = array(
    '#type' => 'submit',
    '#value' => t('Save Message'),
    '#submit' => array('wechat_admin_default_message_submit'),
  );
  $form['update_menu'] = array(
    '#type' => 'fieldset',
    '#title' => t('Update Wechat Menu'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  $form['update_menu']['submit_menu'] = array(
    '#type' => 'submit',
    '#value' => t('Update Menu'),
    '#submit' => array('wechat_admin_update_menu_submit'),
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
  );
  $form['rescources']['submit_rescources'] = array(
    '#type' => 'submit',
    '#value' => t('Update'),
    '#submit' => array('wechat_admin_update_rescources_submit'),
  );
  return $form;
}


/**
 * save config
 */
function wechat_admin_update_rescources_submit($form, &$form_state){
  global $user;
  variable_set('wechat_resources_'.$user->uid, $form_state['values']['rescources_info']);
}


/**
 * save wechat setting config
 */
function wechat_admin_config_submit($form, &$form_state){
	global $user;
  variable_set('mp_config_token_'.$user->uid, $form_state['values']['config_token']);
  variable_set('mp_config_appid_'.$user->uid, $form_state['values']['config_appid']);
  variable_set('mp_config_appsecret_'.$user->uid, $form_state['values']['config_appsecret']);
  variable_set('mp_config_appaes_'.$user->uid, $form_state['values']['config_appaes']);

}

/**
 * save config
 */
function wechat_admin_default_message_submit($form, &$form_state){
	global $user;
  variable_set('wechat_default_message_'.$user->uid, $form_state['values']['default_message']);
  variable_set('wechat_follow_message_'.$user->uid, $form_state['values']['follow_message']);
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
  $menu_arr = _mp_new_menu();
  if(empty($menu_arr['button'])){
    drupal_set_message('Empty WeChat Menu', 'error');
  }
  else{
	  $weObj = _mp_service_init_wechat($account);
    if($weObj->createMenu($menu_arr))
  	{
      drupal_set_message('Update menu success.');
  	}
  	else{
  	  drupal_set_message($weObj->errMsg.'-'.$weObj->errCode, 'error');
  	}
  }
  return;
}



function _mp_new_menu(){
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
        'type' => $node->field_wechate_menu_type[LANGUAGE_NONE]['0']['value'],
        'name' => $node->title,
        'key' => $node->field_wechat_key_url[LANGUAGE_NONE]['0']['value'],
      );
    }       
    if($item['depth'] == 3){
      $mp_menu[$item['plid']]['sub_button'][]= array(
        'type' => $node->field_wechate_menu_type[LANGUAGE_NONE]['0']['value'],
        'name' => $node->title,
        'key' => $node->field_wechat_key_url[LANGUAGE_NONE]['0']['value'],
      );
    }
  }
  $newmenu = array(
    'button' => $mp_menu,
  );
      return $newmenu;   
}