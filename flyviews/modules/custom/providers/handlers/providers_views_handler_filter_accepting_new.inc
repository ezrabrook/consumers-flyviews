<?php

/**
 * @file providers_views_handler_filter_accepting_new.inc
 * Basic "Provider" equality filter handler specifically for radius.
 */

/**
 * Simple filter to handle equality for the radius.
 */
class providers_views_handler_filter_accepting_new extends providers_views_handler_filter_equality {

  /**
   * Provide the form for choosing a year.
   */
  function value_form(&$form, &$form_state) {
    $form['value'] = array(
      '#type' => 'select',
      '#title' => t('Accepts New Patients'),
      '#default_value' => (!empty($this->value)) ? $this->value : 'All',
      '#options' => array(
		'All'=> '-Any-',
		'1' => 'Yes',
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

