
#ifndef COH_EXAMPLES_ADDRESS_HPP
#define COH_EXAMPLES_ADDRESS_HPP

#include <iostream>
#include <string>

#include "Pof.hpp"

/**
* Address is a place where a contact is located.
* <p/>
* The type implements PortableObject for efficient cross-platform
* serialization.
*
* @author ch  2009.02.17
*/
class COH_POF_EXPORT Address
   {
   public:
      /**
       * Default constructor, required for Managed<> types.
       */
      Address() {}

      /**
      * Construct an Address.
      *
      * @param sStreet1  first line of the street address
      * @param sStreet2  second line of the street address
      * @param sCity     city name
      * @param sState    State name
      * @param sZip      Zip (postal) code
      * @param sCountry  country name
      */
      Address(const std::string& sStreet1, const std::string& sStreet2,
              const std::string& sCity, const std::string& sState,
              const std::string& sZip, const std::string& sCountry);

      /**
      * Copy constructor, required for Managed<> types.
      */
      Address(const Address& that);

      // ----- accessors -------------------------------------------------------

   public:
      /**
      * Return the first line of the street address.
      *
      * @return the first line of the street address
      */
      std::string getStreet1() const
      {
      return m_sStreet1;
      }

      /**
      * Set the first line of the street address.
      *
      * @param sStreet1 the first line of the street address
      */
      void setStreet1(const std::string& sStreet1)
         {
         m_sStreet1 = sStreet1;
         }

      /**
      * Return the second line of the street address.
      *
      * @return the second line of the street address
      */
      std::string getStreet2() const
      {
      return m_sStreet2;
      }

      /**
      * Set the second line of the street address.
      *
      * @param sStreet2 the second line of the street address
      */
      void setStreet2(const std::string& sStreet2)
         {
         m_sStreet2 = sStreet2;
         }

      /**
      * Return the city name.
      *
      * @return the city name
      */
      std::string getCity() const
      {
      return m_sCity;
      }

      /**
      * Set the city name.
      *
      * @param sCity the city name
      */
      void setCity(const std::string& sCity)
         {
         m_sCity = sCity;
         }

      /**
      * Return the state or territory name.
      *
      * @return  the state or territory name
      */
      std::string getState() const
      {
      return m_sState;
      }

      /**
      * Set the State or Province name.
      *
      * @param  sState the State or Province name
      */
      void setState(const std::string& sState)
         {
         m_sState = sState;
         }

      /**
      * Return the Zip code.
      *
      * @return  the Zip code
      */
      std::string getZipCode() const
      {
      return m_sZip;
      }

      /**
      * Set the Zip code.
      *
      * @param  sZip the Zip code
      */
      void setZipCode(const std::string& sZip)
         {
         m_sZip = sZip;
         }

      /**
      * Return the Country name.
      *
      * @return the Country name
      */
      std::string getCountry() const
      {
      return m_sCountry;
      }

      /**
      * Set the country name.
      *
      * @param  sCountry the country name
      */
      void setCountry(const std::string& sCountry)
         {
         m_sCountry = sCountry;
         }

   // ----- data members ----------------------------------------------------

   private:
      /**
      * First line of street address.
      */
      std::string m_sStreet1;

      /**
      * Second line of street address.
      */
      std::string m_sStreet2;

      /**
      * City.
      */
      std::string m_sCity;

      /**
      * State or Province.
      */
      std::string m_sState;

      /**
      * Zip or other postal code.
      */
      std::string m_sZip;

      /**
      * Country.
      */
      std::string m_sCountry;
   };

   // ----- free functions --------------------------------------------------

/**
* Output this Address to the stream
*
* @param out  the stream to output to
*
* @return the stream
*/
COH_POF_EXPORT std::ostream& operator<<(std::ostream& out, const Address& address);

/**
* Perform an equality test on two Address objects
*
* @param addressA  the first Address
* @param addressB  the second Address
*
* @return true if the objects are equal
*/
COH_POF_EXPORT bool operator==(const Address& addressA, const Address& addressB);

/**
* Returns an identity hash for the Address.
*
* @param address  the address
*
* @return the hash code of the address
*/
COH_POF_EXPORT size_t hash_value(const Address& address);

#endif // COH_EXAMPLES_ADDRESS_HPP
