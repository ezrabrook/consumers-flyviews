<?php

/**
 * @file providers_views_handler_accepting_new.inc
 * "DrupalCon" link field handler.
 */

/**
 * Field handler to render a field as a link.
 */
class providers_views_handler_accepting_new extends views_handler_field {

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
  	if (isset($values->ProviderLocations[0]->AcceptingNewPatients)){
		$new = $values->ProviderLocations[0]->AcceptingNewPatients;
		if (empty($new)){
			$accepting = t("Yes");
	 	  }
		elseif ($new == '1'){
			$accepting = t("Yes");
	 	  }
		elseif ($new == '0') {
			$accepting = t("No");
	 	 }
		elseif ($new == '2') {
			$accepting = t("Established Only");
		}		
		return $accepting;
	}
	else { return $accepting = t("Yes");}
	}
}



