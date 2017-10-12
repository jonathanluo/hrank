/*
 * #%L
 * PasswordExample.cpp
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

#include "PasswordExample.hpp"
#include "SecurityExampleHelper.hpp"

#include "coherence/net/CacheFactory.hpp"
#include "coherence/net/NamedCache.hpp"
#include "coherence/security/RunAsBlock.hpp"

COH_OPEN_NAMESPACE2(coherence,examples)

using namespace coherence::lang;

using coherence::net::CacheFactory;
using coherence::net::NamedCache;
using coherence::security::auth::Subject;


void PasswordExample::getCache()
    {
    std::cout << "------PasswordExample begins------" << std::endl;

    Subject::View vSubject = SecurityExampleHelper::login("BuckarooBanzai");

    try
        {
        NamedCache::Handle hCache = NULL;

        COH_RUN_AS(vSubject)
            {
            hCache = CacheFactory::getCache("security");
            }

        std::cout << "------password example succeeded------" << std::endl;
        }
    catch (Exception::View ve)
        {
        // get exception if the password is invalid
        std::cout << "Unable to connect to proxy" << std::endl;
        std::cout << ve << std::endl;
        }

    std::cout << "------PasswordExample completed------" << std::endl;
    }

COH_CLOSE_NAMESPACE2
