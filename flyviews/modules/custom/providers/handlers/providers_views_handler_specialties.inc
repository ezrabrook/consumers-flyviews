<?php

/**
 * @file providers_views_handler_specialties.inc
 * Sub Location handler
 */

/**
 * Field handler to provide simple renderer that allows linking to a Provider.
 */
class providers_views_handler_specialties extends views_handler_field {

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
	
   function render($values){
      $specialties = array();
	if(!empty($values->Specialties)){
	  foreach($values->Specialties as $obj){
	    $specialties[] = $obj->Specialty->Name;
	    }
	    return  "<ul><li>" . implode("</li><li>", $specialties) . "</li></ul>";
	}
	else{
	    return;
	}
    }
  }
