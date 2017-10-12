
#ifndef COH_EXAMPLES_BASICEXAMPLE_HPP
#define COH_EXAMPLES_BASICEXAMPLE_HPP

#include "coherence/lang.ns"
#include "coherence/net/NamedCache.hpp"

#include "Contacts.hpp"

COH_OPEN_NAMESPACE2(coherence,examples)

using namespace coherence::lang;
using coherence::net::NamedCache;

/**
* BasicExample shows basic cache operations like adding, getting and removing
* data.
*
* @author ch  2009.04.03
*/
class BasicExample
    {
        // ----- Constructors ----------------------------------------------------

    public:
        BasicExample() {}

        virtual ~BasicExample() {}


        // ----- BasicExample methods --------------------------------------------

    public:
        /**
        * Execute a cycle of basic operations.
        *
        * @param cache  target cache
        */
        virtual void execute(NamedCache::Handle hCache);

    protected:

        virtual Contact generateContact() const;
    };

COH_CLOSE_NAMESPACE2

#endif //COH_EXAMPLES_BASICEXAMPLE_HPP
