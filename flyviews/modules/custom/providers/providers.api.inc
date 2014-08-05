<?php 
/**
 * @file providers.api.inc
 */

/**
 * Simple class for putting together a URL for the API call, and doing an HTTP request
 * for retrieving information about Providers
 * All public methods return $this and can be chained together, except the execute(),
 * which returns the response data.
 *
 * Possible and recommended improvement: implementing a caching logic.
 * See Last.FM module for a smart example:
 * http://drupalcode.org/project/lastfm.git/blob/refs/heads/7.x-2.x:/lastfm.api.inc
 */
  class ProvidersAPIRequest{
	//default API URL for the request
	private $api_url;
	
	//flag to designate whether or not we are in debug mode
	private $debug_mode;
	
	//API call arguments. USE ConsumersProvidersAPIRequest->addArgument() to set
	private $arguments = array();
	
	//The ID of a particular provider. If it greater than 0, it means the request goes on
	//for certain providers, no arguments
	private $provider_id = 0;
	
	/**
	 * Constructor
	 */
	public function __construct() {
		$this->api_url = variable_get('providers_api_url', PROVIDERS_DEFAULT_API_URL);
		$this->debug_mode = variable_get('providers_debug_mode', PROVIDERS_DEFAULT_DEBUG_MODE);
	}
	
/*
 * Sets the ID for the Provider, the execute() method will ignore the argument and the request will go for certain providers.
 */
	public function getItem($id){
		$this->Id = $id;
		return $this;
	}
	
	/**
	 * Sets argument for the request
	 */
	public function addArgument($key, $value) {
		$this->arguments[$key] = $value;
		return $this;
	}
	
	/**
	 * Executes the request
	 */
	public function execute() {
		$options = array();
		$options['absolute'] = TRUE;
		if ($this->provider_id > 0) {
			$request_url = url($this->api_url . '/providers/' . $this->provider_id, $options);
		}
		else {
			$options['query'] = $this->arguments;
			$request_url = url($this->api_url .'/providers/search', $options);
		}
		if ($this->debug_mode){
			drupal_set_message(t('Request URL: !url', array('!url' => urldecode($request_url))));
		}
		return $this->request($request_url);
	}
	
	/**
	 * Actual HTTP Request
	 */
	private function request($request_url) {
		$response = drupal_http_request($request_url);
		if ($response->code != 200){
			watchdog('providers', 'HTTP error !code received.', array('!code' => $response->code), WATCHDOG_ERROR);
			return FALSE;
		}
		$data = json_decode($response->data);
		//$langlength = count($data->Providers->Languages);
		//for($x=0;$x<$langlength;$x++){
		//	echo $data->Providers->Languages[$x]->Name;
		//	echo "<br>";
		//}
		if (!is_object($data)){
			watchdog('providers', 'Did not receive a valid API response (invalid JSON).', array(), WATCHDOG_ERROR);
			return FALSE;
		}
		if (isset($data->error)){
			watchdog('providers', 'ERROR! !code received: %message', array('!code'=> $data->error, '%message' =>$data->message), WATCHDOG_ERROR);
		}
		return $this->parse($data);
	}
	
	
	/**
	 * Parses the response data
	 */
	private function parse($data) {
	    $parsed_data = $data->Providers;
		foreach($data as $item) {
			$parsed_data = $item;
        }
    //if ($this->Id > 0) {
      //return reset($parsed_data);
    //}
    return $parsed_data;
  }
}
