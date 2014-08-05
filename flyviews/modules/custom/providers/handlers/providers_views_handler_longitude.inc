<?php

/**
 * @file providers_views_handler_longitude.inc
 * Sub Location handler
 */

/**
 * Field handler to provide simple renderer that allows linking to a Location.
 */
class providers_views_handler_longitude extends views_handler_field {

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
	return $values->ProviderLocations[0]->Location->Geocode->longitude;
	}
}
