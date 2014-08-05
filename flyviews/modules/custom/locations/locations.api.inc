<? 
/**
 * @file locations.api.inc
 */

/**
 * Simple class for putting together a URL for the API call, and doing an HTTP request
 * for retrieving information about Locations
 * All public methods return $this and can be chained together, except the execute(),
 * which returns the response data.
 *
 * Possible and recommended improvement: implementing a caching logic.
 * See Last.FM module for a smart example:
 * http://drupalcode.org/project/lastfm.git/blob/refs/heads/7.x-2.x:/lastfm.api.inc
 */
 
class LocationsAPIRequest {
	//default API URL for the request
	private $api_url;
	
	//flag to designate whether or not we are in debug mode
	private $debug_mode;
	
	//API call arguments. USE ConsumersLocationsAPIRequest->addArgument() to set
	private $arguments = array();
	
	//The ID of a particular location. If it greater than 0, it means the request goes on
	//for certain locations, no arguments
	private $location_id = 0;
	
	//String for keyword
	private $keyword = '';
	
	/**
	 * Constructor
	 */
	public function __construct() {
		$this->api_url = variable_get('locations_api_url', LOCATIONS_DEFAULT_API_URL);
		$this->debug_mode = variable_get('locations_debug_mode', LOCATIONS_DEFAULT_DEBUG_MODE);
	}
	
/*
 * Sets the ID for the Provider, the execute() method will ignore the argument and the request will go for certain locations.
 */
	public function getItem($location_id){
		$this->location_id = $location_id;
		return $this;
	}
	
	public function keywordSearch($keyword){
		$this->keyword = $keyword;
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
		if ($this->location_id > 0) {
			$request_url = url($this->api_url . '/locations/' . $this->location_id, $options);
		}
		else if (!empty($this-> keyword)){
			$request_url = url($this->api_url . '/autocomplete/'. $this->keyword, $options);
		}
		else {
			$options['query'] = $this->arguments;
			$request_url = url($this->api_url .'/locations/search', $options);
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
			watchdog('locations', 'HTTP error !code received.', array('!code' => $response->code), WATCHDOG_ERROR);
			return FALSE;
		}
		$data = json_decode($response->data);		
		if (!is_object($data)){
			watchdog('locations', 'Did not receive a valid API response (invalid JSON).', array(), WATCHDOG_ERROR);
			return FALSE;
		}
		if (isset($data->error)){
			watchdog('locations', 'ERROR! !code received: %message', array('!code'=> $data->error, '%message' =>$data->message), WATCHDOG_ERROR);
		}
		return $this->parse($data);
	}
	
	/**
	 * Parses the response data
	 */
	private function parse($data) {
	    $parsed_data = $data->Locations;
		foreach($data as $item) {
      		$parsed_data = $item;
    	}
    //if ($this->provider_id > 0) {
      //return reset($parsed_data);
    //}
	return $parsed_data;
  } 
}

 	

