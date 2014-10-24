<?php

$plugin = array();

function kpane_kpane_whitespace_bundle_info() {
  return _kpane_plugin_bundle_info('whitespace');
}

function kpane_kpane_whitespace_theme_registry($existing, $type, $theme, $path) {
  return _kpane_plugin_theme_registry('whitespace');
}
