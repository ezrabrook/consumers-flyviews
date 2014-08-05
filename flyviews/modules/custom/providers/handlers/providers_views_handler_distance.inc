<?php

/**
 * @file providers_views_handler_distance.inc
 * Sub Provider handler
 * For array type
 */

/**
 * Field handler to provide simple renderer that allows linking to a Provider.
 */
class providers_views_handler_distance extends views_handler_field {

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
		 return  $values->ProviderLocations[0]->Location->Distance;
	}
	
}

