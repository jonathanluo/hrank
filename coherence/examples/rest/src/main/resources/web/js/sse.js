/**
 * sse.js
 *
 * AngularJS support for sse.html.
 *
 * @author tam  2015.07.10
 * @since 12.2.1
 */

var app = angular.module('myApp', []);

app.controller('eventsCtrl', function($scope, $window) {
    // determine if we are using Internet Explorer as
    // SSE are not supported with IE
    var ua      = $window.navigator.userAgent;
    $scope.isIE = ua.indexOf ('MSIE ') > 0 || ua.indexOf('Trident') > 0;
    // contacts

    var contacts    = {};
    var products    = {};
    var departments = {};

    contacts.listening   = false;
    contacts.status      = 'Stopped';
    contacts.insertCount = 0;
    contacts.updateCount = 0;
    contacts.deleteCount = 0;
    contacts.allCount    = 0;
    contacts.lastEvent   = 'N/A';
    contacts.filter      = 'all';

    // products
    products.listening   = false;
    products.status      = 'Stopped';
    products.insertCount = 0;
    products.updateCount = 0;
    products.deleteCount = 0;
    products.allCount    = 0;
    products.lastEvent   = 'N/A';
    products.filter      = 'all';

    // departments
    departments.listening   = false;
    departments.status      = 'Stopped';
    departments.insertCount = 0;
    departments.updateCount = 0;
    departments.deleteCount = 0;
    departments.allCount    = 0;
    departments.lastEvent   = 'N/A';

    $scope.contacts    = contacts;
    $scope.products    = products;
    $scope.departments = departments;

    $scope.setType = function(filterType) {
        $scope.contacts.filter = filterType;
    };

    $scope.setTypeProducts = function(filterType) {
        $scope.products.filter = filterType;
    };

    // add listeners to contacts
    $scope.startListeningContacts = function() {
        $scope.contacts.listening = true;
        $scope.contacts.started   = true;

        if ($scope.contacts.filter == 'all') {
            query = '';
        }
        else if ($scope.contacts.filter == '>=45') {
            query = '?q=age%20>=%2045';
            $scope.contacts.filter = 'age >= 45';
        }
        else {
            query = '?q=age%20<%2045';
            $scope.contacts.filter = 'age < 45';
        }

        $scope.contacts.status  = 'Listening: ' + $scope.contacts.filter;
        var eventSourceContacts = new EventSource('/cache/contacts' + query);

        eventSourceContacts.addEventListener('insert', function(event) {
            $scope.contacts.insertCount++;
            $scope.contacts.allCount++;
            $scope.updateContactEvent(JSON.parse(event.data), 'insert');
            $scope.$apply();
        });

        eventSourceContacts.addEventListener('update', function(event) {
            $scope.contacts.updateCount++;
            $scope.contacts.allCount++;
            $scope.updateContactEvent(JSON.parse(event.data), 'update');
            $scope.$apply();
        });

        eventSourceContacts.addEventListener('delete', function(event) {
            $scope.contacts.deleteCount++;
            $scope.contacts.allCount++;
            $scope.updateContactEvent(JSON.parse(event.data), 'delete');
            $scope.$apply();
        });

        eventSourceContacts.addEventListener('error', function(event) {
            var eventData = JSON.parse(event.data);
            alert('error');
        });
    };

    // update the contact event data on screen
    $scope.updateContactEvent = function(eventData, eventType) {
        $scope.contacts.eventType = eventType;
        $scope.contacts.eventKey  = eventData.key.firstName + ' ' + eventData.key.lastName;

        $scope.contacts.eventNewValue = 'N/A';
        $scope.contacts.eventOldValue = 'N/A';

        if (eventType == 'insert' || eventType == 'update') {
            $scope.contacts.eventNewValue = $scope.getContactString(eventData.newValue);
        }
        if (eventType == 'delete' || eventType == 'update') {
            $scope.contacts.eventOldValue = $scope.getContactString(eventData.oldValue);
        }
    };

    // build an address string
    $scope.getAddressString = function(address) {
       return address.street1 + ' '  + address.street2 + ' ' +
              address.city    + ', ' + address.state   + ' ' +
              address.zipCode + ' '  + address.country;
    };

    // build a string to represent a contact
    $scope.getContactString = function(contact) {
        return 'firstName=' + contact.firstName + ', lastName=' + contact.lastName +
            ', age=' + contact.age + ', birthDate=' + contact.birthDate +
            ', home=' + $scope.getAddressString(contact.homeAddress) +
            ', work=' + $scope.getAddressString(contact.workAddress);
    };

    // add listeners to products
    $scope.startListeningProducts = function() {
        $scope.products.listening = true;

        if ($scope.products.filter == 'all') {
            query = '';
        }
        else if ($scope.products.filter == '>=1000') {
            query = '?q=price%20>=%201000d';
            $scope.products.filter = 'price >= 1000d';
        }

        $scope.products.status  = 'Listening: ' + $scope.products.filter;
        var eventSourceProducts = new EventSource('/cache/products' + query);

        eventSourceProducts.addEventListener('insert', function(event) {
            $scope.products.insertCount++;
            $scope.products.allCount++;
            $scope.updateProductEvent(JSON.parse(event.data), 'insert');
            $scope.$apply();
        });

        eventSourceProducts.addEventListener('update', function(event) {
            $scope.products.updateCount++;
            $scope.products.allCount++;
            $scope.updateProductEvent(JSON.parse(event.data), 'update');
            $scope.$apply();
        });

        eventSourceProducts.addEventListener('delete', function(event) {
            $scope.products.deleteCount++;
            $scope.products.allCount++;
            $scope.updateProductEvent(JSON.parse(event.data), 'delete');
            $scope.$apply();
        });

        eventSourceProducts.addEventListener('error', function(event) {
            var eventData = JSON.parse(event.data);
            alert("error");
        });
    };

    // update the product event data on screen
    $scope.updateProductEvent = function(eventData, eventType) {
        $scope.products.eventType = eventType;
        $scope.products.eventKey  = eventData.key;

        $scope.products.eventNewValue = 'N/A';
        $scope.products.eventOldValue = 'N/A';

        if (eventType == 'insert' || eventType == 'update') {
            $scope.products.eventNewValue = 'productId=' + eventData.newValue.productId + ', name=' + eventData.newValue.name +
            ', price=' + eventData.newValue.price + ', deptCode=' + eventData.newValue.deptCode +
            ', qtyOnHand=' + eventData.newValue.qtyOnHand;
        }
        if (eventType == 'delete' || eventType == 'update') {
            $scope.products.eventOldValue = 'productId=' + eventData.oldValue.productId + ', name=' + eventData.oldValue.name +
            ', price=' + eventData.oldValue.price + ', deptCode=' + eventData.oldValue.deptCode +
            ', qtyOnHand=' + eventData.oldValue.qtyOnHand;
        }
    };

    // add listeners to departments
    $scope.startListeningDepartments = function() {
        $scope.departments.listening = true;
        $scope.departments.status    = 'Listening: all';
        var eventSourceDepartments = new EventSource('/cache/departments');

        eventSourceDepartments.addEventListener('insert', function(event) {
            $scope.departments.insertCount++;
            $scope.departments.allCount++;
            $scope.updateDepartmentEvent(JSON.parse(event.data), 'insert');
            $scope.$apply();
        });

        eventSourceDepartments.addEventListener('update', function(event) {
            $scope.departments.updateCount++;
            $scope.departments.allCount++;
            $scope.updateDepartmentEvent(JSON.parse(event.data), 'update');
            $scope.$apply();
        });

        eventSourceDepartments.addEventListener('delete', function(event) {
            $scope.departments.deleteCount++;
            $scope.departments.allCount++;
            $scope.updateDepartmentEvent(JSON.parse(event.data), 'delete');
            $scope.$apply();
        });

        eventSourceDepartments.addEventListener('error', function(event) {
            var eventData = JSON.parse(event.data);
            alert("error");
        });
    };

    // update the department event data on screen
    $scope.updateDepartmentEvent = function(eventData, eventType) {
        $scope.departments.eventType = eventType;
        $scope.departments.eventKey  = eventData.key;

        $scope.departments.eventNewValue = 'N/A';
        $scope.departments.eventOldValue = 'N/A';

        if (eventType == 'insert' || eventType == 'update') {
            $scope.departments.eventNewValue = 'deptCode=' + eventData.newValue.deptCode + ', name=' + eventData.newValue.name;
        }
        if (eventType == 'delete' || eventType == 'update') {
            $scope.departments.eventOldValue = 'deptCode=' + eventData.oldValue.deptCode + ', name=' + eventData.oldValue.name;
        }
    };
});
