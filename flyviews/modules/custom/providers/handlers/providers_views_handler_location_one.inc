<?php

/**
 * @file providers_views_handler_location_one.inc
 * Sub Location handler
 */

/**
 * Field handler to provide simple renderer that allows linking to a Location.
 */
class providers_views_handler_location_one extends views_handler_field {

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

  //instatiate all the variables that we could need
  $phone = '';
  $fax = '';
  $latlong = '';
  $geocode = '';
  $distance = '';
  $getdirections = '';
  $message =  '';
  $ot_name = '';
  $ot_id = '';
  $ot_src = '';
  $email = '';
  $address = '';
  $zip = '';
  $state = '';
  $city = '';
  $group = '';
  $address1 = '';
  $address2 = '';
  $hours = '';
  $location = '';
  $locations = array();
  $name = '';
  $item = '';
  $counter = 0;

  if(isset($values->ProviderLocations)){
    foreach($values->ProviderLocations as $obj){
    		if($counter++ < 1) continue;
    				if(isset($obj->Location->OfficeType)){
    					$ot_name = $obj->Location->OfficeType->Name;
    					$ot_id = $obj->Location->OfficeType->Id;
    					$ot_src = office_type($ot_id);
    					$ot_src = '<div class="row"><div class="span2"><img class="officetype_image" src="' . $ot_src . '"></div>';
    				}
    				if(isset($obj->Location->Name)){
    					$name = $obj->Location->Name;
    					$name = '<div class="span4"><h5 class="name_heading">'. $name . '</h5>';
    				}
    				if(isset($obj->Location->Address1)){
    					$address1 = $obj->Location->Address1;
    				}
    				if(!empty($obj->Location->Address2)){
    					$address2 = '<br/>' . $obj->Location->Address2;
    				}
    				if(isset($obj->Location->City)){
    					$city =  '<br/>' . $obj->Location->City;
    				}
    				if(isset($obj->Location->State)){
    					$state = $obj->Location->State->Abbr;
    					$state = ', ' . $state . ' ';
    				}
    				if(isset($obj->Location->ZipCode)){
    					$zip = $obj->Location->ZipCode;
    					$zip .= '<br/>';
    				}
    				if(isset($obj->Location->Phone)){
    					$phone = $obj->Location->Phone;
    					$phone = us_phone($phone) . '<br/>';
    					$phone = "Phone: " . $phone;
    				}
    				if(isset($obj->Location->Fax)){
    					$fax = $obj->Location->Fax;
    					$fax = us_phone($fax) . '<br/>';
    					$fax = "Fax: " . $fax;
    				}
    				if(isset($obj->Location->Distance)){
								$distance = $obj->Location->Distance . " miles";

						}

    				$item = $obj->Location->Hours;
    				if(isset($obj->Location->Hours)){
    						$hours = "</div><div class='span3'><h5 class='hours_heading'>Hours</h5>";
							  if (!empty($item->Sunday->Open) && !empty($item->Sunday->Close)) {
									 $hours = $hours . 'Sunday:' . '<span class="hours_right">'. $item->Sunday->Open . " - " . $item->Sunday->Close .'</span><br/>';
								}
								if (!empty($item->Monday->Open) && !empty($item->Monday->Close)) {
									 $hours = $hours . 'Monday:' . '<span class="hours_right">' . $item->Monday->Open . " - " . $item->Monday->Close . '</span><br/>';
								}
								if (!empty($item->Tuesday->Open) && !empty($item->Tuesday->Close)) {
									 $hours = $hours . 'Tuesday:' . '<span class="hours_right">'. $item->Tuesday->Open . " - " . $item->Tuesday->Close . '</span><br/>';
								}
								if (!empty($item->Wednesday->Open) && !empty($item->Wednesday->Close)) {
									 $hours = $hours . 'Wednesday:' . '<span class="hours_right">'. $item->Wednesday->Open . " - " . $item->Wednesday->Close .'</span><br/>';
								}
								if (!empty($item->Thursday->Open) && !empty($item->Thursday->Close)) {
									$hours = $hours . 'Thursday:' . '<span class="hours_right">'. $item->Thursday->Open . " - " . $item->Thursday->Close . '</span><br/>';
								}
								if (!empty($item->Friday->Open) && !empty($item->Friday->Close)) {
									 $hours = $hours . 'Friday:' . '<span class="hours_right">'.  $item->Friday->Open . " - " . $item->Friday->Close . '</span><br/>';
								}
								if (!empty($item->Saturday->Open) && !empty($item->Saturday->Close)){
									 $hours = $hours .  'Saturday:' . '<span class="hours_right">' . $item->Saturday->Open . " - " . $item->Saturday->Close .'</span><br/>';
								}
							  if($hours == "</div><div class='span3'><h5 class='hours_heading'>Hours</h5>") {
							     $noresults = t("Please call provider.");
									 $hours = $hours . $noresults . "</div>";
							  }
								elseif(($noresults == ' ') && ($hours == ' ')){
									 $noresults = t("Please call provider.");
									 $hours = $hours  . $noresults . "</div>" ;
							  }
							  else{
										$hours =  $hours . "</div>";
								}
						}

						if(isset($obj->Location->Groups)){
								foreach ($obj->Location->Groups as $grp){
									$group = $grp->Name;
									$group = '<div class="span3"><strong>Group Affliations:</strong><ul><li>' . $group  . '</li></ul>';
								}
								$group = $group . "</div></div>";

						}


						$location = $ot_src . $name . $address1 . $address2 . $city . $state . $zip . $phone . $fax . $distance . $hours . $group;

						$locations[$counter++] = $location;


      }
     return join( '<br/>' , $locations);
    }
    return;
  }
}

