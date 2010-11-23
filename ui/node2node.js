if (Drupal.jsEnabled){
  /**
   * Definieren eines objektes, welches den event-handler bindet, und daten vom server anfordert,
   * entgegennimmt und parst.
   */
  function dropAjaxObj(url,callback) {

    //configuration-attributes
    this.config = new Array();

    //data-attribute
    this.db = new String();

    //call-method
    this.call = function(){
      $.get(url, function(data){
        var output = $(data).find('div.view-content');
        $(callback).html(output);
        Drupal.attachBehaviors()
      });//$.get     
    }//this.call

  }
  
  $(document).ready(function() {

    /**
    *Predefine some jquery-objects to get natural feeling when going to run the code
    */

    var n2nForm = $('form#node-form');
    var n2nContainer = '#node2nodeResponse';
    var n2nLink = $('form#node-form .node2node-link a');
    var n2nAdress = n2nLink.attr('href');

    /**
     *Declare an object, which can handle ajax-calls
     */
    var n2nRequest = new dropAjaxObj(n2nAdress,n2nContainer);

    /**
     *##runcode
     *First append a new div and build a jquery-object from it
     */

    n2nForm.append('<div id="node2nodeResponse"></div>');
    var n2nDialog = $('#node2nodeResponse');
    //run it as a closed dialog-box
    n2nDialog.dialog({autoOpen: false});

    /**
     *##eventhandler
     *declare eventlisteners for different click-events
     */

    //ajax call on click-event
    n2nLink.click(function(event){
      event.preventDefault();
      n2nRequest.call();
      n2nDialog.dialog('open');
      return false;
    });

    
 
  });
}

Drupal.behaviors.n2nDialogClick = function(){
  $('#node2nodeResponse .field-content a').click(function(event){
    event.preventDefault();
    n2nLinkHtml = '&lt;a href="';
    n2nLinkHtml += $(this).attr('href');
    n2nLinkHtml += '"&gt;';
    n2nLinkHtml += $(this).text();
    n2nLinkHtml += '&lt;/a&gt;';
    $('#edit-body').append(n2nLinkHtml);
  });
}
/**
 * @todo: define .call()-method for dropJsonObj
 * @todo: implementation of jquery.ui.dialog
 */