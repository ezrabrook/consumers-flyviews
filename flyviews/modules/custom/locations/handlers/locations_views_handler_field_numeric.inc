<?php

/**
 * @file locations_views_handler_field_numeric.inc
 * "Locations" numeric field handler.
 * Only used to extend certain fields
 */

/**
 * Field handler to render a field as a numeric value.
 */
class locations_views_handler_field_numeric extends views_handler_field_numeric {

  /**
   * Called to add the field to a query.
   */
  function query() {
    $this->field_alias = $this->real_field;
  }

}

