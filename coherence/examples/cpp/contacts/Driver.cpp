/*
 * #%L
 * Driver.cpp
 * ---
 * Copyright (C) 2000 - 2017 Oracle and/or its affiliates. All rights reserved.
 * ---
 * Oracle is a registered trademarks of Oracle Corporation and/or its
 * affiliates.
 * 
 * This software is the confidential and proprietary information of Oracle
 * Corporation. You shall not disclose such confidential and proprietary
 * information and shall use it only in accordance with the terms of the
 * license agreement you entered into with Oracle.
 * 
 * This notice may not be removed or altered.
 * #L%
 */

/**
 * Driver executes all the contact examples. The driver will if not passed a
 * cache name use the 'contacts' as as the default cache name. If
 * passed a different name, make sure that the changes are reflected in the
 * configuration files.
 * <p/>
 * Before the examples are run, the Driver will populate the cache with random
 * contact data.
 * <p/>
 * Examples are invoked in this order <p/>
 * 1) LoaderExample<br/>
 * 2) QueryExample <br/>
 * 3) QueryLanguageExample <br/>
 * 4) ObserverExample <br/>
 * 5) BasicExample<br/>
 * 6) ProcessorExample<br/>
 *
 * @author ch  2009.03.02
 */
#include <fstream>
#include <iostream>

#include "coherence/lang/Exception.hpp"
#include "coherence/lang/String.hpp"
#include "coherence/net/CacheFactory.hpp"
#include "coherence/net/NamedCache.hpp"

#include "BasicExample.hpp"
#include "LoaderExample.hpp"
#include "ObserverExample.hpp"

#include "ProcessorExample.hpp"
#include "QueryExample.hpp"
#include "QueryLanguageExample.hpp"

using coherence::lang::Exception;
using coherence::lang::String;
using coherence::net::CacheFactory;
using coherence::net::NamedCache;

using namespace coherence::examples;

#define DEFUALT_CONTACTS "../../resource/contacts.csv"


/**
 * Execute Contact examples.
 * <p/>
 * usage: [cache-name] [contacts file]
 *
 * @param asArg command line arguments
 *
 * return 0 when done
 */
int main(int argc, char** argv)
    {
    try
        {
        // The first argument is the name of the cache
        String::View vsCache        = argc > 1 ? argv[1] : "contacts";
        String::View vsContactsFile = argc > 2 ? argv[2] : DEFUALT_CONTACTS;

        std::cout << "------contacts examples begin------" << std::endl;
        // retrieve the cache
        NamedCache::Handle hCache = CacheFactory::getCache(vsCache);
        // Load data into cache
        std::ifstream contactsFile(vsContactsFile->getCString());
        if (contactsFile.fail())
            {
        std::cerr << "unable to open source file: " << vsContactsFile
        << std::endl;
        return 1;
            }

        std::cout << "Loading " << vsContactsFile << std::endl;
        LoaderExample loader;
        loader.load(contactsFile, hCache);

        // Run sample queries.
        QueryExample querier;
        querier.query(hCache);

        // Run sample queries using query language.
        QueryLanguageExample languageQuerier;
        languageQuerier.query(hCache, FilterFactory::create("InvocationService"));

        // Run sample change observer.
        ObserverExample observer;
        observer.observe(hCache);

        // Run basic cache commands.
        BasicExample basic;
        basic.execute(hCache);

        // Run sample entry processor.
        ProcessorExample processor;
        processor.execute(hCache);

        // remove the observer
        observer.remove(hCache);

        CacheFactory::shutdown();
        std::cout << "------contacts examples completed------" << std::endl;
        }
    catch (Exception::View ex)
        {
        std::cout << ex << std::endl;
        }
    return 0;
    }
