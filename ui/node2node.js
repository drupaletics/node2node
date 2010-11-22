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
        $(callback).html(output)
      });//$.get     
    }//this.call

  }
  


  
  
  $(document).ready(function() {
  
  var n2nForm = $('form#node-form');
  var n2nContainer = 'form#node-form #node2nodeResponse';
  var n2nLink = $('form#node-form .node2node-link a');
  var n2nAdress = n2nLink.attr('href');
  var n2nRequest = new dropAjaxObj(n2nAdress,n2nContainer);


    n2nForm.append('<div id="node2nodeResponse"></div>');
    n2nLink.click(function(event){
      event.preventDefault();
      n2nRequest.call();
      return false;
    });
  });
}

/**
 * @todo: define .call()-method for dropJsonObj
 * @todo: implementation of jquery.ui.dialog
 */