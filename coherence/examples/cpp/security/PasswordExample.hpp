
#ifndef COH_EXAMPLES_PASSWORDEXAMPLE_HPP
#define COH_EXAMPLES_PASSWORDEXAMPLE_HPP

#include "coherence/lang.ns"

COH_OPEN_NAMESPACE2(coherence,examples)

using namespace coherence::lang;

/**
* This class shows how a Coherence Proxy can require a password to get a
* reference to a cache.
* <p>
* The PasswordIdentityTransformer will generate a security token that
* contains the password. The PasswordIdentityAsserter will validate the
* security token to enforce the password. The token generation and
* validation occurs automatically when a connection to the proxy is made.
*
* @author dag 2010.04.30
*/
class PasswordExample
    {
    // ----- PasswordExample methods ----------------------------------------

    public:
        /**
        * Get a reference to the cache. Password will be required.
        */
        virtual void getCache();

        virtual ~PasswordExample() {}
    };

COH_CLOSE_NAMESPACE2

#endif //COH_EXAMPLES_PASSWORDEXAMPLE_HPP
