<?php

/**
 * @file providers_views_handler_address_geocode.inc
 * Sub Provider handler --for geocode text address or get directions
 */

/**
 * Field handler to provide simple renderer that allows linking to a Provider.
 */
class providers_views_handler_address_geocode extends views_handler_field {

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
	$address = $values->ProviderLocations[0]->Location;
	if(!empty($address->Address2)) {
		   return '&nbsp;' . $address->Name . '&nbsp;' . $address->Address1 . '&nbsp;' . $address->Address2 . '&nbsp;' . $address->City . ',&nbsp;' . $address->State->Abbr . '&nbsp;' . $address->ZipCode . '&nbsp;' ;
		}
		elseif(empty($values->ProviderLocations[0]->Address2)){
			return '&nbsp;' . $address->Name . '&nbsp;' . $address->Address1 . '&nbsp;' . $address->City . ',&nbsp;' . $address->State->Abbr . '&nbsp;' . $address->ZipCode . '&nbsp;' ;
		}
	else {
		return;
		}
	}
}

