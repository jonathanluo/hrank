/*
 * #%L
 * Address.cpp
 * ---
 * Copyright (C) 2000 - 2017 Oracle and/or its affiliates. All rights reserved.
 * ---
 * Oracle is a registered trademarks of Oracle Corporation and/or its
 * affiliates.
 * 
 * This software is the confidential and proprietary information of Oracle
 * Corporation. You shall not disclose such confidential and proprietary
 * information and shall use it only in accordance with the terms of the
 * license agreement you entered into with Oracle.
 * 
 * This notice may not be removed or altered.
 * #L%
 */
#include "Address.hpp"

// ----- constructors -------------------------------------------------------

Address::Address(const std::string& sStreet1, const std::string& sStreet2,
      const std::string& sCity, const std::string& sState, const std::string& sZip,
      const std::string& sCountry)
   : m_sStreet1(sStreet1), m_sStreet2(sStreet2), m_sCity(sCity),
     m_sState(sState), m_sZip(sZip), m_sCountry(sCountry)
       {
       }

Address::Address(const Address& that)
   : m_sStreet1(that.m_sStreet1), m_sStreet2(that.m_sStreet2),
     m_sCity(that.m_sCity), m_sState(that.m_sState), m_sZip(that.m_sZip),
     m_sCountry(that.m_sCountry)
       {
       }


// ----- free functions -----------------------------------------------------

std::ostream& operator<<(std::ostream& out, const Address& address)
   {
   out << address.getStreet1() << std::endl
       << address.getStreet2() << std::endl
       << address.getCity()    << ", " << address.getState() << " "
       << address.getZipCode() << std::endl
       << address.getCountry();
   return out;
   }

bool operator==(const Address& addressA, const Address& addressB)
   {
   return addressA.getStreet1() == addressB.getStreet1() &&
      addressA.getStreet2()     == addressB.getStreet2() &&
      addressA.getCity()        == addressB.getCity()    &&
      addressA.getState()		  == addressB.getState()   &&
      addressA.getZipCode()     == addressB.getZipCode() &&
      addressA.getCountry()     == addressB.getCountry();
      }

size_t hash_value(const Address& address)
   {
   // Since this is not a key use identity hash code.
   return (size_t) &address;
   }
