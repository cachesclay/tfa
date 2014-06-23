<?php
/**
 * @file
 * tfa_locations_feature.features.inc
 */

/**
 * Implements hook_views_api().
 */
function tfa_locations_feature_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function tfa_locations_feature_node_info() {
  $items = array(
    'centers' => array(
      'name' => t('Centers'),
      'base' => 'node_content',
      'description' => t('Cetner'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
