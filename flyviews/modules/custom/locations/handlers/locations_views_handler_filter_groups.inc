<?php

/**
 * @file locations_views_handler_filter_groups.inc
 * Basic "Locations" equality filter handler.
 */


class locations_views_handler_filter_groups extends views_handler_filter_equality{
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
    $groups_array = array('All' => '-Any-');

    //Create the request
    $output = drupal_http_request($location_api . "/groups/used/" );
    $decoded_output = json_decode($output->data);
    foreach ($decoded_output as $row) {
       $groups_array[$row->Id] = $row->Name;
    }

    //sort groups_array locations.module
    aasort($groups_array);

    /*
    * Put the array into the select,
    * multi select enabled with the chosen module
    */

    $form['value'] = array(
      '#type' => 'select',
      '#title' => t('Group Affiliations'),
      '#multiple' => TRUE,
      '#size' => 5,
      '#default_value' =>(!empty($this->value)) ? $this->value : '',
      '#options' => $groups_array,
      '#attributes' => array(
        'placeholder' => t('Example: University of Michigan'),
        '#size' => 4,
      )
    );
  }

}
