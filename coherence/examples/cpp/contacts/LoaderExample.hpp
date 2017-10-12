
#ifndef COH_EXAMPLES_LOADERXAMPLE_HPP
#define COH_EXAMPLES_LOADERXAMPLE_HPP

#include <iostream>

#include "coherence/lang.ns"
#include "coherence/net/NamedCache.hpp"

COH_OPEN_NAMESPACE2(coherence,examples)

using namespace coherence::lang;
using coherence::net::NamedCache;

/**
 * LoaderExample loads contacts into the cache from a file or stream.
 * <p/>
 * Demonstrates the most effective way of inserting data into a cache using the
 * Map.putAll() method. This will allow for minimizing the number of network
 * round trips between the application and the cache.
 *
 * @author ch 2009-04-06
 */
class LoaderExample
    {
        // ----- Constructors ----------------------------------------------------

    public:
        virtual ~LoaderExample() {}


        // ----- public methods --------------------------------------------------

    public:
        /**
         * Load contacts from the input stream and insert them into the cache.
         *
         * @param in      stream containing contacts
         * @param hCache  target cache
         */
        virtual void load(std::istream& in, NamedCache::Handle hCache) const;

        /**
         * Read a single contact from the supplied stream.
         *
         * @param in  the stream from which to read a contact
         *
         * @return  the contact or null upon reaching end of stream
         */
        virtual Managed<Contact>::View readContact(std::istream& in) const;
    };

COH_CLOSE_NAMESPACE2

#endif //COH_EXAMPLES_LOADERXAMPLE_HPP
