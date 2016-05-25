<?php

/**
 * @file
 * The PHP page that serves all page requests on a Drupal installation.
 *
 * The routines here dispatch control to the appropriate handler, which then
 * prints the appropriate page.
 *
 * All Drupal code is released under the GNU General Public License.
 * See COPYRIGHT.txt and LICENSE.txt.
 */

/**
 * Root directory of Drupal installation.
 */
define('DRUPAL_ROOT', getcwd());

require_once DRUPAL_ROOT . '/includes/bootstrap.inc';
drupal_bootstrap(DRUPAL_BOOTSTRAP_FULL);
//menu_execute_active_handler();
// echo 'begin <br/><pre>';
$caches =  cache_get_like('ga_push_event_');
if($caches)
foreach ($caches as $key=>$cache) {
    // echo $key.'<br/>';
    // print_r($cache);
    $data = drupal_json_decode($cache->data);
    // print_r($data);
    ga_push_add_event($data);
    cache_set($key, '', 'cache',  time() - 86400);
    // break ;
}
// $data = array(
//     'category'        => 'test6',
//     'action'          => 'test6',
//     'label'           => 'wxservice_',
//     'value'           => 'test',
// );
// ga_push_add_event($data);
// echo 'end';
drupal_exit();
