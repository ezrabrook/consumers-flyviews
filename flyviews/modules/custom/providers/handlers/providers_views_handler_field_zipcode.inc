<?php

/**
 * @file providers_views_handler_field_numeric.inc
 * 
 */

/**
 * Field handler to render a field as a numeric value.
 */
class providers_views_handler_field_zipcode extends views_handler_field_numeric {

  /**
   * Called to add the field to a query.
   */
  function query() {
    $this->field_alias = $zip;
  }
     
}

