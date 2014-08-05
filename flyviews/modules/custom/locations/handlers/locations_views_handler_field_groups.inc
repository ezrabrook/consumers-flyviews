<?php

/**
 * @file locations_views_handler_field_groups.inc
 * Sub Location handler
 */

/**
 * Field handler to provide simple renderer that allows linking to a Location.
 */
class locations_views_handler_field_groups extends views_handler_field{

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
    $groups = array();
    if(isset($values->Location->Groups)){
      foreach($values->Location->Groups as $obj){
        $groups[] = $obj->Name;
      }
      return  join(', ', $groups);
    }
    return;
  }

}

