<?php

/**
 * @file
 * form functions for the jdt_user_notes module.
 */

/**
 * Base of a form for jdt_user_notes.
 */
function jdt_user_notes_note_form_base(&$form, $article_id, $author_id, $note_text) {
  $form['article_id'] = array(
    '#type' => 'value',
    '#value' => $article_id,
  );

  $form['author_id'] = array(
    '#type' => 'value',
    '#value' => $author_id,
  );

  $form['note_text'] = array(
    '#type' => 'textarea',
    '#title' => t('Note'),
    '#default_value' => $note_text,
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );
}

/**
 * Form to add a note.
 */
function jdt_user_notes_add_note_form($form, &$form_state, $node) {
  global $user;
  $form = array();

  jdt_user_notes_note_form_base($form, $node->nid, $user->uid, '');

  return $form;
}

/**
 * Submit add note form.
 */
function jdt_user_notes_add_note_form_submit($form, &$form_state) {
  module_load_include('inc', 'jdt_user_notes', 'jdt_user_notes.admin');
  jdt_user_notes_add_note($form_state['values']['article_id'], $form_state['values']['author_id'], $form_state['values']['note_text']);
}

/**
 * Form to edit a note.
 */
function jdt_user_notes_edit_note_form($form, &$form_state, $note) {
  $form = array();

  $form['note_id'] = array(
    '#type' => 'value',
    '#value' => $note->note_id,
  );

  jdt_user_notes_note_form_base($form, $note->article_nid, $note->author_uid, $note->note_text);

  return $form;
}

/**
 * Submit edit note form.
 */
function jdt_user_notes_edit_note_form_submit($form, &$form_state) {
  module_load_include('inc', 'jdt_user_notes', 'jdt_user_notes.admin');
  jdt_user_notes_update_note($form_state['values']['note_id'], $form_state['values']['article_id'], $form_state['values']['author_id'], $form_state['values']['note_text']);
}
