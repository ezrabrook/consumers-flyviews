<?php 
/**
 * @file provider_context.inc
 */

$plugin = array(
	'title' => t('Provider'), 
		'description' => t('A Provider Object'), 
		'context' => 'provider_context_settings_form', 
		'keyword' => 'provider', 
		'context name' => 'provider', 
		'convert list' => 'provider_context_convert_list', 
		'covert' => 'provider_context_covert', 
		'placeholder form' => array(
	       '#type' => 'textfield', 
		   '#description' => t('Enter the ID of the Provider'), 
		), 
 );

function provider_context_create($empty, $data = NULL, $conf = FALSE) {
	$context = new ctools_context('provider');
	$context->plugin = 'provider';
	
	if ($empty) {
		return $context; 
	}
	 
	if ($conf) {
		$request = new ProvidersAPIRequest();
		$data = $request
		->getItem($data['ProviderId'])
		->execute();
	}
	
	if (!empty($data)) {
		$context->data = $data;
		$context->argument = check_plain($data->id);
		$context->title = t('Provider @FullName', array('@FullName' =>$data->FullName));
		return context;
	}
	 return FALSE;
	 
}

function provider_context_settings_form($form, &$form_state){
$conf = $form_state['conf'];
$form['provider'] = array(
	'#title' => t('Provider ID'), 
	'#description' => t('Enter a Provider ID'), 
	'#default_value' => $conf['provider'],
	'#type' => 'textfield', 
	
	);
	return $form;
}
	

function provider_context_settings_form_submit($form, &$form_state){
	$form_state['conf']['provider'] = $form_state['values']['provider'];
}

/**
 * Providers a list of keywords for use in a content type, pane etc. 
 */
function provider_context_convert_list() {
	return array(
		'FullName' => t('Full Name'),
		'FirstName' => t('First Name'), 
		'LastName' => t('Last Name'), 
		'Gender' => t('Gender'), 
		'LocationId' => t('LocationId'), 
		'ZipCode' => t('Zipcode'), 
		'Radius' => t('Radius'),
	);
}

function provider_context_convert($context, $type){
	return $context->data->{$type};
}