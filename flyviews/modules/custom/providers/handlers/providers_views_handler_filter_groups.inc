<?php

/**
 * @file providers_views_handler_filter_groups.inc
 * Basic "Locations" equality filter handler.
 */

/**
 * Simple filter to handle equality.
 */
class providers_views_handler_filter_groups extends views_handler_filter_equality{
  /**
   * Add this filter to the request.
   */
   function query() {
      $this->query->request_arguments[$this->real_field] = $this->value;
    }

    function value_form(&$form, &$form_state){
      //Get the provider api url
      $provider_api = variable_get('providers_api_url');

      $groups_array = array('All' => '-Any-');

      $output = array();

      $output = drupal_http_request($provider_api . "/groups/used/" );
      $decoded_output = json_decode($output->data);

      foreach ($decoded_output as $row) {
        $groups_array[$row->Id] = $row->Name;
      }

      //alphabetical sort $groups_array in locations.module
      aasort($groups_array);

      $form['value'] = array(
        '#title' => 'Group Affiliation',
        '#type' => 'select',
        '#size' => 5,
        '#multiple' => TRUE,
        '#default_value' => (!empty($this->value)) ? $this->value : '',
        '#options' => $groups_array,
        '#attributes' => array(
            'placeholder' => t('Example: Michigan State Health Team'),
            '#size' => 4,
         )
      );

    }//end value_form

}//end class
