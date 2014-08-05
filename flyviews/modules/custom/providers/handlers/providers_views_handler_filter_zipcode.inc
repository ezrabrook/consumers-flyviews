<?php

/**
 * @file providers_views_handler_filter_zipcode.inc
 * Basic "Locations" numeric filter handler.
 */

/**
 * Simple filter to handle numeric filtering. Supports only the "between" operator.
 */
class providers_views_handler_filter_zipcode extends providers_views_handler_filter_equality {

  /**
   * Provide simple equality operator
   */
  function operator_options() {
    return array(
	  '=' => t('Is equal to'),
    );
  }


  function value_form(&$form, &$form_state) {
	$zipcode = isset($_GET['zipcode']) ? $_GET['zipcode'] : '' ;
 	if(!empty($this->value)){
 		$zipcode = $this->value;
 	}
   $form ['value'] = array (
	'#type' => 'textfield',
	'#title' => empty($form_state['exposed']) ? t('Equals'): '',
	'#size' => 7,
	'#required' => true,
	'#maxlength' => 5,
	'#default_value' => $zipcode,
	'#rules' => array(
	    'numeric',
	    'regexp[/^([0-9]{5}(?:-[0-9]{4})?)*$/]',
	    array('rule' => 'numeric', 'error' => 'Please use only numeric characters for zipcode.'),
	   ),
	  );
    }
  }

