<?php

/**
 * @file providers_views_handler_latitude.inc
 * Sub Location handler
 */

/**
 * Field handler to provide simple renderer that allows linking to a Location.
 */
class providers_views_handler_latitude extends views_handler_field {

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
	return $values->ProviderLocations[0]->Location->Geocode->latitude;
	}
}

