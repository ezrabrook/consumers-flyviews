<?php 
/**
 * @file consumers_locations.admin.inc
 */

/**
 * Form Builder; administrative form
 */

function locations_admin_form($form) {
	$form = array();
	$form['locations_api_url'] = array (
			'#title' => t('API URL'), 
			'#description' => t('Enter the URL where the provider info can be fetched from, do not include the trailing slash'),
			'#type' => 'textfield', 
			'#default_value' => variable_get('locations_api_url', LOCATIONS_DEFAULT_API_URL),
	);
	$form['locations_debug_mode'] = array(
			'#title' => t('Debug mode'),
			'#description' => t('Enable debug mode if you would like to see the url when the request is being made.'),
			'#type' => 'checkbox',
			'#default_value' => variable_get('locations_debug_mode', LOCATIONS_DEFAULT_DEBUG_MODE),	
	);
	return system_settings_form($form);
}