<?php

/**
 * @file
 * API functions for the jdt_user_notes module.
 */

/**
 * Gets the notes with the specific article ID
 *
 * @param $article_id
 *  The id of the article
 * @return
 *  The notes with the specific article id
 */
function jdt_user_notes_get_notes($article_id = NULL){
	if ($article_id == NULL) {
		$results = db_select('user_article_notes', 'uan')
		->fields('uac')
		->execute()
		->fetchAssoc();
	}
	else {
		$results = db_select('user_article_notes', 'uan')
		->fields('uac')
		->condition('article_nid', $article_id);
		->execute()
		->fetchAssoc();
	}
	return $results;
}

/**
 * Adds a note to the table 'user_article_notes'
 *
 * @param $article_id
 *  The id of the article
 * @param $author_id
 *  The user id of the author
 * @param $note_text
 *  The text of the note
 */
function jdt_user_notes_add_note($article_id, $author_id, $note_text){
	db_insert('user_article_notes')
	->fields(array(
		'article_nid' => $article_id,
		'author_uid' => $author_id,
		'note_text' => $note_text,
		))
	->execute();
}

/**
 * Update a note in the table 'user_article_notes'
 *
 * @param $note_id
 *  The id of the note
 * @param $article_id
 *  The id of the article
 * @param $author_id
 *  The user id of the author
 * @param $note_text
 *  The text of the note
 */
function jdt_user_notes_update_note($note_id, $article_id, $author_id, $note_text){
	db_update('user_article_notes')
	->fields(array(
		'article_nid' => $article_id,
		'author_uid' => $author_id,
		'note_text' => $note_text,
		))
	->condition('note_nid', $note_id)
	->execute();
}

/**
 * Delete a note in the table 'user_article_notes'
 * @param $note_id
 *  The id of the note
 */
function jdt_user_notes_delete_note($note_id){
	db_delete('user_article_notes')
	->condition('note_nid', $note_id)
	->execute();
}



