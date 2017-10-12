
#ifndef COH_EXAMPLES_EXAMPLEINVOCABLE_HPP
#define COH_EXAMPLES_EXAMPLEINVOCABLE_HPP

#include "coherence/lang.ns"

#include "coherence/io/pof/PofReader.hpp"
#include "coherence/io/pof/PofWriter.hpp"
#include "coherence/io/pof/PortableObject.hpp"
#include "coherence/net/Invocable.hpp"
#include "coherence/net/InvocationService.hpp"

#include "Pof.hpp"

COH_OPEN_NAMESPACE2(coherence,examples)

using coherence::io::pof::PofReader;
using coherence::io::pof::PofWriter;
using coherence::io::pof::PortableObject;
using coherence::net::Invocable;
using coherence::net::InvocationService;


/**
* Invocable implementation that increments and returns a given integer.
*/
class COH_POF_EXPORT ExampleInvocable
    : public class_spec<ExampleInvocable,
        extends<Object>,
        implements<Invocable, PortableObject> >
    {
    friend class factory<ExampleInvocable>;

    // ----- constructors ---------------------------------------------------

    protected:
        /**
        * Create a new ExampleInvocable instance.
        */
        ExampleInvocable();


    // ----- Invocable interface --------------------------------------------

    public:
        /**
        * {@inheritDoc}
        */
        virtual void init(InvocationService::Handle hService);

        /**
        * {@inheritDoc}
        */
        virtual Object::Holder getResult() const;

        /**
        * {@inheritDoc}
        */
        virtual void run();


    // ----- PortableObject interface ---------------------------------------

    public:
        /**
        * {@inheritDoc}
        */
        virtual void readExternal(PofReader::Handle hIn);

        /**
        * {@inheritDoc}
        */
        virtual void writeExternal(PofWriter::Handle hOut) const;


    // ----- data members ---------------------------------------------------

    protected:
        /**
         * The integer value to increment.
         */
        int32_t m_nValue;
    };

    COH_CLOSE_NAMESPACE2

#endif // COH_EXAMPLES_EXAMPLEINVOCABLE_HPP
