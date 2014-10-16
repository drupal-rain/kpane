<div class="<?php print $classes; ?>"<?php print $attributes; ?>>
  <?php if (isset($title)): ?>
    <h2><?php print $title; ?></h2>
  <?php endif; ?>
  <?php print render($posts); ?>
</div>