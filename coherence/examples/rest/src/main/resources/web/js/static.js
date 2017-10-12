/**
 * static.js
 *
 * AngularJS support for static.html.
 *
 * @author tam  2015.11.03
 * @since 12.2.1.1
 */

var app = angular.module('myApp', ['filters']);

/**
 * Define a "fileSize" filter for formatting content.
 */
angular.module('filters', [])
    .filter('fileSize', function () {
        return function (size) {
            if (isNaN(size))
                size = 0;

            if (size < 1024)
                return size + ' Bytes';

            size /= 1024;

            if (size < 1024)
                return size.toFixed(2) + ' KB';

            size /= 1024;

            if (size < 1024)
                return size.toFixed(2) + ' MB';

            size /= 1024;

            if (size < 1024)
                return size.toFixed(2) + ' GB';

            size /= 1024;

            return size.toFixed(2) + ' TB';
        };
    });

app.controller('staticCtrl', function($scope, $document,  $http, $window, $location) {

    $scope.maxFileSize   = 30;
    $scope.uploadMessage = 'Upload';
    var MB               = 1024 * 1024;
    var MAX_SIZE         = $scope.maxFileSize * MB;

    // refresh the data
    $http.get('/cache/static-content/entries')
        .success(function (response) {
            $scope.entries = response;
        });

    $scope.current_url = $location.protocol() + '://' + $location.host() + ':' + $location.port();
    $scope.delete      = false;

    // setup vars for messages
    action = $location.search().action;
    if (action == 'delete') {
        $scope.entryActioned = $location.search().description;
        $scope.delete = true;
    }

    // called on click to upload a file
    $scope.addEntry = function() {
        $scope.description  = '';
        $scope.fileToUpload = '';
        $scope.fileType     = '';
        $scope.fileSize     = '';
        $("#modalAdd").modal();
    };

    $scope.setUploadFile = function(o) {
        $scope.fileToUpload    = o.files[0];
        $scope.description     = $scope.fileToUpload.name;
        $scope.fileTypeDisplay = $scope.fileToUpload.type;
        $scope.fileSizeDisplay = ($scope.fileToUpload.size / MB).toFixed(1) + ' MB';
        $scope.$apply();
    };

    // called on uploading an entry
    $scope.saveEntry = function() {
        $scope.uploadMessage = 'Working...';
        if ($scope.description && $scope.fileToUpload) {
            var reader = new FileReader();

            reader.onload = function(e) {
                var uploadData = e.target.result;

                $http({
                      method: 'PUT',
                      url:    '/cache/static-content/' + $scope.description,
                      headers: {'Content-Type' : $scope.fileToUpload.type },
                      data: uploadData,
                      transformRequest: [] // stops angular converting to json
                      })
                    .success( function(response) {
                        $window.location.href = 'static.html';
                        $window.location.reload();
                    })
                    .error(function (message, code) {
                        if (message) {
                            alert('Error ' + message + ', \nHTTP Code: ' + code);
                            $scope.uploadMessage = 'Failed Upload ...';
                        }
                    });
            };

            if ($scope.fileToUpload.size > MAX_SIZE) {
                alert('File size should be less than ' + MAX_SIZE / MB + ' MB. Selected file is ' +
                        ($scope.fileToUpload.size / MB).toFixed(1) + ' MB');
            }
            else {
                reader.readAsArrayBuffer($scope.fileToUpload);
            }
        }
        else {
            alert('Please enter a description and a file to upload');
        }
    };

    // called on deleting a binary entry
    $scope.deleteEntry = function(description) {
        var deleteEntry = $window.confirm('Are you sure you want to entry named ' + description + '?');
        if (deleteEntry) {
            $http.delete('/cache/static-content/' + description)
                .success(function (response) {
                    $window.location.href = 'static.html#?action=delete&description=' + description;
                    $window.location.reload();
                })
                .error(function (message, code) {
                    if (message) {
                        alert('Error ' + message + ', ' + code);
                    }
                });
        }
    };

    // called on downloading an entry
    $scope.downloadEntry = function(description) {
        $window.open('/cache/static-content/' + description);
    };
});