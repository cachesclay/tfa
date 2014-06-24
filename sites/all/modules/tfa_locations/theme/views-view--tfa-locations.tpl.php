<?php

/**
 * @file
 * Main view template.
 *
 * Variables available:
 * - $classes_array: An array of classes determined in
 *   template_preprocess_views_view(). Default classes are:
 *     .view
 *     .view-[css_name]
 *     .view-id-[view_name]
 *     .view-display-id-[display_name]
 *     .view-dom-id-[dom_id]
 * - $classes: A string version of $classes_array for use in the class attribute
 * - $css_name: A css-safe version of the view name.
 * - $css_class: The user-specified classes names, if any
 * - $header: The view header
 * - $footer: The view footer
 * - $rows: The results of the view query, if any
 * - $empty: The empty text to display if the view is empty
 * - $pager: The pager next/prev links to display, if any
 * - $exposed: Exposed widget form/info to display
 * - $feed_icon: Feed icon to display, if any
 * - $more: A link to view more, if any
 *
 * @ingroup views_templates
 */
?>
<div class="<?php print $classes; ?>">
  <?php print render($title_prefix); ?>
  <?php if ($title): ?>
    <?php print $title; ?>
  <?php endif; ?>
  <?php print render($title_suffix); ?>
  <?php if ($header): ?>
    <div class="view-header">
      <?php print $header; ?>
    </div>
  <?php endif; ?>
  <div id='locations-top-select' class="clearfix">
    <?php if ($exposed): ?>
      <div class="view-filters">
        <?php print $exposed; ?>
      </div>
      <div id="map-container">
        <div id='region-map'>
          <img src ="http://localhost/tfa/sites/all/modules/tfa_locations/images/clear.png" width="500" height="345" alt="Planets" usemap="#Map">
          <map name="Map" id="Map">
            <area id="map-west" title="west" href="#" shape="poly" coords="42,2,98,7,91,79,114,87,95,204,229,290,61,287,19,104,30,17" />
            <area id="map-mountain-west" title="mountain-west" href="#" shape="poly" coords="105,6,92,79,116,85,111,134,216,150,215,105,200,105,202,17,145,12" />
            <area id="map-southwest" title="southwest" href="#" shape="poly" coords="112,143,101,189,265,276,294,227,283,146,195,150" />
            <area id="map-southeast" title="southeast" href="#" shape="poly" coords="286,154,291,227,395,225,424,269,445,262,417,192,458,144,422,98,398,101,388,117,365,117,326,153,309,154" />
            <area id="map-midwest" title="midwest" href="#" shape="poly" coords="397,81,395,96,383,118,364,108,350,130,323,149,214,145,216,104,199,102,200,17,357,29,385,75" />
            <area id="map-east" title="east" href="#" shape="poly" coords="448,32,455,74,476,74,447,106,438,111,426,97,399,101,400,75,413,56" />
            <area id="map-new-england" title="new-england" href="#" shape="poly" coords="449,24,458,76,491,64,494,7,462,2,451,14" />
          </map>
        </div>
      </div>
    <?php endif; ?>
  </div>
  <?php if ($attachment_before): ?>
    <div class="attachment attachment-before">
      <?php print $attachment_before; ?>
    </div>
  <?php endif; ?>
  <div id='locations-bottom-results'>
    <h2> Pathway Programs by State: 
      <?php print $view->tax_data['region']?>
      <?php if ($view->tax_data['program'] != ''): ?> 
        <?php print '(' . $view->tax_data['program'] . ')'; ?>
      <?php endif;?>
    </h2>
    <?php if ($view->tax_data['states']): ?>
      <div id="avail-states">
        <?php print $view->tax_data['states'] ?>
      </div>
    <?php endif;?>
    <?php if ($rows): ?>
      <div class="view-content">
        <?php print $rows; ?>
      </div>
    <?php elseif ($empty): ?>
      <div class="view-empty">
        <?php print $empty; ?>
      </div>
    <?php endif; ?>

    <?php if ($pager): ?>
      <?php print $pager; ?>
    <?php endif; ?>

    <?php if ($attachment_after): ?>
      <div class="attachment attachment-after">
        <?php print $attachment_after; ?>
      </div>
    <?php endif; ?>

    <?php if ($more): ?>
      <?php print $more; ?>
    <?php endif; ?>
  </div>
  <?php if ($footer): ?>
    <div class="view-footer">
      <?php print $footer; ?>
    </div>
  <?php endif; ?>

  <?php if ($feed_icon): ?>
    <div class="feed-icon">
      <?php print $feed_icon; ?>
    </div>
  <?php endif; ?>

</div><?php /* class view */ ?>
