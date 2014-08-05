<?php

/**
 * @file providers_views_handler_hours_one.inc
 * Sub Location handler /object
 */

/**
 * Field handler to provide simple renderer that allows linking to a Location.
 */
class providers_views_handler_hours_one extends views_handler_field{

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
		 $noresults = ' ';
		 $Hours = ' ';
		 $item = $values->ProviderLocations[0]->Hours;
	if (!empty($item->Sunday->Open) && !empty($item->Sunday->Close)) {
		 $Hours = $Hours . 'Sunday:' . '<span class="hours_right">'. $item->Sunday->Open . " - " . $item->Sunday->Close .'</span><br/>';
		}
	if (!empty($item->Monday->Open) && !empty($item->Monday->Close)) {
		 $Hours = $Hours . 'Monday:' . '<span class="hours_right">' . $item->Monday->Open . " - " . $item->Monday->Close . '</span><br/>';
		}
	if (!empty($item->Tuesday->Open) && !empty($item->Tuesday->Close)) {
		 $Hours = $Hours . 'Tuesday:' . '<span class="hours_right">'. $item->Tuesday->Open . " - " . $item->Tuesday->Close . '</span><br/>';
		}
	if (!empty($item->Wednesday->Open) && !empty($item->Wednesday->Close)) {
		 $Hours = $Hours . 'Wednesday:' . '<span class="hours_right">'. $item->Wednesday->Open . " - " . $item->Wednesday->Close .'</span><br/>';
		}
	if (!empty($item->Thursday->Open) && !empty($item->Thursday->Close)) {
		$Hours = $Hours . 'Thursday:' . '<span class="hours_right">'. $item->Thursday->Open . " - " . $item->Thursday->Close . '</span><br/>';
		}
	if (!empty($item->Friday->Open) && !empty($item->Friday->Close)) {
		 $Hours = $Hours . 'Friday:' . '<span class="hours_right">'.  $item->Friday->Open . " - " . $item->Friday->Close . '</span><br/>';
		}
	if (!empty($item->Saturday->Open) && !empty($item->Saturday->Close)){
		 $Hours = $Hours .  'Saturday:' . '<span class="hours_right">' . $item->Saturday->Open . " - " . $item->Saturday->Close .'</span><br/>';
		}
    if(empty($Hours)) {
    	 $noresults = t("Please call provider.");
		 $Hours = "<H5 class='hours_heading'>Hours</H5>" . $noresults. "<BR>";
    } 
	elseif(($noresults == ' ') && ($Hours == ' ')){
		 $noresults = t("Please call provider.");
		 $Hours = "<H5 class='hours_heading'>Hours</H5>" . $noresults;
    }
	else{
		$Hours = "<H5 class='hours_heading'>Hours</H5>" . $Hours;
	}
	return $Hours;
	
		
	}
}

