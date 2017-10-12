            Oracle Coherence C++ Examples
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

 This document describes the source and build system for the Oracle Coherence C++ examples.

Prerequisites
==================
  To run the examples, you will need the Coherence for C++ 3.6 or later, the Java version of Coherence 3.6 or
  later and the appropriate Java Development Kit (JDK).  Please refer to Chapter 2, Installing Oracle Coherence
  for Java in the Oracle Coherence Developer's Guide for the JDK versions supported by the release of Oracle
  Coherence you are using. The JDK is required because the Coherence*Extend proxy and cache servers require Java.
  Also, the examples depend on Java example classes that must be built before running the proxy and cache
  server. See the Java examples readme.txt for instructions on how to build and run. Note that the Java 
  run-proxy script must be executed; the Java run-cache-server is optional because the proxy is storage 
  enabled.

  If you are running the examples on Windows, you need Visual Studio 2005, or Visual Studio 2010 or later to build
  the examples.

  $COHERENCE_HOME   
    Make sure that the COHERENCE_HOME environment variable points to the location of the unpacked Coherence 3.6
    (or later) directory.
  
  $JAVA_HOME
    Make sure that the JAVA_HOME environment variable points to the location of a JDK supported by the
    Oracle Coherence version you are using before building the examples.
    
  $COHERENCE_CPP_HOME
    Make sure that the COHERENCE_CPP_HOME environment variable points to the location of the unpacked Coherence
    for C++ directory.

Directory Structure
======================

  The directory structure described below is relative to ../examples/

  cpp/bin
    Scripts for building and executing the examples. Scripts with no file extension
    are bash scripts. Scripts with a .cmd file extension are Windows command scripts. The following description
    refers to the script names without specifying any file extension.
    
    build_pof       -- builds the classes for objects stored in the cache into a dynamic library
    build           -- builds the executable
    run             -- runs an example, requires that java/bin/run-proxy is started.

  cpp
    All example source organized under the <example name> (such as contacts and security) and pof directories.

  contact/out
     The object files output from a build. This directory will not exist until the build
     script is executed.

  resource
    The data file used for the contacts LoaderExample: contacts.csv.

  cpp/contacts
    contains the contacts example sources.

  cpp/security
    contains the security example sources.
    
  cpp/pof
    contains the classes for objects stored in the cache.

  cpp/config
     The common coherence configuration files required by the examples.

  cpp/config/<example name>  
    If an example has configuration that is required instead of the common configuration, it will 
    have its own directory. The security example uses configuration files from cpp/config/security.
    
  $COHERENCE_CPP_HOME/include
    Contains the Coherence header files.
  
  $COHERENCE_CPP_HOME/lib
    Contains the Coherence library.
     
Build Instructions
==================
 
  Ensure the environment variable COHERENCE_CPP_HOME is defined.  

  Execute the build script with the name of the example: "bin/build contacts" or "bin/build security".
  The script will build the pof files and then the files for the particular example.

  For Windows user, execute the build script from a Visual Studio Command Prompt.


Run Instructions
=================

  Execute the run scripts. There are two parts to running the example.  From within new command shells:

  contacts example

     First, start one or more cache servers from the Java examples directory using:
         "bin/run-cache-server"

     The cache server also runs a proxy service which allows connections from Coherence*Extend
     clients.

     Each execution will start a cache server cluster node. To add additional nodes, execute the command in
     a new command shell.

     Second, in a new command shell, execute run with the name of the example:
         "bin/run contacts".

     The Driver.main method will run through the features of the example with output
     going to the command window (stdout).

     Starting with Coherence 3.6, an example of the new Query Language feature was added.  
     This example shows how to configure and use a simple helper class "FilterFactory" using the 
     Coherence InvocationService.
  
  security example

     First, start one or more cache servers from the Java examples directory using:
         "bin/run-cache-server security"

     The cache server also runs a proxy service which allows connections from Coherence*Extend
     clients.
     
     Second, in a new command shell, execute run with the name of the example:
         "bin/run security".

     The Driver.main method will run through the features of the example with output
     going to the command window (stdout).
      


References
==========

  Coherence:

  * Getting Started:
    http://www.oracle.com/technology/products/coherence/index.html

