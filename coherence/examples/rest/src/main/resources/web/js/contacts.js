/**
 * contacts.js
 *
 * AngularJS support for contacts.html.
 *
 * @author tam  2015.07.10
 * @since 12.2.1
 */

var app = angular.module('myApp', []);

app.controller('contactsCtrl', function($scope, $http, $window, $location, $q) {
    var sort = ';sort=lastName:asc';
    var q    = '';
    var query = $location.search();

    if (query.q) {
      q = '?q=' + query.q;
    }
    if (query.sort) {
      sort = ';sort=' + query.sort;
    }

    var urlPrefix = $location.protocol() + '://' + $location.host() + ':' + $location.port();

    if (query['action'] == 'create') {
       $scope.createMessage = urlPrefix +
            '/cache/contacts/' + query.firstName + '_' + query.lastName + ';' +
            '/random-contact-creator()';
       $scope.displayCreateMessage = true;
    }
    else if (query['action'] == 'delete') {
       $scope.deleteMessage = urlPrefix +
            '/cache/contacts/' + query.firstName + '_' + query.lastName;
       $scope.displayDeleteMessage = true;
    }

    $scope.current_url = urlPrefix + '/cache/contacts' + sort + q;

    // refresh the contacts table
    $http.get('/cache/contacts.json' + sort + q)
        .success(function (response) {$scope.names = response;});

    // populate the states dropdown
    $http.get('/cache/states.json;sort=name:asc')
        .success(function (response) {$scope.states = response;});

    // populate the country dropdown
    $http.get('/cache/countries.json;sort=name:asc')
        .success(function (response) {$scope.countries = response;});

    // set sorting params
    $scope.doSort = function($sortparam) {
        $window.location.href = 'contacts.html#?sort=' + $sortparam;
        $window.location.reload();
    };

    // set query params
    $scope.doQuery = function($queryParam) {
        $window.location.href = 'contacts.html#?q=' + $queryParam;
        $window.location.reload();
    };

    // called on click to add contact
    $scope.showCreateContact = function() {
        $scope.firstName = '';
        $scope.lastName  = '';
        $("#modalAdd").modal();
    };

    // called to create contact with a first name and last name and
    // random other attributes via custom entry processor
    $scope.createContact = function() {
        if ($scope.firstName == '' || $scope.lastName == '') {
            alert('Please enter First and Last Name');
        }
        else {
            $scope.putContact($scope.firstName, $scope.lastName, true);
        }
    };

    // called to create a contact with given name and random attributes
    $scope.putContact = function(firstName, lastName, refresh) {
        // for a composite key we need to match the format of the
        // ContactIdKeyConverter class.  We also use POST rather than
        // PUT as POST is used for an entry processor
        var myPromise =  $http.post('/cache/contacts/' + firstName + '_' + lastName +
            '/random-contact-creator()');
        if (refresh == false) {
            // if we are not refreshing straight away then return the promise
            // so we can wait on them all before refreshing
            return myPromise;
        }

        myPromise
            .success(function (response) {
                $window.location.href = 'contacts.html#?action=create&firstName=' + firstName +
                '&lastName=' + lastName;
                $window.location.reload();
            })
            .error(function (message, code) {
                if (message) {
                    alert('Error ' + message + ', ' + code);
                }
            });
    };

    // called on deleting a contact
    $scope.deleteContact = function(firstName, lastName) {

        var deleteDept = $window.confirm('Are you sure you want to delete contact ' +
                         firstName + ' ' + lastName + '?');
        if (deleteDept) {
            $http.delete('/cache/contacts/' + firstName + '_' + lastName)
                .success(function (response) {
                    $window.location.href = 'contacts.html#?action=delete&firstName=' +
                                            firstName + '&lastName=' + lastName;
                    $window.location.reload();
                })
                .error(function (message, code) {
                    if (message) {
                        alert('Error ' + message + ', ' + code);
                    }
                });
        }
    };

    // called to view contact as XML
    $scope.viewAsXML = function(firstName, lastName) {
        var url = '/cache/contacts/' + firstName + '_' + lastName + '.xml';
        $http.get(url)
            .success(function (response) {
                alert('GET ' + $location.protocol() + '://' + $location.host() + ':' + $location.port()
                + url + '\n\n' + response);
            });
    };

    // populate default contacts with random names generated
    // from http://listofrandomnames.com
    $scope.populateDefaults = function() {
        var calls = new Array(30);
        var i = 0;

        calls[i++] = $scope.putContact('Brittaney', 'Beeman', false);
        calls[i++] = $scope.putContact('Rey', 'Garza', false);
        calls[i++] = $scope.putContact('Laura', 'Schnieders', false);
        calls[i++] = $scope.putContact('Scott', 'Veasley', false);
        calls[i++] = $scope.putContact('Lashawnda', 'Pisano', false);
        calls[i++] = $scope.putContact('Darleen', 'Hammon', false);
        calls[i++] = $scope.putContact('Ashlyn', 'Dahlstrom', false);
        calls[i++] = $scope.putContact('Particia', 'Canady', false);
        calls[i++] = $scope.putContact('Beatriz', 'Merrigan', false);
        calls[i++] = $scope.putContact('Shawn', 'Villacorta', false);
        calls[i++] = $scope.putContact('Verda', 'Newbrough', false);
        calls[i++] = $scope.putContact('Arcelia', 'Cade', false);
        calls[i++] = $scope.putContact('Levi', 'Willard', false);
        calls[i++] = $scope.putContact('Lynn', 'Dalley', false);
        calls[i++] = $scope.putContact('Retha', 'Brian', false);
        calls[i++] = $scope.putContact('Desiree', 'Celestine', false);
        calls[i++] = $scope.putContact('Dodie', 'Mcghee', false);
        calls[i++] = $scope.putContact('Will', 'Plewa', false);
        calls[i++] = $scope.putContact('Leatrice', 'Bushard', false);
        calls[i++] = $scope.putContact('Brice', 'Eakins', false);
        calls[i++] = $scope.putContact('Izola', 'Grahm', false);
        calls[i++] = $scope.putContact('Dot', 'Lansford', false);
        calls[i++] = $scope.putContact('Diamond', 'Dobbins', false);
        calls[i++] = $scope.putContact('Deon', 'Soule', false);
        calls[i++] = $scope.putContact('Lieselotte', 'Borchardt', false);
        calls[i++] = $scope.putContact('Corene', 'Lipsett', false);
        calls[i++] = $scope.putContact('Gerard', 'Rumore', false);
        calls[i++] = $scope.putContact('Jay', 'Leisy', false);
        calls[i++] = $scope.putContact('Sari', 'Searle', false);
        calls[i++] = $scope.putContact('Pamelia', 'Tookes', false);

        // wait for all requests to finish
        $q.all(calls)
            .then(function() {
                $window.location.href = 'contacts.html#?action=populate';
                $window.location.reload();
            })
    };

    // called on click to edit address
    $scope.editAddress = function(addressType, firstName, lastName, street1, street2, city, state, zipCode, country) {
        $scope.addressType = addressType;

        // save key values
        $scope.hiddenFirstName = firstName;
        $scope.hiddenLastName  = lastName;

        $scope.street1     = street1;
        $scope.street2     = street2;
        $scope.city        = city;
        $scope.state       = state;
        $scope.zipCode     = zipCode;
        $scope.country     = country;
        $("#modalAddress").modal();
    };

    // save address that was being edited
    $scope.saveAddress = function() {
        // get the current contact
        var key = $scope.hiddenFirstName + '_' + $scope.hiddenLastName;
        $http.get('/cache/contacts/' + key + '.json')
            .success(function (response)
            {
                var customer = response;
                if ($scope.addressType == 'Home') {
                    customer.homeAddress.city    = $scope.city;
                    customer.homeAddress.country = $scope.country;
                    customer.homeAddress.state   = $scope.state;
                    customer.homeAddress.street1 = $scope.street1;
                    customer.homeAddress.street2 = $scope.street2;
                    customer.homeAddress.zipCode = $scope.zipCode;
                }
                else {
                    customer.workAddress.city    = $scope.city;
                    customer.workAddress.country = $scope.country;
                    customer.workAddress.state   = $scope.state;
                    customer.workAddress.street1 = $scope.street1;
                    customer.workAddress.street2 = $scope.street2;
                    customer.workAddress.zipCode = $scope.zipCode;
                }
                // save the modified customer
                $http.put('/cache/contacts/' + key, customer)
                    .success(function (response) {
                        $window.location.href = 'contacts.html';
                        $window.location.reload();
                    });
            })
            .error(function (message, code) {
                if (message) {
                    alert('Error ' + message + ', ' + code);
                }
            });
    }
});