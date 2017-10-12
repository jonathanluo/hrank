            Oracle Coherence Java Examples
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

 This document describes the source and build system for the Oracle Coherence Java examples.


Prerequisites
==================
  In order to build and run the examples, you must have Coherence installed as well as the appropriate
  Java Development Kit (JDK).  Please refer to Chapter 2, "Installing Oracle Coherence for Java" in the
  Installing Oracle Coherence Guide for instructions and supported JDK versions.

  JAVA_HOME
    Make sure that the JAVA_HOME environment variable points to the location of a JDK supported by the
    Oracle Coherence version you are using before building the examples.


Directory Structure
======================

  The directory structure described below is relative to ../examples/

  java/bin
    Scripts for building and executing examples. There are two sets of scripts. Scripts with no file extension
    are bash scripts. Scripts with a .cmd file extension are Windows command scripts. The following description
    refers to the script names without specifying any file extension.

    build               -- builds an example
    run                 -- runs an example
    run-cache-server    -- run the cluster "server" used for examples - (includes proxy service)

  java/src
    All example source. The examples are in the com.tangosol.examples.<example name> package. The classes
    for objects stored in the cache used by the examples are in the com.tangosol.examples.pof package.

  java/classes
     The class files output from a build. This directory will not exist until the build
     script is executed.

  java/resource/config
     The common coherence configuration files required by the examples.

  java/resource/<example name>
    If an example has configuration that is required instead of the common configuration, it will
    have its own directory. The security example uses configuration files from java/resource/security.

  resource
    The data file used for the contacts LoaderExample: contacts.csv.

  Ensure you are in the examples/java directory before running all the examples below.

Build Instructions
==================

  Execute the build script with the name of the example: "bin/build contacts", "bin/build security",
  "bin/build persistence", "bin/build archiver", "bin/build federation", "bin/build java8" or
  "bin/build async". The script will build the pof package files and then the files for the particular example.
  Some examples require you to also build the contacts example as it contains common classes that are used
  by a number of the examples.
  You will need to carry out additional steps (outlined below) before building the archiver example.

