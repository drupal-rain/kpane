<?php

$plugin = array();

function kpane_kpane_picture_bundle_info() {
  return _kpane_kpane_bundle_info('picture');
}

function kpane_kpane_picture_theme_registry($existing, $type, $theme, $path) {
  return _kpane_kpane_theme_registry('picture');
}

function kpane_kpane_picture_template_preprocess(&$vars, $entity) {
  $settings = $entity->settings['picture'] + field_info_formatter_settings('picture');
  $vars['picture'] = field_view_field('fieldable_panels_pane', $entity,
    'field_pane_picture_image',
    array(
      'label' => 'hidden',
      'type' => 'picture',
      'settings' => $settings,
    )
  );
}

function kpane_kpane_picture_settings_form($form_orig, &$form_state, $entity) {
  $form = array();

  $field = field_info_field('image');
  $instance = field_info_instance('fieldable_panels_pane', 'field_pane_picture_image', 'picture');
  $settings = $entity->settings['picture'] + field_info_formatter_settings('picture');
  $form = picture_field_formatter_settings_picture_form($field, $instance, $settings);

  return $form;
}
