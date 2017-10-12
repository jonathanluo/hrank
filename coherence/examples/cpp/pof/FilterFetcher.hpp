
#ifndef COH_EXAMPLES_FILTERFETCHER_HPP
#define COH_EXAMPLES_FILTERFETCHER_HPP

#include "coherence/lang.ns"

#include "coherence/io/pof/PofReader.hpp"
#include "coherence/io/pof/PofWriter.hpp"
#include "coherence/io/pof/PortableObject.hpp"
#include "coherence/net/AbstractInvocable.hpp"
#include "coherence/util/Map.hpp"

#include "Pof.hpp"

COH_OPEN_NAMESPACE2(coherence,examples)

using coherence::io::pof::PortableObject;
using coherence::io::pof::PofReader;
using coherence::io::pof::PofWriter;
using coherence::net::AbstractInvocable;
using coherence::util::Map;


/**
* FilterFetcher is a Class that supports getting a Filters or ValueExtractors
* by using an InvocationService.  See FilterFactory.
*
* @author djl  2010.02.15
*/
class COH_POF_EXPORT FilterFetcher
    : public class_spec<FilterFetcher,
             extends<AbstractInvocable>,
             implements<PortableObject> >
    {
    friend class factory<FilterFetcher>;

    // ----- constructors ---------------------------------------------------

    protected:
        /**
        * Construct an empty FilterFetcher
        * (necessary for the PortableObject interface).
        */
        FilterFetcher();

        /**
        * Construct a ReflectionExtractor based on a method name, optional
        * parameters and the entry extraction target.
        *
        * @param vsQuery     the name of the method to invoke via reflection
        * @param fExtractor  flag to control whether to fetch ValueExtractor
        *                    vs. Filter
        * @param vaEnv       the array of bindings to be used in the method;
        *                    may be NULL
        * @param vbindings   the Map of bindings to be used in the method;
        *                    may be NULL
        */
        FilterFetcher(String::View vsQuery, bool fExtractor = false,
                      ObjectArray::View vaEnv = NULL,
                      Map::View vbindings = NULL);


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

    private:
        /**
        * The flag that controls whether to fetch a ValueExtractor
        * vs. a Filter.
        */
        bool m_fExtractor;

        /**
        * The name of the method to invoke.
        */
        MemberView<String> m_vsQuery;

        /**
        * The parameter array.
        */
        MemberView<ObjectArray> m_vaEnv;

        /**
        * The parameter array.
        */
        MemberView<Map> m_vbindings;
    };

COH_CLOSE_NAMESPACE2

#endif // COH_EXAMPLES_FILTERFETCHER
