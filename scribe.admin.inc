<?php
/**
 *  @file
 *  scribe.admin.inc
 *
 *  @author blazey http://drupal.org/user/353861
 */

/**
 *  Settings form.
 */
function scribe_settings_form() {
  $form['scribe_enabled'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable Scribe logging'),
    '#description' => t('Make sure your server settings are ok before setting this at !test_link.',
            array('!test_link' => l(t('test link'), 'scribe-test'))),
    '#default_value' => variable_get('scribe_enabled', 0),
  );
  $form['scribe_category'] = array(
    '#type' => 'textfield',
    '#title' => t('Site messages category'),
    '#default_value' => variable_get('scribe_category', variable_get('site_name', 'Drupal')),
  );
  $form['server'] = array(
    '#type' => 'fieldset',
    '#title' => t('Server settings'),
    '#collapsible' => FALSE,
    '#collapsed' => FALSE,
  );
  $form['server']['scribe_hostname'] = array(
    '#type' => 'textfield',
    '#title' => t('Hostname or ip address'),
    '#default_value' => variable_get('scribe_hostname', 'localhost'),
    '#required' => FALSE,
  );
  $form['server']['scribe_port'] = array(
    '#type' => 'textfield',
    '#title' => t('Port'),
    '#default_value' => variable_get('scribe_port', 1463),
  );

  return system_settings_form($form);
}