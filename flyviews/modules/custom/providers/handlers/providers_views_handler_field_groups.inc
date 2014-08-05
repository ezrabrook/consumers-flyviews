<?php

/**
 * @file providers_views_handler_field_groups.inc
 * Sub Provider handler arrays
 */

/**
 * Field handler to provide simple renderer that allows linking to a Provider.
 */


class providers_views_handler_field_groups extends views_handler_field {

  function construct() {
    parent::construct();
  }

  /**
   * Called to add the field to a query.
   */
   function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
    }

  function render($values) {

    //returns only the first Value

    if (isset($values->ProviderLocations[0]->Location->Groups[0]->Name)){
          $group = $values->ProviderLocations[0]->Location->Groups[0]->Name;
          return  "<ul><li>" . $group . "</li></ul>";
    }
    else{
    return null;}
  }
}
