<?php

/**
 * @file providers_views_handler_address.inc
 * Sub Location handler
 */

/**
 * Field handler to provide simple renderer that allows linking to a Location.
 */
class providers_views_handler_address extends views_handler_field {

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
		if(!empty($values->ProviderLocations[0]->Location->Address2)) {
		   return '<span>' . $values->ProviderLocations[0]->Location->Name . '<br/>'. $values->ProviderLocations[0]->Location->Address1 . "<br/>" . $values->ProviderLocations[0]->Location->Address2 . '<br/>' . $values->ProviderLocations[0]->Location->City . ",&nbsp;" . $values->ProviderLocations[0]->Location->State->Abbr . "&nbsp;" . $values->ProviderLocations[0]->Location->ZipCode .'<br/></span>' ;
		}
		elseif(empty($values->ProviderLocations[0]->Location->Address2)){
			return'<span>' . $values->ProviderLocations[0]->Location->Name . '<br/>'. $values->ProviderLocations[0]->Location->Address1 . "<br/>"  . $values->ProviderLocations[0]->Location->City . ",&nbsp;" . $values->ProviderLocations[0]->Location->State->Abbr . "&nbsp;" . $values->ProviderLocations[0]->Location->ZipCode . '<br/></span>' ;
		}
	else {
		return;
		}
	}
}
