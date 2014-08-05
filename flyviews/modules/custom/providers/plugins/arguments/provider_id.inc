<?php
/**
 * @file provider_arg.inc
 */

$plugin = array (
		'title' => t('Provider: ID'),
		'keyword' => 'provider', 
		'description' => t('Creates a Provider context from the argument'), 
		'context' => 'provider_argument_context', 
		'placeholder form' => array(
			'#type' => 'textfield', 
			'#description' => t('Enter the Provider argument'), 
		), 
	);

function provider_argument_context ($arg = NULL, $conf = NULL, $empty = FALSE) {
	if ($empty){
		return ctools_context_create_empty('provider');
	}
	if (!is_numeric($arg)){
		return FALSE;
	}
	
	$request = new ProvidersAPIRequest();
	$provider = $request
	->getItem($arg)
	->execute();
	
	return ctools_context_create('provider', $provider);
}