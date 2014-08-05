<?php

/**
 * @file providers_views_handler_languages.inc
 * Sub Provider handler arrays
 */

/**
 * Field handler to provide simple renderer that allows linking to a Provider.
 */


class providers_views_handler_languages extends views_handler_field {

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
		$languages = array();
		foreach($values->Languages as $obj){
			$languages[] = $obj->Name;
		}
		return  join(', ', $languages);
	}
}



