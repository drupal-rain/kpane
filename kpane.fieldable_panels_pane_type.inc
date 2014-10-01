<?php
/**
 * @file
 * kpane.fieldable_panels_pane_type.inc
 */

/**
 * Implements hook_default_fieldable_panels_pane_type().
 */
function kpane_default_fieldable_panels_pane_type() {
  $export = array();

  $fieldable_panels_pane_type = new stdClass();
  $fieldable_panels_pane_type->disabled = FALSE; /* Edit this to true to make a default fieldable_panels_pane_type disabled initially */
  $fieldable_panels_pane_type->api_version = 1;
  $fieldable_panels_pane_type->name = 'pane_content';
  $fieldable_panels_pane_type->title = 'Content Pane';
  $fieldable_panels_pane_type->description = '';
  $export['pane_content'] = $fieldable_panels_pane_type;

  $fieldable_panels_pane_type = new stdClass();
  $fieldable_panels_pane_type->disabled = FALSE; /* Edit this to true to make a default fieldable_panels_pane_type disabled initially */
  $fieldable_panels_pane_type->api_version = 1;
  $fieldable_panels_pane_type->name = 'pane_dividend';
  $fieldable_panels_pane_type->title = 'Dividend Pane';
  $fieldable_panels_pane_type->description = 'Horizontal dividend.';
  $export['pane_dividend'] = $fieldable_panels_pane_type;

  $fieldable_panels_pane_type = new stdClass();
  $fieldable_panels_pane_type->disabled = FALSE; /* Edit this to true to make a default fieldable_panels_pane_type disabled initially */
  $fieldable_panels_pane_type->api_version = 1;
  $fieldable_panels_pane_type->name = 'pane_feature';
  $fieldable_panels_pane_type->title = 'Feature Pane';
  $fieldable_panels_pane_type->description = 'Display feature definition.';
  $export['pane_feature'] = $fieldable_panels_pane_type;

  $fieldable_panels_pane_type = new stdClass();
  $fieldable_panels_pane_type->disabled = FALSE; /* Edit this to true to make a default fieldable_panels_pane_type disabled initially */
  $fieldable_panels_pane_type->api_version = 1;
  $fieldable_panels_pane_type->name = 'pane_heading';
  $fieldable_panels_pane_type->title = 'Heading Pane';
  $fieldable_panels_pane_type->description = 'Show title only as heading.';
  $export['pane_heading'] = $fieldable_panels_pane_type;

  $fieldable_panels_pane_type = new stdClass();
  $fieldable_panels_pane_type->disabled = FALSE; /* Edit this to true to make a default fieldable_panels_pane_type disabled initially */
  $fieldable_panels_pane_type->api_version = 1;
  $fieldable_panels_pane_type->name = 'pane_longtext';
  $fieldable_panels_pane_type->title = 'Longtext Pane';
  $fieldable_panels_pane_type->description = '';
  $export['pane_longtext'] = $fieldable_panels_pane_type;

  $fieldable_panels_pane_type = new stdClass();
  $fieldable_panels_pane_type->disabled = FALSE; /* Edit this to true to make a default fieldable_panels_pane_type disabled initially */
  $fieldable_panels_pane_type->api_version = 1;
  $fieldable_panels_pane_type->name = 'pane_quote';
  $fieldable_panels_pane_type->title = 'Quote Pane';
  $fieldable_panels_pane_type->description = 'Display quote text.';
  $export['pane_quote'] = $fieldable_panels_pane_type;

  return $export;
}
