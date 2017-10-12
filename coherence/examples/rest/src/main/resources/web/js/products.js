/**
 * products.js
 *
 * AngularJS support for products.html.
 *
 * @author tam  2015.07.10
 * @since 12.2.1
 */

var app = angular.module('myApp', []);
app.controller('productsCtrl', function($scope, $http, $window, $location, $q) {
    // populate the product table
    $http.get('/cache/products.json;sort=productId:asc')
        .success(function (response) {$scope.names = response;});

    // populate the department list
    $http.get('/cache/departments.json;sort=name:asc')
        .success(function (response) {
            $scope.departments = response;
            if (response.length == 0) {
                alert('Please navigate to the Departments page to add departments before addding products');
            }
        });

    $scope.current_url = $location.protocol() + '://' + $location.host() + ':' + $location.port();
    $scope.productActioned = '';
    $scope.editing = false;
    $scope.delete  = false;
    $scope.save    = false;
    $scope.adjust  = false;

    // setup vars from messages
    action = $location.search().action;
    if (action == 'delete') {
        $scope.productActioned = $location.search().productId;
        $scope.delete = true;
    }
    else if (action == 'save') {
        $scope.productActioned = $location.search().productId;
        $scope.save = true;
    }
    else if (action == 'receive') {
        $scope.productActioned = $location.search().productId;
        $scope.amount          = $location.search().amount;
        $scope.receive = true;
    }
    else if (action == 'priceAdjust') {
        $scope.amount = $location.search().amount;
        $scope.adjust = true;
    }

    // called on click to add product
    $scope.addProduct = function() {
        $scope.editing      = false;
        $scope.buttonAction = 'Add';
        $scope.productId    = '';
        $scope.name         = '';
        $scope.price        = '';
        $scope.deptCode     = '';
        $scope.qtyOnHand    = 0;
        $("#modalAdd").modal();
    };

    // called on click to edit product
    $scope.editProduct = function(productId, name, price, deptCode, qtyOnHand) {
        $scope.productId = productId;
        $scope.name      = name;
        $scope.price     = price;
        $scope.deptCode  = deptCode;
        $scope.qtyOnHand = qtyOnHand;
        $scope.editing   = true;
        $scope.buttonAction = "Edit";
        $("#modalAdd").modal();
    };

    // called on saving a product
    $scope.saveProduct = function() {
        if ($scope.productId == undefined || $scope.deptCode == undefined ||
            $scope.name      == undefined || $scope.price    == undefined ||
            $scope.qtyOnHand == undefined) {
            alert('Please enter all required details');
        }
        else {
            $scope.putProduct($scope.productId, $scope.name, $scope.price,
                              $scope.deptCode, $scope.qtyOnHand, true);
        }
    };

    // called to add a new product
    $scope.putProduct = function(productId, name, price, deptCode, qtyOnHand, refresh) {
        var newProduct = '{ "productId" : "' + productId + '", ' +
                          ' "name" : "'      + name      + '", ' +
                          ' "price" : "'     + price     + '", ' +
                          ' "deptCode" : "'  + deptCode  + '", ' +
                          ' "qtyOnHand" : "' + qtyOnHand + '"  ' +
                          '}';

        var myPromise = $http.put('/cache/products/' + productId, newProduct);
        if (refresh == false) {
            // if we are not refreshing straight away then return the promise
            // so we can wait on them all before refreshing
            return myPromise;
        }

        myPromise
            .success(function (response) {
                if (refresh) {
                    $window.location.href = 'products.html#?action=save&productId=' + productId;
                    $window.location.reload();
                }
            })
            .error(function (message, code) {
                if (message) {
                    alert('Error ' + message + ', ' + code);
                }
            });
    };

    // called on deleting a product
    $scope.deleteProduct = function(productId) {
        var deleteProduct = $window.confirm('Are you sure you want to delete product ' + productId + '?');
        if (deleteProduct) {
            $http.delete('/cache/products/' + productId)
                .success(function (response) {
                    $window.location.href = 'products.html#?action=delete&productId=' + productId;
                    $window.location.reload();
                })
                .error(function (message, code) {
                    if (message) {
                        alert('Error ' + message + ', ' + code);
                    }
                });
        }
    };

    // populate default products
    $scope.populateDefaults = function() {

        var calls = new Array(17);
        var i = 0;
        calls[i++] = $scope.putProduct(1, 'Apple MacBook Air 13 inch 1.4GHz i5 256GB', 1399, '01', 0, false);
        calls[i++] = $scope.putProduct(2, 'Apple MacBook Pro with Retina Display 13 inch: 2.7GHz i5 256GB', 2097, '01', 0, false);
        calls[i++] = $scope.putProduct(3, 'Lenovo Z50-70 15.6inch i7 Laptop', 1118, '01', 0, false);

        calls[i++] = $scope.putProduct(10, 'Samsung Galaxy S6 32GB - Blue', 942, '02', 0, false);
        calls[i++] = $scope.putProduct(11, 'Samsung Galaxy S6 Edge 64GB - Gold', 1127, '02', 0, false);
        calls[i++] = $scope.putProduct(12, 'Apple iPhone 6 64GB', 1144, '02', 0, false);
        calls[i++] = $scope.putProduct(13, 'Apple iPhone 6 Plus 64GB', 1244, '02', 0, false);

        calls[i++] = $scope.putProduct(15, 'TomTom Via 280 GPS Navigator', 176, '02', 0, false);
        calls[i++] = $scope.putProduct(16, 'TomTom GO 60 Lifetime Maps & Traffic GPS', 249, '02', 0, false);
        calls[i++] = $scope.putProduct(17, 'Garmin Approach G3 Handheld GPS', 198, '02', 0, false);

        calls[i++] = $scope.putProduct(20, 'Xbox One With Kinect', 598, '03', 0, false);
        calls[i++] = $scope.putProduct(21, 'PS4 Console', 550, '03', 0, false);

        calls[i++] = $scope.putProduct(30, 'LG 84 inch 4K Ultra HD LED LCD 3D Capable Smart TV', 12000, '04', 0, false);
        calls[i++] = $scope.putProduct(31, 'LG 55 inch Full HD OLED 3D Capable Smart Curved TV', 3400, '04', 0, false);

        calls[i++] = $scope.putProduct(40, 'Beats by Dr. Dre Solo 2 On-Ear Headphones', 248, '05', 0, false);
        calls[i++] = $scope.putProduct(41, 'Sennheiser Wireless RF Headphones', 129, '05', 0, false);
        calls[i++] = $scope.putProduct(42, 'Sennheiser HD558 Headphones', 298, '05', 0, false);

        // wait for all requests to complete
        $q.all(calls).then(function() {
            $window.location.href = 'products.html#?action=populate';
            $window.location.reload();
        });
    };

    // receive stock by using an out of the box entry processor
    $scope.receiveStock = function(productId) {
        var val = parseInt(prompt('Enter the number of products to receive', '10'));
        if (isNaN(val) == false) {
            $http.post('/cache/products/' + productId + '/increment(qtyOnHand,' + val + ')')
                .success(function (response) {
                    $window.location.href = 'products.html#?action=receive&productId=' + productId +
                    '&amount=' + val;
                    $window.location.reload();

                })
                .error(function (message, code) {
                    if (message) {
                        alert('Error ' + message + ', ' + code);
                    }
                });
        }
    };

    // adjust prices by a user defined factor
    $scope.priceAdjust = function() {
        var val = parseFloat(prompt('Enter the price adjustment for all products. (e.g. 1.1 = +%10)', '1.1'));
        if (isNaN(val) == false) {
            $http.post('/cache/products/price-adjust(' + val + ')')
                .success(function (response) {
                    $window.location.href = 'products.html#?action=priceAdjust&amount=' + val;
                    $window.location.reload();
                })
                .error(function (message, code) {
                    if (message) {
                        alert('Error ' + message + ', ' + code);
                    }
            });
        }
    }
});
