<?php

/**
 * @file
 * API functions for the jdt_user_notes module.
 */

/**
 * Gets the notes with the specific article ID.
 *
 * @param int $article_id
 *   The id of the article
 *
 * @return object
 *   The notes with the specific article id
 */
function jdt_user_notes_get_notes($article_id = NULL) {
  if ($article_id == NULL) {
    $query = db_select('jdt_user_notes_article_notes', 'jun')
    ->fields('jun')
    ->extend('PagerDefault')
    ->limit(10);
    $results = $query
    ->execute()
    ->fetchAll();
  }
  else {
    $query = db_select('jdt_user_notes_article_notes', 'jun')
    ->fields('jun')
    ->condition('article_nid', $article_id)
    ->extend('PagerDefault')
    ->limit(10);
    $results = $query
    ->execute()
    ->fetchAll();
  }
  return $results;
}

/**
 * Adds a note to the table 'user_article_notes'.
 *
 * @param int $article_id
 *   The id of the article
 * @param int $author_id
 *   The user id of the author
 * @param text $note_text
 *   The text of the note
 */
function jdt_user_notes_add_note($article_id, $author_id, $note_text) {
  db_insert('jdt_user_notes_article_notes')
  ->fields(array(
    'article_nid' => $article_id,
    'author_uid' => $author_id,
    'note_text' => $note_text,
    ))
  ->execute();
}

/**
 * Update a note in the table 'user_article_notes'.
 *
 * @param int $note_id
 *   The id of the note
 * @param int $article_id
 *   The id of the article
 * @param int $author_id
 *   The user id of the author
 * @param text $note_text
 *   The text of the note
 */
function jdt_user_notes_update_note($note_id, $article_id, $author_id, $note_text) {
  db_update('jdt_user_notes_article_notes')
  ->fields(array(
    'article_nid' => $article_id,
    'author_uid' => $author_id,
    'note_text' => $note_text,
    ))
  ->condition('note_id', $note_id)
  ->execute();
}

/**
 * Delete a note in the table 'user_article_notes'.
 *
 * @param int $note_id
 *   The id of the note
 */
function jdt_user_notes_delete_note($note_id) {
  db_delete('jdt_user_notes_article_notes')
  ->condition('note_id', $note_id)
  ->execute();
}
