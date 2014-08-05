<?php

/**
 * @file providers_views_handler_filter_affiliations.inc
 * Basic "Locations" equality filter handler.
 */

/**
 * Custom Filter for hospital affiliations
 */
class providers_views_handler_filter_affiliations extends views_handler_filter_equality{
  /**
   * Add this filter to the request.
   */
   function query() {
      $this->query->request_arguments[$this->real_field] = $this->value;
    }

    function value_form(&$form, &$form_state){
      //Get the provider api url
      $provider_api = variable_get('providers_api_url');

      $hospitals_array = array('All' => '-Any-');

      $output = array();

      $output = drupal_http_request($provider_api . "/hospitals/used/" );

      $decoded_output = json_decode($output->data);

      foreach ($decoded_output as $row) {
        $hospitals_array[$row->Id] = $row->Name;
      }

      //sort array alphabetically, but preserve ID structure
      //function in locations.module
      aasort($hospitals_array);

      $form['value'] = array(
        '#title' => 'Hospital Affiliations',
        '#type' => 'select',
        '#size' => 5,
        '#multiple' => TRUE,
        '#default_value' => (!empty($this->value)) ? $this->value : '',
        '#options' => $hospitals_array,
        '#attributes' => array(
            'placeholder' => t('Example: McLaren Regional Medical Center'),
            '#size' => 4,
         )
      );

    }//end value_form

}//end class
