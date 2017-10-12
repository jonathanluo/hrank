/*
 * #%L
 * PhoneNumber.cpp
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

#include "PhoneNumber.hpp"

// ----- constructors -------------------------------------------------------

PhoneNumber::PhoneNumber(const short nAccessCode, const short nCountryCode,
      const short nAreaCode, const long nLocalNumber)
   : m_nAccessCode(nAccessCode), m_nCountryCode(nCountryCode),
     m_nAreaCode(nAreaCode), m_nLocalNumber(nLocalNumber)
       {
       }

PhoneNumber::PhoneNumber(const PhoneNumber& that)
   : m_nAccessCode(that.m_nAccessCode), m_nCountryCode(that.m_nCountryCode),
     m_nAreaCode(that.m_nAreaCode), m_nLocalNumber(that.m_nLocalNumber)
       {
       }

// ----- free functions -----------------------------------------------------

std::ostream& operator<<(std::ostream& out, const PhoneNumber& phone)
   {
   out << "+" << phone.getAccessCode()
   << " " << phone.getCountryCode()
   << " " << phone.getAreaCode()
   << " " << phone.getLocalNumber();
   return out;
   }

bool operator==(const PhoneNumber& phoneA, const PhoneNumber& phoneB)
	   {
	   return phoneA.getAccessCode() == phoneB.getAccessCode()  &&
	   phoneA.getCountryCode()       == phoneB.getCountryCode() &&
	   phoneA.getAreaCode()          == phoneB.getAreaCode()    &&
	   phoneA.getLocalNumber()       == phoneB.getLocalNumber();
	   }

size_t hash_value(const PhoneNumber& phone)
   {
   // Since this is not a key use identity hash code.
   return (size_t) &phone;
   }
