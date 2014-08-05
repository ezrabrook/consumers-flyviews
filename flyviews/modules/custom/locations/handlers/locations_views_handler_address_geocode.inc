<?php

/**
 * @file locations_views_handler_address_geocode.inc
 * Sub Location handler --for geocode text address or get directions
 */

class locations_views_handler_address_geocode extends views_handler_field {

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

    //if street address only has 1 line
	if(!empty($values->Location->Address2)) {
		   return $values->Location->Name . '&nbsp;' . $values->Location->Address1 . '&nbsp;' . $values->Location->Address2 . '&nbsp;&#x000D;' . $values->Location->City . ',&nbsp;' . $values->Location->State->Abbr . '&nbsp;' . $values->Location->ZipCode . '&nbsp;' ;
		}

    //if street address has 2 lines
		elseif(empty($values->Location->Address2)){
			return $values->Location->Name . '&nbsp;' . $values->Location->Address1 . '&nbsp;&#x000D;' . $values->Location->City . ',&nbsp;' . $values->Location->State->Abbr . '&nbsp;' . $values->Location->ZipCode . '&nbsp;' ;
		}
	else {
		return;
		}
	}
}

