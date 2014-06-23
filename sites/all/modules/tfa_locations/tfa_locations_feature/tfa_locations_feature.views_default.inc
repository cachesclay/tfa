<?php
/**
 * @file
 * tfa_locations_feature.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function tfa_locations_feature_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'tfa_locations';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'TFA Locations';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'TFA Locations';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'input_required';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['text_input_required_format'] = 'filtered_html';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '0';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_program_region',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['wrapper_class'] = 'item-list [title]';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No results match this search, please alter your query.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Relationship: Content: Taxonomy terms on node */
  $handler->display->display_options['relationships']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['relationships']['term_node_tid']['field'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['vocabularies'] = array(
    'locations' => 'locations',
    'country_regions' => 0,
    'program_types' => 0,
    'tags' => 0,
  );
  /* Field: Content: Program Image */
  $handler->display->display_options['fields']['field_program_image']['id'] = 'field_program_image';
  $handler->display->display_options['fields']['field_program_image']['table'] = 'field_data_field_program_image';
  $handler->display->display_options['fields']['field_program_image']['field'] = 'field_program_image';
  $handler->display->display_options['fields']['field_program_image']['label'] = '';
  $handler->display->display_options['fields']['field_program_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_program_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_program_image']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => '',
  );
  /* Field: Content: Program Website */
  $handler->display->display_options['fields']['field_program_website']['id'] = 'field_program_website';
  $handler->display->display_options['fields']['field_program_website']['table'] = 'field_data_field_program_website';
  $handler->display->display_options['fields']['field_program_website']['field'] = 'field_program_website';
  $handler->display->display_options['fields']['field_program_website']['label'] = '';
  $handler->display->display_options['fields']['field_program_website']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_program_website']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_program_website']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_program_website']['type'] = 'link_absolute';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = '[field_program_website]';
  $handler->display->display_options['fields']['title']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['alter']['max_length'] = '200';
  $handler->display->display_options['fields']['body']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  /* Field: Content: Program Region */
  $handler->display->display_options['fields']['field_program_region']['id'] = 'field_program_region';
  $handler->display->display_options['fields']['field_program_region']['table'] = 'field_data_field_program_region';
  $handler->display->display_options['fields']['field_program_region']['field'] = 'field_program_region';
  $handler->display->display_options['fields']['field_program_region']['label'] = '';
  $handler->display->display_options['fields']['field_program_region']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_program_region']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_program_region']['type'] = 'taxonomy_term_reference_plain';
  /* Sort criterion: Content: Program Region (field_program_region) */
  $handler->display->display_options['sorts']['field_program_region_tid']['id'] = 'field_program_region_tid';
  $handler->display->display_options['sorts']['field_program_region_tid']['table'] = 'field_data_field_program_region';
  $handler->display->display_options['sorts']['field_program_region_tid']['field'] = 'field_program_region_tid';
  $handler->display->display_options['sorts']['field_program_region_tid']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'centers' => 'centers',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Has taxonomy terms (with depth) */
  $handler->display->display_options['filters']['term_node_tid_depth']['id'] = 'term_node_tid_depth';
  $handler->display->display_options['filters']['term_node_tid_depth']['table'] = 'node';
  $handler->display->display_options['filters']['term_node_tid_depth']['field'] = 'term_node_tid_depth';
  $handler->display->display_options['filters']['term_node_tid_depth']['value'] = array(
    45 => '45',
    4 => '4',
    2 => '2',
    52 => '52',
    5 => '5',
    3 => '3',
    1 => '1',
  );
  $handler->display->display_options['filters']['term_node_tid_depth']['group'] = 1;
  $handler->display->display_options['filters']['term_node_tid_depth']['exposed'] = TRUE;
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['operator_id'] = 'term_node_tid_depth_op';
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['operator'] = 'term_node_tid_depth_op';
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['identifier'] = 'term_node_tid_depth';
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['reduce'] = TRUE;
  $handler->display->display_options['filters']['term_node_tid_depth']['type'] = 'select';
  $handler->display->display_options['filters']['term_node_tid_depth']['vocabulary'] = 'locations';
  $handler->display->display_options['filters']['term_node_tid_depth']['hierarchy'] = 1;
  $handler->display->display_options['filters']['term_node_tid_depth']['depth'] = '2';
  /* Filter criterion: Content: Program Type (field_program_type) */
  $handler->display->display_options['filters']['field_program_type_tid']['id'] = 'field_program_type_tid';
  $handler->display->display_options['filters']['field_program_type_tid']['table'] = 'field_data_field_program_type';
  $handler->display->display_options['filters']['field_program_type_tid']['field'] = 'field_program_type_tid';
  $handler->display->display_options['filters']['field_program_type_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_program_type_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_program_type_tid']['expose']['operator_id'] = 'field_program_type_tid_op';
  $handler->display->display_options['filters']['field_program_type_tid']['expose']['operator'] = 'field_program_type_tid_op';
  $handler->display->display_options['filters']['field_program_type_tid']['expose']['identifier'] = 'field_program_type_tid';
  $handler->display->display_options['filters']['field_program_type_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_program_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_program_type_tid']['vocabulary'] = 'program_types';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['path'] = 'locations';
  $export['tfa_locations'] = $view;

  return $export;
}
