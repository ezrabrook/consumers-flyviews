<?php

/**
 * @file locations_views_handler_filter_equality.inc
 * Basic "Locations" equality filter handler.
 * Only used to extend other filters
 */

/**
 * Simple filter to handle equality.
 */
class locations_views_handler_filter_equality extends views_handler_filter_equality {

  /**
   * Provide simple equality operator
   */
  function operator_options() {
    return array(
      '=' => t('Is equal to'),
    );
  }

  /**
   * Add this filter to the request.
   */
  function query() {
    $this->query->request_arguments[$this->real_field] = $this->value;
  }

}

