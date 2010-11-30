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
  dsm($options);
  function make_array($options){
  foreach ($options as $key => $value) {
      $option[][$value] = $value;
  }
  return $option;
  }
  dsm($option);
  //Defines the admin-form
  $form['node2node_nodetypes'] = array(
      '#type' => 'checkboxes',
      '#title' => 'Choose nodetypes which should run with node2node-feature',
      '#options' => $options,
      '#default_value' => variable_get('node2node_nodetypes', array('Story')),
      '#description' => t('The node2node-Button will available on all form of nodetypes you choose here.'),
  );
  if (module_exists('views')) {
      foreach ($form['node2node_nodetypes']['#options'] as $value) {

      }
        $views = array('--' => '--');
        $all_views = views_get_all_views();
        foreach ($all_views as $view) {
          // Only 'node' views that have fields will work for our purpose.
          if ($view->base_table == 'node' && !empty($view->display['default']->display_options['fields'])) {
            if ($view->type == 'Default') {
              $views[t('Default Views')][$view->name] = $view->name;
            }
            else {
              $views[t('Existing Views')][$view->name] = $view->name;
            }
          }
        }

        $form['advanced'] = array(
           '#type' => 'fieldset',
           '#title' => t('Advanced - Nodes that can be referenced (View)'),
           '#collapsible' => TRUE,
           '#collapsed' => !isset($field['advanced_view']) || $field['advanced_view'] == '--',
         );
        if (count($views) > 1) {
          $form['advanced']['advanced_view'] = array(
            '#type' => 'select',
            '#title' => t('View used to select the nodes'),
            '#options' => $views,
            '#default_value' => isset($field['advanced_view']) ? $field['advanced_view'] : '--',
            '#description' => t('<p>Choose the "Views module" view that selects the nodes that can be referenced.<br />Note:</p>') .
              t('<ul><li>Only views that have fields will work for this purpose.</li><li>This will discard the "Content types" settings above. Use the view\'s "filters" section instead.</li><li>Use the view\'s "fields" section to display additional informations about candidate nodes on node creation/edition form.</li><li>Use the view\'s "sort criteria" section to determine the order in which candidate nodes will be displayed.</li></ul>'),
          );
          $form['advanced']['advanced_view_args'] = array(
            '#type' => 'textfield',
            '#title' => t('View arguments'),
            '#default_value' => isset($field['advanced_view_args']) ? $field['advanced_view_args'] : '',
            '#required' => FALSE,
            '#description' => t('Provide a comma separated list of arguments to pass to the view.'),
          );
        }
        else {
          $form['advanced']['no_view_help'] = array(
            '#value' => t('<p>The list of nodes that can be referenced can be based on a "Views module" view but no appropriate views were found. <br />Note:</p>') .
              t('<ul><li>Only views that have fields will work for this purpose.</li><li>This will discard the "Content types" settings above. Use the view\'s "filters" section instead.</li><li>Use the view\'s "fields" section to display additional informations about candidate nodes on node creation/edition form.</li><li>Use the view\'s "sort criteria" section to determine the order in which candidate nodes will be displayed.</li></ul>'),
          );
        }
      }
      dsm($form);
  return system_settings_form($form);
}
