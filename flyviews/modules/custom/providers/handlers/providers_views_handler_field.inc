<?php

/**
 * @file providers_views_handler_field.inc
 * Basic "Provider" field handler.
 */

/**
 * Field handler to provide simple renderer that allows linking to a Provider.
 */
class providers_views_handler_field extends views_handler_field {

  function init(&$view, &$options) {
    parent::init($view, $options);

    if (!empty($this->options['link_to_provider'])) {
	 $this->aliases['Id'] = 'id';
     $this->additional_fields['Id'] = array('field' => 'ProviderId');
	 $this->additional_fields['FirstName'] = array( 'field' => 'FirstName');
    }
  }

  function option_definition() {
    $options = parent::option_definition();
    $options['link_to_provider'] = array('default' => FALSE);
    return $options;
  }

  /**
   * Provide link.
   */
  function options_form(&$form, &$form_state) {
    $form['link_to_provider'] = array(
      '#title' => t('Link this field to the Provider page.'),
      '#description' => t("Enable to override this field's links."),
      '#type' => 'checkbox',
      '#default_value' => !empty($this->options['link_to_provider']),
    );
    parent::options_form($form, $form_state);
  }

  /**
   * Render whatever the data is as a link to the Provider page.
   * Data should be made XSS safe prior to calling this function.
   */
  function render_link($data, $values)
	{
		if (!empty($this->options['link_to_provider']) && $data !== NULL && $data !== '') {
		  $this->options['alter']['make_link'] = TRUE;
		  $this->options['alter']['path'] = "providers/" . $this->get_value($values, 'ProviderId');
		}
		return $data;
	}
 
  function render($values) {
		//dsm($values);
		$value = $this->get_value($values);
		return $this->render_link($this->sanitize_value($value), $values);
	}

  /**
   * Called to add the field to a query.
   */
  function query() {
    $this->field_alias = $this->real_field;
  }

}

