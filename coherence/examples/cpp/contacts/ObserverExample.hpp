
#ifndef COH_EXAMPLES_OBSERVEREXAMPLE_HPP
#define COH_EXAMPLES_OBSERVEREXAMPLE_HPP

#include "coherence/net/NamedCache.hpp"

#include "ContactChangeListener.hpp"

COH_OPEN_NAMESPACE2(coherence,examples)

using coherence::net::NamedCache;

/**
 * ObserverExample demonstrates how to use a MapListener to monitor cache events.
 *
 * @author ch  20094.07
 */
class ObserverExample
    {
    // ----- Constructors   -----------------------------------------------

    public:
        virtual ~ObserverExample() {}


    // ----- ObserverExample methods --------------------------------------

    public:
        /**
        * Observe changes to the contacts.
        *
        * @param hCache  target cache
        */
        virtual void observe(NamedCache::Handle hCache);

        /**
        * Stop observing changes to the contacts.
        *
        * @param hCache  target cache
        */
        virtual void remove(NamedCache::Handle hCache);


        // -----data members    ------------------------------------------

    private:
        /**
        * The MapListener observing changes
        */
        ContactChangeListener::Handle m_hListener;
    };

COH_CLOSE_NAMESPACE2

#endif //COH_EXAMPLES_OBSERVEREXAMPLE_HPP
