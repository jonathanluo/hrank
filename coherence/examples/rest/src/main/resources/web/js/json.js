/**
 * json.js
 *
 * AngularJS support for json.html.
 *
 * @author tam  2015.11.03
 * @since 12.2.1.1
 */

var app = angular.module('myApp', ['filters']);

/**
 * Define a "memory" filter for formatting content.
 */
angular.module('filters', [])
    .filter('jsonShort', function () {
        return function (jsonData) {
            var jsonString = JSON.stringify(jsonData);
            if (jsonString.length > 120) {
                return jsonString.substring(0, 117) + '...';
            }
            return jsonString;
        };
    });

app.controller('jsonCtrl', function($scope, $document,  $http, $window, $location, $q) {

    var sort      = '';
    var q         = '';
    var query     = $location.search();
    var urlPrefix = $location.protocol() + '://' + $location.host() + ':' + $location.port();

    $scope.delete      = false;
    $scope.save        = false;
    $scope.increment   = false;
    $scope.queryValue  = '';
    $scope.sortByValue = '';
    $scope.sortApplied = false;
    $scope.maxAge  = 0;
    $scope.minAge  = 0;

    if (query.q) {
        q = '?q=' + query.q;
        $scope.queryValue  = query.q;

    }
    if (query.sort) {
        sort = ';sort=' + query.sort;
        $scope.sortByValue = query.sort;
    }

    $scope.sortApplied = $scope.queryValue != '' || $scope.sortByValue != '';

    $scope.current_url = urlPrefix + '/cache/json/entries.json' + sort + q;

    // refresh the data
    $http.get('/cache/json/entries.json' + sort + q)
        .success(function (response) {
            $scope.entries = response;
        });

    // get min and max ages for all objects
    // using aggregators over native JSON!
    $http.get('/cache/json/long-min(age)')
        .success(function(response) {
        $scope.minAge = response;
        });

    $http.get('/cache/json/long-max(age)')
        .success(function(response) {
        $scope.maxAge = response;
        });

    // setup vars from messages
    action = $location.search().action;
    if (action == 'delete') {
        $scope.entryActioned = $location.search().key;
        $scope.delete = true;
    }
    else if (action == 'save') {
        $scope.entryActioned = $location.search().key;
        $scope.save = true;
    }
    else if (action == 'increment') {
        $scope.entryActioned = $location.search().key;
        $scope.increment = true;
    }

    // called on applying sort values
    $scope.applySortAndQuery = function(sort, query) {
        var url = 'json.html#';
        if (sort != '') {
            url += '?sort=' + encodeURIComponent(sort);
        }
        if (query != '') {
            url += (sort === '' ? '?' : '&') +
                    'q=' + encodeURIComponent(query);
        }

        $window.location.href = url;
        $window.location.reload();
    };

    // called on click to add entry
    $scope.addEntry = function() {
        $scope.editing      = false;
        $scope.buttonAction = 'Add';
        $scope.key          = '';
        $scope.jsondata     = '';
        $("#modalAdd").modal();
    };

    // called on click to edit entry
    $scope.editEntry = function(key, jsondata) {
        $scope.key      = key;
        $scope.jsondata = JSON.stringify(jsondata, null, 2);
        $scope.editing  = true;
        $scope.buttonAction = 'Edit';
        $("#modalAdd").modal();
    };

    // called on saving an entry
    $scope.saveEntry = function() {
        if ($scope.key === '' || $scope.jsondata === '') {
            alert('Please enter key and JSON data');
        }
        else {
            var finalData = JSON.parse($scope.jsondata);

            $http({
                  method: 'PUT',
                  url:    '/cache/json/' + $scope.key,
                  headers: { 'Content-Type' : 'application/json' },
                  data: finalData
                  })
                .success(function (response) {
                   $window.location.href = 'json.html#?action=save&key=' + encodeURIComponent($scope.key) +
                           '&q=' + encodeURIComponent($scope.queryValue) + '&sort=' + encodeURIComponent($scope.sortByValue);
                   $window.location.reload();
            })
            .error(function (message, code) {
                if (message) {
                    alert('Error ' + message + ', ' + code);
                }
            });
        }
    };

    // called on deleting a json entry
    $scope.deleteEntry = function(key) {
        var deleteEntry = $window.confirm('Are you sure you want to delete json data with key ' + key + '?');
        if (deleteEntry) {
            $http.delete('/cache/json/' + key)
                .success(function (response) {
                    $window.location.href = 'json.html#?action=delete&key=' + encodeURIComponent(key) +
                          '&q=' + encodeURIComponent($scope.queryValue) + '&sort=' + encodeURIComponent($scope.sortByValue);
                    $window.location.reload();
                })
                .error(function (message, code) {
                    if (message != null) {
                        alert('Error ' + message + ', ' + code);
                    }
                });
        }
    };

    // called on incrementing age
    $scope.incrementAge = function(key) {
      $http.post('/cache/json/' + key + '/increment(age,1)')
          .success(function (response) {
              $window.location.href = 'json.html#?action=increment&key=' + encodeURIComponent(key) +
                      '&q=' + encodeURIComponent($scope.queryValue) + '&sort=' + encodeURIComponent($scope.sortByValue);
              $window.location.reload();
          })
          .error(function (message, code) {
              if (message != null) {
                  alert('Error ' + message + ', ' + code);
              }
          });
    };

    // populate default JSON data with random names generated
    // from http://listofrandomnames.com
    $scope.populateDefaults = function() {
        var calls = new Array(12);
        var i = 0;

        calls[i++] = $http.put('/cache/json/1.json',  {name: "Brittaney Beeman",  age: 25, address: { line1: "123 James St",  city: "Perth", country: "Australia" } });
        calls[i++] = $http.put('/cache/json/2.json',  {name: "Rey Garza",         age: 26, address: { line1: "55 William St", city: "Perth", country: "Australia" } });
        calls[i++] = $http.put('/cache/json/3.json',  {name: "Laura Schnieders",  age: 45, address: { line1: "Unit 1, 200 George St", city: "Sydney", country: "Australia" } });
        calls[i++] = $http.put('/cache/json/4.json',  {name: "Lashawnda Pisano",  age: 55, address: { line1: "30 Pitt St", city: "Sydney", country: "Australia" } });
        calls[i++] = $http.put('/cache/json/5.json',  {name: "Darleen Hammon",    age: 18, address: { line1: "443 Hay St", city: "Perth", country: "Australia" } });
        calls[i++] = $http.put('/cache/json/6.json',  {name: "Ashlyn Dahlstrom",  age: 13, address: { line1: "52 Bridge St", city: "Sydney", country: "Australia" } });
        calls[i++] = $http.put('/cache/json/7.json',  {name: "Timothy Dahlstrom", age: 12, address: { line1: "111 St Kilda Rd", city: "Melbourne", country: "Australia" } });
        calls[i++] = $http.put('/cache/json/9.json',  {name: "Retha Brian",       age: 12, address: { line1: "551 Turbot St", city: "Brisbane", country: "Australia" } });
        calls[i++] = $http.put('/cache/json/10.json', {name: "Izola Jones",       age: 39, address: { line1: "88 Flinders St", city: "Melbourne", country: "Australia" } });
        calls[i++] = $http.put('/cache/json/11.json', {name: "Corene Bell",       age: 12, address: { line1: "123 St Georges Tce", city: "Perth", country: "Australia" } });
        calls[i++] = $http.put('/cache/json/12.json', {name: "Pamelia Wynton",    age: 12, address: { line1: "2 Ann St", city: "Brisbane", country: "Australia" } });

        // wait for all requests to finish
        $q.all(calls)
            .then(function() {
                $window.location.href = 'json.html#?action=populate' +
                        '&q=' + encodeURIComponent($scope.queryValue) + '&sort=' + encodeURIComponent($scope.sortByValue);
                $window.location.reload();
        })
    };

});