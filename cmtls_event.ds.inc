<?php
/**
 * @file
 * cmtls_event.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function cmtls_event_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'comment|comment_node_cmtls_event|cmtls_teaser';
  $ds_fieldsetting->entity_type = 'comment';
  $ds_fieldsetting->bundle = 'comment_node_cmtls_event';
  $ds_fieldsetting->view_mode = 'cmtls_teaser';
  $ds_fieldsetting->settings = array(
    'post_date' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'ds_post_date_short',
    ),
    'author' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'ds_user_picture' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'ds_picture_cmtls_small',
    ),
  );
  $export['comment|comment_node_cmtls_event|cmtls_teaser'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'comment|comment_node_cmtls_event|default';
  $ds_fieldsetting->entity_type = 'comment';
  $ds_fieldsetting->bundle = 'comment_node_cmtls_event';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'post_date' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'ds_post_date_short',
    ),
    'author' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'ds_user_picture' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'ds_picture_cmtls_small',
    ),
  );
  $export['comment|comment_node_cmtls_event|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|cmtls_event|cmtls_teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'cmtls_event';
  $ds_fieldsetting->view_mode = 'cmtls_teaser';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h2',
        'class' => '',
      ),
    ),
  );
  $export['node|cmtls_event|cmtls_teaser'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|cmtls_event|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'cmtls_event';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'comments' => array(
      'weight' => '40',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|cmtls_event|default'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function cmtls_event_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'comment|comment_node_cmtls_event|cmtls_teaser';
  $ds_layout->entity_type = 'comment';
  $ds_layout->bundle = 'comment_node_cmtls_event';
  $ds_layout->view_mode = 'cmtls_teaser';
  $ds_layout->layout = 'cmtls_short_4region';
  $ds_layout->settings = array(
    'hide_empty_regions' => 1,
    'hide_sidebars' => 0,
    'regions' => array(
      'left_column' => array(
        0 => 'author',
        1 => 'ds_user_picture',
      ),
      'footer' => array(
        0 => 'post_date',
      ),
      'middle' => array(
        0 => 'comment_body',
      ),
    ),
    'fields' => array(
      'author' => 'left_column',
      'ds_user_picture' => 'left_column',
      'post_date' => 'footer',
      'comment_body' => 'middle',
    ),
    'classes' => array(),
  );
  $export['comment|comment_node_cmtls_event|cmtls_teaser'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'comment|comment_node_cmtls_event|default';
  $ds_layout->entity_type = 'comment';
  $ds_layout->bundle = 'comment_node_cmtls_event';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'cmtls_short_4region';
  $ds_layout->settings = array(
    'hide_empty_regions' => 1,
    'hide_sidebars' => 0,
    'regions' => array(
      'left_column' => array(
        0 => 'ds_user_picture',
      ),
      'middle' => array(
        0 => 'author',
        1 => 'post_date',
        2 => 'comment_body',
      ),
    ),
    'fields' => array(
      'ds_user_picture' => 'left_column',
      'author' => 'middle',
      'post_date' => 'middle',
      'comment_body' => 'middle',
    ),
    'classes' => array(),
  );
  $export['comment|comment_node_cmtls_event|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|cmtls_event|cmtls_teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'cmtls_event';
  $ds_layout->view_mode = 'cmtls_teaser';
  $ds_layout->layout = 'cmtls_short_4region';
  $ds_layout->settings = array(
    'hide_empty_regions' => 1,
    'hide_sidebars' => 0,
    'regions' => array(
      'middle' => array(
        0 => 'title',
        1 => 'field_cmtls_event_date',
        2 => 'body',
      ),
      'footer' => array(
        0 => 'field_cmtls_location',
        1 => 'field_cmtls_tags',
      ),
    ),
    'fields' => array(
      'title' => 'middle',
      'field_cmtls_event_date' => 'middle',
      'body' => 'middle',
      'field_cmtls_location' => 'footer',
      'field_cmtls_tags' => 'footer',
    ),
    'classes' => array(),
  );
  $export['node|cmtls_event|cmtls_teaser'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|cmtls_event|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'cmtls_event';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'hide_empty_regions' => 1,
    'hide_sidebars' => 0,
    'regions' => array(
      'ds_content' => array(
        0 => 'field_cmtls_event_date',
        1 => 'body',
        2 => 'comments',
      ),
    ),
    'fields' => array(
      'field_cmtls_event_date' => 'ds_content',
      'body' => 'ds_content',
      'comments' => 'ds_content',
    ),
    'classes' => array(),
  );
  $export['node|cmtls_event|default'] = $ds_layout;

  return $export;
}
