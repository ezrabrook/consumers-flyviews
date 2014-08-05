<?php

/**
 * @file providers_views_handler_address_two.inc
 * Sub Location handler
 */

/**
 * Field handler to provide simple renderer that allows linking to a Location.
 */
class providers_views_handler_address_two extends views_handler_field {

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
	$item = $values->ProviderLocations[1]->Location;
	if (!empty($item->Phone)){
		$num = $item->Phone;
		$num = preg_replace('/[^0-9]/', '', $num);
	 
		$len = strlen($num);
		if($len == 7)
		$num = preg_replace('/([0-9]{3})([0-9]{4})/', '$1-$2', $num);
		elseif($len == 10)
		$num = preg_replace('/([0-9]{3})([0-9]{3})([0-9]{4})/', '($1) $2-$3', $num);
		$num = "Phone: " . $num;
	}
	if (!empty($item->Fax)){
		$fax = $item->Fax;
		$fax = preg_replace('/[^0-9]/', '', $fax);
	 
		$len = strlen($fax);
		if($len == 7)
		$fax = preg_replace('/([0-9]{3})([0-9]{4})/', '$1-$2', $fax);
		elseif($len == 10)
		$fax = preg_replace('/([0-9]{3})([0-9]{3})([0-9]{4})/', '($1) $2-$3', $fax);
		$fax = "Fax: " . $fax;
	}

	if (!empty($values->Provider->ProviderLocations[1])){
		if(!empty($item->Address2)) {
		   return '<span><h5>' . $item->Name . '</h5>'. $item->Address1 . "<br>" . $item->Address2 . '<br/>' . $item->City . ",&nbsp;" . $item->State->Abbr . "&nbsp;" . $item->ZipCode . '<br/>' . $num .'<br/>'. $fax . '</span>' ;
		}
		elseif(empty($values->ProviderLocations[1]->Location->Address2)){
			return'<span><h5>' . $item->Name . '</h5>'. $item->Address1 . "<br>"  . $item->City . ",&nbsp;" . $item->State->Abbr . "&nbsp;" . $item->ZipCode . '<br/>' . $num .'<br/>'. $fax . '</span>' ;
		}
	else{
		return;
	}
	
	}
}
}
