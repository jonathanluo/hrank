
#ifndef COH_EXAMPLES_OFFICEUPDATER_HPP
#define COH_EXAMPLES_OFFICEUPDATER_HPP

#include <iostream>

#include "coherence/lang.ns"
#include "coherence/io/pof/PortableObject.hpp"
#include "coherence/io/pof/PofWriter.hpp"
#include "coherence/io/pof/PofReader.hpp"
#include "coherence/io/pof/SystemPofContext.hpp"
#include "coherence/util/InvocableMap.hpp"
#include "coherence/util/processor/UpdaterProcessor.hpp"

#include "contacts/Contacts.hpp"
#include "Pof.hpp"


COH_OPEN_NAMESPACE2(coherence,examples)

using coherence::io::pof::PortableObject;
using coherence::io::pof::PofReader;
using coherence::io::pof::PofWriter;
using coherence::util::InvocableMap;
using coherence::util::processor::UpdaterProcessor;


/**
 * OfficeUpdater updates a contact's office address.
 *
 * @author ch  2009.04.07
 */
class COH_POF_EXPORT OfficeUpdater
    : public class_spec<OfficeUpdater,
      extends<UpdaterProcessor>,
      implements<PortableObject> >
    {
    // add support for auto-generated static create methods
    friend class factory<OfficeUpdater>;


    // ----- Constructors ----------------------------------------------------

    protected:
        /**
        * Default constructor (necessary for PortableObject implementation).
        */
        OfficeUpdater() : m_addrWork(self())
            {
            }

        /**
        * Construct an OfficeUpdater with a new work Address.
        *
        * @param addrWork  the new work address.
        */
        OfficeUpdater(Managed<Address>::View addrWork)
            : m_addrWork(self(), addrWork)
            {
            }


    // ----- InvocableMap.EntryProcessor interface ---------------------------

    public:
        /**
        * The entry for the EntryProcessor.
        * <p/>
        * Important to note is that this will not be invoked unless a local cache
        * scheme is used. Rather the Java implementation will of this type will
        * be used.
        *
        * @param  hEntry the entry that will be processed
        *
        * @return  an object containing the result of the processor.
        */
        virtual Object::Holder process(InvocableMap::Entry::Handle hEntry) const;


    // ----- PortableObject interface ----------------------------------------

    public:
        /**
        * Deserialize the Entry processor.
        *
        * @param hReader  the reader containing the serialized instance
        */
        virtual void readExternal(PofReader::Handle hReader);

        /**
        * Serialize the Entry processor.
        *
        * @param hWriter  the writer to serialize this instance to
        */
        virtual void writeExternal(PofWriter::Handle hWriter) const;


    // ----- data members ----------------------------------------------------

    private:
        /**
        * New work address.
        */
        FinalView<Managed<Address> > m_addrWork;

        /**
        * The POF index for the Address property
        */
        static const int POF_WORK_ADDRESS = 0;
    };

COH_CLOSE_NAMESPACE2

#endif //COH_EXAMPLES_OFFICEUPDATER_HPP
