<?php

/**
 * @file locations_views_handler_distance.inc
 *
 *
 */


class locations_views_handler_distance extends views_handler_field {

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
		 return  $values->Distance;
	}

}
