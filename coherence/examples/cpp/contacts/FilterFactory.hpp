
#ifndef COH_EXAMPLES_FILTERFACTORY_HPP
#define COH_EXAMPLES_FILTERFACTORY_HPP


#include "coherence/lang.ns"

#include "coherence/net/InvocationService.hpp"

#include "coherence/util/Map.hpp"
#include "coherence/util/Filter.hpp"
#include "coherence/util/ValueExtractor.hpp"


COH_OPEN_NAMESPACE2(coherence,examples)

using coherence::net::InvocationService;
using coherence::util::Map;
using coherence::util::Filter;
using coherence::util::ValueExtractor;


/**
* FilterFactory is a utility class that provides a set of factory methods
* that is used for building instances of Filter or ValueExtractor. 
* We use an InvocationService to build the Filters and ValueExtractors on 
* a java proxy server. This class is compatible with the QueryHelper in the
* java version of Coherence 3.6 and provides an example of using the
* InvocationService.
* 
* The FilterFactory API accepts a string that specifies the creation of rich
* Filters in a format that should be familiar to anyone that understands
* SQL WHERE clauses.  For example the Sring "street = 'Main' and state = 'TX'"
* would create a tree of Filters that is the same as the following code:
*
*  new AndFilter(
*        new EqualsFilter("getStreet","Main"),
*        new EqualsFilter("getState","TX"));
*
* @see QueryHelper
* <p/>
* The factory methods catch a number of Exceptions from the implementation
* stages and subsequently may throw an unchecked FilterBuildingException.
*
* @author djl  2010.02.18
*/
class FilterFactory
    : public class_spec<FilterFactory,
             extends<Object> >
    {
    friend class factory<FilterFactory>;

    // ----- constructors ---------------------------------------------------

    public:
        /**
        * Construct a FilterFactory
        */
        FilterFactory();

        /**
		* Construct a FilterFactory that builds Filters using the supplied
		* InvocationService name.
        *
        * @param vsName  the name of the method to invoke via reflection
        */
        FilterFactory(String::View vsName);


    // ----- FilterBuilder API ----------------------------------------------

    public:
        /**
        * Make a new Filter from the given String and optional environments
        * for binding vars.
        *
        * @param vs           a String in the Coherence Query Language representing
        *                     a Filter
        * @param vaBindings   the array of Objects to use for Bind vars,
        *                     pass a NULL for this parameter if only a
        *                     Map of bindings is desired
        * @param vmapBindings the Map of Objects to use for Bind vars
        *
        * @return the constructed Filter
        *
        */
        virtual Filter::View createFilter(String::View vs,
                  ObjectArray::View vaBindings = NULL,
                  Map::View vmapBindings = NULL);

        /**
        * Make a new ValueExtracter from the given String.
        *
        * @param vs  a String in the Coherence Query Language representing
        *           a ValueExtractor
        *
        * @return the constructed ValueExtractor
        *
        */
        virtual ValueExtractor::View createExtractor(String::View vs);


    // -----Helper Methods --------------------------------------------------

    private:

        /**
        * Make a new ValueExtracter from the given String.
        *
        * @param vs a String in the Coherence Query Language representing
        *           a ValueExtractor
        *
        * @return the constructed ValueExtractor
        */
        virtual ValueExtractor::View fetchExtractor(String::View vs);

        /**
        * Make a new Filter from the given String using InvocationService.
        *
        * @param vs          a String in the Coherence Query Language representing
        *                    a Filter
        * @param vaBindings  the array of Objects to use for Bind vars
        *
        * @return the constructed Filter
        */
        virtual Filter::View fetchFilter(String::View vs,
                  ObjectArray::View vaBindings, Map::View vmapBindings);

 
    // ----- data members ---------------------------------------------------

    private:
        /**
        * The name of the method to invoke.
        */
        MemberHandle<InvocationService> m_hService;
    };

COH_CLOSE_NAMESPACE2

#endif //COH_EXAMPLES_FILTERFACTORY_HPP