Run Instructions
=================

  Execute the run script.

  Note: The run-cache-server command is specific to each example.  You must stop the
        cache servers started for all previous example before starting the next example.

  Contacts example
      First, build the contacts example using:
         "bin/build contacts"

      Next, start one or more cache servers using:
          "bin/run-cache-server"

      Each execution will start a cache server cluster node. To add additional
      nodes, execute the command in a new command shell.

      Second, in a new command shell, run with the name of the example:
          "bin/run contacts".

      The Driver.main method will run through the features of the example with output
      going to the command window (stdout).

      Starting with Coherence 3.6, an example of the new Query Language feature was added.
      This example shows how to configure and use a simple helper class "FilterFactory" using the
      Coherence InvocationService.

  Security example
      The security example requires Coherence*Extend, which uses a proxy.
      The cache server for this example runs in the same JVM as the proxy.

      First, build the security example using:
           "bin/build security"

      Next, start a cache server using:
          "bin/run-cache-server security".

      The cache server also runs a proxy service which allows connections from Coherence*Extend
      clients.

      Second, in a new command shell, run with the name of the example:
          "bin/run security".
      The Driver.main method will run through the features of the example with output
      going to the command window (stdout).

  Java8 example
      The Java8 example provides code samples on how to use Coherence with various features
      introduced in Java 8 including Streams, Lambdas, and Map default methods.

      First, build the Java8 example using:
          "bin/build contacts"
          "bin/build java8"

      Next, start a cache server using:
           "bin/run-cache-server"

      Lastly, run the example using:
           "bin/run java8"

      Inspect the output and refer to the code under src/com/tangosol/examples/java8.

   Events example
      The events example provides code samples on how to utilize events through the
      Coherence Unified Events Model.

      First, build the events example using:
          "bin/build contacts"
          "bin/build events"

      Next, start at least two cache server using:
           "bin/run-cache-server events"

      Lastly, run the example using:
           "bin/run events"

      Inspect the output and refer to the code under src/com/tangosol/examples/events.

  Async example
       The Async example provides code samples on how to use asynchronous processing when using
       the AsyncNamedCache interface.

       First, build the async example using:
           "bin/build contacts"
           "bin/build async"

       Next, start a cache server using:
           "bin/run-cache-server"

       Lastly, run the examples using:
           "bin/run async"

       Inspect the output and refer to the code under src/com/tangosol/examples/async.

  Federated Caching example
      The federated caching example gives a general view of how to configure and use Federated Caching. In
      this example, two clusters are started: ClusterA and ClusterB. The clusters are setup as
      Active-Active which means data can be replicated from either cluster to the other.

      The Federated cache service is configured in the resource/federation/examples-cache-configure.xml
      and the cluster configuration is in the resource/federation/tangosol-coherence-override.xml.
      Inspect these configuration files and refer to the documentation for Federated Caching for more
      information. The configuration is all that is required to use Federated Caching.  The examples
      below use basic cache operations to insert and remove data but present this in an easy to use GUI.

      First, build the federation example using:
          "bin/build contacts"
          "bin/build federation"

      Next, start ClusterA using:
          "bin/run-cache-server federation ClusterA"

      Next, in a new command shell, start ClusterB using:
          "bin/run-cache-server federation ClusterB"

      Next, run the following to start a small GUI which connects to ClusterA:
          "bin/run federation ClusterA"

      Next, run the following to start a small GUI which connects to ClusterB:
          "bin/run federation ClusterB"

      There are now two windows, each of which is connected to a separate cluster. Carry
      out the following to exercise Federation:
      - Insert 100 objects into ClusterA's cache
      - Observe they are replicated to ClusterB
      - insert 500 objects into ClusterA's cache
      - They are replicated to ClusterB
      - Clear the cache in ClusterA
      - The removal of entries are replicated to ClusterB

      Because the setup is Active-Active, you can also insert or remove entries from ClusterB
      and the changes are replicated to ClusterA.

      Note: If you wish to run this example across two physically separate machines, carry
      out the following:
      a) Shutdown all processes.
      b) Install Coherence (with examples) on a separate machine.
      c) Build the federation examples on the seconds machine as described above.
      d) Modify resource/federation/tangosol-coherence-override.xml on each machines to change
         ClusterA and ClusterB address from 127.0.0.1 to the actual IP address of each machine.
      e) Startup cache servers using ClusterA on the first machine and ClusterB on the second machine.
      f) Insert data on the first machine using the GUI.
      g) Observe the cache size of the second cluster using the GUI.

      If you install the Coherence JVisualVM plugin, then you can monitor progress in the
      "Federation" tab.

      You may also run the following to startup CohQL for either cluster if you want to
      experiment using Federated Caching:
         "bin/run federation ClusterA cohql"

      Enabling SSL for Federated Caching Example
      ------------------------------------------
      The example above uses standard TCP connections between clusters.  The instructions
      below explain how to configure the Federated Caching example to use SSL.
      By using SSL you can encrypt connections between clusters as well as ensuring only
      authorized clusters can exchange information by using two-way Authentication.

      Note: The example below uses self signed certificates and obvious passwords. You should
            follow security best practices and online documentation to configure this for
            production environments.

      To configure the example we must do the following:
      1. Generate keystores for each of the clusters
      2. Create SSL Certificates for each cluster
      3. Import these certificates into a "trust store" that will ensure only
         authorized members can communicate.

      Note: Ensure that you have JAVA_HOME environment variable set as described in
            Prerequisites section above.

      For windows environments make sure you use %JAVA_HOME%\bin\keytool

      1. Generate Keystores for ClusterA and ClusterB
         Change to the classes directory under examples/java

         "cd classes"

         "$JAVA_HOME/bin/keytool -genkeypair -dname "cn=ClusterA, ou=Coherence, o=Oracle, c=US" -alias ClusterA -keypass password -keystore ClusterA-keystore.jks -storepass password"
         "$JAVA_HOME/bin/keytool -genkeypair -dname "cn=ClusterB, ou=Coherence, o=Oracle, c=US" -alias ClusterB -keypass password -keystore ClusterB-keystore.jks -storepass password"

      2. Export certificates from each store:
         "$JAVA_HOME/bin/keytool -export -alias ClusterA -storepass password -file ClusterA.cer -keystore ClusterA-keystore.jks"
         "$JAVA_HOME/bin/keytool -export -alias ClusterB -storepass password -file ClusterB.cer -keystore ClusterB-keystore.jks"

      3. Import both certificates into the trust store that defines which clusters can connect.
         "$JAVA_HOME/bin/keytool -import -v -trustcacerts -alias ClusterA -file ClusterA.cer -keystore trust.jks -storepass password"
         "$JAVA_HOME/bin/keytool -import -v -trustcacerts -alias ClusterB -file ClusterB.cer -keystore trust.jks -storepass password"

         Enter 'yes' for both of the above to confirm importing the certificates.

      4. Validate the entries in the trust store using:
         "$JAVA_HOME/bin/keytool -list -keystore trust.jks -storepass password"

      Once the above has been completed, you will have the following in the classes dir:
         - trust.jks    - keystore containing the ClusterA and ClusterB certificates
         - ClusterA.jks - keystore containing the ClusterA private key
         - ClusterB.jks - keystore containing the ClusterB private key

      To run the example, set the the following environment variable in each command prompt window
      and run the examples as described above.
         Windows:
            SET SSL=true

         *NIX, Solaris, OSX
            export SSL=true

      In the cache server log files you will notice that the connection is now tmbs (TCP Message Bus over SSL).
        "Connecting to service FederatedPartitionedPofCache at participant ClusterB with address tmbs://127.0.0.1:56217.39550"

      We can simulate that ClusterB is not allowed to send or receive data but removing it
      from the trust store.  To do this, firstly shutdown both cache servers an the GUI's.

      Next, remove ClusterB from the trust store.
        "$JAVA_HOME/bin/keytool -delete -keystore trust.jks -alias ClusterB -storepass password"

      Next, re-run the example as above with SSL=true. You will see RequestTimeoutExceptions from both
      clusters indicating that the connections cannot be established.

      Finally, shutdown all processes and re-import the ClusterB certificate:
        "$JAVA_HOME/bin/keytool -import -v -trustcacerts -alias ClusterB -file ClusterB.cer -keystore trust.jks -storepass password"

      Re-run the examples and the clusters will now be able to communicate.

      Important: Ensure you start a command prompt or unset the SSL environment variable if you
      are going to run other examples. E.g.
         Windows:
            SET SSL=

         *NIX, Solaris, OSX
            unset SSL

  Persistence example

      1. Basic snapshot operations
          This example shows how to call basic snapshot operations from Java.
          Persistence is configured to store data in the 'persistence-data' directory
          under java examples home. Refer to resource/persistence/tangosol-coherence-override.xml
          for details of the defined persistence-environment.

          First, build the persistence example using:
              "bin/build contacts"
              "bin/build persistence"

          Next, start one or more cache servers using:
              "bin/run-cache-server persistence"

          Next, run the persistence example using:
              "bin/run persistence"

          The Driver.main method will run through the features of the example with output
          going to the command window (stdout).

      2. Displaying Persistence notifications
          This example shows how to determine the duration of Persistence operations
          by subscribing to JMX notifications.

          First, start one or more cache servers using:
              "bin/run-cache-server persistence"

          Next, start the notification listener using:
              "bin/run persistence notifications"

          Lastly, in a new command shell, leaving "persistence notifications" running,
          run the persistence example using:
              "bin/run persistence"

          You should see output similar to below, indicating that Persistence operations
          are being carried out.

             Thu Mar 19 15:41:17 AWST 2015 : PartitionedPofCache (create.snapshot.begin) Building snapshot "snapshot-empty"
             Thu Mar 19 15:41:17 AWST 2015 : PartitionedPofCache (create.snapshot.end)   Successfully created snapshot "snapshot-empty" (Duration=295ms)

          Use CTRL-C to interrupt the notifications listener.

      3. Running Persistence operations in parallel
          This example shows how to run operations in parallel across multiple services.
          Note: As these operations are I/O intensive, running in parallel may not
          yield faster snapshot times.

          First, start one or more cache servers using:
              "bin/run-cache-server persistence"

          Next, run the persistence example using:
              "bin/run persistence parallel"

      4. Using SFTP to archive snapshots
          Coherence provides a directory snapshot archiver out of the box to archive snapshots
          to a shared directory location available to all cluster members.

          This examples shows an example of a custom snapshot archiver which uses SFTP
          to store and retrieve snapshots.  In this example we have used the JSch library
          from JCraft (http://www.jcraft.com/jsch/).

          To build the archiver example, you must download the JSch library jsch-0.1.51.jar
          and extract the contents into the classes directory. E.g.
              "cd classes"
              "jar xvf /path/to/jsch-0.1.51.jar"
              "cd .."

          First, build the archiver example using:
              "bin/build archiver"

          Next, update the file resource/archiver/tangosol-coherence-override.xml and modify the
          third parameter for the custom archiver and replace the username, password and
          path to the location of a machine running SSH.  If you have ssh equivalence setup to
          your machine, you can omit the password.

          Note: Use ssh-keygen -t rsa to generate an authorized_keys file as hosts.equiv/.rhosts
          may not work on all platforms. You may also consider using other methods to hide your
          password if one is required.

          Next, start one or more cache servers using:
              "bin/run-cache-server archiver"

          If the cache servers fail to start, this may indicate the the authentication or remote
          details are not correct.

          Next, run the archive example using:
              "bin/run archiver"

          The following message will be displayed:
              "look at archived snapshot on remote SFTP machine then press RETURN to continue"

          You can inspect the remote SFTP machine to see the archive directory and archive
          parts have been written. When complete, press RETURN to continue running the example.

References
==========

  Coherence Documentation:

    http://www.oracle.com/technetwork/middleware/coherence/documentation/index.html

  Coherence Community:

    https://coherence.java.net/

