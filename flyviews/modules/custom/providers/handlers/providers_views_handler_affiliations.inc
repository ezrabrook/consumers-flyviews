<?php

/**
 * @file providers_views_handler_affiliations.inc
 * Sub Provider handler arrays
 */

/**
 * Field handler to provide simple renderer that allows linking to a Provider.
 */


class providers_views_handler_affiliations extends views_handler_field {

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
	    $hospitals = array();
		if (!empty($values->ProviderHospitals)){
			foreach($values->ProviderHospitals as $obj){
				if(!empty($obj->Hospital->Name)){
					$hospitals[] = $obj->Hospital->Name ;
				}
			}
			return  "<ul><li>" . implode("</li><li>", $hospitals) . "</li></ul>";
		}
		else{
		return null;}
	}
}


