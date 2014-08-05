<?php

/**
 * @file providers_views_handler_provider_lastname.inc
 * Sub Location handler
 */

/**
 * Field handler to provide simple renderer that allows linking to a Location.
 */
class providers_views_handler_provider_lastname extends views_handler_field {

  function construct() {
    parent::construct();
		$this->aliases['Name'] = 'LastName';
	}


  /**
   * Called to add the field to a query.
   */
   function query() {
		$this->ensure_my_table();
		$this->add_additional_fields();
	}
  function render($values) {
		return $values->LastName;
	}
}
