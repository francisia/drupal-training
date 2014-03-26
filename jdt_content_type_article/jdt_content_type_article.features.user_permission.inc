<?php
/**
 * @file
 * jdt_content_type_article.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function jdt_content_type_article_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'add note'.
  $permissions['add note'] = array(
    'name' => 'add note',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'jdt_user_notes',
  );

  // Exported permission: 'delete note'.
  $permissions['delete note'] = array(
    'name' => 'delete note',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'jdt_user_notes',
  );

  // Exported permission: 'edit note'.
  $permissions['edit note'] = array(
    'name' => 'edit note',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'jdt_user_notes',
  );

  // Exported permission: 'view notes'.
  $permissions['view notes'] = array(
    'name' => 'view notes',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'jdt_user_notes',
  );

  return $permissions;
}
