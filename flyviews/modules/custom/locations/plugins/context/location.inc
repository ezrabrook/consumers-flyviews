<?php 
/**
 * @file location_context.inc
 * Plugin to provide a Location context
 */

$plugin = array(
	'title' => t('Location'), 
		'description' => t('A Location Object'), 
		'context' => 'location_context_create', 
		'edit form' => 'location_context_settings_form',
		'keyword' => 'location', 
		'context name' => 'location', 
		'convert list' => 'location_context_convert_list', 
		'convert' => 'location_context_covert', 
		'placeholder form' => array(
	        '#type' => 'textfield', 
		   '#description' => t('Enter the ID of the Location'), 
		), 
 );

function location_context_create($empty, $data = NULL, $conf = FALSE) {
	$context = new ctools_context('location');
	$context->plugin = 'location';
	
	if ($empty) {
		return $context; 
	}
	 
	if ($conf) {
		$request = new LocationsAPIRequest();
		$data = $request
		->getItem($data->Locations)
		->execute();
	}
	
	if (!empty($data)) {
		$context->data = $data;
		$context->argument = check_plain($data->Location->Id);
		$context->title = t('Location @Name', array('@Name' =>$data->Name));
		return context;
	}
	 return FALSE;
	 
}

function location_context_settings_form($form, &$form_state){
$conf = $form_state['conf'];
$form['location'] = array(
	'#title' => t('Location ID'), 
	'#description' => t('Enter a Location ID'), 
	'#default_value' => $conf['location'],
	'#type' => 'textfield', 
	
	);
	return $form;
}
	

function location_context_settings_form_submit($form, &$form_state){
	$form_state['conf']['location'] = $form_state['values']['location'];
}

/**
 * Locations a list of keywords for use in a content type, pane etc. 
 */
function location_context_convert_list() {
	return array(
		'FirstName' => t('First Name'), 
		'LastName' => t('Last Name'), 
		'Gender' => t('Gender'), 
		'LocationId' => t('LocationId'), 
		'ZipCode' => t('Zipcode'), 
		'Radius' => t('Radius'),
	);
}

function location_context_convert($context, $type){
	return $context->data->{$type};
}