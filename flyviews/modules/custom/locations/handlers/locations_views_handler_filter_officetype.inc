<?php

/**
 * @file locations_views_handler_filter_officetype.inc
 * Basic "Locations" equality filter handler specifically for officetype.
 */

class locations_views_handler_filter_officetype extends locations_views_handler_filter_equality {

    function query() {
      $this->query->request_arguments[$this->real_field] = $this->value;
    }

    function value_form(&$form, &$form_state){
      //get location api url
      $location_api = variable_get('locations_api_url');
      $specialty_array = array();
	    $output = array();

      //Build the request
      $output = drupal_http_request($location_api . "/officetypes" );
      $decoded_output = json_decode($output->data);
      sort($decoded_output);

      $existing = array('All' => '-Any-');
      foreach ($decoded_output as $row) {
		    $specialty_array[$row->Id] = $row->Name;
      }

      //Sort the result keeping the ID/Name pair
	    aasort($specialty_array, "Name");

      /*
      * Multiple select and search
      * autocomplete, by using the chosen module
      * Set the #edit- id in the configuration
      */

	    $form['value'] = array(
        '#title' => 'Officetypes',
  	    '#type' => 'checkboxes',
  	    '#size' => 5,
  	    '#multiple' => true,
  	    '#default_value' => $existing,
  	    '#options' => $specialty_array,
	    );
  }
}

