<?php

/**
 * @file locations_views_handler_officetype_name.inc
 * Sub Location handler
 */

/**
 * Field handler to provide simple renderer that allows linking to a Location.
 */
class locations_views_handler_officetype_name extends views_handler_field{

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
        $type = array();
        if(!empty($values->Location->OfficeType)){
            return $values->Location->OfficeType->Name;
        }
        else{
            return;
        }
    }
}