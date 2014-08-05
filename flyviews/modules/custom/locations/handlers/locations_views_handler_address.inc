<?php

/**
 * @file locations_views_handler_address.inc
 * Sub Location handler
 */

/**
 * Field handler to provide simple renderer that allows linking to a Location.
 */
class locations_views_handler_address extends views_handler_field {

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
	if(!empty($values->Location->Address2)) {
		   return '<span>' . '<h5 class="name_heading">' . $values->Location->Name .'</h5>'. $values->Location->Address1 . "<br/>" . $values->Location->Address2 . '<br/>' . $values->Location->City . ",&nbsp;" . $values->Location->State->Abbr . "&nbsp;" . $values->Location->ZipCode .'<br/></span>' ;
		}
		elseif(empty($values->Location->Address2)){
			return'<span>'  . '<h5 class="name_heading">' .$values->Location->Name .  '</h5>' . $values->Location->Address1 . "<br/>". $values->Location->City . ",&nbsp;" . $values->Location->State->Abbr . "&nbsp;" . $values->Location->ZipCode . '<br/></span>' ;
		}
	else {
		return;
		}
	}
}

