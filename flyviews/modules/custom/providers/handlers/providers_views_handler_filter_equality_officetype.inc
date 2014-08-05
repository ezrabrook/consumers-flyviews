<?php

/**
 * @file providers_views_handler_filter_equality_officetype.inc
 * Basic "Provider" equality filter handler specifically for officetype.
 */

/**
 * Simple filter to handle equality for the radius.
 */
class providers_views_handler_filter_equality_officetype extends providers_views_handler_filter_equality {

  /**
   * Provide the form for choosing a year.
   */
    function query() {
     $this->query->request_arguments[$this->real_field] = $this->value;
     }
   
    function value_form(&$form, &$form_state){
      $provider_api = variable_get('providers_api_url');
      $specialty_array = array('All' => '-Any-');
      $output = drupal_http_request($provider_api . "/officetypes" );
      $decoded_output = json_decode($output->data);
      sort($decoded_output);
      foreach ($decoded_output as $row) {
	$specialty_array[$row->Id] = $row->Name;
      }
       $form['value'] = array(
	  '#title' => 'Officetypes',
	  '#type' => 'select',
	  '#multiple' => TRUE,
	  '#size' => 5 ,
	  '#default_value' => (!empty($this->value)) ? $this->value : '',
	  '#options' => $specialty_array,
	  '#attributes' => array(
	      'placeholder' => t('Example: Clinic'),
	      '#size' => 4,
	    )
	 );
       
  }
}