<?php 
/**
 * @file consumers_providers.admin.inc
 */

/**
 * Form Builder; administrative form
 */

function providers_admin_form($form) {
	$form = array();
	$form['providers_api_url'] = array (
			'#title' => t('API URL'), 
			'#description' => t('Enter the URL where the provider info can be fetched from, do not include the trailing slash'),
			'#type' =>'textfield', 
			'#default_value' => variable_get('providers_api_url', PROVIDERS_DEFAULT_API_URL),
	);
	$form['providers_debug_mode'] = array(
			'#title' => t('Debug mode'),
			'#description' => t('Enable debug mode if you would like to see the url when the request is being made.'),
			'#type' =>'checkbox',
			'#default_value' => variable_get('providers_debug_mode', PROVIDERS_DEFAULT_DEBUG_MODE),	
	);
	return system_settings_form($form);
}