<?php

/**
 * @file providers_views_handler_gender_name.inc
 * Sub Location handler
 */

/**
 * Field handler to provide simple renderer that allows linking to a Location.
 */
class providers_views_handler_gender_name extends views_handler_field {

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
	if ($values->Gender == '1') {
		$gender = t('Female');
	}
	elseif ($values->Gender == '2') {
		$gender =  t('Male');
	}
	else {
		$gender = t('Unknown');
	}
	return $gender;
	}
}
