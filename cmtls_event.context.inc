<?php
/**
 * @file
 * cmtls_event.context.inc
 */

/**
 * Implementation of hook_context_default_contexts().
 */
function cmtls_event_context_default_contexts() {
  $export = array();

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'CT Event meta blocks';
  $context->description = 'Community Tools event metadata blocks';
  $context->tag = 'cmtls';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'cmtls_event' => 'cmtls_event',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-cmtls_event_date-block' => array(
          'module' => 'views',
          'delta' => 'cmtls_event_date-block',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'views-cmtls_event_location-block' => array(
          'module' => 'views',
          'delta' => 'cmtls_event_location-block',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
        'views-cmtls_event_attachments-block' => array(
          'module' => 'views',
          'delta' => 'cmtls_event_attachments-block',
          'region' => 'sidebar_second',
          'weight' => '-8',
        ),
        'views-cmtls_event_tags-block' => array(
          'module' => 'views',
          'delta' => 'cmtls_event_tags-block',
          'region' => 'sidebar_second',
          'weight' => '-7',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Community Tools event metadata blocks');
  t('cmtls');
  $export['CT Event meta blocks'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'CT Events wall';
  $context->description = 'Community Tools events calendar';
  $context->tag = 'cmtls';
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
        'views-cmtls_events_calendar-block_3' => array(
          'module' => 'views',
          'delta' => 'cmtls_events_calendar-block_3',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Community Tools events calendar');
  t('cmtls');
  $export['CT Events wall'] = $context;

  return $export;
}
