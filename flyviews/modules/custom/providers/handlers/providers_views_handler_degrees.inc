<?php

/**
 * @file providers_views_handler_degrees.inc
 * Sub Provider handler
 * For array type
 */

/**
 * Field handler to provide simple renderer that allows linking to a Provider.
 */
class providers_views_handler_degrees extends views_handler_field {

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
	    $degrees = array();
		foreach($values->Degrees as $obj){
			$degrees[] = $obj->Name;
		}
		return  join(', ', $degrees);
	}
	
}

