<?php

/**
 * @file locations_views_handler_filter_keyword.inc
 * Basic "Locations" equality filter handler.
 */


class locations_views_handler_filter_keyword extends views_handler_filter_search{
  /**
   * Add this filter to the request.
   */
   function query() {
    $this->query->request_arguments[$this->real_field] = $this->value;
	}

  function value_form(&$form, &$form_state){
    /*
    * Uses the callback in the locations.module file to create a
    * function to show all of the specialties.
    */
      $form['value'] = array(
		    '#title' => 'Place name',
        '#type' => 'textfield',
		    '#size' => 50,
        '#autocomplete_path' => 'locations/autocomplete',
		    '#attributes' => array('placeholder' => t('Example: Walgreens')),
	   );

   }
}
