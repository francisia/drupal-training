<?php
/**
 * @file
 * Javascript file for Drupal behavior
 */

?>

/**
 * Implementation of Drupal behavior.
 */
(function($) {
Drupal.behaviors.coolthing = {};
Drupal.behaviors.coolthing.attach = function(context) {
  // If there are both main column and side column buttons, only show the main
  // column buttons if the user scrolls past the ones to the side.
  $('div.form:has(div.column-main div.form-actions):not(.coolthing-processed)').each(function() {
    var form = $(this);
    var offset = $('div.column-side div.form-actions', form).height() + $('div.column-side div.form-actions', form).offset().top;
    $(window).scroll(function () {
      if ($(this).scrollTop() > offset) {
        $('div.column-main div.form-actions', form).show();
      }
      else {
        $('div.column-main div.form-actions', form).hide();
      }
    });
    form.addClass('coolthing-processed');
  });

  $('a.toggler:not(.coolthing-processed)', context).each(function() {
    var id = $(this).attr('href').split('#')[1];
    // Target exists, add click handler.
    if ($('#' + id).size() > 0) {
      $(this).click(function() {
        toggleable = $('#' + id);
        toggleable.toggle();
        $(this).toggleClass('toggler-active');
        return false;
      });
    }
    // Target does not exist, remove click handler.
    else {
      $(this).addClass('toggler-disabled');
      $(this).click(function() { return false; });
    }
    // Mark as processed.
    $(this).addClass('coolthing-processed');
  });
};
$(document).ready(function() {
  // If there's no active secondary tab, make the first one show.
  var activeli = $('.primary-tabs li.active .secondary-tabs li.active');
  if (activeli.length == 0) {
    $('.primary-tabs li.active .secondary-tabs li:first-child a').css('display', 'block');
  }
});
})(jQuery);
