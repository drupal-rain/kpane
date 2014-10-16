<div class="<?php print $classes; ?> row vertical-align" <?php print $attributes; ?>>
  <div class="feature-main col-md-<?php print kalatheme_grid_size(KALATHEME_GRID_THIRD) * 2; ?>">
    <h2 class="feature-title">
      <?php print $title; ?>
    </h2>
    <div class="feature-intro">
      <?php print render($intro); ?>
    </div>
    <div class="feature-items-first col-md-<?php print kalatheme_grid_size(KALATHEME_GRID_HALF); ?>">
      <?php print $items_first; ?>
    </div>
    <div class="feature-items-second col-md-<?php print kalatheme_grid_size(KALATHEME_GRID_HALF); ?>">
      <?php print $items_second; ?>
    </div>
  </div>
  <div class="feature-picture col-md-<?php print kalatheme_grid_size(KALATHEME_GRID_THIRD); ?>">
    <?php print render($picture); ?>
  </div>
</div>