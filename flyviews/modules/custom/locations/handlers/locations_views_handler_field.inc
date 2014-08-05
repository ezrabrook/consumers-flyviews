<?php

/**
 * @file locations_views_handler_field.inc
 * NOT USED
 */

/**
 * Field handler to provide simple renderer that allows linking to a Location.
 */
class locations_views_handler_field extends views_handler_field {

  function init(&$view, &$options) {
    parent::init($view, $options);

    if (!empty($this->options['link_to_provider'])) {
	   $this->aliases['Id'] = 'id';
     $this->additional_fields['Id'] = array('field' => 'LocationId');
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
      '#title' => t('Link this field to the Location page.'),
      '#description' => t("Enable to override this field's links."),
      '#type' => 'checkbox',
      '#default_value' => !empty($this->options['link_to_provider']),
    );
    parent::options_form($form, $form_state);
  }

  /**
   * Render whatever the data is as a link to the Location page.
   * Data should be made XSS safe prior to calling this function.
   */
  function render_link($data, $values)
	{
		if (!empty($this->options['link_to_provider']) && $data !== NULL && $data !== '') {
		  $this->options['alter']['make_link'] = TRUE;
		  $this->options['alter']['path'] = "locations/" . $this->get_value($values, 'Id');
		}
		return $data;
	}

  function render($values) {
		$value = $this->get_value($values);
		return $this->render_link($this->sanitize_value($value), $values);
	}

  /**
   * Called to add the field to a query.
   */
  function query() {
    $this->field_alias = $this->Location->real_field;
  }

}

