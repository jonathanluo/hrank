/*
 * #%L
 * FilterFactory.cpp
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

#include "coherence/net/CacheFactory.hpp"
#include "coherence/net/Service.hpp"

#include "coherence/util/Iterator.hpp"

#include "FilterFactory.hpp"
#include "pof/FilterFetcher.hpp"


COH_OPEN_NAMESPACE2(coherence,examples)

using coherence::net::CacheFactory;
using coherence::net::Service;
using coherence::util::Iterator;


// ----- constructors -------------------------------------------------------

FilterFactory::FilterFactory()
  : m_hService(self(), NULL)
    {
    }
   
FilterFactory::FilterFactory(String::View vsName)
  : m_hService(self(), NULL)
    {
    COH_ENSURE_PARAM(vsName);
    try
        {
        Service::Handle hs = CacheFactory::getService(vsName);
        m_hService         = cast<InvocationService::Handle>(hs);
        }
    catch (Exception::View)
        {
        m_hService = NULL;
        }
    }


// ----- FilterBuilder API ---------------------------------------------------

Filter::View FilterFactory::createFilter(String::View vs,
               ObjectArray::View vaBindings, Map::View vmapBindings)
    {
    return fetchFilter(vs, vaBindings, vmapBindings);
    }

ValueExtractor::View FilterFactory::createExtractor(String::View vs)
    {
    return fetchExtractor(vs);
    }

// ----- Helper Methods -----------------------------------------------------

ValueExtractor::View FilterFactory::fetchExtractor(String::View vs)
    {
    if (m_hService == NULL)
        {
        return NULL;
        }
    FilterFetcher::Handle hff      = FilterFetcher::create(vs, true);
    Map::View             vresult  = m_hService->query(hff, NULL);
    Iterator::Handle      hIter    = vresult->values()->iterator();
    if (hIter->hasNext())
        {
        return cast<ValueExtractor::View>(hIter->next());
        }
    else
        {
        return NULL;
        }
    }
     
Filter::View FilterFactory::fetchFilter(String::View vs,
            ObjectArray::View vaBindings, Map::View vmapBindings)
    {
    if (m_hService == NULL)
        {
        return NULL;
        }
    FilterFetcher::Handle hff     = FilterFetcher::create(vs, false,
                                    vaBindings, vmapBindings);
    Map::View             vresult = m_hService->query(hff,NULL);
    Iterator::Handle      hIter   = vresult->values()->iterator();
    if (hIter->hasNext())
        {
        return cast<Filter::View>(hIter->next());
        }
    else
        {
        return NULL;
        }
    }

COH_CLOSE_NAMESPACE2
