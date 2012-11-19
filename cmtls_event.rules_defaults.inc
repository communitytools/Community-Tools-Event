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
  $items['rules_cmtls_event_app_notifications'] = entity_import('rules_config', '{ "rules_cmtls_event_app_notifications" : {
      "LABEL" : "CT Event app notifications",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "cmtls" ],
      "REQUIRES" : [ "rules", "flag" ],
      "ON" : [ "node_insert" ],
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "node" ],
            "type" : { "value" : { "cmtls_event" : "cmtls_event" } }
          }
        }
      ],
      "DO" : [
        { "flag_fetch_users_node" : {
            "USING" : {
              "flag" : "cmtls_app_follow",
              "node" : [ "node:field-cmtls-application:0" ]
            },
            "PROVIDE" : { "users" : { "users" : "Users who flagged" } }
          }
        },
        { "entity_fetch" : {
            "USING" : { "type" : "node", "id" : [ "node:field-cmtls-application:0:nid" ] },
            "PROVIDE" : { "entity_fetched" : { "entity_fetched" : "Fetched entity" } }
          }
        },
        { "LOOP" : {
            "USING" : { "list" : [ "users" ] },
            "ITEM" : { "list_item" : "Current list item" },
            "DO" : [
              { "mail" : {
                  "to" : "\\u0022[list-item:field-cmtls-firstname] [list-item:field-cmtls-lastname]\\u0022 \\u003C[list-item:mail]\\u003E",
                  "subject" : "[site:name] has new content \\u0022[node:title]\\u0022",
                  "message" : "Hello [list-item:field-cmtls-firstname],\\r\\n\\r\\n[site:name] has new event \\u0022[node:title] ([node:field-cmtls-event-date:value])\\u0022:\\r\\n\\r\\n[node:body]\\r\\n\\r\\n[node:url]\\r\\n---\\r\\nYou can change notification settings for \\u0022[entity-fetched:title]\\u0022 at [entity-fetched:url].",
                  "language" : [ "" ]
                }
              }
            ]
          }
        }
      ]
    }
  }');
  $items['rules_cmtls_event_attending_follow'] = entity_import('rules_config', '{ "rules_cmtls_event_attending_follow" : {
      "LABEL" : "CT Event attending follow",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "cmtls" ],
      "REQUIRES" : [ "flag" ],
      "ON" : [ "flag_flagged_cmtls_event_attending" ],
      "DO" : [
        { "flag_flagnode" : {
            "flag" : "cmtls_event_follow",
            "node" : [ "flagged-node" ],
            "flagging_user" : [ "flagging-user" ],
            "permission_check" : 1
          }
        }
      ]
    }
  }');
  $items['rules_cmtls_event_follow_own_thread'] = entity_import('rules_config', '{ "rules_cmtls_event_follow_own_thread" : {
      "LABEL" : "CT Event follow own thread",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "cmtls" ],
      "REQUIRES" : [ "rules", "flag" ],
      "ON" : [ "node_insert" ],
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "node" ],
            "type" : { "value" : { "cmtls_event" : "cmtls_event" } }
          }
        }
      ],
      "DO" : [
        { "flag_flagnode" : {
            "flag" : "cmtls_event_follow",
            "node" : [ "node" ],
            "flagging_user" : [ "node:author" ],
            "permission_check" : 1
          }
        }
      ]
    }
  }');
  $items['rules_cmtls_event_thread_notifications'] = entity_import('rules_config', '{ "rules_cmtls_event_thread_notifications" : {
      "LABEL" : "CT Event thread notifications",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "cmtls" ],
      "REQUIRES" : [ "rules", "flag", "comment" ],
      "ON" : [ "comment_insert" ],
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "comment:node" ],
            "type" : { "value" : { "cmtls_event" : "cmtls_event" } }
          }
        }
      ],
      "DO" : [
        { "flag_fetch_users_node" : {
            "USING" : { "flag" : "cmtls_event_follow", "node" : [ "comment:node" ] },
            "PROVIDE" : { "users" : { "users" : "Users who flagged" } }
          }
        },
        { "LOOP" : {
            "USING" : { "list" : [ "users" ] },
            "ITEM" : { "list_item" : "Current list item" },
            "DO" : [
              { "mail" : {
                  "to" : "\\u0022[list-item:field-cmtls-firstname] [list-item:field-cmtls-lastname]\\u0022 \\u003C[list-item:mail]\\u003E",
                  "subject" : "[site:name] - [comment:author:field-cmtls-firstname] [comment:author:field-cmtls-lastname] has commented on: [comment:node]",
                  "message" : "[comment:author:field-cmtls-firstname] [comment:author:field-cmtls-lastname] commented on \\u0022[comment:node]\\u0022\\r\\n\\r\\n[comment:body]\\r\\n\\r\\n[comment:url]\\r\\n---\\r\\nYou can change notification settings for \\u0022[comment:node]\\u0022 at [comment:node:url].",
                  "language" : [ "" ]
                }
              }
            ]
          }
        },
        { "flag_flagnode" : {
            "flag" : "cmtls_event_follow",
            "node" : [ "comment:node" ],
            "flagging_user" : [ "comment:author" ],
            "permission_check" : 1
          }
        }
      ]
    }
  }');
  $items['rules_cmtls_event_views_attendees_cache'] = entity_import('rules_config', '{ "rules_cmtls_event_views_attendees_cache" : {
      "LABEL" : "CT Event views attendees cache",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "cmtls" ],
      "REQUIRES" : [ "cache_actions", "flag" ],
      "ON" : [
        "flag_flagged_cmtls_event_attending",
        "flag_unflagged_cmtls_event_attending"
      ],
      "DO" : [
        { "cache_actions_action_clear_views_cache" : { "view" : { "value" : { "cmtls_event_attendees" : "cmtls_event_attendees" } } } }
      ]
    }
  }');
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
