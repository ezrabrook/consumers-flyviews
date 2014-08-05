<?php

/**
 * @file locations_views_handler_filter_zipcode.inc
 * Basic "Locations" numeric filter handler.
 */

/**
 * Simple filter to handle numeric filtering. Supports only the "between" operator.
 */
class locations_views_handler_filter_zipcode extends locations_views_handler_filter_equality {

  /**
   * Provide simple equality operator
   */
  function operator_options() {
    return array(
	  '=' => t('Is equal to'), 
    );
  }  

 
  function value_form(&$form, &$form_state) {
    $update_zip = isset($_GET['zipcode']) ? $_GET['zipcode'] : '' ;
 	if(!empty($this->value)){
 		$this->value = $update_zip;
 	}
  
   $form ['value'] = array (
	'#type' => 'textfield', 
	'#title' => empty($form_state['exposed']) ? t('Equals'): '', 
	'#size' => 7,
	'#maxlength' => 5, 
	'#default_value' => $update_zip,
	'#rules' => array(
	    'numeric',
	    'length[5]',
	    array('rule' => 'numeric', 'error' => 'Please use only numeric characters in %field.'),
	   ),
	  );
	 /*{ if (!empty($form_state['exposed']) && !isset($form_state['input'][$identifier]['equals'])) {
      $form_state['input'][$identifier]['equals'] = $this->value;
    };
	  if (!isset($form['value'])) {
      // Ensure there is something in the 'value'.
      $form['value'] = array(
        '#type' => 'value',
        '#value' => NULL
      ); } 
    }*/
  }
}

