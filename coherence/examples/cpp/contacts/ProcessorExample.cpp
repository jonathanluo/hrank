/*
 * #%L
 * ProcessorExample.cpp
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

#include "coherence/util/Filter.hpp"
#include "coherence/util/InvocableMap.hpp"
#include "coherence/util/Map.hpp"
#include "coherence/util/extractor/ChainedExtractor.hpp"
#include "coherence/util/filter/EqualsFilter.hpp"
#include "coherence/util/processor/UpdaterProcessor.hpp"

#include "ProcessorExample.hpp"
#include "pof/Address.hpp"
#include "pof/OfficeUpdater.hpp"

COH_OPEN_NAMESPACE2(coherence,examples)

using coherence::util::Filter;
using coherence::util::InvocableMap;
using coherence::util::Map;
using coherence::util::extractor::ChainedExtractor;
using coherence::util::filter::EqualsFilter;

void ProcessorExample::execute(NamedCache::Handle hCache) const
    {
    std::cout <<  "------ProcessorExample begins------" << std::endl;
    // People who live in Massachusetts moved to an in-state office
    Managed<Address>::View addrWork = Managed<Address>::create(
            Address("200 Newbury St.", "Yoyodyne, Ltd.",
                    "Boston", "MA", "02116", "US"));

    // Apply the OfficeUpdater on all contacts who live in MA
    Filter::View vEqualsFilter = EqualsFilter::create(
            ChainedExtractor::create(ChainedExtractor::createExtractors(
                    "getHomeAddress.getState")),
                    String::create("MA"));
    InvocableMap::EntryProcessor::Handle hOffice = OfficeUpdater::create(addrWork);
    Map::View vMap = hCache->invokeAll(vEqualsFilter, hOffice);
    std::cout <<  "------ProcessorExample completed------" << std::endl;
    }

COH_CLOSE_NAMESPACE2
