<?php

$plugin = array();

function kpane_kpane_heading_bundle_info() {
  return array(
    'label' => t('Heading'),
    'pane category' => t('Kpane'),
    'pane top level' => FALSE, // set to true to make this show as a top level icon
    //'pane icon' => '/path/to/custom/icon/for/this/pane.png',
    'admin' => array(
      'path' => 'admin/structure/fieldable-panels-panes/manage/%fieldable_panels_pane_type',
      'bundle argument' => 4,
      'real path' => 'admin/structure/fieldable-panels-panes/manage/heading',
      'access arguments' => array('administer fieldable panels panes'),
    ),
  );
}

function kpane_kpane_heading_theme_registry($existing, $type, $theme, $path) {
  $plugin = kpane_kpane_get_plugins('heading');
  $registry = array();
  $registry['fieldable_panels_pane__heading'] = array (
    'base hook' => 'fieldable_panels_pane',
    'render element' => 'elements',
    'path' => $plugin['path'],
    'template' => 'heading',
  );

  return $registry;
}

function kpane_kpane_heading_template_preprocess(&$vars) {

}

function kpane_kpane_heading_settings_form(&$form, &$form_state) {

}
