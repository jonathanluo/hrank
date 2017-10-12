
#ifndef COH_EXAMPLES_CONTACTCHANGELISTENER_HPP
#define COH_EXAMPLES_CONTACTCHANGELISTENER_HPP

#include "coherence/lang.ns"
#include "coherence/util/MapEvent.hpp"
#include "coherence/util/MapListener.hpp"

COH_OPEN_NAMESPACE2(coherence,examples)

using namespace coherence::lang;
using coherence::util::MapEvent;
using coherence::util::MapListener;

/**
* ContactChangeListener listens for changes to Contacts.
*
* @author ch  2009.04.07
*/
class ContactChangeListener
    : public class_spec<ContactChangeListener,
      extends<Object>, implements <MapListener> >
    {
    // add support for auto-generated static create methods
    friend class factory<ContactChangeListener>;


    // ----- Constructors ----------------------------------------------------

    protected:
        ContactChangeListener() {}


    // ----- MapListener interface ------------------------------------------

    public:
        /**
        * {@inheritDoc}
        */
        void entryInserted(MapEvent::View vEvent);

        /**
        * {@inheritDoc}
        */
        void entryUpdated(MapEvent::View vEvent);

        /**
        * {@inheritDoc}
        */
        void entryDeleted(MapEvent::View vEvent);
    };

COH_CLOSE_NAMESPACE2

#endif //COH_EXAMPLES_CONTACTCHANGELISTENER_HPP
