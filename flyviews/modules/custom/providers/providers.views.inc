<?php
/**
 * @file providers.views.inc
 */

/**
 * Implements hook_views_data().
 */
 function providers_views_data() {
 	$data = array();

 	//Base table definition
 	$data['provider']['table'] = array(
 		'group' =>  t('Providers'),
 	    'base'=> array(
 	    		'title' => t('Providers'),
 	    		'help' => t('Information about Providers from Consumers Mutual'),
 	    		'query class' =>'providers_query',
 	    	     ),
 	      );
	//Degrees
	$data['provider']['Degrees'] = array(
		'title'=> t('Degrees'),
		'help' => t('Degrees of the Provider'),
		'field' => array(
			'handler' => 'providers_views_handler_degrees',
		     ),
	      );
	//Educations
	$data['provider']['Educations'] = array(
		'title'=> t('Education'),
		'help' => t('Education of the Provider'),
		'field' => array(
			'handler' => 'providers_views_handler_educations',
			),
		);
	//Languages
	$data['provider']['Languages'] = array(
		'title' => t('Languages'),
		'help' => t('Secondary Languages Spoken'),
		'field' => array(
			'handler' => 'providers_views_handler_languages',
			),
		'filter' => array(
			'handler' => 'providers_views_handler_filter_languages',
			),
		);
	//ProviderLocations
	$data['provider']['ProviderLocations'] = array(
		'title' => t('Provider Locations'),
		'help' => t('Provider Locations'),
		'field' => array(
			'handler' => 'providers_views_handler_providerlocations',
			),
		);
	//ProviderType
	$data['provider']['ProviderType'] = array(
		'title' => t('Provider Type'),
		'help' => t('Provider Type'),
		'field' => array(
			'handler' => 'providers_views_handler_providertype',
			),
		);
		//First Name
	$data['provider']['FirstName'] = array(
		'title' => t('First Name'),
		'help' => t('First Name'),
		'field' => array(
			'handler' => 'providers_views_handler_provider_firstname',
			),
		);
		//Last Name
	$data['provider']['LastName'] = array(
		'title' => t('Last Name'),
		'help' => t('Last Name'),
		'field' => array(
			'handler' => 'providers_views_handler_provider_lastname',
			),
		);
		//Distance Based on zipcode
	$data['provider']['Distance'] = array(
	   'title' => t('Distance'),
	   'help' => t('Distance'),
	   'field' => array(
	      'handler' => 'providers_views_handler_distance',
		  ),
		);
	//Specialty
	$data['provider']['Specialties'] = array(
		'title' => t('Specialties'),
		'help' => t('Specialties'),
		'field' => array(
			'handler' => 'providers_views_handler_specialties',
			),
		);
 	//Provider Hours
 	$data['provider']['Hours_One'] = array(
 		'title' => t('Hours One'),
 		'help' => t('Hours for the closest location (first result)'),
 		'field' => array(
 			'handler' => 'providers_views_handler_hours_one',
 			),
 		);
	//Gender
	$data['provider']['Gender'] = array(
		'title' => t('Gender'),
		'help' => t('Provider Gender'),
		'field' => array(
			'handler' => 'providers_views_handler_gender',
			),
		);
	//Gender Name
	$data['provider']['Gender_Name'] = array(
	   'title' => t('Gender Name'),
	   'help' => t('Provider Gender Name'),
	   'field' => array(
		   'handler' => 'providers_views_handler_gender_name',
		   ),
       );
	  //accepts new patients
	$data['provider']['newpatients'] = array(
		'title' => t('Accepts New Patients'),
		'help' => t('Displays Yes, No, and Established Only'),
		'field' => array(
			'handler' => 'providers_views_handler_accepting_new',
		   ),
		'filter' => array(
			'handler' => 'providers_views_handler_filter_accepting_new',
		   ),
		);
	//Address from first result of provider
	$data['provider']['Address'] = array(
		'title' => t('Address'),
		'help' => t('Provider Address from first result'),
		'field' => array(
			'handler' => 'providers_views_handler_address',
			),
		);
	$data['provider']['Address_Geocode'] = array(
	   'title' => t('Address Geocode'),
	   'help' => t('Provider Geocode stucture address for texting/email/etc.'),
	   'field' => array(
	      'handler' => 'providers_views_handler_address_geocode',
		  ),
		);
	//Address from first result of provider
	$data['provider']['Phone'] = array(
		'title' => t('Phone'),
		'help' => t('Provider Phone from first result'),
		'field' => array(
			'handler' => 'providers_views_handler_phone',
			),
		);
	//Address from first result of provider
	$data['provider']['Fax'] = array(
		'title' => t('Fax'),
		'help' => t('Provider fax from first result'),
		'field' => array(
			'handler' => 'providers_views_handler_fax',
			),
		);
		//Lat
	$data['provider']['Latitude'] = array(
		'title' => t('Latitude'),
		'help' => t('Latitude'),
		'field' => array(
			'handler' => 'providers_views_handler_latitude',
			),
		);
		//Long
	$data['provider']['Longitude'] = array(
		'title' => t('Longitude'),
		'help' => t('Longitude'),
		'field' => array(
			'handler' => 'providers_views_handler_longitude',
			),
		);
	//Directions2
	$data['provider']['Directions_Two'] = array(
		'title' => t('Directions Two Link'),
		'help' => t('Directions Two Link'),
		'field' => array(
			'handler' => 'providers_views_handler_location_directions_two',
			),
		);
	//Zipcode
	$data['provider']['zipcode'] = array(
		'title' => t('Zipcode'),
		'help' => t('Zipcode for Location'),
		'field' => array(
			'handler' => 'providers_views_handler_field_zipcode',
			),
		'filter' => array(
			'handler' => 'providers_views_handler_filter_zipcode',
			),
		'sort' => array(
			'handler' => 'providers_views_handler_filter_numeric',
			),
		);
	//Radius
	$data['provider']['radius'] = array(
		'title' => t('Radius'),
		'help' => t('Sortable Field for Radius'),
		'filter' => array(
			'handler' => 'providers_views_handler_filter_equality_radius',
			),
		'sort' => array(
			'handler' => 'providers_views_handler_filter_numeric',
			),
		);
	//Specialties
	$data['provider']['specialties'] = array(
		'title' => t('Specialties'),
		'help' => t('Provider Specialties'),
		'filter' => array(
			'handler' => 'providers_views_handler_filter_keyword_specialties',
			),
		);
	$data['provider']['boards'] = array(
		'title' => t('Boards'),
		'help' => t('Boards'),
		'field' => array(
			'handler' => 'providers_views_handler_boards',
			),
		);
	//Providers hospital affiliations field and filter
	$data['provider']['hospitals'] = array(
		'title' => t('Hospital Affiliations'),
		'help' => t('Hospitals'),
		'field' => array(
			'handler' => 'providers_views_handler_affiliations',
			),
		'filter'=> array(
			'handler' => 'providers_views_handler_filter_affiliations',
			),
		);
	//Provider groups affiliations field and filter
	$data['provider']['groups'] = array(
		'title' => t('Group Affiliation'),
		'help' => t('Group Affiliation'),
		'field' => array(
			'handler' => 'providers_views_handler_field_groups',
			),
		'filter'=> array(
			'handler' => 'providers_views_handler_filter_groups',
			),
		);
	//Office Type (used for Provider and for Behavorial
	$data['provider']['type'] = array(
		'title' => t('Type'),
		'help' => t('Provider Type'),
		'filter' => array(
			'handler' => 'providers_views_handler_filter_equality_type',
			),
		);
	//Gender Female/Male/Unknown
	$data['provider']['gender'] = array(
		'title' => t('Gender'),
		'help' => t('Filter for Gender of Provider'),
		'filter' => array(
			'handler' => 'providers_views_handler_filter_gender',
			),
		);
	$data['provider']['officetype'] = array(
		'title' => t('Office Type'),
		'help' => t('Filter for Provider Office Type'),
		'filter' => array(
			'handler' => 'providers_views_handler_filter_equality_officetype',
			),
		);
	$data['provider']['LocalRowOne'] = array(
		'title' => t('LocationRowOne'),
		'help' => t('Secondary location details'),
		'field' => array(
			'handler' => 'providers_views_handler_location_one',
			),
		);
	$data['provider']['LocalRowTwo'] = array(
		'title' => t('LocationRowTwo'),
		'help' => t('Secondary location details'),
		'field' => array(
			'handler' => 'providers_views_handler_location_two',
			),
		);
	$data['provider']['LocalRowThree'] = array(
		'title' => t('LocationRowThree'),
		'help' => t('Secondary location details'),
		'field' => array(
			'handler' => 'providers_views_handler_location_three',
			),
		);
	$data['provider']['LocalRowFour'] = array(
		'title' => t('LocationRowFour'),
		'help' => t('Secondary location details'),
		'field' => array(
			'handler' => 'providers_views_handler_location_four',
			),
		);
	$data['provider']['LocalRowFive'] = array(
		'title' => t('LocationRowFive'),
		'help' => t('Secondary location details'),
		'field' => array(
			'handler' => 'providers_views_handler_location_five',
			),
		);
	$data['provider']['LocalRowSix'] = array(
		'title' => t('LocationRowSix'),
		'help' => t('Secondary location details'),
		'field' => array(
			'handler' => 'providers_views_handler_location_six',
			),
		);
	$data['provider']['LocalRowSeven'] = array(
		'title' => t('LocationRowSeven'),
		'help' => t('Secondary location details'),
		'field' => array(
			'handler' => 'providers_views_handler_location_seven',
			),
		);
	$data['provider']['keyword'] = array(
		'title' => t('Keyword'),
		'help' => t('Filter for Provider keywords'),
		'filter' => array(
			'handler' => 'providers_views_handler_filter_keywords',
			),
		);
   return $data;
 }

 /**
  * Implements hook_views_plugins()
  */
 function providers_views_plugins() {
 	$plugins = array(
 		'query' => array(
 		'providers_query' => array(
 			'title' => t('ProvidersAPIRequest'),
 			'help' => ('Uses ProvidersAPIRequest for querying information about Providers form an external api'),
 		    'handler' =>'providers_views_plugin_query',
 			),
 		),
 	);

 	return $plugins;
 }

