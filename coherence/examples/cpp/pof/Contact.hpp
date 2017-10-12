
#ifndef COH_EXAMPLES_CONTACT_HPP
#define COH_EXAMPLES_CONTACT_HPP

#include <iostream>
#include <map>

#include <time.h>

#include "Pof.hpp"
#include "Address.hpp"
#include "PhoneNumber.hpp"

/**
* Contact represents information needed to contact a person.
* <p/>
* The type implements PortableObject for efficient cross-platform
* serialization.
*
* @author ch  2009.04.14
*/
class COH_POF_EXPORT Contact
   {
   // ----- typedefs ------------------------------------------------------
   
   public:
      typedef std::map<std::string, PhoneNumber> phone_map;


   // ----- constructors ---------------------------------------------------

   public:
      /**
       * Default constructor, required for Managed<> types.
       */
      Contact() {}

      /**
      * Construct Contact
      *
      * @param sFirstName    the first name
      * @param sLastName     the last name
      * @param addrHome      the home address
      * @param addrWork      the work address
      * @param mapTelNumber  map string number type (e.g. "work") to
      *                      TelephoneNumber
      * @param dtBirth       date of birth
      */
      Contact(const std::string& sFirstName, const std::string& sLastName,
            const Address& addrHome, const Address& addrWork,
            const phone_map& mapTelNumber, const struct tm dtBirth);

      /**
      * Copy constructor, required for Managed<> types.
      */
      Contact(const Contact& that);

      // ----- accessors ----------------------------------------------------

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

      /**
      * Return the home address.
      *
      * @return the home address
      */
      Address getHomeAddress() const
      {
      return m_addrHome;
      }

      /**
      * Set the home address.
      *
      * @param addrHome  the home address
      */
      void setHomeAddress(const Address& addrHome)
         {
         m_addrHome = addrHome;
         }

      /**
      * Return the work address.
      *
      * @return the work address
      */
      Address getWorkAddress() const
      {
      return m_addrWork;
      }

      /**
      * Set the work address.
      *
      * @param addrWork  the work address
      */
      void setWorkAddress(const Address& addrWork)
         {
         m_addrWork = addrWork;
         }

      /**
      * Get all telephone numbers.
      *
      * @return a map of telephone numbers
      */
      phone_map getTelephoneNumbers() const
      {
      return m_mapTelNumber;
      }

      /**
      * Set the list of telephone numbers.
      *
      * @param mapTelNumber  a map of telephone numbers
      */
      void setTelephoneNumbers(const phone_map& mapTelNumber)
         {
         m_mapTelNumber = mapTelNumber;
         }

      /**
      * Get the date of birth.
      *
      * @return the date of birth
      */
      struct tm getBirthDate() const
      {
      return m_dtBirth;
      }

      /**
      * Set the date of birth.
      *
      * @param dtBirth  the date of birth
      */
      void setBirthDate(const struct tm dtBirth)
         {
         m_dtBirth = dtBirth;
         }

      /**
      * Get the age.
      *
      * @return the age
      */
      int getAge() const
      {
      return m_nAge;
      }

      /**
      * Set the age.
      *
      * @param nAge  the age
      */
      void setAge(const int nAge)
          {
          m_nAge = nAge;
          }

      // ----- functions ----------------------------------------------------

      /**
      * Calculate the age of a contact given a date of bith
      *
      * @param dtBirth  the date of birth
      *
      * @return the age of the contact
      */
      int calculateAge(const struct tm dtBirth);

   private:

      // ----- data members -------------------------------------------------

      /**
      * First name.
      */
      std::string m_sFirstName;

      /**
      * Last name.
      */
      std::string m_sLastName;

      /**
      * Home address.
      */
      Address m_addrHome;

      /**
      * Work address.
      */
      Address m_addrWork;

      /**
      * Birth Date.
      */
      struct tm m_dtBirth;

      /**
      *  Maps telephone number type (such as "work", "home") to TelephoneNumber.
      */
      phone_map m_mapTelNumber;

      /**
      * Age.
      */
      int m_nAge;
   };

/*
* Output this Contact to the stream
*
* @param out  the stream to output to
* @param contact the contact to output
*
* @return the stream
*/
COH_POF_EXPORT std::ostream& operator<<(std::ostream& out, const Contact& contact);

/**
* Perform an equality test on two Contact objects
*
* @param contactA  the first Contact
* @param contactB  the second Contact
*
* @return true if the objects are equal
*/
COH_POF_EXPORT bool operator==(const Contact& contactA, const Contact& contactB);

/**
* Returns identity has of the Contact.
*
* @param contact  the contact
*
* @return the hash code of the contact
*/
COH_POF_EXPORT size_t hash_value(const Contact& contact);

#endif // COH_EXAMPLES_ADDRESS_HPP
