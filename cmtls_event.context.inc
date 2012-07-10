<?php
/**
 * @file
 * cmtls_event.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function cmtls_event_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'cmtls_event_page';
  $context->description = 'Community tools single event page';
  $context->tag = 'CT event';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'cmtls_event' => 'cmtls_event',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-cb129c8a19431ae6b2fd1711646e2de2' => array(
          'module' => 'views',
          'delta' => 'cb129c8a19431ae6b2fd1711646e2de2',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'views-d3b739be3a716e61b54f0c1254eefd60' => array(
          'module' => 'views',
          'delta' => 'd3b739be3a716e61b54f0c1254eefd60',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
        'views-53e22d565fc4333e016372c7c33e1bfc' => array(
          'module' => 'views',
          'delta' => '53e22d565fc4333e016372c7c33e1bfc',
          'region' => 'sidebar_second',
          'weight' => '-8',
        ),
        'views-0d26dd0aa81634fc961ec5e8e8191976' => array(
          'module' => 'views',
          'delta' => '0d26dd0aa81634fc961ec5e8e8191976',
          'region' => 'preface_first',
          'weight' => '-6',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('CT event');
  t('Community tools single event page');
  $export['cmtls_event_page'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'cmtls_events_page';
  $context->description = 'Community Tools events calendar';
  $context->tag = 'CT event';
  $context->conditions = array(
    'cmtls_app_type' => array(
      'values' => array(
        'cmtls_event' => 'cmtls_event',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
    'node' => array(
      'values' => array(
        'cmtls_app' => 'cmtls_app',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-3edf64118acc6553a9f6254863dbe98d' => array(
          'module' => 'views',
          'delta' => '3edf64118acc6553a9f6254863dbe98d',
          'region' => 'content',
          'weight' => '-10',
        ),
        'views-d9e168f4a7cca184af1d56e5bf3f1a03' => array(
          'module' => 'views',
          'delta' => 'd9e168f4a7cca184af1d56e5bf3f1a03',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('CT event');
  t('Community Tools events calendar');
  $export['cmtls_events_page'] = $context;

  return $export;
}
