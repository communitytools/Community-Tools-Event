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
        'cmtls-cmtls_subscribe' => array(
          'module' => 'cmtls',
          'delta' => 'cmtls_subscribe',
          'region' => 'sidebar_second',
          'weight' => '-32',
        ),
        'views-ef8d7e2b65cd38981de33986447f3e1d' => array(
          'module' => 'views',
          'delta' => 'ef8d7e2b65cd38981de33986447f3e1d',
          'region' => 'sidebar_second',
          'weight' => '-31',
        ),
        'views-d2652874c19359991568e2594c7fcb4b' => array(
          'module' => 'views',
          'delta' => 'd2652874c19359991568e2594c7fcb4b',
          'region' => 'sidebar_second',
          'weight' => NULL,
        ),
        'views-cb129c8a19431ae6b2fd1711646e2de2' => array(
          'module' => 'views',
          'delta' => 'cb129c8a19431ae6b2fd1711646e2de2',
          'region' => 'sidebar_second',
          'weight' => '-29',
        ),
        'views-d3b739be3a716e61b54f0c1254eefd60' => array(
          'module' => 'views',
          'delta' => 'd3b739be3a716e61b54f0c1254eefd60',
          'region' => 'sidebar_second',
          'weight' => '-28',
        ),
        'views-53e22d565fc4333e016372c7c33e1bfc' => array(
          'module' => 'views',
          'delta' => '53e22d565fc4333e016372c7c33e1bfc',
          'region' => 'sidebar_second',
          'weight' => '-27',
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
        'cmtls-cmtls_subscribe' => array(
          'module' => 'cmtls',
          'delta' => 'cmtls_subscribe',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'views-d9e168f4a7cca184af1d56e5bf3f1a03' => array(
          'module' => 'views',
          'delta' => 'd9e168f4a7cca184af1d56e5bf3f1a03',
          'region' => 'sidebar_first',
          'weight' => '-9',
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
