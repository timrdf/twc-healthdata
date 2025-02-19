<!DOCTYPE html>
<html lang="en" prefix="foaf: http://xmlns.com/foaf/0.1/ dc: http://purl.org/dc/terms/ conv: http://purl.org/twc/vocab/conversion/ void: http://rdfs.org/ns/void# health: http://healthdata.tw.rpi.edu/source/hub-healthdata-gov/vocab/ dcat: http://www.w3.org/ns/dcat#">
  <head>
    <meta charset="utf-8"/>
    <title>HealthData.tw.rpi.edu</title>
    <meta name="viewport" content="width=device-width, initial-scale=1.0"/>
    <meta name="description" content=""/>
    <meta name="author" content=""/>
    <link rel="alternate" type="application/rdf+xml" title="RDF/XML Version" href="{{lodspk.local.value}}.rdf" />
    <link rel="alternate" type="text/turtle" title="Turtle Version" href="{{lodspk.local.value}}.ttl" />
    <link rel="alternate" type="text/plain" title="N-Triples Version" href="{{lodspk.local.value}}.nt" />
    <link rel="alternate" type="application/json" title="RDFJSON Version" href="{{lodspk.local.value}}.json" />
    <link href="{{lodspk.home}}css/bootstrap.min.css" rel="stylesheet" type="text/css" media="screen" />
    <style>
      body {
        padding-top: 60px; /* 60px to make the container go all the way to the bottom of the topbar */
      }
      .wait{
        background-image:url('{{lodspk.home}}img/wait.gif');
        background-repeat:no-repeat;
        padding-right:20px;
        background-position: right;
      }
    </style>
    <link href="{{lodspk.home}}css/bootstrap-responsive.min.css" rel="stylesheet" type="text/css" media="screen" />
    <script type="text/javascript" src="{{lodspk.home}}js/jquery.js"></script>
    <script type="text/javascript" src="{{lodspk.home}}js/bootstrap.min.js"></script>
    <script type="text/javascript" src="{{lodspk.home}}js/bootstrap-typeahead.js"></script>
    <script type="text/javascript">
    $(document).ready(function(){
        $('.typeahead').typeahead({
            source: function (typeahead, query) {
              $('.typeahead').addClass('wait');[]
              return $.get('{{lodspk.home}}search/'+encodeURIComponent(query), { }, function (data) {
                  $('.typeahead').removeClass('wait');[]
                  return typeahead.process(data);
              }, 'json');
            },
            onselect: function (obj) {
              $('.typeahead').attr('disabled', true);
              window.location = obj.uri;
            }
        });
    });
    </script>
  </head>
  <body>
 <div class="navbar navbar-fixed-top">
      <div class="navbar-inner">
        <div class="container">
          <a class="btn btn-navbar" data-toggle="collapse" data-target=".nav-collapse">
            <span class="icon-bar"></span>
            <span class="icon-bar"></span>
            <span class="icon-bar"></span>
          </a>
          <a class="brand" href="{{lodspk.home}}"><img src='/img/health-tw-logo.png' width="24px"/> healthdata.tw.rpi.edu</a>
          <div class="nav-collapse">
            <ul class="nav">
              <li><a href="/">Home</a></li>
              <li><a href="{{lodspk.home}}datasets">Datasets</a></li>
              <li><a href="{{lodspk.home}}namedGraphs">Named Graphs</a></li>
              <li><a href="{{lodspk.home}}vocabularies">Vocabularies</a></li>
            </ul>
          </div><!--/.nav-collapse -->
        </div>
      </div>
    </div>
