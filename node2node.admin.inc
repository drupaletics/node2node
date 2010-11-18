<?php
/* 
 * Project:
 * Filename:
 * 
 * Development by Siegfried Dünkel
 * contact: chaosprinz76@googlemail.com
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published
 * by the Free Software Foundation.
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License 
 * along with this program as the file LICENSE.txt; if not, please see
 * http://www.gnu.org/licenses/old-licenses/gpl-2.0.txt.
 * 

 */

/**
 * define forms for administration of node2node-module
 *
 * @ingroup_forms
 * @see system_stettings_form()
 */
function node2node_admin_settings(){
  //Call a array, containing the nodetypes with internal names as #key and
  //userfriendly names for the value
  $options = node_get_types('names');
  //Defines the admin-form
  $form['node2node_nodetypes'] = array(
      '#type' => 'checkboxes',
      '#title' => 'Choose nodetypes which should run with node2node-feature',
      '#options' => $options,
      '#default_value' => variable_get('node2node_types', array('story')),
      '#description' => t('The node2node-Button will avaiable on all form of nodetypes you choose here.'),
  );
  return system_settings_form($form);
}
