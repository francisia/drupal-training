<?php

/**
 * @file
 * views functions for the jdt_user_notes module.
 */

function jdt_user_notes_views_data() {
  // This example describes how to write hook_views_data() for the following
  // table:
  //
  // CREATE TABLE example_table (
//   nid INT(11) NOT NULL         COMMENT 'Primary key; refers to {node}.nid.',
//   plain_text_field VARCHAR(32) COMMENT 'Just a plain text field.',
//   numeric_field INT(11)        COMMENT 'Just a numeric field.',
//   boolean_field INT(1)         COMMENT 'Just an on/off field.',
//   timestamp_field INT(8)       COMMENT 'Just a timestamp field.',
//   PRIMARY KEY(nid)
  // );

  // First, the entry $data['example_table']['table'] describes properties of
  // the actual table – not its content.

  // The 'group' index will be used as a prefix in the UI for any of this
  // table's fields, sort criteria, etc. so it's easy to tell where they came
  // from.
  $data['jdt_user_notes_article_notes']['table']['group'] = t('jdt_user_notes');

  // Define this as a base table – a table that can be described in itself by
  // views (and not just being brought in as a relationship). In reality this
  // is not very useful for this table, as it isn't really a distinct object of
  // its own, but it makes a good example.
  $data['jdt_user_notes_article_notes']['table']['base'] = array(
    'field' => 'note_id', // This is the identifier field for the view.
    'title' => t('jdt_user_notes'),
    'help' => t('jdt_user_notes_article_notes table contains user notes related to articles.'),
    'weight' => -10,
  );

  // This table references the {node} table. The declaration below creates an
  // 'implicit' relationship to the node table, so that when 'node' is the base
  // table, the fields are automatically available.
  $data['jdt_user_notes_article_notes']['table']['join'] = array(
    // Index this array by the table name to which this table refers.
    // 'left_field' is the primary key in the referenced table.
    // 'field' is the foreign key in this table.
    'node' => array(
      'left_field' => 'nid',
      'field' => 'article_nid',
    ),
    'users' => array(
      'left_field' => 'uid',
      'field' => 'author_uid',
    ),
  );

  // Next, describe each of the individual fields in this table to Views. This
  // is done by describing $data['example_table']['FIELD_NAME']. This part of
  // the array may then have further entries:
//   - title: The label for the table field, as presented in Views.
//   - help: The description text for the table field.
//   - relationship: A description of any relationship handler for the table
//     field.
//   - field: A description of any field handler for the table field.
//   - sort: A description of any sort handler for the table field.
//   - filter: A description of any filter handler for the table field.
//   - argument: A description of any argument handler for the table field.
//   - area: A description of any handler for adding content to header,
//     footer or as no result behaviour.
  //
  // The handler descriptions are described with examples below.

  // Node ID table field.
  $data['jdt_user_notes_article_notes']['note_id'] = array(
    'title' => t('jdt_user_notes ID'),
    'help' => t('jdt_user-note identifier.'),
    // Define a relationship to the {node} table, so example_table views can
    // add a relationship to nodes. If you want to define a relationship the
    // other direction, use hook_views_data_alter(), or use the 'implicit' join
    // method described above.
    'relationship' => array(
      'base' => 'node', // The name of the table to join with.
      'base field' => 'nid', // The name of the field on the joined table.
      // 'field' => 'nid' -- see hook_views_data_alter(); not needed here.
      'handler' => 'views_handler_relationship',
      'label' => t('User Note ID'),
      'title' => t('User Note ID'),
      'help' => t('ID of the user note.'),
    ),
    'field' => array(
      'handler' => 'views_handler_field',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  $data['jdt_user_notes_article_notes']['article_nid'] = array(
    'title' => t('jdt_user_notes article ID'),
    'help' => t('Article to which this note is related.'),
    // Define a relationship to the {node} table, so example_table views can
    // add a relationship to nodes. If you want to define a relationship the
    // other direction, use hook_views_data_alter(), or use the 'implicit' join
    // method described above.
    'relationship' => array(
      'base' => 'node', // The name of the table to join with.
      'base field' => 'nid', // The name of the field on the joined table.
      // 'field' => 'nid' -- see hook_views_data_alter(); not needed here.
      'handler' => 'views_handler_relationship',
      'label' => t('Article ID'),
      'title' => t('Article ID'),
      'help' => t('Article to which the user note is related.'),
    ),
  );

  $data['jdt_user_notes_article_notes']['author_uid'] = array(
    'title' => t('jdt_user_notes author ID'),
    'help' => t('Author who created this article.'),
    // Define a relationship to the {node} table, so example_table views can
    // add a relationship to nodes. If you want to define a relationship the
    // other direction, use hook_views_data_alter(), or use the 'implicit' join
    // method described above.
    'relationship' => array(
      'base' => 'users', // The name of the table to join with.
      'base field' => 'uid', // The name of the field on the joined table.
      // 'field' => 'nid' -- see hook_views_data_alter(); not needed here.
      'handler' => 'views_handler_relationship',
      'label' => t('Author ID'),
      'title' => t('Author ID'),
      'help' => t('Author of the user note.'),
    ),
  );

  // Example plain text field.
  $data['jdt_user_notes_article_notes']['note_text'] = array(
    'title' => t('Note text'),
    'help' => t('Note text.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE, // This is use by the table display plugin.
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  return $data;
}
