<?php

/**
 * @file providers_views_handler_gender.inc
 * Sub Location handler
 */

/**
 * Field handler to provide simple renderer that allows linking to a Location.
 */
class providers_views_handler_gender extends views_handler_field {

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
		$gender = '<img class="gender_image" src="/sites/all/modules/flyviews/modules/custom/files/femaledoctor.jpg" alt="Female Doctor">';
	}
	elseif ($values->Gender == '2') {
		$gender =  '<img class="gender_image" src="/sites/all/modules/flyviews/modules/custom/files/maledoctor.jpg" alt="Male Doctor">';
	}
	else {
		$gender = '<img class="gender_image" src="/sites/all/modules/flyviews/modules/custom/files/stethoscope.png" alt="Unknown Gender">';
	}
	return $gender;
	}
}
