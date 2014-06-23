/**
 * @file
 * Javascript file for TFA module. 
 *
**/
(function ($) {
  Drupal.behaviors.tfa_locations = {
    attach: function(context, settings) {

      $('.view-tfa-locations .view-content .item-list').each(function() {
        $(this).attr('data-state-list', $(this).find('h3').text());
      });


      $('#state-list li').click(function() {
        item = $('[data-state-list="' + $(this).text() + '"]')
        if ($(item).is(':visible')) {
          $('.view-tfa-locations .view-content .item-list').not($(item)).slideUp(500);
        }
        else {
          $('.view-tfa-locations .view-content .item-list').hide();
          $('[data-state-list="' + $(this).text() + '"]').fadeIn(750);
        }
      })

      maps = $('#map-west, #map-east, #map-southwest, #map-mountain-west, #map-southeast, #map-new-england, #map-midwest');

      Drupal.behaviors.tfa_locations.switchOut();

      $(maps).hover(function() {
        $(maps).each(function() {
          if ($('body').hasClass('map-active-' + $(this).attr('title'))) {
            detachedClass = 'map-active-' + $(this).attr('title');
            $('body').removeClass(detachedClass);
          }
        })
          $('#region-map').addClass('map-' + $(this).attr('title'));
        }, function() {
          $('#region-map').removeClass('map-' + $(this).attr('title'));
          $('body').addClass(detachedClass);
        }
      ).click(function() {
        // Unset all map related body classes and set the new one
        $(maps).each(function() {
          $('body').removeClass('map-active-' + $(this).attr('title'))
        })
        $('body').addClass('map-active-' + $(this).attr('title'));

        elem = $(this)[0];

        switch ($(elem).attr('title')) {
          case "west":
            tid = 1;
            break;
          case "southwest":
            tid = 3;
            break;       
          case "midwest":
            tid = 4;
            break;
          case "mountain-west":
            tid = 2;
            break;  
          case "southeast":
            tid = 5;
            break;  
          case "east":
            tid = 45;
            break;
          case "new-england":
            tid = 52;
            break;  
        }
        $('#edit-term-node-tid-depth').val(tid);
        $('#edit-submit-tfa-locations').click();
      });
      $('select[name="term_node_tid_depth"]').change(function() {
        Drupal.behaviors.tfa_locations.switchOut();
      });
    },

    switchOut: function(context, settings) {
      city = '';
        switch ($('select[name="term_node_tid_depth"]').val()) {
          case '1' :
            city = "west";
            break;
          case '3':
            city = "southwest";
            break;       
          case '4':
            city = "midwest";
            break;
          case '2':
            city = "mountain-west";
            break;  
          case '5':
            city = "southeast";
            break;  
          case '45':
            city = "east";
            break;
          case '52':
            city = "new-england";
            break; 
          case 'All':
            city = '';
            break;
        }

        $(maps).each(function() {
          $('body').removeClass('map-active-' + $(this).attr('title'))
        })
        if (city) {
          $('body').addClass('map-active-' + city);  
        }
      }

  }

})(jQuery);