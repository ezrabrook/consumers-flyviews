<?php

/**
 * @file providers_views_handler_address_seven.inc
 * Sub Location handler
 */

/**
 * Field handler to provide simple renderer that allows linking to a Location.
 */
class providers_views_handler_address_seven extends views_handler_field {

  function construct() {
    parent::construct();
		 $this->aliases['LocationId'] = 'LocationID';
		 $this->additional_fields['LocationId'] = array('LocationID' => 'Address');
	}

  /**
   * Called to add the field to a query.
   */
   function query() {
		$this->ensure_my_table();
		$this->add_additional_fields();
	}
	function render($values) {
	if (!empty($values->Provider->ProviderLocations[6]->Location->Phone)){
		$num = $values->Provider->ProviderLocations[6]->Location->Phone;
		$num = preg_replace('/[^0-9]/', '', $num);
	 
		$len = strlen($num);
		if($len == 7)
		$num = preg_replace('/([0-9]{3})([0-9]{4})/', '$1-$2', $num);
		elseif($len == 10)
		$num = preg_replace('/([0-9]{3})([0-9]{3})([0-9]{4})/', '($1) $2-$3', $num);
		$num = "Phone: " . $num;
	}
	if (!empty($values->Provider->ProviderLocations[6]->Location->Fax)){
		$fax = $values->Provider->ProviderLocations[6]->Location->Fax;
		$fax = preg_replace('/[^0-9]/', '', $fax);
	 
		$len = strlen($fax);
		if($len == 7)
		$fax = preg_replace('/([0-9]{3})([0-9]{4})/', '$1-$2', $fax);
		elseif($len == 10)
		$fax = preg_replace('/([0-9]{3})([0-9]{3})([0-9]{4})/', '($1) $2-$3', $fax);
		$fax = "Fax: " . $fax;
	}

	if (!empty($values->Provider->ProviderLocations[6])){
		if(!empty($values->Provider->ProviderLocations[6]->Location->Address2)) {
		   return '<span><h5>' . $values->Provider->ProviderLocations[6]->Location->Name . '</h5>'. $values->Provider->ProviderLocations[6]->Location->Address1 . "<br>" . $values->Provider->ProviderLocations[6]->Location->Address2 . '<br/>' . $values->Provider->ProviderLocations[6]->Location->City . "&nbsp;" . $values->Provider->ProviderLocations[6]->Location->State->Abbr . ",&nbsp;" . $values->Provider->ProviderLocations[6]->Location->ZipCode . '<br/>' . $num .'<br/>'. $fax . '</span>' ;
		}
		elseif(empty($values->Provider->ProviderLocations[6]->Location->Address2)){
			return'<span><h5>' . $values->Provider->ProviderLocations[6]->Location->Name . '</h5>'. $values->Provider->ProviderLocations[6]->Location->Address1 . "&nbsp;"  . $values->Provider->ProviderLocations[6]->Location->Address2 . '<br/>' . $values->Provider->ProviderLocations[6]->Location->City . "&nbsp;" . $values->Provider->ProviderLocations[6]->Location->State->Abbr . ",&nbsp;" . $values->Provider->ProviderLocations[6]->Location->ZipCode . '<br/>' . $num .'<br/>'. $fax . '</span>' ;
		}
	else{
		return;
	}
	
	}
}
}
