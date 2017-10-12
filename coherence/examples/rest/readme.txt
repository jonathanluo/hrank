            Oracle Coherence REST Examples
            =======================================================

Contents
========

    * Overview
    * Directory Structure
    * Build Instructions
    * Run Instructions
    * References

Overview
========

 This document describes the source and build system for the Oracle Coherence REST examples.


Prerequisites
==================

  In order to build and run the examples, you must have the following installed:
  1 - Coherence
  2 - Java Development Kit (JDK)
  3 - Maven version 3.2.5 or above
  4 - A web browser supported by AngularJS 1.4.1+ - see https://docs.angularjs.org/misc/faq

  Note: Internet Explorer does not support Server Sent Events (SSE) and as such you must
        use a supported browser for the SSE example. All other examples here will work with
        Internet Explorer.
        Refer to: http://www.w3schools.com/html/html5_serversentevents.asp

  Please refer to Chapter 2, "Installing Oracle Coherence for Java" in the Installing Oracle Coherence
  Guide for instructions and supported JDK versions.

  Ensure the following environment variables are set:

  JAVA_HOME
    Make sure that the JAVA_HOME environment variable points to the location of a JDK supported by the
    Oracle Coherence version you are using before building the examples.

  COHERENCE_HOME
    Make sure COHERENCE_HOME is set to point to your Coherence install directory.

  MAVEN_HOME
    If mvn command is not in your path then you should set MAVEN_HOME and then add MAVEN_HOME\bin to your PATH
    in a similar way to Java being added to the path below.

  You must also ensure the java command is in the path.
    E.g. for Linux/UNIX:
      export PATH=$JAVA_HOME/bin:$PATH

    For Windows:
      set PATH=%JAVA_HOME%\bin;%PATH%

  You must have Oracle Coherence installed into your local maven repository. If you
  do not, then carry out the following, replacing the version number with the version
  of Coherence you have installed.

  E.g. for Linux/UNIX/Mac:

    mvn install:install-file -Dfile=$COHERENCE_HOME/lib/coherence.jar      -DpomFile=$COHERENCE_HOME/plugins/maven/com/oracle/coherence/coherence/12.2.1/coherence.12.2.1.pom
    mvn install:install-file -Dfile=$COHERENCE_HOME/lib/coherence-rest.jar -DpomFile=$COHERENCE_HOME/plugins/maven/com/oracle/coherence/coherence-rest/12.2.1/coherence-rest.12.2.1.pom

  E.g. for Windows:

    mvn install:install-file -Dfile=%COHERENCE_HOME%\lib\coherence.jar      -DpomFile=%COHERENCE_HOME%\plugins\maven\com\oracle\coherence\coherence\12.2.1\coherence.12.2.1.pom
    mvn install:install-file -Dfile=%COHERENCE_HOME%\lib\coherence-rest.jar -DpomFile=%COHERENCE_HOME%\plugins\maven\com\oracle\coherence\coherence-rest\12.2.1\coherence-rest.12.2.1.pom

  Note: You may need to specify your settings.xml file by adding the following to download
        required dependencies.

     "mvn -s /path/to/settings.xml ..."

  If you do not have a settings file and you are using a proxy server for internet access,
  you can utilize the sample settings.xml provided in the base directory. You must modify
  this to add your proxy server settings.

Directory Structure
======================

  The REST example is currently the only example that uses maven for building and running
  and as such the directory layout is in standard maven format.

  src/main/java
    Root for Java source.

  src/main/resources
    Configuration files directory.

  src/main/resources/web
    Static HTML content served from this directory.

Build Instructions
==================

  Issue the following to build the REST example:
     "mvn clean compile"

  If this is the first time you have run Maven on your machine, then a number of
  files will need to be downloaded.

  Note: You may need to specify a settings.xml file by adding the following to download
        required dependencies.
     "mvn -s /path/to/settings.xml clean compile"

Run Instructions
=================

    First, start a cache server and http proxy using:
          "mvn exec:exec -DhttpProxy"

    Once started, reference code data for Countries and States will be loaded and
    the application startup page will be automatically loaded.

    Although not required, you can also start additional cache servers (without HTTP server)
    by using:
          "mvn exec:exec -DcacheServer"

  Web-based examples

      To access the application, open the following URL (if not already opened).

          http://127.0.0.1:8080/application/index.html

      This example shows a basic application and how the REST endpoints could be
      integrated into a web application using the Angular JS framework. You can
      use buttons on Departments and Products page to populate see data.

      The example has a number of pages:

      Departments
        This page shows how to query, create, update, remove or populate default
        departments using standard REST API's in Coherence.

      Products
        This page shows how to query, create, update, remove or populate default
        products using standard REST API's in Coherence.

        There are also custom entry processors to increase product prices and
        receive more stock of an item.

      Contacts
        This page shows how to query, create, update, remove or populate default
        contacts using standard REST API's in Coherence.  The contacts also
        has composite keys and shows the use of a KeyConverter class to work with these keys.

        There are also examples of how to sort queries that are returned from REST calls.

      Server Sent Events
        This page uses SSE to listen for events from the Coherence REST API's.

      For most pages, the REST operations for each operation are displayed in a
      message box at the top of the screen after the operations complete.

      Note: the HTTP server listens on all IP Addresses but you can change the
      address and port that the application runs on by passing the following to your
      mvn exec:exec command:

          mvn exec:exec -DhttpProxy -Dhttp.address=x.x.x.x -Dhttp.port=7777

References
==========

  Coherence Documentation:

    http://www.oracle.com/technetwork/middleware/coherence/documentation/index.html

  Coherence Community:

    https://coherence.java.net/
