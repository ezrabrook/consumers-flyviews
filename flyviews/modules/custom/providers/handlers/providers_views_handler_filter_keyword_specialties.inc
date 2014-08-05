<?php

/**
 * @file providers_views_handler_filter_keyword_specialties.inc
 * Basic "Locations" equality filter handler.
 */

/**
 * Simple filter to handle equality.
 */
class providers_views_handler_filter_keyword_specialties extends views_handler_filter_equality{
  /**
   * Add this filter to the request.
   */
   function query() {
     $this->query->request_arguments[$this->real_field] = $this->value;
     }

    function value_form(&$form, &$form_state){
      $provider_api = variable_get('providers_api_url');

      $specialty_array = array('All' => '-Any-');

      $output = array();
      $output = drupal_http_request($provider_api . "/providers/specialties/" );

      $decoded_output = json_decode($output->data);
	
      foreach ($decoded_output as $row) {
	       $specialty_array[$row->Id] = $row->Name;
      }
		
       $form['value'] = array(
    	  '#title' => 'Specialties Name',
    	  '#type' => 'select',
    	  '#size' => 5,
    	  '#multiple' => TRUE,
    	  '#default_value' => (!empty($this->value)) ? $this->value : '',
    	  '#options' => $specialty_array,
    	  '#attributes' => array(
    	      'placeholder' => t('Example: Pediatrics'),
    	      '#size' => 4,
    	    )
    	 );
    }//end value_form

}//end class
