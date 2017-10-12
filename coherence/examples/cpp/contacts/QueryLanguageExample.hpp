
#ifndef COH_EXAMPLES_QUERYLANGUAGEEXAMPLE_HPP
#define COH_EXAMPLES_QUERYLANGUAGEEXAMPLE_HPP

#include <iostream>

#include "coherence/lang.ns"
#include "coherence/net/NamedCache.hpp"
#include "coherence/util/Set.hpp"

#include "Contacts.hpp"
#include "FilterFactory.hpp"

COH_OPEN_NAMESPACE2(coherence,examples)


using namespace coherence::lang;
using coherence::net::NamedCache;
using coherence::util::Set;

/**
* QueryLanguageExample runs sample queries for contacts.
* <p/>
* The purpose of this example is to show how to create ReflectionExtrector on
* cache data. How to create a KeyExtractor index for the cache keys.
* <p/>
* It also illustrates how to utilize the indexes to filter the data set how to
* efficiently create a matching set.
* <p/>
* Finally the example demonstrates how to use some of the built-in cache
* aggregators to do simple computational tasks on the cache data.
*
* @author ch 2009.04.07
*/
class QueryLanguageExample
    {
        // ----- Constructors   --------------------------------------------------
    public:
        virtual ~QueryLanguageExample()
            {
            }

        // ----- QueryLanguageExample methods --------------------------------------

    public:
        /**
        * Create indexes in the cache and query it for data.
        *
        * @param hCache  cache to query
        * @param hFF     the FilterFactory used to convert String to Filters
        */
        virtual void query(NamedCache::Handle hCache, FilterFactory::Handle hFF) const;

    private:
        /**
        * Print results of the query
        *
        * @param sTitle       the title that describes the results
        * @param vsetResults  a set of query results
        */
        void printResults(String::View vsTitle, Set::View vsetResults) const;
    };

COH_CLOSE_NAMESPACE2

#endif //COH_EXAMPLES_QUERYLANGUAGEEXAMPLE_HPP
