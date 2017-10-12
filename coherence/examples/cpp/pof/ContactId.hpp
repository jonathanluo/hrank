
#ifndef COH_EXAMPLES_CONTACT_ID_HPP
#define COH_EXAMPLES_CONTACT_ID_HPP

#include <iostream>
#include <string>

#include "coherence/lang/compatibility.hpp"

#include "Pof.hpp"

using coherence::lang::size32_t;

/**
* ContactId represents a key to the contact for whom information is stored in
* the cache.
* <p/>
* The type implements PortableObject for efficient cross-platform
* serialization..
*
* @author ch  2009.02.18
*/
class COH_POF_EXPORT ContactId
   {
   // ----- constructors ---------------------------------------------------

   protected:
      /**
      * Default constructor, required for Managed<> types.
      */
      ContactId() {}

   public:
      /**
      * Construct ContactId
      *
      * @param sFirstName    the first name
      * @param sLastName     the last name
      */
      ContactId(const std::string& sFirstName, const std::string& sLastName);

      /**
      * Copy constructor, required for Managed<> types.
      */
      ContactId(const ContactId& that);

   // ----- accessors -------------------------------------------------------

   public:
      /**
      * Return the first name.
      *
      * @return the first name
      */
      std::string getFirstName() const
      {
      return m_sFirstName;
      }

      /**
      * Set the first name.
      *
      * @param sFirstName  the first name
      */
      void setFirstName(const std::string& sFirstName)
         {
         m_sFirstName = sFirstName;
         }

      /**
      * Return the last name.
      *
      * @return the last name
      */
      std::string getLastName() const
      {
      return m_sLastName;
      }

      /**
      * Set the last name.
      *
      * @param sLastName  the last name
      */
      void setLastName(const std::string& sLastName)
         {
         m_sLastName = sLastName;
         }

      // ----- data members ----------------------------------------------------

   private:
      /**
      * The first name of ContactId
      */
      std::string m_sFirstName;
      /**
       * The last name of ContactId
       */
      std::string m_sLastName;
   };

/*
* Output this ContactId to the stream
*
* @param out       the stream to output to
* @param contactId the contactId to output
*
* @return the stream
*/
COH_POF_EXPORT std::ostream& operator<<(std::ostream& out, const ContactId& contactId);

/**
* Perform an equality test on two Contact objects
*
* @param contactIdA  the first ContactId
* @param contactIdA  the second ContactId
*
* @return true if the objects are equal
*/
COH_POF_EXPORT bool operator==(const ContactId& contactIdA, const ContactId& contactIdB);

/**
* Returns the value hash code for a ContactId object.
*
* @param contactId  the ContactId
*
* @return the hash code of the ContactId
*/
COH_POF_EXPORT size32_t hash_value(const ContactId& contactId);

#endif // COH_EXAMPLES_CONTACT_ID_HPP
