<?php

$plugin = array(
  'css' => 'posts.css',
);

function kpane_kpane_posts_bundle_info() {
  return _kpane_plugin_bundle_info('posts');
}

function kpane_kpane_posts_theme_registry($existing, $type, $theme, $path) {
  return _kpane_plugin_theme_registry('posts');
}

// @todo Consider 'access'.
function kpane_kpane_posts_template_preprocess(&$vars, $entity) {
  $settings = $entity->settings['posts'];
  switch ($settings['style']) {
    case 'media':
      $vars['classes_array'][] = 'posts-media';
      $vars['posts'] = kpane_kpane_posts_media_list($vars['kpane_posts_ref']);
      break;
    case 'thumbnail':
      $vars['classes_array'][] = 'posts-thumbnail row';
      $vars['posts'] = kpane_kpane_posts_thumbnails($vars['kpane_posts_ref']);
      break;
  }
}

function kpane_kpane_posts_settings_form($form_orig, &$form_state, $entity) {
  $form = array();

  $style_options = array(
    'media' => t('Media'),
    'thumbnail' => t('Thumbnail'),
  );
  $form['style'] = array(
    '#type' => 'select',
    '#options' => $style_options,
    '#default_value' => kpane_settings_default_value($entity, 'style', array()),
  );

  return $form;
}

function kpane_kpane_posts_reset() {
  kfield_add_field_default('entityreference', KPANE_ENTITY, 'posts', 'kpane_posts_ref', t('Posts'));
}

// =============================================================================
//

function kpane_kpane_posts_media_list($posts) {
  $output = '<ul class="media-list">';

  foreach ($posts as $post) {
    if ($post['access']) {
      $output .= kpane_kpane_posts_media($post['entity']);
    }
  }

  $output .= '</ul>';

  return $output;
}

function kpane_kpane_posts_media($post) {
  $output = '<li class="media">';

  $output .= '<a class="pull-left">';
  $vars = array(
    'style_name' => 'thumbnail',
    'path' => $post->kpost_image[LANGUAGE_NONE][0]['uri'],
    'attributes' => array(
      'class' => 'media-object',
    ),
  );
  $output .= theme('image_style', $vars);
  $output .= '</a>';

  $output .= '<div class="media-body">';

  $output .= '<h3 class="media-heading">' . $post->title . '</h3>';
  $output .= '<p>' . $post->body . '</p>';

  $output .= '</div>';

  $output .= '</li>';

  return $output;
}

function kpane_kpane_posts_thumbnails($posts) {
  $output = '';

  foreach ($posts as $post) {
    if ($post['access']) {
      $output .= kpane_kpane_posts_thumbnail($post['entity']);
    }
  }

  return $output;
}

function kpane_kpane_posts_thumbnail($post) {
  $output = '';

  $output .= '<div class="col-md-4">';

  $output .= '<div class="thumbnail">';

  kore_include('picture');
  $output .= kore_picture_theme_image($post->kpost_image[LANGUAGE_NONE][0]['uri'], 'bootstrap_3_1');

  $output .= '<div class="caption">';

  $output .= '<h3>' . $post->title . '</h3>';
  $output .= '<p>' . $post->body . '</p>';

  $output .= '</div>';

  $output .= '</div>';

  $output .= '</div>';

  return $output;
}
