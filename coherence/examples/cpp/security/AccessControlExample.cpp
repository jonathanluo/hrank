/*
 * #%L
 * AccessControlExample.cpp
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

#include "AccessControlExample.hpp"
#include "SecurityExampleHelper.hpp"
#include "pof/ExampleInvocable.hpp"

#include "coherence/net/CacheFactory.hpp"
#include "coherence/net/InvocationService.hpp"
#include "coherence/security/RunAsBlock.hpp"

COH_OPEN_NAMESPACE2(coherence,examples)

using namespace coherence::lang;

using coherence::net::CacheFactory;
using coherence::net::InvocationService;
using coherence::net::NamedCache;
using coherence::security::auth::Subject;

#define SECURITY_CACHE_NAME "security"
#define INVOCATION_SERVICE_NAME "InvocationService"


void AccessControlExample::accessCache()
    {
    std::cout << "------cache access control example begins------" << std::endl;

    Subject::View vSubject = SecurityExampleHelper::login("JohnWhorfin");

    // Someone with writer role can write and read
    try
        {
        NamedCache::Handle hCache = NULL;

        COH_RUN_AS(vSubject)
            {
            hCache = CacheFactory::getCache(SECURITY_CACHE_NAME);
            }
        hCache->put(String::create("myKey"), String::create("myValue"));
        hCache->get(String::create("myKey"));
        std::cout <<  "    Success: read and write allowed" << std::endl;
        }
    catch (Exception::View ve)
        {
        // get exception if not allowed to perform the operation
        std::cout << ve << std::endl;
        }

    // Someone with reader role can read but not write
    vSubject = SecurityExampleHelper::login("JohnBigboote");
    try
        {
        NamedCache::Handle hCache = NULL;

        COH_RUN_AS(vSubject)
            {
            hCache = CacheFactory::getCache(SECURITY_CACHE_NAME);
            }
        hCache->get(String::create("myKey"));
        std::cout <<  "    Success: read allowed" << std::endl;
        hCache->put(String::create("anotherKey"), String::create("anotherValue"));
        }
    catch (Exception::View ve)
        {
        // get exception if not allowed to perform the operation
        std::cout <<
                "    Success: Correctly cannot write" << std::endl;
        }

    // Someone with writer role cannot call destroy
    vSubject = SecurityExampleHelper::login("JohnWhorfin");
    try
        {
        NamedCache::Handle hCache = NULL;

        COH_RUN_AS(vSubject)
            {
            hCache = CacheFactory::getCache(SECURITY_CACHE_NAME);
            }
        hCache->destroy();
        }
    catch (Exception::View ve)
        {
        // get exception if not allowed to perform the operation
        std::cout <<
                "    Success: Correctly cannot destroy the cache" << std::endl;
        }

    // Someone with admin role can call destroy
    vSubject = SecurityExampleHelper::login("BuckarooBanzai");
    try
        {
        NamedCache::Handle hCache = NULL;

        COH_RUN_AS(vSubject)
            {
            hCache = CacheFactory::getCache(SECURITY_CACHE_NAME);
            }
        hCache->destroy();
        std::cout <<
                "    Success: Correctly allowed to destroy the cache" << std::endl;
        }
    catch (Exception::View ve)
        {
        // get exception if not allowed to perform the operation
        std::cout << ve << std::endl;
        }

    std::cout << "------cache access control example completed------" << std::endl;
    }

void AccessControlExample::accessInvocationService()
    {
    std::cout <<
            "------InvocationService access control example begins------" << std::endl;

    Subject::View vSubject = SecurityExampleHelper::login("JohnWhorfin");

    // Someone with writer role can run invocables
    try
        {
        InvocationService::Handle hService;

        COH_RUN_AS(vSubject)
            {
            hService = cast<InvocationService::Handle>
                (CacheFactory::getService(INVOCATION_SERVICE_NAME));
            }
        hService->query(ExampleInvocable::create(), NULL);
        std::cout <<
                "    Success: Correctly allowed to use the invocation service"
                << std::endl;
        }
    catch (Exception::View ve)
        {
        // get exception if not allowed to perform the operation
        std::cout << ve << std::endl;
        }

    // Someone with reader role cannot cannot run invocables
    vSubject = SecurityExampleHelper::login("JohnBigboote");
    try
        {
        InvocationService::Handle hService;

        COH_RUN_AS(vSubject)
            {
            hService = cast<InvocationService::Handle>
                (CacheFactory::getService(INVOCATION_SERVICE_NAME));
            }
        hService->query(ExampleInvocable::create(), NULL);
        }
    catch (Exception::View ve)
        {
        // get exception if not allowed to perform the operation
        std::cout <<
                "    Success: Correctly unable to use the invocation service"
                << std::endl;
        }

    std::cout <<
            "------InvocationService access control example completed------"
            << std::endl;
    }

COH_CLOSE_NAMESPACE2

