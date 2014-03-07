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

  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );

  $form['actions']['cancel'] = array(
    '#prefix' => '&nbsp; &nbsp; &nbsp;',
    '#markup' => l(t('Cancel'), 'article/' . $article_id),
  );
}

/**
 * Form to add a note.
 */
function jdt_user_notes_add_note_form($form, &$form_state, $node) {
  global $user;
  $form = array();

  if ($node) {
    $article_id = $node->nid;
  }
  else {
    $article_id = $form_state['build_info']['args'][0]->nid;
  }
  jdt_user_notes_note_form_base($form, $article_id, $user->uid, '');

  return $form;
}

/**
 * Submit add note form.
 */
function jdt_user_notes_add_note_form_submit($form, &$form_state) {
  module_load_include('inc', 'jdt_user_notes', 'jdt_user_notes.admin');
  jdt_user_notes_add_note($form_state['values']['article_id'], $form_state['values']['author_id'], $form_state['values']['note_text']);

  $form_state['ajax_commands'][] = ctools_modal_command_dismiss();
  $form_state['ajax_commands'][] = ctools_ajax_command_reload();
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

  if ($note) {
    $article_id = $note->article_nid;
    $author_id = $note->author_uid;
    $note_text = $note->note_text;
  }
  else {
    $article_id = $form_state['build_info']['args'][0]->article_nid;
    $author_id = $form_state['build_info']['args'][0]->author_uid;
    $note_text = $form_state['build_info']['args'][0]->note_text;
  }

  jdt_user_notes_note_form_base($form, $article_id, $author_id, $note_text);

  return $form;
}

/**
 * Submit edit note form.
 */
function jdt_user_notes_edit_note_form_submit($form, &$form_state) {
  module_load_include('inc', 'jdt_user_notes', 'jdt_user_notes.admin');
  jdt_user_notes_update_note($form_state['values']['note_id'], $form_state['values']['article_id'], $form_state['values']['author_id'], $form_state['values']['note_text']);

  $form_state['ajax_commands'][] = ctools_modal_command_dismiss();
  $form_state['ajax_commands'][] = ctools_ajax_command_reload();
}
