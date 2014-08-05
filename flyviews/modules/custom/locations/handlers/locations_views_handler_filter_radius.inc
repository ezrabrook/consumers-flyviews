<?php

/**
 * @file locations_views_handler_filter_radius.inc
 * Basic "Location" equality filter handler specifically for radius.
 */

/**
 * Simple filter to handle equality for the radius.
 */
class locations_views_handler_filter_radius extends locations_views_handler_filter_equality {

  /**
   * Provide the form for choosing a radius value
   * and setting the user settings
   * api_recieves => user sees
   */
  function value_form(&$form, &$form_state) {
    $form['value'] = array(
      '#type' => 'select',
      '#title' => t('Radius'),
      '#default_value' => (!empty($this->value)) ? $this->value : '15',
      '#options' => array(
        '5' => 'Within 5 Miles',
        '10' => 'Within 10 Miles',
    	  '15' => 'Within 15 Miles',
        '20' => 'Within 20 Miles',
        '30' => 'Within 30 Miles',
        '50' => 'Within 50 Miles',
		    '100' => 'Within 100 Miles',
		    '250' => 'Within 250 Miles',
      ),
    );

    if (!empty($form_state['exposed'])) {
      $identifier = $this->options['expose']['identifier'];
      if (!isset($form_state['input'][$identifier])) {
        $form_state['input'][$identifier] = $this->value;
      }
    }
  }

}

