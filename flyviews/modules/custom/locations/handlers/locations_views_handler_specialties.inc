<?php

/**
 * @file locations_views_handler_specialties.inc
 * Sub Location handler
 */

/**
 * Field handler to provide simple renderer that allows linking to a Location.
 */
class locations_views_handler_specialties extends views_handler_field {

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
		$specialties = array();
		if(isset($values->Location->Specialties)){
			foreach($values->Location->Specialties as $obj){
				$specialties[] = $obj->Name;
			}
			return  join(', ', $specialties);
		}
		else{
		      return;
		}
  }
}

