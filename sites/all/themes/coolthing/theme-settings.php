<?php
/**
 * @file
 * Theme settings file
 */

/**
 * Implements hook_form_system_theme_settings_alter().
 */
function coolthing_form_system_theme_settings_alter(&$form, $form_state, $form_id = NULL) {
  // Work-around for a core bug affecting admin themes. See issue #943212.
  if (isset($form_id)) {
    return;
  }

  $form['coolthing'] = array(
    '#type' => 'fieldset',
    '#title' => t('coolthing'),
  );
  $form['coolthing']['coolthing_inline_field_descriptions'] = array(
    '#type' => 'checkbox',
    '#title' => t('Display form field descriptions inline.'),
    '#description' => t("By default, each field's description is displayed in a pop-up, which is only visible when hovering over that field. Select this option to make all field descriptions visible at all times."),
    '#default_value' => theme_get_setting('coolthing_inline_field_descriptions', 'coolthing'),
  );
}
