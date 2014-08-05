<?php

/**
 * @file providers_views_handler_educations.inc
 * Sub Provider handler arrays
 */

/**
 * Field handler to provide simple renderer that allows linking to a Provider.
 */


class providers_views_handler_educations extends views_handler_field {

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
	    $educations = array();
		$specialty = '';
		$school = '';
		$type = '';
		if (!empty($values->Educations)){
			foreach($values->Educations as $obj){
				if(isset($obj->Type)){
				    $type = $obj->Type . ' - ';
				}
				if(isset($obj->School)){
				    $school = $obj->School . ' ';
				}
				if(!empty($obj->Specialty) && ($obj->Specialty != "No Value Specified")){
				    $specialty = ' - <span class="italic">'. $obj->Specialty . '<span>' ;
				}
				$educations[] = $type . $school . $specialty; 
			}
			return  "<ul><li>" . implode("</li><li>", $educations) . "</li></ul>";
		}
		else{return null;}
	}
}


