/*
 * #%L
 * QueryLanguageExample.cpp
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

#include "coherence/util/aggregator/ComparableMin.hpp"
#include "coherence/util/aggregator/Count.hpp"
#include "coherence/util/aggregator/Float64Average.hpp"
#include "coherence/util/aggregator/Integer64Max.hpp"
#include "coherence/util/aggregator/Integer64Min.hpp"
#include "coherence/util/Filter.hpp"
#include "coherence/util/HashMap.hpp"
#include "coherence/util/Iterator.hpp"
#include "coherence/util/ValueExtractor.hpp"

#include "QueryLanguageExample.hpp"


COH_OPEN_NAMESPACE2(coherence,examples)

using coherence::util::Filter;
using coherence::util::Iterator;
using coherence::util::HashMap;
using coherence::util::ValueExtractor;
using coherence::util::aggregator::ComparableMin;
using coherence::util::aggregator::Count;
using coherence::util::aggregator::Float64Average;
using coherence::util::aggregator::Integer64Max;
using coherence::util::aggregator::Integer64Min;

void QueryLanguageExample::query(NamedCache::Handle hCache,
                          FilterFactory::Handle hff) const
    {
    std::cout << "------QueryLanguageExample begins------" << std::endl;

    // Ordered index applied to fields used in range and like filter queries.
    hCache->addIndex(hff->createExtractor("age"),
       /*fOrdered*/ true,  /*vComparator*/ NULL);
    hCache->addIndex(hff->createExtractor("key().lastName"),
      /*fOrdered*/ true,  /*vComparator*/ NULL);
    hCache->addIndex(hff->createExtractor("homeAddress.city"),
      /*fOrdered*/ true,  /*vComparator*/ NULL);
    hCache->addIndex(hff->createExtractor("homeAddress.state"),
      /*fOrdered*/ false, /*vComparator*/ NULL);
    hCache->addIndex(hff->createExtractor("workAddress.state"),
     /*fOrdered*/ false, /*vComparator*/ NULL);

    Object::View voStateName = String::create("MA");
    // Find all contacts who live in Massachusetts
    Set::View setResults = hCache->entrySet(hff->createFilter("homeAddress.state is 'MA'"));
     printResults("MA Residents", setResults);

    // Find all contacts who live in Massachusetts and work elsewhere
    setResults = hCache->entrySet(
          hff->createFilter("homeAddress.state is 'MA' and workAddress.state is not 'MA'"));
    printResults("MA Residents, Work Elsewhere", setResults);

    // Find all contacts whose city name begins with 'Sa'
    setResults = hCache->entrySet(hff->createFilter("homeAddress.city like 'Sa%'"));
    printResults("City Begins with Sa", setResults);

    // Find all contacts who are older than nAge
    Integer32::View     nAge   = Integer32::valueOf(58);
    ObjectArray::Handle haEnv  = ObjectArray::create(1);
    HashMap::Handle     hbinds = HashMap::create();

	haEnv[0]   = nAge;
    hbinds->put(String::create("nAge"), nAge);
    setResults = hCache->entrySet(hff->createFilter("age > ?1", haEnv));
    printResults(COH_TO_STRING ("Age > " << nAge->getValue()), setResults);

    // Find all contacts with last name beginning with 'Sa' that live
    // in Massachusetts. Uses both key and value in the query
    setResults = hCache->entrySet(
           hff->createFilter("key().lastName like 'Sa%' and homeAddress.state = 'MA'"));
    printResults("Last Name Begins with Sa and State is MA", setResults);

    // Count contacts who are older than nAge for the entire cache.
    Object::View vResult = hCache->aggregate(
            hff->createFilter("age > :nAge", haEnv, hbinds),
            Count::create());
    std::cout << "count > " << nAge->getValue() << ": " << vResult << std::endl;

    // Setup aggregators

    ValueExtractor::View   vAgeExtractor = hff->createExtractor("age");
    Integer64Min::Handle   hnMinAge	     = Integer64Min::create(vAgeExtractor);
    Integer64Max::Handle   hnMaxAge	     = Integer64Max::create(vAgeExtractor);
    Float64Average::Handle hdflAvgAge    = Float64Average::create(vAgeExtractor);
    Filter::View           hFilter       = hff->createFilter("true");

    // Find minimum age for the entire cache.
    std::cout << "min age: " << cast<Integer64::View>(hCache->aggregate(
            hFilter, hnMinAge)) << std::endl;

    // Calculate average age for the entire cache.
    std::cout << "avg age: " << cast<Float64::View>(hCache->aggregate(
            hFilter, hdflAvgAge)) << std::endl;

    // Find maximum age for the entire cache.
    std::cout << "max age: " << cast<Integer64::View>(hCache->aggregate(
            hFilter, hnMaxAge)) << std::endl;

    std::cout << "------QueryLanguageExample completed------" << std::endl;
    }

void QueryLanguageExample::printResults(String::View vsTitle, Set::View vSetResult) const
    {
	std::cout << vsTitle << std::endl;

    for (Iterator::Handle iter = vSetResult->iterator(); iter->hasNext(); )
        {
        Map::Entry::View vEntry = cast<Map::Entry::View>(iter->next());

		//  Cast the key type to ContactId and value type to Contact, their original types. 
        std::cout << cast<Managed<ContactId>::View>(vEntry->getKey()) << " " << cast<Managed<Contact>::View>(vEntry->getValue()) << std::endl;
        }
    }

COH_CLOSE_NAMESPACE2

