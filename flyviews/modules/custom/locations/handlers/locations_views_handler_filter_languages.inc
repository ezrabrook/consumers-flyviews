<?php
/*
*@file locations_views_handler_filter_languages.inc
*
*/

class locations_views_handler_filter_languages extends locations_views_handler_filter_equality {

  function query() {
      $this->query->request_arguments[$this->real_field] = $this->value;
    }

  function value_form(&$form, &$form_state){
    //Get location api from admin
      $location_api = variable_get('locations_api_url');

      $specialty_array = array();

	    $output = array();

     //Build the Request
      $output = drupal_http_request($location_api . "/languages/used" );
      $decoded_output = json_decode($output->data);
      sort($decoded_output);
      $existing = array('All' => '-Any-');

      foreach ($decoded_output as $row) {
		    $specialty_array[$row->Id] = $row->Name;
      }

      aasort($specialty_array, "Name");
      $form['value'] = array(
	      '#title' => 'Languages',
	      '#type' => 'select',
	      '#multiple' => true,
	      '#size' => 5,
	      '#default_value' => $existing,
	      '#options' => $specialty_array,
	      '#attributes' => array(
	         'placeholder' => t('Example: Spanish'),
	         'size' => 4,
	      )
	    );

   } //end value_form

} //end class
