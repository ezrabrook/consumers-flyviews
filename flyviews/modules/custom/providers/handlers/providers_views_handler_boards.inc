<?php

/**
 * @file providers_views_handler_boards.inc
 * Sub Provider handler arrays
 */

/**
 * Field handler to provide simple renderer that allows linking to a Provider.
 */


class providers_views_handler_boards extends views_handler_field {

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
	    $boards = array();
		if (!empty($values->Specialties[0]->Board)){
			foreach($values->Specialties as $obj){
				if(!empty($obj->Board)){
					$boards[] = $obj->Board .', '.$obj->BoardStatus;
				}
			}
			return  "<ul><li>" . implode("</li><li>", $boards) . "</li></ul>";
		}
		else{
		return null;}
	}
}


