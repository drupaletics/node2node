<?php

// $Id$
/**
 * @file
 * Return a administration-form for node2node-module
 */

/**
 * define forms for administration of node2node-module
 *
 * @ingroup_forms
 * @see system_stettings_form()
 */
function node2node_admin_settings() {
  //Call a array, containing the nodetypes with internal names as #key and
  //userfriendly names for the value
  $options = node_get_types('names');
  //Defines the admin-form
  $form['node2node_nodetypes'] = array(
      '#type' => 'checkboxes',
      '#title' => 'Choose nodetypes which should run with node2node-feature',
      '#options' => $options,
      '#default_value' => variable_get('node2node_nodetypes', array('Story')),
      '#description' => t('The node2node-Button will available on all form of nodetypes you choose here.'),
  );
  return system_settings_form($form);
}
