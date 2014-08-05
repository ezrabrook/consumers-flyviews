<?php

/**
 * @file locations_views_handler_hours.inc
 * Sub Location handler /object
 */

/**
 * Field handler to provide simple renderer that allows linking to a Location.
 */
class locations_views_handler_hours extends views_handler_field{

  function construct() {
    parent::construct();
	}


  /**
   * Called to add the field to a query.
   */
   function query() {
		$this->ensure_my_table();
		$this->add_additional_fields();
	}

	function render($values) {
	$times = "";
	$item = $values->Location->Hours;
	if (isset($item->Sunday->Open)) {
		$times = 'Sunday:' . '<span class="hours_location">'. $item->Sunday->Open . " - " . $item->Sunday->Close .'</span><br>';
		}
	if (isset($item->Monday->Open)) {
		$times = $times . 'Monday:' . '<span class="hours_location">' . $item->Monday->Open . " - " . $item->Monday->Close . '</span><br>';
		}
	if (isset($item->Tuesday->Open)) {
		$times = $times .'Tuesday:' . '<span class="hours_location">'. $item->Tuesday->Open . " - " . $item->Tuesday->Close . '</span><br>';
		}
	if (isset($item->Wednesday->Open)) {
		$times = $times .'Wednesday:' . '<span class="hours_location">'. $item->Wednesday->Open . " - " . $item->Wednesday->Close .'</span><br>';
		}
	if (isset($item->Thursday->Open)) {
		$times = $times . 'Thursday:' . '<span class="hours_location">'. $item->Thursday->Open . " - " . $item->Thursday->Close . '</span><br>';
		}
	if (isset($item->Friday->Open)) {
		$times = $times .'Friday:' . '<span class="hours_location">'.  $item->Friday->Open . " - " . $item->Friday->Close . '</span><br>';
		}
	if (isset($item->Saturday->Open)){
		$times = $times . 'Saturday:' . '<span class="hours_location">' . $item->Saturday->Open . " - " . $item->Saturday->Close .'</span><br>';
		}
	if(empty($times)){
		$noresults = t("Please call provider.");
		}


    if(isset($noresults)) {
      $Hours = "<H5 class='hours_heading'>Hours</H5>" .$noresults. "<BR>";
    } else {
	    $Hours = "<H5 class='hours_heading'>Hours</H5>" . $times . '<br>';
    }
	return $Hours;
	
		
	}
}

