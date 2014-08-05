<?php

/**
 * @file locations_views_handler_fax.inc
 * Gets fax from api and regulates format
 */

class locations_views_handler_fax extends views_handler_field {

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
	* @param   String   $num   A unformatted fax number
	* @return  String   Returns the formatted fax number
	*/

	// echo formatPhone('1 208 - 386 2934');
	// will print: (208) 386-2934 </code>

  function render($values) {
    if(isset($values->Location->Fax)) {
      $num = $values->Location->Fax;
    } else {
      $num = "";
    }
	$num = preg_replace('/[^0-9]/', '', $num);

	$len = strlen($num);
	if($len == 7)
	$num = preg_replace('/([0-9]{3})([0-9]{4})/', '$1-$2', $num);
	elseif($len == 10)
	$num = preg_replace('/([0-9]{3})([0-9]{3})([0-9]{4})/', '($1) $2-$3', $num);

	return $num;
	}
}

