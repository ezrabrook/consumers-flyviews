<?php

/**
 * @file providers_views_handler_filter_equality_type.inc
 * Basic "Provider" equality filter handler specifically for officetype.
 */

/**
 * Simple filter to handle equality for the radius.
 */
class providers_views_handler_filter_equality_type extends providers_views_handler_filter_equality {

  /**
   * Provide the form for choosing a year.
   */
  function value_form(&$form, &$form_state) {
    $form['value'] = array(
      '#type' => 'select',
      '#title' => t('Type'),
      '#multiple' => true,
      '#size' => 4,
      '#default_value' => (!empty($this->value)) ? $this->value : 'All',
      '#options' => array(
        'All' => '-Any-',
        '1'  => 'Primary Care Physician',
	'2'  => 'Specialist',
        '4'  => 'Ancillary',
        '5'   => 'Mental/Behavioral',
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