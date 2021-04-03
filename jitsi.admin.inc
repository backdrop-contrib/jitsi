<?php
/**
 * @file
 * Admin settings form for Jitsi Meet integration.
 */

function jitsi_admin_form() {
  $form = array();
  $config = config('jitsi.settings');
  $form['domain'] = array(
    '#type' => 'textfield',
    '#title' => t('Domain'),
    '#description' => t('If you have installed Jitsi Meet on your own server you can specify here. Default: %domain', array('%domain' => 'meet.jit.si')),
    '#default_value' => $config->get('domain'),
  );

  $form['actions']['#type'] = 'actions';
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save configuration'),
  );

  return $form;
}

/**
 * Submit handler for jitsi_admin_form().
 */
function jitsi_admin_form_submit($form, &$form_state) {
  $config = config('jitsi.settings');
  $values = $form_state['values'];
  if (!empty($values['domain'])) {
    $config->set('domain', $values['domain']);
  }
  else {
    $config->set('domain', 'meet.jit.si');
  }
  $config->save();
  backdrop_set_message(t('Jitsi settings have been saved.'));
}
