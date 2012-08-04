<?php
/**
 * @file
 * cmtls_event.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function cmtls_event_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  list($module, $api) = func_get_args();
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function cmtls_event_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_flag_default_flags().
 */
function cmtls_event_flag_default_flags() {
  $flags = array();
  // Exported flag: "Attending".
  $flags['cmtls_event_attending'] = array(
    'content_type' => 'node',
    'title' => 'Attending',
    'global' => '0',
    'types' => array(
      0 => 'cmtls_event',
    ),
    'flag_short' => 'Going',
    'flag_long' => 'Mark me as attending.',
    'flag_message' => 'You are now marked as attending.',
    'unflag_short' => 'Not going',
    'unflag_long' => 'Mark me as not attending.',
    'unflag_message' => 'You are no longer marked as attending.',
    'unflag_denied_text' => '',
    'link_type' => 'normal',
    'roles' => array(
      'flag' => array(
        0 => '2',
        1 => '3',
      ),
      'unflag' => array(
        0 => '2',
        1 => '3',
      ),
    ),
    'weight' => 0,
    'show_on_page' => 1,
    'show_on_teaser' => 1,
    'show_on_form' => 0,
    'show_contextual_link' => FALSE,
    'access_author' => '',
    'i18n' => 0,
    'module' => 'cmtls_event',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 2,
  );
  // Exported flag: "Follow".
  $flags['cmtls_event_follow'] = array(
    'content_type' => 'node',
    'title' => 'Follow',
    'global' => '0',
    'types' => array(
      0 => 'cmtls_event',
    ),
    'flag_short' => 'Follow',
    'flag_long' => 'Subscribe to [node:title]',
    'flag_message' => 'You are now subscribed to [node:title]',
    'unflag_short' => 'Unfollow',
    'unflag_long' => 'Unsubscribe from [node:title]',
    'unflag_message' => 'You are now unsubscribed from [node:title]',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'roles' => array(
      'flag' => array(
        0 => '2',
        1 => '3',
      ),
      'unflag' => array(
        0 => '2',
        1 => '3',
      ),
    ),
    'weight' => 0,
    'show_on_page' => 1,
    'show_on_teaser' => 0,
    'show_on_form' => 1,
    'show_contextual_link' => FALSE,
    'access_author' => '',
    'i18n' => 0,
    'module' => 'cmtls_event',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 2,
  );
  return $flags;
}

/**
 * Implements hook_node_info().
 */
function cmtls_event_node_info() {
  $items = array(
    'cmtls_event' => array(
      'name' => t('Event'),
      'base' => 'node_content',
      'description' => t('Event in Community Tools groups'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
