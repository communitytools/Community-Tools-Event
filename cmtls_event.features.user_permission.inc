<?php
/**
 * @file
 * cmtls_event.features.user_permission.inc
 */

/**
 * Implementation of hook_user_default_permissions().
 */
function cmtls_event_user_default_permissions() {
  $permissions = array();

  // Exported permission: create cmtls_event content
  $permissions['create cmtls_event content'] = array(
    'name' => 'create cmtls_event content',
    'roles' => array(
      0 => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any cmtls_event content
  $permissions['delete any cmtls_event content'] = array(
    'name' => 'delete any cmtls_event content',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own cmtls_event content
  $permissions['delete own cmtls_event content'] = array(
    'name' => 'delete own cmtls_event content',
    'roles' => array(
      0 => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any cmtls_event content
  $permissions['edit any cmtls_event content'] = array(
    'name' => 'edit any cmtls_event content',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own cmtls_event content
  $permissions['edit own cmtls_event content'] = array(
    'name' => 'edit own cmtls_event content',
    'roles' => array(
      0 => 'authenticated user',
    ),
    'module' => 'node',
  );

  return $permissions;
}
