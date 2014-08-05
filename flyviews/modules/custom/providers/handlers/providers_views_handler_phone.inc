<?php
/**
 * @file providers_views_handler_phone.inc
 * Sub Location handler
 */

/**
 * Field handler to provide simple renderer that allows linking to a Location.
 */
class providers_views_handler_phone extends views_handler_field {

  function construct() {
    parent::construct();
	}


  /**
   * Called to add the field to a query.
   */
   function query() {
		$this->ensure_my_table();
	}
	/**
	* Converts phone numbers to the formatting standard
	*
	* @param   String   $num   A unformatted phone number
	* @return  String   Returns the formatted phone number
	*/
	
	// echo formatPhone('1 208 - 386 2934');
	// will print: (208) 386-2934 </code>
  function render($values) {
  	$num = '';
	if (!empty($values->ProviderLocations[0]->Location->Phone)){
		$num = $values->ProviderLocations[0]->Location->Phone;
		$num = preg_replace('/[^0-9]/', '', $num);
	 
		$len = strlen($num);
		if($len == 7)
		$num = preg_replace('/([0-9]{3})([0-9]{4})/', '$1-$2', $num);
		elseif($len == 10)
		$num = preg_replace('/([0-9]{3})([0-9]{3})([0-9]{4})/', '($1) $2-$3', $num);
		return "Phone: " . $num;
	}
	return $num;
	}
}


