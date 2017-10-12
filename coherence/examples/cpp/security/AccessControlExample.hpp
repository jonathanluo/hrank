
#ifndef COH_EXAMPLES_ACCESSCONTROLEXAMPLE_HPP
#define COH_EXAMPLES_ACCESSCONTROLEXAMPLE_HPP

#include "coherence/lang.ns"

COH_OPEN_NAMESPACE2(coherence,examples)

using namespace coherence::lang;

/**
* This class demonstrates simplified role based access control.
* <p>
* The role policies are defined in SecurityExampleHelper. Enforcement
* is done by EntitledCacheService and EntitledNamedCache on the proxy.
*
* @author dag 2010.05.04
*/
class AccessControlExample
    {
    // ----- AccessControlExample methods -----------------------------------

    public:
        /**
        * Demonstrate role based access to the cache.
        */
        virtual void accessCache();

        /**
        * Demonstrate role based access to the invocation service.
        */
        virtual void accessInvocationService();

        virtual ~AccessControlExample() {}
    };

COH_CLOSE_NAMESPACE2

#endif //COH_EXAMPLES_ACCESSCONTROLEXAMPLE_HPP
