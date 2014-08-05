<?php
/**
 * @file locations.views.inc
 */

/**
 * Implements hook_views_data().
 * Creates a custom view based on the fields provided
 */

 function locations_views_data() {
 $data = array();

 $data['Locations']['table'] = array(
   'group' => t('Locations'),
   'base' => array(
     'title' => t('Locations'),
     'field' => 'Id',
     'help' => t('Information about Locations fetched from an external website.'),
     'query class' => 'locations_query',
    ),
  );

	//Secondary Languages Field/Filter
  $data['Locations']['Languages'] = array (
    'title' => t('Secondary Languages Spoken'),
		'help' => t('Secondary Languages at the Location'),
		'field' => array(
	  	'handler' => 'locations_views_handler_languages',
	   	 ),
		'filter' => array(
	  	'handler' => 'locations_views_handler_filter_languages',
	    ),
	);

   //Specialities Field/Filter
  $data['Locations']['Specialties'] = array (
		'title' => t('Specialties Name'),
		'help' => t('Specialties Name'),
		'field' => array(
	         'handler' => 'locations_views_handler_specialties',
			),
		'filter' => array(
		  'handler' => 'locations_views_handler_filter_keyword_specialty'
			),
	);

	//Officetypes Field/Filter (used for image on locations)
  $data['Locations']['officetypes'] = array(
	  'title' => t('Office Types'),
	  'help' => t('Name of Location'),
	  'field' => array(
        'handler' => 'locations_views_handler_officetype',
		  ),
	   'filter' => array(
				'handler' => 'locations_views_handler_filter_officetype',
		 ),
	);
	//Group Affiliations Field and Filter
	$data['Locations']['groups'] = array(
	  'title' => t('Group Affiliations'),
	  'help' => t('Group Affiliation for the Location'),
	  'field' => array(
        'handler' => 'locations_views_handler_field_groups',
		  ),
	   'filter' => array(
				'handler' => 'locations_views_handler_filter_groups',
		 ),
	);

  //Office Type Name Field (used for name on locations)
  $data['Locations']['OfficeTypeName'] = array(
	  'title' => t('Office Type Name'),
	  'help' => t('Office Type Name'),
	  'field' => array(
        'handler' => 'locations_views_handler_officetype_name',
		  ),
	);

	//Location Address Field
	$data['Locations']['Address'] = array(
	  'title' => t('Address'),
	  'help' => t('Address'),
	  'field' => array(
			'handler' => 'locations_views_handler_address',
		  ),
	);

  //Distance Field from search zipcode
	$data['Locations']['Distance'] = array(
	  'title' => t('Distance'),
	  'help' => t('Distance'),
	  'field' => array(
			'handler' => 'locations_views_handler_distance',
		),
	);

	//Address Field more suitable for Geocoding(email/google api)
	$data['Locations']['AddressGeocode'] = array(
	  'title' => t('Address for geocode map or text'),
	  'help' => t('Address for map or text'),
	  'field' => array(
				'handler' => 'locations_views_handler_address_geocode',
		),
	);

	//Geocoded Latitude
	$data['Locations']['GeoLat'] = array(
	  'title' => t('Geocoded Latitude'),
	  'help' => t('Geocoded Latitude Value(Float)'),
	  'field' => array(
				'handler' => 'locations_views_handler_latitude',
		),
	);

	//Geocoded Longitude
	$data['Locations']['GeoLong'] = array(
	  'title' => t('Geocoded Longitude'),
	  'help' => t('Geocoded Longitude Value(Float)'),
	  'field' => array(
				'handler' => 'locations_views_handler_longitude',
		),
	);

	//Phone Field
	$data['Locations']['Phone'] = array(
	  'title' => t('Phone'),
	  'help' => t('Phone Number'),
	  'field' => array(
	     'handler' => 'locations_views_handler_phone',
		),
	);

	//Fax Field
	$data['Locations']['Fax'] = array(
	  'title' => t('Fax'),
	  'help' => t('Fax Number'),
	  'field' => array(
	    'handler' => 'locations_views_handler_fax',
		),
	);

	//Hours Field
	$data['Locations']['Hours'] = array(
	  'title' => t('Hours'),
	  'help' => t('Hours'),
	  'field' => array(
	    'handler'=> 'locations_views_handler_hours',
		),
	);

	//Radius Filter
	$data['Locations']['radius'] = array(
	  'title' => t('Radius'),
	  'help' => t('Radius for Location'),
    'filter' => array(
	      'handler'=> 'locations_views_handler_filter_radius',
		),
	);

	//Zipcode Filter
	$data['Locations']['Zipcode'] = array(
	  'title' => t('ZipCode'),
	  'help' => t('Zipcode for Location'),
	  'filter' => array(
		 		'handler' => 'locations_views_handler_filter_zipcode',
		),
	);

	//Keyword Filter
	$data['Locations']['keyword'] = array(
	  'title' => t('Keyword'),
	  'help' => t('Location Keyword (do not alter)'),
	  'filter' => array(
		  'handler'=> 'locations_views_handler_filter_keyword',
		),
	);
	return $data;
}

 /**
  * Implements hook_views_plugins()
  */
 function locations_views_plugins() {
 	$plugins = array(
 		'query' => array(
 		'locations_query' => array(
 			'title' => t('LocationsAPIRequest'),
 			'help' => ('Uses LocationsAPIRequest for querying information about Locations from an external api'),
 		        'handler' =>'locations_views_plugin_query',
 			),
 		),
 	);

 	return $plugins;
 }

