<?php
/*
*@file provider_views_handler_filter_languages.inc
*
*/

/**
 * Simple filter to handle languages.
 */
class providers_views_handler_filter_languages extends providers_views_handler_filter_equality {
  function query() {
     $this->query->request_arguments[$this->real_field] = $this->value;
    }


  function value_form(&$form, &$form_state){
      $provider_api = variable_get('providers_api_url');
      $specialty_array = array('All' => '-Any-');
	    $output = array();
      $output = drupal_http_request($provider_api . "/languages/used" );
      $decoded_output = json_decode($output->data);


    foreach ($decoded_output as $row) {
		    $languages_array[$row->Id] = $row->Name;
    }

    //alphabetical sort locations.module
	  aasort($languages_array, "Name");

    $form['value'] = array(
	  '#title' => 'Languages',
	  '#type' => 'select',
	  '#multiple' => TRUE,
	  '#size' => 5,
	  '#default_value' => (!empty($this->value)) ? $this->value : '',
	  '#options' => $languages_array,
	  '#attributes' => array(
	      'placeholder' => t('Example: Spanish'),
	      '#size' => 4,
	    )

	 );
  }
}
