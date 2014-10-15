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
    'kpane_picture_image',
    array(
      'label' => 'hidden',
      'type' => 'picture',
      'settings' => $settings,
    )
  );
}

function kpane_kpane_picture_settings_form($form_orig, &$form_state, $entity) {
  $form = array();

  $base = field_info_field('kpane_picture_image');
  $instance = field_info_instance(KPANE_ENTITY, 'kpane_picture_image', 'picture');
  $settings = isset($entity->settings['picture']) ? $entity->settings['picture'] : array();
  $settings += field_info_formatter_settings('picture');
  $form = picture_field_formatter_settings_picture_form($base, $instance, $settings);

  return $form;
}

// Reset the bundle settings
function kpane_kpane_picture_reset() {
  // @todo Hide the title property in display.

  // Fields
  $field = field_info_field('kpane_picture_image');
  if (!$field) {
    field_create_field(array(
      'field_name' => 'kpane_picture_image',
      'type' => 'image',
      'cardinality' => 1,
      'settings' => array(
        'uri_scheme' => 'public',
        'default_image' => 0,
      ),
    ));
  }
  $instance = field_info_instance('fieldable_panels_pane', 'kpane_picture_image', 'picture');
  if (!$instance) {
    field_create_instance(array(
      'field_name' => 'kpane_picture_image',
      'entity_type' => 'fieldable_panels_pane',
      'bundle' => 'picture',
      'label' => t('Image'),
      'widget' => array(
        'type' => 'media_generic',
        /*
        'settings' => array(
          'allowed_types' => array('image'),
          'allowed_schemes' => array('public'),
        ),
        */
      ),
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'type' => 'image',
          //'settings' => array(),
        ),
      ),
    ));
  }

}
