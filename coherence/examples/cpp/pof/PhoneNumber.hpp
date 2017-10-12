
#ifndef COH_EXAMPLES_PHONE_HPP
#define COH_EXAMPLES_PHONE_HPP

#include <iostream>
#include <string>

#include "Pof.hpp"

/**
* Phone represents a sequence of numers used to call a telephone.
* <p/>
* An example that uses the full sequence of numbers is a call from the United
* States to Beijing, China: 011 86 10 85001234.
* <p/>
* The type implements PortableObject for efficient cross-platform
* serialization..
*
* @author ch  2009.02.17
*/
class COH_POF_EXPORT PhoneNumber
   {
   // ----- constructors ---------------------------------------------------

   public:
      /**
       * Default constructor, required for Managed<> types.
       */
      PhoneNumber() {}

      /**
      * Construct a PhoneNumber.
      *
      * @param nAccessCode   the numbers used to access international or
      *                      non-local calls
      * @param nCountryCode  the numbers used to designate a country
      * @param nAreaCode     the numbers used to indicate a geographical region
      * @param nLocalNumber  the local numbers
      */
      PhoneNumber(const short nAccessCode, const short nCountryCode,
            const short nAreaCode, const long nLocalNumber);

      /**
      * Copy constructor, required for Managed<> types.
      */
      PhoneNumber(const PhoneNumber& that);


      // ----- accessors ------------------------------------------------------

   public:
      /**
      * Return the access code.
      *
      * @return the access code
      */
      short getAccessCode() const
      {
      return m_nAccessCode;
      }

      /**
      * Set the numbers used to access international or non-local calls.
      *
      * @param nAccessCode  the access code numbers
      */
      void setAccessCode(const short nAccessCode)
         {
         m_nAccessCode = nAccessCode;
         }

      /**
      * Return the country code.
      *
      * @return the country code
      */
      short getCountryCode() const
      {
      return m_nCountryCode;
      }

      /**
      * Set the country code.
      *
      * @param nCountryCode  the country code
      */
      void setCountryCode(const short nCountryCode)
         {
         m_nCountryCode = nCountryCode;
         }

      /**
      * Return the area code.
      *
      * @return the area code
      */
      short getAreaCode() const
      {
      return m_nAreaCode;
      }

      /**
      * Set the numbers used indicate a geographic area within a country.
      *
      * @param nAreaCode  the area code
      */
      void setAreaCode(const short nAreaCode)
         {
         m_nAreaCode = nAreaCode;
         }

      /**
      * Return the local or subscriber number.
      *
      * @return the local or subscriber number
      */
      long getLocalNumber() const
      {
      return m_nLocalNumber;
      }

      /**
      * Set the local or subscriber number.
      *
      * @param nLocalNumber  the local or subscriber number
      */
      void setLocalNumber(const long nLocalNumber)
         {
         m_nLocalNumber = nLocalNumber;
         }


   // ----- data members ---------------------------------------------------

   private:
      /**
      * The numbers used to access international or non-local calls.
      */
      short m_nAccessCode;

      /**
      * The numbers used to designate a country in international calls.
      */
      short m_nCountryCode;

      /**
      * The numbers used indicate a geographic area within a country.
      */
      short m_nAreaCode;

      /**
      * The local number.
      */
      long m_nLocalNumber;
   };

// ----- free functions -----------------------------------------------------

/**
* Output this Phone to the stream
*
* @param out  the stream to output to
*
* @return the stream
*/
COH_POF_EXPORT std::ostream& operator<<(std::ostream& out, const PhoneNumber& phone);

/**
* Perform an equality test on two Phone objects
*
* @param phoneNumberA  the first PhoneNumber
* @param phoneNumberB  the second PhoneNumber
*
* @return true if the objects are equal
*/
COH_POF_EXPORT bool operator==(const PhoneNumber& phoneA, const PhoneNumber& phoneB);

/**
* Returns the identity hash for the Phone number
*
* @param phone  the PhoneNumber
*
* @return the hash code of the phone
*/
COH_POF_EXPORT size_t hash_value(const PhoneNumber& phone);

#endif // COH_EXAMPLES_PHONE_HPP
