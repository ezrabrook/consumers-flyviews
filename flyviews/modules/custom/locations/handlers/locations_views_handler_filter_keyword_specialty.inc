<?php

/**
 * @file locations_views_handler_filter_keyword_specialty.inc
 * Basic "Locations" equality filter handler.
 */


class locations_views_handler_filter_keyword_specialty extends views_handler_filter_equality{
    /**
   * Provide the form for choosing specialties
   */
  function query() {
    $this->query->request_arguments[$this->real_field] = $this->value;

 }
  function value_form(&$form, &$form_state) {
    //Get the api url from the admin view
    $location_api = variable_get('locations_api_url');

    //Set default value
    $specialty_array = array('All' => '-Any-');

    //Create the request
    $output = drupal_http_request($location_api . "/locations/specialties/" );
    $decoded_output = json_decode($output->data);
    foreach ($decoded_output as $row) {
       $specialty_array[$row->Id] = $row->Name;
    }

    /*
    * Put the array into the select,
    * multi select enabled with the chosen module
    */

    $form['value'] = array(
      '#type' => 'select',
      '#title' => t('Specialties'),
      '#multiple' => TRUE,
      '#size' => 5,
      '#default_value' =>(!empty($this->value)) ? $this->value : '',
      '#options' => $specialty_array,
      '#attributes' => array(
	      'placeholder' => t('Example: Pediatrics'),
	      '#size' => 4,
	    )
    );
  }

}
