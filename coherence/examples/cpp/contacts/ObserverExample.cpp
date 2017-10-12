/*
 * #%L
 * ObserverExample.cpp
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

#include "ObserverExample.hpp"

COH_OPEN_NAMESPACE2(coherence,examples)

void ObserverExample::observe(NamedCache::Handle hCache)
    {
    std::cout << "------ObserverExample begins------" << std::endl;
    m_hListener = ContactChangeListener::create();
    hCache->addFilterListener(m_hListener);
    std::cout << "------ContactChangleListener added------" << std::endl;
    }

void ObserverExample::remove(NamedCache::Handle hCache)
    {
    hCache->removeFilterListener(m_hListener, NULL);
    std::cout << "------ContactChangeListener removed------" << std::endl;
    std::cout << "------ObserverExample completed------" << std::endl;
    }

COH_CLOSE_NAMESPACE2
