<?php

/**
 * @file providers_views_handler_filter_keyword.inc
 * Basic "Locations" equality filter handler.
 */

/**
 * Simple filter to handle equality.
 */
class providers_views_handler_filter_keywords extends views_handler_filter_search{
  /**
   * Add this filter to the request.
   */

   function query() {
    $this->query->request_arguments[$this->real_field] = $this->value;
   }

   function value_form(&$form, &$form_state){
      $form['value'] = array(
         '#type' => 'textfield',
	 '#size' => 50,
         '#autocomplete_path' => 'providerlist/autocomplete',
	 '#attributes' => array('placeholder' => t('Example: Smith'))
	);
   }
}
