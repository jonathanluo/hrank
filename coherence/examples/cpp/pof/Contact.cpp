/*
 * #%L
 * Contact.cpp
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

#include "Contact.hpp"
#include "Address.hpp"

// ----- constructors -------------------------------------------------------

Contact::Contact(const std::string& sFirstName, const std::string& sLastName,
      const Address& addrHome, const Address& addrWork,
      const phone_map& mapTelNumber, const struct tm dtBirth)
   : m_sFirstName(sFirstName), m_sLastName(sLastName), m_addrHome(addrHome),
     m_addrWork(addrWork), m_dtBirth(dtBirth), m_mapTelNumber(mapTelNumber),
     m_nAge(calculateAge(dtBirth))
       {
       }

Contact::Contact(const Contact& that)
   : m_sFirstName(that.m_sFirstName), m_sLastName(that.m_sLastName),
     m_addrHome(that.m_addrHome), m_addrWork(that.m_addrWork),
     m_dtBirth(that.m_dtBirth), m_mapTelNumber(that.m_mapTelNumber),
     m_nAge(that.m_nAge)
       {
       }

// ---- functions -----------------------------------------------------------

int Contact::calculateAge(const struct tm dtBirth)
   {
   time_t tnow;
   time(&tnow);
   struct tm* tmNow = localtime(&tnow);
   return tmNow->tm_year - dtBirth.tm_year;
   }

// ----- free functions -----------------------------------------------------

std::ostream& operator<<(std::ostream& out, const Contact& contact)
   {
   out << contact.getFirstName() << " " << contact.getLastName()
       << "\nAddresses" << "\nHome: " << contact.getHomeAddress()
       << "\nWork: "     << contact.getWorkAddress()
       << "\nPhone Numbers";

  Contact::phone_map mapPhones = contact.getTelephoneNumbers();

  for (Contact::phone_map::iterator iter = mapPhones.begin(),
       iEnd = mapPhones.end();
       iter != iEnd; ++iter )
      {
      out << std::endl << iter->first << ": " << iter->second;
      }

    out << "\nBirth Date: " << contact.getBirthDate().tm_year + 1900 << "-"
       << contact.getBirthDate().tm_mon + 1 << "-"
       << contact.getBirthDate().tm_mday;

    out << " (" << contact.getAge() << " years old)";

   return out;
   }

bool operator==(const Contact& contactA, const Contact& contactB)
	   {
	   return contactA.getFirstName()  == contactB.getFirstName()         &&
	   contactA.getLastName()          == contactB.getLastName()          &&
	   contactA.getHomeAddress()       == contactB.getHomeAddress()       &&
	   contactA.getWorkAddress()       == contactB.getWorkAddress()       &&
	   contactA.getTelephoneNumbers()  == contactB.getTelephoneNumbers()  &&
	   contactA.getBirthDate().tm_year == contactB.getBirthDate().tm_year &&
	   contactA.getBirthDate().tm_mon  == contactB.getBirthDate().tm_mon  &&
	   contactA.getBirthDate().tm_mday == contactB.getBirthDate().tm_mday &&
	   contactA.getAge()               == contactB.getAge();
	   }

size_t hash_value(const Contact& contact)
   {
   // Since this is not a key use identity hash code.
   return (size_t) &contact;
   }

