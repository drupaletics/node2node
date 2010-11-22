if (Drupal.jsEnabled){
  /**
   * Definieren eines objektes, welches den event-handler bindet, und daten vom server anfordert,
   * entgegennimmt und parst.
   */
  function dropAjaxObj(url,callback) {

    //configuration-attributes
    this.config = new Array();
    this.config['url'] = url;
    this.config['responded_obj'] = callback;

    //data-attribute
    this.db = new String();

    //call-method
    this.call = function(){
      $.get(this.config['url'], function(data){
        this.db = data;
      });//$.get
    }//this.call

    //jsonparse-method
    this.output = function(){
      var max = this.db.length;
      var html = '<div class="gotJson"><ul class="jsonList">';
      for(i=0; i <= max; i++){
        html += '<li class="jsonElement">';
        html += this.db[i];
        html += '</li>';
      }
      html += '</ul></div>';
      return html;
    }
  }

  var n2nForm = 'form#node-form';
  var n2nLink = 'form#node-form .node2node-link a';
  var n2nAdress = $(n2nLink).attr('href');
  var n2nRequest = new dropAjaxObj(n2nAdress);
  
  $(document).ready(function() {
    $(n2nLink).click(function(event){
      event.preventDefault();
      n2nRequest.call();
      return false;
    });
    $(n2nForm).ajaxComplete(function(e, xhr, settings){
      $(this).append(n2nRequest.jsonParse());
      return false;
    });
  });
}

/**
 * @todo: define .call()-method for dropJsonObj
 * @todo: implementation of jquery.ui.dialog
 */