<?php

$plugin = array();

function kpane_kpane_picture_bundle_info() {
  return _kpane_plugin_bundle_info('picture');
}

function kpane_kpane_picture_theme_registry($existing, $type, $theme, $path) {
  return _kpane_plugin_theme_registry('picture');
}

function kpane_kpane_picture_template_preprocess(&$vars, $entity) {
  $vars['picture'] = kpane_picture_template_variable($entity, 'kpane_picture_image', 'picture');
}

function kpane_kpane_picture_settings_form($form_orig, &$form_state, $entity) {
  $form = array();

  $form['picture'] = kpane_picture_settings_form($entity, 'kpane_picture_image', 'picture');

  return $form;
}

// Reset the bundle settings
function kpane_kpane_picture_reset() {
  kfield_add_field_custom('image', KPANE_ENTITY, 'picture', 'kpane_picture_image', t('Picture'));
  kpane_hide_title('picture');
}
