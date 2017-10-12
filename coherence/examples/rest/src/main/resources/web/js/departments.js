/**
 * department.js
 *
 * AngularJS support for departments.html.
 *
 * @author tam  2015.07.10
 * @since 12.2.1
 */

var app = angular.module('myApp', []);
app.controller('departmentsCtrl', function($scope, $http, $window, $location, $q) {

    $http.get('/cache/departments.json;sort=deptCode:asc')
        .success(function (response) {
            $scope.names = response;
        });

    $scope.current_url = $location.protocol() + '://' + $location.host() + ':' + $location.port();
    $scope.departmentActioned = '';
    $scope.editing = false;
    $scope.delete  = false;
    $scope.save    = false;

    // setup vars from messages
    action = $location.search().action;
    if (action == 'delete') {
        $scope.departmentActioned = $location.search().deptCode;
        $scope.delete = true;
    }
    else if (action == 'save') {
        $scope.departmentActioned = $location.search().deptCode;
        $scope.save = true;
    }

    // called on click to add department
    $scope.addDepartment = function() {
        $scope.editing      = false;
        $scope.buttonAction = 'Add';
        $scope.deptCode     = '';
        $scope.deptName     = '';
        $("#modalAdd").modal();
    };

    // called on click to edit department
    $scope.editDepartment = function(deptCode, deptName) {
        $scope.deptCode     = deptCode;
        $scope.deptName     = deptName;
        $scope.editing      = true;
        $scope.buttonAction = 'Edit';
        $("#modalAdd").modal();
    };

    // called on saving a department
    $scope.saveDepartment = function() {
        if ($scope.deptCode == undefined || $scope.deptName == undefined) {
            alert('Please enter department code and name');
        }
        else {
            $scope.putDepartment($scope.deptCode, $scope.deptName, true);
        }
    };

    // called to add a new department
    $scope.putDepartment = function(deptCode, deptName, refresh) {
        var newDept = '{ "deptCode" : "' + deptCode + '", "name" : "' + deptName + '"}';
        var myPromise = $http.put('/cache/departments/' + deptCode, newDept);
        if (refresh == false) {
            // if we are not refreshing straight away then return the promise
            // so we can wait on them all
            return myPromise;
        }
        myPromise
            .success(function (response) {
                if (refresh) {
                   $window.location.href = 'departments.html#?action=save&deptCode=' + deptCode;
                   $window.location.reload();
                }
            })
            .error(function (message, code) {
                if (message) {
                    alert('Error ' + message + ', ' + code);
                }
            });
    };

    // called on deleting a department
    $scope.deleteDepartment = function(deptCode) {
        // check that there are no products with this department
        $scope.hasProducts = false;
        var myPromises = new Array(1);
        myPromises[0]  = $http.get('/cache/products.json?q=deptCode%20is%20%27' + deptCode + '%27')
            .success(function (response)
            {
                if (response.length > 0) {
                   alert('There are products belonging to department ' + deptCode +
                         ', unable to delete');
                   $scope.hasProducts = true;
                }
            });

        $q.all(myPromises).then(function() {
            var deleteDept = false;
            if ($scope.hasProducts == true) {
                deleteDept = false;
            }
            else {
                deleteDept = $window.confirm('Are you sure you want to delete department ' + deptCode + '?');
            }
            if (deleteDept) {
                $http.delete('/cache/departments/' + deptCode)
                    .success(function (response) {
                        $window.location.href = 'departments.html#?action=delete&deptCode=' + deptCode;
                        $window.location.reload();
                    })
                    .error(function (message, code) {
                        if (message) {
                            alert('Error ' + message + ", " + code);
                        }
                    });
            }
        });
    };

    // populate default departments
    $scope.populateDefaults = function() {
        var calls = new Array(10);
        var i = 0;

        calls[i++] = $scope.putDepartment('01', 'Computers & Tablets', false);
        calls[i++] = $scope.putDepartment('02', 'Cameras, Phones & GPS', false);
        calls[i++] = $scope.putDepartment('03', 'Games & Gaming Consoles', false);
        calls[i++] = $scope.putDepartment('04', 'TV & Home Theatre', false);
        calls[i++] = $scope.putDepartment('05', 'Headphones & Audio', false);
        calls[i++] = $scope.putDepartment('06', 'Kitchen Appliance', false);
        calls[i++] = $scope.putDepartment('07', 'Heating & Cooling', false);
        calls[i++] = $scope.putDepartment('08', 'Connected Fitness & Health', false);
        calls[i++] = $scope.putDepartment('09', 'Beds & Manchester', false);
        calls[i++] = $scope.putDepartment('10', 'Sports & Camping', false);

        // wait for all requests to finish
        $q.all(calls)
            .then(function() {
                $window.location.href = 'departments.html#?action=populate';
                $window.location.reload();
        })
    };
});
