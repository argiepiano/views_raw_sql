<?php

/**
 * A handler to provide a filter that is completely custom SQL by the administrator.
 *
 * @ingroup views_filter_handlers
 */
class views_handler_filter_views_raw_sql extends views_handler_filter {

  function query() {

    $raw_sql = $this->options['raw_sql'];
    // Get replacement tokens.
    $tokens = views_raw_sql_get_query_tokens($this->view, $this->options['id']);
    // And replace.
    $raw_sql = str_replace(array_keys($tokens), $tokens, $raw_sql);

    $this->ensure_my_table();

    if (!empty($this->options['raw_sql_use_having']))
      $this->query->add_having_expression($this->options['group'], $raw_sql);
    else
      $this->query->add_where_expression($this->options['group'], $raw_sql);

  } // query

  function option_definition() {

    $options = parent::option_definition();

    $options['raw_sql'] = array('default' => '');
    $options['raw_sql_use_having'] = array('default' => FALSE);

    return $options;

  } // option_definition

  function options_form(&$form, &$form_state) {

    parent::options_form($form, $form_state);

    $form['raw_sql'] = array(
      '#type' => 'textarea',
      '#title' => 'SQL',
      '#description' => t('This SQL will be added to the query as a filter expression. You can use placeholders like in field rewrite.'),
      '#default_value' => $this->options['raw_sql'],
      '#required' => TRUE,
    );
    $form['raw_sql_use_having'] = array(
      '#type' => 'checkbox',
      '#title' => 'Use HAVING clause',
      '#description' => t('Add this SQL to the query HAVING clause rather than the WHERE clause'),
      '#default_value' => $this->options['raw_sql_use_having']
    );

    if (!user_access('edit views raw sql')) {
      $form['raw_sql']['#disabled'] = TRUE;
      $form['raw_sql']['#description'] = t('You lack %permission permission to edit this field.', array('%permission' => 'edit views raw sql'));
    } // if

  } // options_form

  /**
   * Simple submit handler
   */
  function options_submit(&$form, &$form_state) {

    $this->options['raw_sql'] = $form_state['values']['options']['raw_sql'];
    $this->options['raw_sql_use_having'] = $form_state['values']['options']['raw_sql_use_having'];

  } // options_submit

} // views_handler_filter_views_raw_sql
