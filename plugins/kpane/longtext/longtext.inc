<?php

$plugin = array();

function kpane_kpane_longtext_bundle_info() {
  return _kpane_kpane_bundle_info('longtext');
}

function kpane_kpane_longtext_theme_registry($existing, $type, $theme, $path) {
  return _kpane_kpane_theme_registry('longtext');
}

// @todo Not just initiate function.
function kpane_kpane_longtext_reset() {
  // Field 'kpane_longtext'
  ctools_include('text', 'kfield');
  kfield_text_add_longtext_default('fieldable_panels_pane', 'longtext', 'kpane_longtext', t('Longtext'));
  $instance = field_info_instance('fieldable_panels_pane', 'kpane_longtext', 'longtext');
  $instance['settings']['text_processing'] = TRUE;
  $instance['display']['default']['label'] = 'hidden';
  field_update_instance($instance);
  $field_bundle_settings = field_bundle_settings('fieldable_panels_pane', 'longtext');
  $field_bundle_settings['extra_fields']['display']['title']['default']['visible'] = FALSE;
  field_bundle_settings('fieldable_panels_pane', 'longtext', $field_bundle_settings);
}
