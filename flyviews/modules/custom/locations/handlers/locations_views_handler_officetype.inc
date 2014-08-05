<?php

/**
 * @file locations_views_handler_officetype.inc
 * Sub Location handler
 */

/**
 * Field handler to provide simple renderer that allows linking to a Location.
 */
class locations_views_handler_officetype extends views_handler_field{

  function construct() {
    parent::construct();
	}


  /**
   * Called to add the field to a query.
   */
   function query() {
		$this->ensure_my_table();
	}

	function render($values) {
	$office = $values->Location->OfficeType->Name;
		if ($office == 'Ambulatory Surgical Center'){
			$rewrite = t("/sites/all/modules/flyviews/modules/custom/files/HOSPITAL.jpg");
		}
		elseif ($office == 'Behavioral Health'){
			$rewrite = t("/sites/all/modules/flyviews/modules/custom/files/MENTAL.jpg");
		}
		elseif ($office == 'Chriopractor'){
			$rewrite = t("/sites/all/modules/flyviews/modules/custom/files/CLINIC.jpg");
		}
		elseif ($office == 'Clinic') {
			$rewrite = t("/sites/all/modules/flyviews/modules/custom/files/CLINIC.jpg");
		}
		elseif ($office == 'DME'){
			$rewrite = t("/sites/all/modules/flyviews/modules/custom/files/MEDICALSUPPLIES.jpg");
		}
		elseif ($office == 'FQHC'){
			$rewrite = t("/sites/all/modules/flyviews/modules/custom/files/CLINIC.jpg");
		}
		elseif ($office == 'Health Department'){
			$rewrite = t("/sites/all/modules/flyviews/modules/custom/files/CLINIC.jpg");
		}
		elseif ($office == 'Hospice'){
			$rewrite = t("/sites/all/modules/flyviews/modules/custom/files/HOSPICE.jpg");
		}
		elseif ($office == 'Hospital'){
			$rewrite = t("/sites/all/modules/flyviews/modules/custom/files/HOSPITAL.jpg");
		}
		elseif ($office == 'Lab'){
			$rewrite = t("/sites/all/modules/flyviews/modules/custom/files/LABS.jpg");
		}
		elseif ($office == 'Pharmacy'){
			$rewrite = t("/sites/all/modules/flyviews/modules/custom/files/PHARM.jpg");
		}
		elseif ($office == 'Physical Therapy') {
			$rewrite = t("/sites/all/modules/flyviews/modules/custom/files/PHYSICALTHE.jpg");
		}
		elseif ($office == 'Radiology Center') {
			$rewrite = t("/sites/all/modules/flyviews/modules/custom/files/XRAY.jpg");
		}
		elseif ($office == 'Skilled Nursing') {
			$rewrite = t("/sites/all/modules/flyviews/modules/custom/files/SKILLEDNURSING.jpg");
		}
		elseif ($office == 'Urgent Care') {
			$rewrite = t("/sites/all/modules/flyviews/modules/custom/files/URGENTCARE.jpg");
		}
		elseif ($office == 'Specialty Center') {
			$rewrite = t("/sites/all/modules/flyviews/modules/custom/files/ALLSPECCENTERS.jpg");
		}
		else {
			$rewrite = t("/sites/all/modules/flyviews/modules/custom/files/HOSPITAL.jpg");
		}
	return $rewrite;
	}

}
