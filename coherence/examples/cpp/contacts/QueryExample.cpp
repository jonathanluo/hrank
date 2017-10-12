/*
 * #%L
 * QueryExample.cpp
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

#include "QueryExample.hpp"

#include "coherence/util/Filter.hpp"
#include "coherence/util/Iterator.hpp"
#include "coherence/util/aggregator/ComparableMin.hpp"
#include "coherence/util/aggregator/Count.hpp"
#include "coherence/util/aggregator/Float64Average.hpp"
#include "coherence/util/aggregator/Integer64Max.hpp"
#include "coherence/util/aggregator/Integer64Min.hpp"
#include "coherence/util/extractor/ChainedExtractor.hpp"
#include "coherence/util/extractor/IdentityExtractor.hpp"
#include "coherence/util/extractor/ReflectionExtractor.hpp"
#include "coherence/util/extractor/KeyExtractor.hpp"
#include "coherence/util/ValueExtractor.hpp"
#include "coherence/util/filter/AlwaysFilter.hpp"
#include "coherence/util/filter/AndFilter.hpp"
#include "coherence/util/filter/EqualsFilter.hpp"
#include "coherence/util/filter/GreaterFilter.hpp"
#include "coherence/util/filter/LikeFilter.hpp"
#include "coherence/util/filter/NotEqualsFilter.hpp"

COH_OPEN_NAMESPACE2(coherence,examples)

using coherence::util::Filter;
using coherence::util::Iterator;
using coherence::util::ValueExtractor;
using coherence::util::aggregator::ComparableMin;
using coherence::util::aggregator::Count;
using coherence::util::aggregator::Float64Average;
using coherence::util::aggregator::Integer64Max;
using coherence::util::aggregator::Integer64Min;
using coherence::util::extractor::ChainedExtractor;
using coherence::util::extractor::IdentityExtractor;
using coherence::util::extractor::ReflectionExtractor;
using coherence::util::extractor::KeyExtractor;
using coherence::util::filter::AlwaysFilter;
using coherence::util::filter::AndFilter;
using coherence::util::filter::EqualsFilter;
using coherence::util::filter::GreaterFilter;
using coherence::util::filter::LikeFilter;
using coherence::util::filter::NotEqualsFilter;


void QueryExample::query(NamedCache::Handle hCache) const
    {
    std::cout << "------QueryExample begins------" << std::endl;
    // Create Reflection Extractors
    // Home address Extractor
    ValueExtractor::View vAddrHomeExtractor = ReflectionExtractor::create(
            "getHomeAddress");
    // Work address Extractor
    ValueExtractor::View vAddrWorkExtractor = ReflectionExtractor::create(
            "getWorkAddress");
    // Age Extractor
    ValueExtractor::View vAgeExtractor = ReflectionExtractor::create("getAge");
    // Last name Extractor from the Key
    ValueExtractor::View vLastNameExtractor = KeyExtractor::create(
            ReflectionExtractor::create("getLastName"));
    // Home state extractor
    ValueExtractor::View vHomeStateExtractor = ChainedExtractor::create(
            ChainedExtractor::createExtractors("getHomeAddress.getState"));
    // Home city extractor
    ValueExtractor::View vHomeCityExtractor = ChainedExtractor::create(
            ChainedExtractor::createExtractors("getHomeAddress.getCity"));
    // Work state extractor
    ValueExtractor::View vWorkStateExtractor = ChainedExtractor::create(
            ChainedExtractor::createExtractors("getWorkAddress.getState"));

    // Ordered index applied to fields used in range and like filter queries.
    hCache->addIndex(vAgeExtractor,       /*fOrdered*/ true,  /*vComparator*/ NULL);
    hCache->addIndex(vLastNameExtractor,  /*fOrdered*/ true,  /*vComparator*/ NULL);
    hCache->addIndex(vHomeCityExtractor,  /*fOrdered*/ true,  /*vComparator*/ NULL);
    hCache->addIndex(vHomeStateExtractor, /*fOrdered*/ false, /*vComparator*/ NULL);
    hCache->addIndex(vWorkStateExtractor, /*fOrdered*/ false, /*vComparator*/ NULL);

    Object::View voStateName = String::create("MA");
    // Find all contacts who live in Massachusetts
    Set::View setResults = hCache->entrySet(
            EqualsFilter::create(vHomeStateExtractor, voStateName));
    printResults("MA Residents", setResults);

    // Find all contacts who live in Massachusetts and work elsewhere
    setResults = hCache->entrySet(
            AndFilter::create(
                    EqualsFilter::create(vHomeStateExtractor, voStateName),
                    NotEqualsFilter::create(vWorkStateExtractor, voStateName)));
    printResults("MA Residents, Work Elsewhere", setResults);

    // Find all contacts whose city name begins with 'Sa'
    setResults = hCache->entrySet(LikeFilter::create(vHomeCityExtractor, "Sa%"));
    printResults("City Begins with Sa", setResults);

    // Find all contacts who are older than nAge
    Integer32::View nAge = Integer32::valueOf(58);
    setResults = hCache->entrySet(GreaterFilter::create(vAgeExtractor, nAge));
    printResults(COH_TO_STRING ("Age > " << nAge->getValue()), setResults);

    // Find all contacts with last name beginning with 'Sa' that live
    // in Massachusetts. Uses both key and value in the query
    setResults = hCache->entrySet(
            AndFilter::create(
                    LikeFilter::create(vLastNameExtractor, "Sa%"),
                    EqualsFilter::create(vHomeStateExtractor, voStateName)));
    printResults("Last Name Begins with Sa and State is MA", setResults);

    // Count contacts who are older than nAge for the entire cache.
    Object::View vResult = hCache->aggregate(
            (Filter::View) GreaterFilter::create(vAgeExtractor, nAge),
            Count::create());
    std::cout << "count > " << nAge->getValue() << ": " << vResult << std::endl;

    // Setup aggregators
    Integer64Min::Handle   hnMinAge	 = Integer64Min::create(vAgeExtractor);
    Integer64Max::Handle   hnMaxAge	 = Integer64Max::create(vAgeExtractor);
    Float64Average::Handle hdflAvgAge = Float64Average::create(vAgeExtractor);
    AlwaysFilter::Handle   hFilter    = AlwaysFilter::getInstance();

    // Find minimum age for the entire cache.
    std::cout << "min age: " << cast<Integer64::View>(hCache->aggregate(
            (Filter::View) hFilter, hnMinAge)) << std::endl;

    // Calculate average age for the entire cache.
    std::cout << "avg age: " << cast<Float64::View>(hCache->aggregate(
            (Filter::View) hFilter, hdflAvgAge)) << std::endl;

    // Find maximum age for the entire cache.
    std::cout << "max age: " << cast<Integer64::View>(hCache->aggregate(
            (Filter::View) hFilter, hnMaxAge)) << std::endl;
    std::cout << "------QueryExample completed------" << std::endl;
    }

void QueryExample::printResults(String::View vsTitle, Set::View vSetResult) const
    {
    std::cout << vsTitle << std::endl;

    for (Iterator::Handle iter = vSetResult->iterator(); iter->hasNext(); )
        {
        Map::Entry::View vEntry = cast<Map::Entry::View>(iter->next());
        std::cout << vEntry->getKey() << " " << vEntry->getValue() << std::endl;
        }
    }

COH_CLOSE_NAMESPACE2
