<?php
/**
 * @file location_id.inc
 */

$plugin = array (
		'title' => t('Location: ID'),
		'keyword' => 'location', 
		'description' => t('Creates a Location context from the argument'), 
		'context' => 'location_argument_context', 
		'placeholder form' => array(
			'#type' => 'textfield', 
			'#description' => t('Enter the Location argument'), 
		), 
	);

function location_argument_context ($arg = NULL, $conf = NULL, $empty = FALSE) {
	if ($empty){
		return ctools_context_create_empty('location');
	}
	if (!is_numeric($arg)){
		return FALSE;
	}
	
	$request = new LocationsAPIRequest();
	$location = $request
	->getItem($arg)
	->execute();
	
	return ctools_context_create('location', $location);
}