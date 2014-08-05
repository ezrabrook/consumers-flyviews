<?php

/**
 * @file providers_views_handler_location_directions_two.inc
 * Sub Provider handler --for geocode text address or get directions
 */

/**
 * Field handler to provide simple renderer that allows linking to a Provider.
 */
class providers_views_handler_location_directions_two extends views_handler_field {

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
	$address = $values->ProviderLocations[1]->Location;
	if(isset($values->ProviderLocations[1]->Location)){
		if(!empty($address->Address2)) {
		   	$geocode = '&nbsp;' . $address->Name . '&nbsp;' . $address->Address1 . '&nbsp;' . $address->Address2 . '&nbsp;' . $address->City . '&nbsp;' . $daddress->State->Abbr . '&nbsp;' . $address->ZipCode . '&nbsp;' ;
		   	$latlong = $address->Geocode->Latitude . ',' . $address->Geocode->Longitude;
		   	$fullname = $values->Provider->FirstName . " " . $values->Provider->LastName;
		   	if(isset($address->Phone)){
		   	  $phone = $address->Phone;
		   	 }
		   	$getdirections = '<a class="make-left" href="/getdirections/latlon/to/' . $latlong . '/'. $geocode . '?width=100%&height=100%">Get Directions</a>';
            $emailprovider = '<a class="make_left" href="mailto:?subject=A Consumers Mutual Provider&body=Your%20requested%20provider%20details%20are%20available%20here: %0D%0A'. $fullname . '%0D%0A'. $geocode . '%0D%0APhone%3A' . $phone . '%0D%0A%0D%0A%0D%0A%0D%0APlease%20contact%20the%20office%20of%20this%20provider%20for%20more%20information.">Email this Information</a>';
            return $getdirections . '<br/>' $emailprovider; 
			}
		elseif(empty($values->ProviderLocations[1]->Address2)){
		   $geocode = '&nbsp;' . $address->Name . '&nbsp;' . $address->Address1 . '&nbsp;' . $address->City . '&nbsp;' . $address->Abbr . '&nbsp;' . $address->ZipCode . '&nbsp;' ;
		   		   	$latlong = $address->Geocode->Latitude . ',' . $address->Geocode->Longitude;
		   	$fullname = $values->Provider->FirstName . " " . $values->Provider->LastName;
		   	if(isset($address->Phone)){
		   	  $phone = $address->Phone;
		   	 }
		   	$getdirections = '<a class="make-left" href="/getdirections/latlon/to/' . $latlong . '/'. $geocode . '?width=100%&height=100%">Get Directions</a>';
            $emailprovider = '<a class="make_left" href="mailto:?subject=A Consumers Mutual Provider&body=Your%20requested%20provider%20details%20are%20available%20here: %0D%0A'. $fullname . '%0D%0A'. $geocode . '%0D%0APhone%3A' . $phone . '%0D%0A%0D%0A%0D%0A%0D%0APlease%20contact%20the%20office%20of%20this%20provider%20for%20more%20information.">Email this Information</a>';
		    }
	    else {
		return;
		}
	}
  }	
	
}

