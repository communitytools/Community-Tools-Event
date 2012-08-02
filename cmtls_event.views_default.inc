<?php
/**
 * @file
 * cmtls_event.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function cmtls_event_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'cmtls_events';
  $view->description = 'Events global page, per application calendar, archive';
  $view->tag = 'cmtls';
  $view->base_table = 'node';
  $view->human_name = 'CT Events';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Events';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'rules';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = 1;
  $handler->display->display_options['exposed_form']['options']['autosubmit_hide'] = 1;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'ds';
  $handler->display->display_options['row_options']['view_mode'] = 'cmtls_teaser';
  $handler->display->display_options['row_options']['load_comments'] = 0;
  $handler->display->display_options['row_options']['alternating'] = 0;
  $handler->display->display_options['row_options']['grouping'] = 0;
  $handler->display->display_options['row_options']['advanced'] = 0;
  $handler->display->display_options['row_options']['grouping_fieldset']['group_field'] = 'node|sticky';
  $handler->display->display_options['row_options']['default_fieldset']['view_mode'] = 'cmtls_teaser';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = FALSE;
  /* Relationship: Group membership: Node group membership */
  $handler->display->display_options['relationships']['og_membership_rel']['id'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['og_membership_rel']['field'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_rel']['required'] = 1;
  /* Relationship: Content: Application (field_cmtls_application) */
  $handler->display->display_options['relationships']['field_cmtls_application_nid']['id'] = 'field_cmtls_application_nid';
  $handler->display->display_options['relationships']['field_cmtls_application_nid']['table'] = 'field_data_field_cmtls_application';
  $handler->display->display_options['relationships']['field_cmtls_application_nid']['field'] = 'field_cmtls_application_nid';
  $handler->display->display_options['relationships']['field_cmtls_application_nid']['required'] = 1;
  $handler->display->display_options['relationships']['field_cmtls_application_nid']['delta'] = '-1';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_cmtls_event_date']['id'] = 'field_cmtls_event_date';
  $handler->display->display_options['fields']['field_cmtls_event_date']['table'] = 'field_data_field_cmtls_event_date';
  $handler->display->display_options['fields']['field_cmtls_event_date']['field'] = 'field_cmtls_event_date';
  /* Sort criterion: Content: Sticky */
  $handler->display->display_options['sorts']['sticky']['id'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['table'] = 'node';
  $handler->display->display_options['sorts']['sticky']['field'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['order'] = 'DESC';
  /* Sort criterion: Content: Date -  start date (field_cmtls_event_date) */
  $handler->display->display_options['sorts']['field_cmtls_event_date_value']['id'] = 'field_cmtls_event_date_value';
  $handler->display->display_options['sorts']['field_cmtls_event_date_value']['table'] = 'field_data_field_cmtls_event_date';
  $handler->display->display_options['sorts']['field_cmtls_event_date_value']['field'] = 'field_cmtls_event_date_value';
  /* Contextual filter: OG membership: Group gid */
  $handler->display->display_options['arguments']['group']['id'] = 'group';
  $handler->display->display_options['arguments']['group']['table'] = 'og_membership';
  $handler->display->display_options['arguments']['group']['field'] = 'group';
  $handler->display->display_options['arguments']['group']['relationship'] = 'og_membership_rel';
  $handler->display->display_options['arguments']['group']['title_enable'] = 1;
  $handler->display->display_options['arguments']['group']['title'] = 'Events for %1';
  $handler->display->display_options['arguments']['group']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['group']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['group']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['group']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['group']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['group']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['group']['not'] = 0;
  /* Contextual filter: Content: Application (field_cmtls_application) */
  $handler->display->display_options['arguments']['field_cmtls_application_nid']['id'] = 'field_cmtls_application_nid';
  $handler->display->display_options['arguments']['field_cmtls_application_nid']['table'] = 'field_data_field_cmtls_application';
  $handler->display->display_options['arguments']['field_cmtls_application_nid']['field'] = 'field_cmtls_application_nid';
  $handler->display->display_options['arguments']['field_cmtls_application_nid']['title_enable'] = 1;
  $handler->display->display_options['arguments']['field_cmtls_application_nid']['title'] = 'Events in %2 for %1';
  $handler->display->display_options['arguments']['field_cmtls_application_nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_cmtls_application_nid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_cmtls_application_nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_cmtls_application_nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_cmtls_application_nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_cmtls_application_nid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['field_cmtls_application_nid']['not'] = 0;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'cmtls_event' => 'cmtls_event',
  );

  /* Display: Global page */
  $handler = $view->new_display('page', 'Global page', 'cmtls_event_global_page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Events';
  $handler->display->display_options['display_description'] = 'Page with all events in all groups';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = FALSE;
  $handler->display->display_options['header']['area']['content'] = '<h2>Today</h2>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['header']['area']['tokenize'] = 0;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Sticky */
  $handler->display->display_options['sorts']['sticky']['id'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['table'] = 'node';
  $handler->display->display_options['sorts']['sticky']['field'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['order'] = 'DESC';
  /* Sort criterion: Content: Date -  start date (field_cmtls_event_date) */
  $handler->display->display_options['sorts']['field_cmtls_event_date_value']['id'] = 'field_cmtls_event_date_value';
  $handler->display->display_options['sorts']['field_cmtls_event_date_value']['table'] = 'field_data_field_cmtls_event_date';
  $handler->display->display_options['sorts']['field_cmtls_event_date_value']['field'] = 'field_cmtls_event_date_value';
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'cmtls_event' => 'cmtls_event',
  );
  /* Filter criterion: Content: Date -  start date (field_cmtls_event_date) */
  $handler->display->display_options['filters']['field_cmtls_event_date_value']['id'] = 'field_cmtls_event_date_value';
  $handler->display->display_options['filters']['field_cmtls_event_date_value']['table'] = 'field_data_field_cmtls_event_date';
  $handler->display->display_options['filters']['field_cmtls_event_date_value']['field'] = 'field_cmtls_event_date_value';
  $handler->display->display_options['filters']['field_cmtls_event_date_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_cmtls_event_date_value']['default_date'] = 'now';
  /* Filter criterion: Content: Date -  start date (field_cmtls_event_date) */
  $handler->display->display_options['filters']['field_cmtls_event_date_value_1']['id'] = 'field_cmtls_event_date_value_1';
  $handler->display->display_options['filters']['field_cmtls_event_date_value_1']['table'] = 'field_data_field_cmtls_event_date';
  $handler->display->display_options['filters']['field_cmtls_event_date_value_1']['field'] = 'field_cmtls_event_date_value';
  $handler->display->display_options['filters']['field_cmtls_event_date_value_1']['operator'] = '<';
  $handler->display->display_options['filters']['field_cmtls_event_date_value_1']['default_date'] = 'now + 1 day';
  $handler->display->display_options['path'] = 'cmtls/events';
  $handler->display->display_options['menu']['title'] = 'Events';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;

  /* Display: Global tomorrow attachment */
  $handler = $view->new_display('attachment', 'Global tomorrow attachment', 'cmtls_event_global_tomorrow_attachment');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Tomorrow';
  $handler->display->display_options['display_description'] = 'Events tomorrow from all groups and apps';
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['use_more_text'] = 'All upcoming events';
  $handler->display->display_options['defaults']['link_display'] = FALSE;
  $handler->display->display_options['link_display'] = 'cmtls_event_upcoming_global_page';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = FALSE;
  $handler->display->display_options['header']['area']['content'] = '<h2>Tomorrow</h2>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['header']['area']['tokenize'] = 0;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'cmtls_event' => 'cmtls_event',
  );
  /* Filter criterion: Content: Date -  start date (field_cmtls_event_date) */
  $handler->display->display_options['filters']['field_cmtls_event_date_value']['id'] = 'field_cmtls_event_date_value';
  $handler->display->display_options['filters']['field_cmtls_event_date_value']['table'] = 'field_data_field_cmtls_event_date';
  $handler->display->display_options['filters']['field_cmtls_event_date_value']['field'] = 'field_cmtls_event_date_value';
  $handler->display->display_options['filters']['field_cmtls_event_date_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_cmtls_event_date_value']['default_date'] = 'now + 1 day';
  /* Filter criterion: Content: Date -  start date (field_cmtls_event_date) */
  $handler->display->display_options['filters']['field_cmtls_event_date_value_1']['id'] = 'field_cmtls_event_date_value_1';
  $handler->display->display_options['filters']['field_cmtls_event_date_value_1']['table'] = 'field_data_field_cmtls_event_date';
  $handler->display->display_options['filters']['field_cmtls_event_date_value_1']['field'] = 'field_cmtls_event_date_value';
  $handler->display->display_options['filters']['field_cmtls_event_date_value_1']['operator'] = '<';
  $handler->display->display_options['filters']['field_cmtls_event_date_value_1']['default_date'] = 'now + 2 day';
  $handler->display->display_options['displays'] = array(
    'cmtls_event_global_page' => 'cmtls_event_global_page',
    'default' => 0,
    'cmtls_event_app_wall_block' => 0,
    'cmtls_event_content_list_block' => 0,
    'cmtls_event_upcoming_global_page' => 0,
    'cmtls_event_past_global_page' => 0,
  );
  $handler->display->display_options['attachment_position'] = 'after';
  $handler->display->display_options['inherit_pager'] = 0;
  $handler->display->display_options['render_pager'] = 0;

  /* Display: Global upcoming attachment */
  $handler = $view->new_display('attachment', 'Global upcoming attachment', 'cmtls_event_global_upcoming_attachment');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Upcoming';
  $handler->display->display_options['display_description'] = 'All global events after tomorrow';
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['use_more_text'] = 'All upcoming events';
  $handler->display->display_options['defaults']['link_display'] = FALSE;
  $handler->display->display_options['link_display'] = 'cmtls_event_upcoming_global_page';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = FALSE;
  $handler->display->display_options['header']['area']['content'] = '<h2>Upcoming</h2>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['header']['area']['tokenize'] = 0;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'cmtls_event' => 'cmtls_event',
  );
  /* Filter criterion: Content: Date -  start date (field_cmtls_event_date) */
  $handler->display->display_options['filters']['field_cmtls_event_date_value']['id'] = 'field_cmtls_event_date_value';
  $handler->display->display_options['filters']['field_cmtls_event_date_value']['table'] = 'field_data_field_cmtls_event_date';
  $handler->display->display_options['filters']['field_cmtls_event_date_value']['field'] = 'field_cmtls_event_date_value';
  $handler->display->display_options['filters']['field_cmtls_event_date_value']['operator'] = '>';
  $handler->display->display_options['filters']['field_cmtls_event_date_value']['default_date'] = 'now + 1 day';
  $handler->display->display_options['displays'] = array(
    'cmtls_event_global_page' => 'cmtls_event_global_page',
    'default' => 0,
    'cmtls_event_app_wall_block' => 0,
    'cmtls_event_content_list_block' => 0,
    'cmtls_event_upcoming_global_page' => 0,
    'cmtls_event_past_global_page' => 0,
  );
  $handler->display->display_options['attachment_position'] = 'after';
  $handler->display->display_options['inherit_pager'] = 0;
  $handler->display->display_options['render_pager'] = 0;

  /* Display: Application content calendar block */
  $handler = $view->new_display('block', 'Application content calendar block', 'cmtls_event_app_wall_block');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['display_description'] = 'All events in an application as calendar';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'date_views_pager';
  $handler->display->display_options['pager']['options']['link_format'] = 'clean';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'calendar_style';
  $handler->display->display_options['style_options']['name_size'] = '1';
  $handler->display->display_options['style_options']['mini'] = '0';
  $handler->display->display_options['style_options']['with_weekno'] = '0';
  $handler->display->display_options['style_options']['multiday_theme'] = '1';
  $handler->display->display_options['style_options']['theme_style'] = '1';
  $handler->display->display_options['style_options']['max_items'] = '0';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'calendar_entity';
  $handler->display->display_options['row_options']['colors']['calendar_colors_type'] = array(
    'cmtls_app' => '#ffffff',
    'cmtls_event' => '#ffffff',
    'cmtls_group' => '#ffffff',
    'cmtls_location' => '#ffffff',
    'cmtls_post' => '#ffffff',
  );
  $handler->display->display_options['row_options']['colors']['calendar_colors_group'] = array(
    1 => '#ffffff',
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: OG membership: Group gid */
  $handler->display->display_options['arguments']['group']['id'] = 'group';
  $handler->display->display_options['arguments']['group']['table'] = 'og_membership';
  $handler->display->display_options['arguments']['group']['field'] = 'group';
  $handler->display->display_options['arguments']['group']['relationship'] = 'og_membership_rel';
  $handler->display->display_options['arguments']['group']['default_action'] = 'default';
  $handler->display->display_options['arguments']['group']['exception']['value'] = '';
  $handler->display->display_options['arguments']['group']['default_argument_type'] = 'og_context';
  $handler->display->display_options['arguments']['group']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['group']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['group']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['group']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['group']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['group']['not'] = 0;
  /* Contextual filter: Content: Application (field_cmtls_application) */
  $handler->display->display_options['arguments']['field_cmtls_application_nid']['id'] = 'field_cmtls_application_nid';
  $handler->display->display_options['arguments']['field_cmtls_application_nid']['table'] = 'field_data_field_cmtls_application';
  $handler->display->display_options['arguments']['field_cmtls_application_nid']['field'] = 'field_cmtls_application_nid';
  $handler->display->display_options['arguments']['field_cmtls_application_nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_cmtls_application_nid']['exception']['value'] = '';
  $handler->display->display_options['arguments']['field_cmtls_application_nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['field_cmtls_application_nid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_cmtls_application_nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_cmtls_application_nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_cmtls_application_nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_cmtls_application_nid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['field_cmtls_application_nid']['not'] = 0;
  /* Contextual filter: Date: Date (node) */
  $handler->display->display_options['arguments']['date_argument']['id'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['table'] = 'node';
  $handler->display->display_options['arguments']['date_argument']['field'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['default_action'] = 'default';
  $handler->display->display_options['arguments']['date_argument']['exception']['value'] = '';
  $handler->display->display_options['arguments']['date_argument']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['date_argument']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['date_argument']['add_delta'] = 'yes';
  $handler->display->display_options['arguments']['date_argument']['date_fields'] = array(
    'field_data_field_cmtls_event_date.field_cmtls_event_date_value' => 'field_data_field_cmtls_event_date.field_cmtls_event_date_value',
    'field_data_field_cmtls_event_date.field_cmtls_event_date_value2' => 'field_data_field_cmtls_event_date.field_cmtls_event_date_value2',
  );

  /* Display: Application content list block  */
  $handler = $view->new_display('block', 'Application content list block ', 'cmtls_event_content_list_block');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Result summary */
  $handler->display->display_options['empty']['result']['id'] = 'result';
  $handler->display->display_options['empty']['result']['table'] = 'views';
  $handler->display->display_options['empty']['result']['field'] = 'result';
  $handler->display->display_options['empty']['result']['empty'] = FALSE;
  $handler->display->display_options['empty']['result']['content'] = '';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: OG membership: Group gid */
  $handler->display->display_options['arguments']['group']['id'] = 'group';
  $handler->display->display_options['arguments']['group']['table'] = 'og_membership';
  $handler->display->display_options['arguments']['group']['field'] = 'group';
  $handler->display->display_options['arguments']['group']['relationship'] = 'og_membership_rel';
  $handler->display->display_options['arguments']['group']['default_action'] = 'default';
  $handler->display->display_options['arguments']['group']['exception']['value'] = '';
  $handler->display->display_options['arguments']['group']['default_argument_type'] = 'og_context';
  $handler->display->display_options['arguments']['group']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['group']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['group']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['group']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['group']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['group']['not'] = 0;
  /* Contextual filter: Content: Application (field_cmtls_application) */
  $handler->display->display_options['arguments']['field_cmtls_application_nid']['id'] = 'field_cmtls_application_nid';
  $handler->display->display_options['arguments']['field_cmtls_application_nid']['table'] = 'field_data_field_cmtls_application';
  $handler->display->display_options['arguments']['field_cmtls_application_nid']['field'] = 'field_cmtls_application_nid';
  $handler->display->display_options['arguments']['field_cmtls_application_nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_cmtls_application_nid']['exception']['value'] = '';
  $handler->display->display_options['arguments']['field_cmtls_application_nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['field_cmtls_application_nid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_cmtls_application_nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_cmtls_application_nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_cmtls_application_nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_cmtls_application_nid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['field_cmtls_application_nid']['not'] = 0;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'cmtls_event' => 'cmtls_event',
  );
  /* Filter criterion: Content: Date -  start date (field_cmtls_event_date) */
  $handler->display->display_options['filters']['field_cmtls_event_date_value']['id'] = 'field_cmtls_event_date_value';
  $handler->display->display_options['filters']['field_cmtls_event_date_value']['table'] = 'field_data_field_cmtls_event_date';
  $handler->display->display_options['filters']['field_cmtls_event_date_value']['field'] = 'field_cmtls_event_date_value';
  $handler->display->display_options['filters']['field_cmtls_event_date_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_cmtls_event_date_value']['default_date'] = 'now';
  /* Filter criterion: Content: Date -  start date (field_cmtls_event_date) */
  $handler->display->display_options['filters']['field_cmtls_event_date_value_1']['id'] = 'field_cmtls_event_date_value_1';
  $handler->display->display_options['filters']['field_cmtls_event_date_value_1']['table'] = 'field_data_field_cmtls_event_date';
  $handler->display->display_options['filters']['field_cmtls_event_date_value_1']['field'] = 'field_cmtls_event_date_value';
  $handler->display->display_options['filters']['field_cmtls_event_date_value_1']['operator'] = '<';
  $handler->display->display_options['filters']['field_cmtls_event_date_value_1']['default_date'] = 'now + 1 day';

  /* Display: Global past events attachment */
  $handler = $view->new_display('attachment', 'Global past events attachment', 'cmtls_event_global_previous_attachment');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Previous events';
  $handler->display->display_options['display_description'] = 'All past events';
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['use_more_text'] = 'All previous events';
  $handler->display->display_options['defaults']['link_display'] = FALSE;
  $handler->display->display_options['link_display'] = 'cmtls_event_past_global_page';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = FALSE;
  $handler->display->display_options['header']['area']['content'] = '<h2>Previous</h2>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['header']['area']['tokenize'] = 0;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Sticky */
  $handler->display->display_options['sorts']['sticky']['id'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['table'] = 'node';
  $handler->display->display_options['sorts']['sticky']['field'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['order'] = 'DESC';
  /* Sort criterion: Content: Date -  start date (field_cmtls_event_date) */
  $handler->display->display_options['sorts']['field_cmtls_event_date_value']['id'] = 'field_cmtls_event_date_value';
  $handler->display->display_options['sorts']['field_cmtls_event_date_value']['table'] = 'field_data_field_cmtls_event_date';
  $handler->display->display_options['sorts']['field_cmtls_event_date_value']['field'] = 'field_cmtls_event_date_value';
  $handler->display->display_options['sorts']['field_cmtls_event_date_value']['order'] = 'DESC';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: OG membership: Group gid */
  $handler->display->display_options['arguments']['group']['id'] = 'group';
  $handler->display->display_options['arguments']['group']['table'] = 'og_membership';
  $handler->display->display_options['arguments']['group']['field'] = 'group';
  $handler->display->display_options['arguments']['group']['relationship'] = 'og_membership_rel';
  $handler->display->display_options['arguments']['group']['title_enable'] = 1;
  $handler->display->display_options['arguments']['group']['title'] = 'Past events for %1';
  $handler->display->display_options['arguments']['group']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['group']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['group']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['group']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['group']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['group']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['group']['not'] = 0;
  /* Contextual filter: Content: Application (field_cmtls_application) */
  $handler->display->display_options['arguments']['field_cmtls_application_nid']['id'] = 'field_cmtls_application_nid';
  $handler->display->display_options['arguments']['field_cmtls_application_nid']['table'] = 'field_data_field_cmtls_application';
  $handler->display->display_options['arguments']['field_cmtls_application_nid']['field'] = 'field_cmtls_application_nid';
  $handler->display->display_options['arguments']['field_cmtls_application_nid']['title_enable'] = 1;
  $handler->display->display_options['arguments']['field_cmtls_application_nid']['title'] = 'Past events in %2 for %1';
  $handler->display->display_options['arguments']['field_cmtls_application_nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_cmtls_application_nid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_cmtls_application_nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_cmtls_application_nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_cmtls_application_nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_cmtls_application_nid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['field_cmtls_application_nid']['not'] = 0;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'cmtls_event' => 'cmtls_event',
  );
  /* Filter criterion: Content: Date -  start date (field_cmtls_event_date) */
  $handler->display->display_options['filters']['field_cmtls_event_date_value']['id'] = 'field_cmtls_event_date_value';
  $handler->display->display_options['filters']['field_cmtls_event_date_value']['table'] = 'field_data_field_cmtls_event_date';
  $handler->display->display_options['filters']['field_cmtls_event_date_value']['field'] = 'field_cmtls_event_date_value';
  $handler->display->display_options['filters']['field_cmtls_event_date_value']['operator'] = '<';
  $handler->display->display_options['filters']['field_cmtls_event_date_value']['default_date'] = 'now';
  $handler->display->display_options['displays'] = array(
    'cmtls_event_global_page' => 'cmtls_event_global_page',
    'default' => 0,
    'cmtls_event_app_wall_block' => 0,
    'cmtls_event_content_list_block' => 0,
    'cmtls_event_upcoming_global_page' => 0,
    'cmtls_event_past_global_page' => 0,
  );
  $handler->display->display_options['attachment_position'] = 'after';
  $handler->display->display_options['inherit_pager'] = 0;
  $handler->display->display_options['render_pager'] = 0;

  /* Display: Global all upcoming */
  $handler = $view->new_display('page', 'Global all upcoming', 'cmtls_event_upcoming_global_page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Upcoming events';
  $handler->display->display_options['display_description'] = 'Page with all upcoming events in all groups';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Sticky */
  $handler->display->display_options['sorts']['sticky']['id'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['table'] = 'node';
  $handler->display->display_options['sorts']['sticky']['field'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['order'] = 'DESC';
  /* Sort criterion: Content: Date -  start date (field_cmtls_event_date) */
  $handler->display->display_options['sorts']['field_cmtls_event_date_value']['id'] = 'field_cmtls_event_date_value';
  $handler->display->display_options['sorts']['field_cmtls_event_date_value']['table'] = 'field_data_field_cmtls_event_date';
  $handler->display->display_options['sorts']['field_cmtls_event_date_value']['field'] = 'field_cmtls_event_date_value';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: OG membership: Group gid */
  $handler->display->display_options['arguments']['group']['id'] = 'group';
  $handler->display->display_options['arguments']['group']['table'] = 'og_membership';
  $handler->display->display_options['arguments']['group']['field'] = 'group';
  $handler->display->display_options['arguments']['group']['relationship'] = 'og_membership_rel';
  $handler->display->display_options['arguments']['group']['title_enable'] = 1;
  $handler->display->display_options['arguments']['group']['title'] = 'Upcoming events for %1';
  $handler->display->display_options['arguments']['group']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['group']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['group']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['group']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['group']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['group']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['group']['not'] = 0;
  /* Contextual filter: Content: Application (field_cmtls_application) */
  $handler->display->display_options['arguments']['field_cmtls_application_nid']['id'] = 'field_cmtls_application_nid';
  $handler->display->display_options['arguments']['field_cmtls_application_nid']['table'] = 'field_data_field_cmtls_application';
  $handler->display->display_options['arguments']['field_cmtls_application_nid']['field'] = 'field_cmtls_application_nid';
  $handler->display->display_options['arguments']['field_cmtls_application_nid']['title_enable'] = 1;
  $handler->display->display_options['arguments']['field_cmtls_application_nid']['title'] = 'Upcoming events in %2 for %1';
  $handler->display->display_options['arguments']['field_cmtls_application_nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_cmtls_application_nid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_cmtls_application_nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_cmtls_application_nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_cmtls_application_nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_cmtls_application_nid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['field_cmtls_application_nid']['not'] = 0;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'cmtls_event' => 'cmtls_event',
  );
  /* Filter criterion: Content: Date -  start date (field_cmtls_event_date) */
  $handler->display->display_options['filters']['field_cmtls_event_date_value_1']['id'] = 'field_cmtls_event_date_value_1';
  $handler->display->display_options['filters']['field_cmtls_event_date_value_1']['table'] = 'field_data_field_cmtls_event_date';
  $handler->display->display_options['filters']['field_cmtls_event_date_value_1']['field'] = 'field_cmtls_event_date_value';
  $handler->display->display_options['filters']['field_cmtls_event_date_value_1']['operator'] = '>';
  $handler->display->display_options['filters']['field_cmtls_event_date_value_1']['default_date'] = 'now + 1 day';
  $handler->display->display_options['path'] = 'cmtls/events/upcoming';
  $handler->display->display_options['menu']['title'] = 'Events';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;

  /* Display: Global all past */
  $handler = $view->new_display('page', 'Global all past', 'cmtls_event_past_global_page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Past events';
  $handler->display->display_options['display_description'] = 'Page with all past events in all groups';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Sticky */
  $handler->display->display_options['sorts']['sticky']['id'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['table'] = 'node';
  $handler->display->display_options['sorts']['sticky']['field'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['order'] = 'DESC';
  /* Sort criterion: Content: Date -  start date (field_cmtls_event_date) */
  $handler->display->display_options['sorts']['field_cmtls_event_date_value']['id'] = 'field_cmtls_event_date_value';
  $handler->display->display_options['sorts']['field_cmtls_event_date_value']['table'] = 'field_data_field_cmtls_event_date';
  $handler->display->display_options['sorts']['field_cmtls_event_date_value']['field'] = 'field_cmtls_event_date_value';
  $handler->display->display_options['sorts']['field_cmtls_event_date_value']['order'] = 'DESC';
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'cmtls_event' => 'cmtls_event',
  );
  /* Filter criterion: Content: Date -  start date (field_cmtls_event_date) */
  $handler->display->display_options['filters']['field_cmtls_event_date_value_1']['id'] = 'field_cmtls_event_date_value_1';
  $handler->display->display_options['filters']['field_cmtls_event_date_value_1']['table'] = 'field_data_field_cmtls_event_date';
  $handler->display->display_options['filters']['field_cmtls_event_date_value_1']['field'] = 'field_cmtls_event_date_value';
  $handler->display->display_options['filters']['field_cmtls_event_date_value_1']['operator'] = '<';
  $handler->display->display_options['filters']['field_cmtls_event_date_value_1']['default_date'] = 'now';
  $handler->display->display_options['path'] = 'cmtls/events/past';
  $handler->display->display_options['menu']['title'] = 'Events';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;

  /* Display: Local tomorrow attachment */
  $handler = $view->new_display('attachment', 'Local tomorrow attachment', 'cmtls_event_local_tomorrow_attachment');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Tomorrow';
  $handler->display->display_options['display_description'] = 'Events tomorrow by group or application';
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['use_more_text'] = 'All upcoming events';
  $handler->display->display_options['defaults']['link_display'] = FALSE;
  $handler->display->display_options['link_display'] = 'cmtls_event_upcoming_global_page';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = FALSE;
  $handler->display->display_options['header']['area']['content'] = '<h2>Tomorrow</h2>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['header']['area']['tokenize'] = 0;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: OG membership: Group gid */
  $handler->display->display_options['arguments']['group']['id'] = 'group';
  $handler->display->display_options['arguments']['group']['table'] = 'og_membership';
  $handler->display->display_options['arguments']['group']['field'] = 'group';
  $handler->display->display_options['arguments']['group']['relationship'] = 'og_membership_rel';
  $handler->display->display_options['arguments']['group']['default_action'] = 'default';
  $handler->display->display_options['arguments']['group']['exception']['value'] = '';
  $handler->display->display_options['arguments']['group']['default_argument_type'] = 'og_context';
  $handler->display->display_options['arguments']['group']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['group']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['group']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['group']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['group']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['group']['not'] = 0;
  /* Contextual filter: Content: Application (field_cmtls_application) */
  $handler->display->display_options['arguments']['field_cmtls_application_nid']['id'] = 'field_cmtls_application_nid';
  $handler->display->display_options['arguments']['field_cmtls_application_nid']['table'] = 'field_data_field_cmtls_application';
  $handler->display->display_options['arguments']['field_cmtls_application_nid']['field'] = 'field_cmtls_application_nid';
  $handler->display->display_options['arguments']['field_cmtls_application_nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_cmtls_application_nid']['exception']['value'] = '';
  $handler->display->display_options['arguments']['field_cmtls_application_nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['field_cmtls_application_nid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_cmtls_application_nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_cmtls_application_nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_cmtls_application_nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_cmtls_application_nid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['field_cmtls_application_nid']['not'] = 0;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'cmtls_event' => 'cmtls_event',
  );
  /* Filter criterion: Content: Date -  start date (field_cmtls_event_date) */
  $handler->display->display_options['filters']['field_cmtls_event_date_value']['id'] = 'field_cmtls_event_date_value';
  $handler->display->display_options['filters']['field_cmtls_event_date_value']['table'] = 'field_data_field_cmtls_event_date';
  $handler->display->display_options['filters']['field_cmtls_event_date_value']['field'] = 'field_cmtls_event_date_value';
  $handler->display->display_options['filters']['field_cmtls_event_date_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_cmtls_event_date_value']['default_date'] = 'now + 1 day';
  /* Filter criterion: Content: Date -  start date (field_cmtls_event_date) */
  $handler->display->display_options['filters']['field_cmtls_event_date_value_1']['id'] = 'field_cmtls_event_date_value_1';
  $handler->display->display_options['filters']['field_cmtls_event_date_value_1']['table'] = 'field_data_field_cmtls_event_date';
  $handler->display->display_options['filters']['field_cmtls_event_date_value_1']['field'] = 'field_cmtls_event_date_value';
  $handler->display->display_options['filters']['field_cmtls_event_date_value_1']['operator'] = '<';
  $handler->display->display_options['filters']['field_cmtls_event_date_value_1']['default_date'] = 'now + 2 day';
  $handler->display->display_options['displays'] = array(
    'cmtls_event_content_list_block' => 'cmtls_event_content_list_block',
    'default' => 0,
    'cmtls_event_global_page' => 0,
    'cmtls_event_app_wall_block' => 0,
    'cmtls_event_upcoming_global_page' => 0,
    'cmtls_event_past_global_page' => 0,
  );
  $handler->display->display_options['attachment_position'] = 'after';
  $handler->display->display_options['inherit_pager'] = 0;
  $handler->display->display_options['render_pager'] = 0;

  /* Display: Local upcoming attachment */
  $handler = $view->new_display('attachment', 'Local upcoming attachment', 'cmtls_event_local_upcoming_attachment');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Upcoming';
  $handler->display->display_options['display_description'] = 'Events after tomorrow by group, application';
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['use_more_text'] = 'All upcoming events';
  $handler->display->display_options['defaults']['link_display'] = FALSE;
  $handler->display->display_options['link_display'] = 'cmtls_event_upcoming_global_page';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = FALSE;
  $handler->display->display_options['header']['area']['content'] = '<h2>Upcoming</h2>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['header']['area']['tokenize'] = 0;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: OG membership: Group gid */
  $handler->display->display_options['arguments']['group']['id'] = 'group';
  $handler->display->display_options['arguments']['group']['table'] = 'og_membership';
  $handler->display->display_options['arguments']['group']['field'] = 'group';
  $handler->display->display_options['arguments']['group']['relationship'] = 'og_membership_rel';
  $handler->display->display_options['arguments']['group']['default_action'] = 'default';
  $handler->display->display_options['arguments']['group']['exception']['value'] = '';
  $handler->display->display_options['arguments']['group']['default_argument_type'] = 'og_context';
  $handler->display->display_options['arguments']['group']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['group']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['group']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['group']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['group']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['group']['not'] = 0;
  /* Contextual filter: Content: Application (field_cmtls_application) */
  $handler->display->display_options['arguments']['field_cmtls_application_nid']['id'] = 'field_cmtls_application_nid';
  $handler->display->display_options['arguments']['field_cmtls_application_nid']['table'] = 'field_data_field_cmtls_application';
  $handler->display->display_options['arguments']['field_cmtls_application_nid']['field'] = 'field_cmtls_application_nid';
  $handler->display->display_options['arguments']['field_cmtls_application_nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_cmtls_application_nid']['exception']['value'] = '';
  $handler->display->display_options['arguments']['field_cmtls_application_nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['field_cmtls_application_nid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_cmtls_application_nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_cmtls_application_nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_cmtls_application_nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_cmtls_application_nid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['field_cmtls_application_nid']['not'] = 0;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'cmtls_event' => 'cmtls_event',
  );
  /* Filter criterion: Content: Date -  start date (field_cmtls_event_date) */
  $handler->display->display_options['filters']['field_cmtls_event_date_value']['id'] = 'field_cmtls_event_date_value';
  $handler->display->display_options['filters']['field_cmtls_event_date_value']['table'] = 'field_data_field_cmtls_event_date';
  $handler->display->display_options['filters']['field_cmtls_event_date_value']['field'] = 'field_cmtls_event_date_value';
  $handler->display->display_options['filters']['field_cmtls_event_date_value']['operator'] = '>';
  $handler->display->display_options['filters']['field_cmtls_event_date_value']['default_date'] = 'now + 1 day';
  $handler->display->display_options['displays'] = array(
    'cmtls_event_content_list_block' => 'cmtls_event_content_list_block',
    'default' => 0,
    'cmtls_event_global_page' => 0,
    'cmtls_event_app_wall_block' => 0,
    'cmtls_event_upcoming_global_page' => 0,
    'cmtls_event_past_global_page' => 0,
  );
  $handler->display->display_options['attachment_position'] = 'after';
  $handler->display->display_options['inherit_pager'] = 0;
  $handler->display->display_options['render_pager'] = 0;

  /* Display: Local past events attachment */
  $handler = $view->new_display('attachment', 'Local past events attachment', 'cmtls_event_local_previous_attachment');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Previous events';
  $handler->display->display_options['display_description'] = 'Past events in a group, application';
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['use_more_text'] = 'All previous events';
  $handler->display->display_options['defaults']['link_display'] = FALSE;
  $handler->display->display_options['link_display'] = 'cmtls_event_past_global_page';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = FALSE;
  $handler->display->display_options['header']['area']['content'] = '<h2>Previous</h2>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['header']['area']['tokenize'] = 0;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Sticky */
  $handler->display->display_options['sorts']['sticky']['id'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['table'] = 'node';
  $handler->display->display_options['sorts']['sticky']['field'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['order'] = 'DESC';
  /* Sort criterion: Content: Date -  start date (field_cmtls_event_date) */
  $handler->display->display_options['sorts']['field_cmtls_event_date_value']['id'] = 'field_cmtls_event_date_value';
  $handler->display->display_options['sorts']['field_cmtls_event_date_value']['table'] = 'field_data_field_cmtls_event_date';
  $handler->display->display_options['sorts']['field_cmtls_event_date_value']['field'] = 'field_cmtls_event_date_value';
  $handler->display->display_options['sorts']['field_cmtls_event_date_value']['order'] = 'DESC';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: OG membership: Group gid */
  $handler->display->display_options['arguments']['group']['id'] = 'group';
  $handler->display->display_options['arguments']['group']['table'] = 'og_membership';
  $handler->display->display_options['arguments']['group']['field'] = 'group';
  $handler->display->display_options['arguments']['group']['relationship'] = 'og_membership_rel';
  $handler->display->display_options['arguments']['group']['default_action'] = 'default';
  $handler->display->display_options['arguments']['group']['default_argument_type'] = 'og_context';
  $handler->display->display_options['arguments']['group']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['group']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['group']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['group']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['group']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['group']['not'] = 0;
  /* Contextual filter: Content: Application (field_cmtls_application) */
  $handler->display->display_options['arguments']['field_cmtls_application_nid']['id'] = 'field_cmtls_application_nid';
  $handler->display->display_options['arguments']['field_cmtls_application_nid']['table'] = 'field_data_field_cmtls_application';
  $handler->display->display_options['arguments']['field_cmtls_application_nid']['field'] = 'field_cmtls_application_nid';
  $handler->display->display_options['arguments']['field_cmtls_application_nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_cmtls_application_nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['field_cmtls_application_nid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_cmtls_application_nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_cmtls_application_nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_cmtls_application_nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_cmtls_application_nid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['field_cmtls_application_nid']['not'] = 0;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'cmtls_event' => 'cmtls_event',
  );
  /* Filter criterion: Content: Date -  start date (field_cmtls_event_date) */
  $handler->display->display_options['filters']['field_cmtls_event_date_value']['id'] = 'field_cmtls_event_date_value';
  $handler->display->display_options['filters']['field_cmtls_event_date_value']['table'] = 'field_data_field_cmtls_event_date';
  $handler->display->display_options['filters']['field_cmtls_event_date_value']['field'] = 'field_cmtls_event_date_value';
  $handler->display->display_options['filters']['field_cmtls_event_date_value']['operator'] = '<';
  $handler->display->display_options['filters']['field_cmtls_event_date_value']['default_date'] = 'now';
  $handler->display->display_options['displays'] = array(
    'cmtls_event_content_list_block' => 'cmtls_event_content_list_block',
    'default' => 0,
    'cmtls_event_global_page' => 0,
    'cmtls_event_app_wall_block' => 0,
    'cmtls_event_upcoming_global_page' => 0,
    'cmtls_event_past_global_page' => 0,
  );
  $handler->display->display_options['attachment_position'] = 'after';
  $handler->display->display_options['inherit_pager'] = 0;
  $handler->display->display_options['render_pager'] = 0;
  $translatables['cmtls_events'] = array(
    t('Master'),
    t('Events'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('group membership'),
    t('field_cmtls_application'),
    t('Date'),
    t('All'),
    t('Events for %1'),
    t('Events in %2 for %1'),
    t('Global page'),
    t('Page with all events in all groups'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('<h2>Today</h2>'),
    t('Global tomorrow attachment'),
    t('Tomorrow'),
    t('Events tomorrow from all groups and apps'),
    t('All upcoming events'),
    t('<h2>Tomorrow</h2>'),
    t('Global upcoming attachment'),
    t('Upcoming'),
    t('All global events after tomorrow'),
    t('<h2>Upcoming</h2>'),
    t('Application content calendar block'),
    t('All events in an application as calendar'),
    t('Application content list block '),
    t('Global past events attachment'),
    t('Previous events'),
    t('All past events'),
    t('All previous events'),
    t('<h2>Previous</h2>'),
    t('Past events for %1'),
    t('Past events in %2 for %1'),
    t('Global all upcoming'),
    t('Upcoming events'),
    t('Page with all upcoming events in all groups'),
    t('Upcoming events for %1'),
    t('Upcoming events in %2 for %1'),
    t('Global all past'),
    t('Past events'),
    t('Page with all past events in all groups'),
    t('Local tomorrow attachment'),
    t('Events tomorrow by group or application'),
    t('Local upcoming attachment'),
    t('Events after tomorrow by group, application'),
    t('Local past events attachment'),
    t('Past events in a group, application'),
  );
  $export['cmtls_events'] = $view;

  return $export;
}
