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
    $views = array('--' => '--');
    $all_views = views_get_all_views();
    foreach ($all_views as $view) {
        // Only 'node' views that have fields will work for our purpose.
        if ($view->base_table == 'node' && !empty($view->display['default']->display_options['fields'])) {
            if ($view->type == 'Default') {
                $views[t('Default Views')][$view->name] = $view->name;
            } else {
                $views[t('Existing Views')][$view->name] = $view->name;
            }
        }

    }
    foreach($options as $option){
        $form[$option]['nodetype_select'] = array(
            '#title' => t('Settings for nodetype ').$option,
            '#type' => 'fieldset',
            '#collapsible' => TRUE,
            '#collapsed' => TRUE,
            //'#tree' => TRUE
        );

        $form[$option]['nodetype_select']['onoff'] = array(
            '#type' => 'checkbox',
            '#title' => $option,
            '#default_value' => variable_get('node2node_nodetype', 'Story')
        );
        $form[$option]['nodetype_select']['select_view'] = array(
            '#type' => 'select',
            '#title' => t('Choose a view for ') . $option,
            '#options' => $views,
        );
    }
    return system_settings_form($form);
}