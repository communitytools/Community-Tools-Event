<?php
/**
 * @file
 * cmtls_event.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function cmtls_event_default_rules_configuration() {
  $items = array();
  $items['rules_cmtls_event_views_cache'] = entity_import('rules_config', '{ "rules_cmtls_event_views_cache" : {
      "LABEL" : "CT Event views cache",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "cmtls" ],
      "REQUIRES" : [ "rules", "cache_actions" ],
      "ON" : [ "node_insert", "node_update", "node_delete" ],
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "node" ],
            "type" : { "value" : { "cmtls_event" : "cmtls_event" } }
          }
        }
      ],
      "DO" : [
        { "cache_actions_action_clear_views_cache" : { "view" : { "value" : { "cmtls_events" : "cmtls_events" } } } }
      ]
    }
  }');
  return $items;
}
