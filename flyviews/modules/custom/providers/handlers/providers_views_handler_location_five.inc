<?php

/**
 * @file providers_views_handler_location_five.inc
 * Sub Location handler
 */

/**
 * Field handler to provide simple renderer that allows linking to a Location.
 */
class providers_views_handler_location_five extends views_handler_field {

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
	$num = '';
	$fax = '';
	$latlong = '';
	$distance = '';
	$getdirections = '';
	$message =  '';
	if (isset($values->ProviderLocations[5] )){
	$item = $values->ProviderLocations[5]->Location;
		if (!empty($item->Phone)){
			$num = $item->Phone;
			$num = preg_replace('/[^0-9]/', '', $num);
		 
			$len = strlen($num);
			if($len == 7)
			$num = preg_replace('/([0-9]{3})([0-9]{4})/', '$1-$2', $num);
			elseif($len == 10)
			$num = preg_replace('/([0-9]{3})([0-9]{3})([0-9]{4})/', '($1) $2-$3', $num);
			$num = "Phone: " . $num;
		}
		if (!empty($item->Fax)){
			$fax = $item->Fax;
			$fax = preg_replace('/[^0-9]/', '', $fax);
		 
			$len = strlen($fax);
			if($len == 7)
			$fax = preg_replace('/([0-9]{3})([0-9]{4})/', '$1-$2', $fax);
			elseif($len == 10)
			$fax = preg_replace('/([0-9]{3})([0-9]{3})([0-9]{4})/', '($1) $2-$3', $fax);
			$fax = "Fax: " . $fax;
		}
		if(!empty($item->OfficeType)){
		    $office = $item->OfficeType->Name;
			if ($office == 'Ambulatory Surgical Center'){
				$officetype = t("/sites/all/modules/flyviews/modules/custom/files/HOSPITAL.jpg");
			}
			elseif ($office == 'Behavioral Health'){
				$officetype = t("/sites/all/modules/flyviews/modules/custom/files/MENTAL.jpg");
			}
			elseif ($office == 'Chiropractor'){
				$officetype = t("/sites/all/modules/flyviews/modules/custom/files/CLINIC.jpg");
			}
			elseif ($office == 'Clinic') {
				$officetype = t("/sites/all/modules/flyviews/modules/custom/files/CLINIC.jpg");
			}
			elseif ($office == 'DME'){
				$officetype = t("/sites/all/modules/flyviews/modules/custom/files/MEDICALSUPPLIES.jpg");
			}
			elseif ($office == 'FQHC'){
				$officetype = t("/sites/all/modules/flyviews/modules/custom/files/CLINIC.jpg");
			}
			elseif ($office == 'Health Department'){
				$officetype = t("/sites/all/modules/flyviews/modules/custom/files/CLINIC.jpg");
			}
			elseif ($office == 'Hospice'){
				$officetype = t("/sites/all/modules/flyviews/modules/custom/files/HOSPICE.jpg");
			}
			elseif ($office == 'Hospital'){
				$officetype = t("/sites/all/modules/flyviews/modules/custom/files/HOSPITAL.jpg");
			}
			elseif ($office == 'Lab'){
				$officetype = t("/sites/all/modules/flyviews/modules/custom/files/LABS.jpg");
			}
			elseif ($office == 'Pharmacy'){
				$officetype = t("/sites/all/modules/flyviews/modules/custom/files/PHARM.jpg");
			}
			elseif ($office == 'Physical Therapy') {
				$officetype = t("/sites/all/modules/flyviews/modules/custom/files/PHYSICALTHE.jpg");
			}
			elseif ($office == 'Radiology Center') {
				$officetype = t("/sites/all/modules/flyviews/modules/custom/files/XRAY.jpg");
			}
			elseif ($office == 'Skilled Nursing') {
				$officetype = t("/sites/all/modules/flyviews/modules/custom/files/SKILLEDNURSING.jpg");
			}
			elseif ($office == 'Urgent Care') {
				$officetype = t("/sites/all/modules/flyviews/modules/custom/files/URGENTCARE.jpg");
			}
			else {
				$officetype = t("http://placehold.it/150x100/D7D7D7/000000&text=Unknown");
			}
		}
		if(isset($item->Address2)) {
		   $address = '<span><h5 class="name_heading">' . $item->Name . '</h5>'. $item->Address1 . "<br>" . $item->Address2 . '<br/>' . $item->City . ",&nbsp;" . $item->State->Abbr . "&nbsp;" . $item->ZipCode . '<br/>' . $num .'<br/>'. $fax . '</span>' ;
		}
		if(empty($item->Address2)){
		   $address = '<span><h5 class="name_heading">' . $item->Name . '</h5>'. $item->Address1 . "&nbsp;" . '<br/>' . $item->City . ",&nbsp;" . $item->State->Abbr . "&nbsp;" . $item->ZipCode . '<br/>' . $num .'<br/>'. $fax . '</span>' ;
		}
		if (!empty($item->Sunday->Open)) {
			$sunday = 'Sunday:' . '<span class="hours_right">'. $item->Sunday->Open . " - " . $item->Sunday->Close .'</span>';
			}
		if (!empty($item->Monday->Open)) {
			$monday = 'Monday:' . '<span class="hours_right">' . $item->Monday->Open . " - " . $item->Monday->Close . '</span>';
			}
		if (!empty($item->Tuesday->Open)) {
			$tuesday = 'Tuesday:' . '<span class="hours_right">'. $item->Tuesday->Open . " - " . $item->Tuesday->Close . '</span>';
			}
		if (!empty($item->Wednesday->Open)) {
			$wednesday = 'Wednesday:' . '<span class="hours_right">'. $item->Wednesday->Open . " - " . $item->Wednesday->Close .'</span>';
			}
		if (!empty($item->Thursday->Open)) {
			$thursday = 'Thursday:' . '<span class="hours_right">'. $item->Thursday->Open . " - " . $item->Thursday->Close . '</span>';
			}
		if (!empty($item->Friday->Open)) {
			$friday = 'Friday:' . '<span class="hours_right">'.  $item->Friday->Open . " - " . $item->Friday->Close . '</span>';
			}
		if (!empty($item->Saturday->Open)){
			$saturday = 'Saturday:' . '<span class="hours_right">' . $item->Saturday->Open . " - " . $item->Saturday->Close .'</span>';
			}
		if((empty($item->Sunday->Open)) && (empty($item->Monday->Open)) && (empty($item->Tuesday->Open)) && (empty($item->Wednesday->Open)) && (empty($item->Thursday->Open)) && (empty($item->Friday->Open)) && (empty($item->Saturday->Open))){
			$noresults = t("Please call provider.");
			}
    if(isset($noresults)) {
      $Hours = "<H5 class='hours_heading'>Hours</H5>" .$noresults. "<BR>";
    } else {
      $Hours = "<H5 class='hours_heading'>Hours</H5>" .$noresults. $monday ."<BR>". $tuesday ."<BR>". $wednesday ."<BR>". $thursday ."<BR>". $friday ."<BR>".$saturday . "<BR>". $sunday ."<BR>";
    }
		
		if(isset($item->Address2)) {
		   $geocode = $item->Name . " \n" . $item->Address1 . " " . $item->Address2 . "\n". $item->City . ", " . $item->State->Abbr . " " . $item->ZipCode . " " ;
		}
		if(empty($item->Address2)){
		   $geocode =  $item->Name . " \n " . $item->Address1 . " \n" . $item->City . ", " . $item->State->Abbr . " " . $item->ZipCode . " " ;
		}
		if(isset($item->Geocode->latitude) && isset($item->Geocode->longitude)){
			$latlong = $item->Geocode->latitude . "," . $item->Geocode->longitude;
		}
		
		if(isset($item->Geocode->latitude) && isset($item->Geocode->longitude)){
			$latlong = $item->Geocode->latitude . "," . $item->Geocode->longitude;
			$getdirections = '<a target="_blank" href="/getdirections/latlon/to/' . $latlong . '/' . $geocode. '?width=100%&height=100%">Get Directions</a>';
		}
		else {
			$getdirections = '<a target="_blank" href="/getdirections/to/' . $geocode. '?width=100%&height=100%">Get Directions</a>';
		
		}
	
		if(isset($item->Distance)){
			$distance = $item->Distance . " miles";
		}
		$message = "Your requested provider details are available here: \n" . $geocode ."\n". 	$office ."\nPlease contact the office of this provider for more information";
		$email_message = '';
		$email_message = rawurlencode($message);
	
		
		$emaillink = "<a class='make_left' href=mailto:?subject=Consumers%20Provider%20Information&body=" . $email_message . ">Email this Information</a>";
		
		
				
		return "<div class='span2'><img class='officetype_image' src='" . $officetype . "'></div><div class='span4'>" . $address ."<br/>". $getdirections. "<br/>". $emaillink ."<br/>" . $distance . "</div><div class='span3'>" . $Hours . "</div>";
	}
		
	else{
		return; 
	}
	
      }
  }