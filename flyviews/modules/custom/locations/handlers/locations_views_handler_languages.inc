<?php

/**
 * @file locations_views_handler_languages.inc
 * Sub Location handler
 */

/**
 * Field handler to provide simple renderer that allows linking to a Location.
 */
class locations_views_handler_languages extends views_handler_field{

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
		$languages = array();
		if(isset($values->Location->Languages)){
			foreach($values->Location->Languages as $obj){
				$languages[] = $obj->Name;
			}
			return  join(', ', $languages);
		}
		return;
	}

}

