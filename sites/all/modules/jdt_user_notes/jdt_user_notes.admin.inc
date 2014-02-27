<?php

/**
 * @file
 * API functions for the jdt_user_notes module.
 */

/**
 * Form to add a note
 */
function jdt_user_notes_add_note_form($form, &$form_state, $node) {
	global $user;
	$form = array();
	
	$form['article_id'] = array(
		'#type' => 'value',
		'#value' => $node->nid,
	);

	$form['author_id'] = array(
		'#type' => 'value',
		'#value' => $user->uid,
	);

	$form['note_text'] = array(
		'#type' => 'textfield',
		'#title' => t('Note'),
		'#maxlength' => 255,
	);

	$form['submit'] = array(
		'#type' => 'submit',
		'#value' => t('Submit'),
	);

	return $form;
}

/**
 * Submit add note form
 */
function jdt_user_notes_add_note_form_submit($form, &$form_state) {
	jdt_user_notes_add_note($form_state['values']['article_id'], $form_state['values']['author_id'], $form_state['values']['note_text']);
}

/**
 * Form to edit a note
 */
function jdt_user_notes_edit_note_form($form, &$form_state, $note) {
	$form = array();

	$form['note_id'] = array(
		'#type' => 'value',
		'#value' => $note->note_id,
	);
	
	$form['article_id'] = array(
		'#type' => 'value',
		'#value' => $note->article_nid,
	);

	$form['author_id'] = array(
		'#type' => 'value',
		'#value' => $note->author_uid,
	);

	$form['note_text'] = array(
		'#type' => 'textfield',
		'#title' => t('Note'),
		'#default_value' => $note->note_text,
		'#maxlength' => 255,
	);

	$form['submit'] = array(
		'#type' => 'submit',
		'#value' => t('Submit'),
	);

	return $form;
}

/**
 * Submit edit note form
 */
function jdt_user_notes_edit_note_form_submit($form, &$form_state) {
	jdt_user_notes_update_note($form_state['values']['note_id'], $form_state['values']['article_id'], $form_state['values']['author_id'], $form_state['values']['note_text']);
}


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
		$results = db_select('jdt_user_notes_article_notes', 'jun')
		->fields('jun')
		->execute()
		->fetchAssoc();
	}
	else {
		$results = db_select('jdt_user_notes_article_notes', 'jun')
		->fields('juc')
		->condition('article_nid', $article_id)
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
	db_insert('jdt_user_notes_article_notes')
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
 * Delete a note in the table 'user_article_notes'
 * @param $note_id
 *  The id of the note
 */
function jdt_user_notes_delete_note($note_id){
	db_delete('jdt_user_notes_article_notes')
	->condition('note_id', $note_id)
	->execute();
}



