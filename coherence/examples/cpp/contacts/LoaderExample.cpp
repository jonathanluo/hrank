/*
 * #%L
 * LoaderExample.cpp
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

#include <fstream>

#include "coherence/util/HashMap.hpp"

#include "Contacts.hpp"
#include "LoaderExample.hpp"

#define BATCH_SIZE 1000

COH_OPEN_NAMESPACE2(coherence,examples)

using coherence::util::HashMap;

void LoaderExample::load(std::istream& in, NamedCache::Handle hCache) const
    {
    HashMap::Handle	     hMapBatch = HashMap::create(BATCH_SIZE);
    int                    cContacts = 0;
    Managed<Contact>::View vContact;

    std::cout << "------LoaderExample begins------" << std::endl;

    while ((vContact = readContact(in)) != NULL)
        {
        // In order for the C++ objects to be stored in the HashMap they first
        // need to be transformed into managed objects.
        ContactId id(vContact->getFirstName(), vContact->getLastName());
        Managed<ContactId>::View vContactId = Managed<ContactId>::create(id);

        hMapBatch->put(vContactId, vContact);
        ++cContacts;

        // When reached the BATCH_SIZE threshold transfer the records to
        // the cache.
        if (cContacts % BATCH_SIZE == 0)
            {
            // minimize the network round trips by using putAll()
            hCache->putAll(hMapBatch);
            hMapBatch->clear();
            std::cout << ".";
            std::cout.flush();
            }
        }

    // insert the final batch
    if (!hMapBatch->isEmpty())
        {
        hCache->putAll(hMapBatch);
        }
    std::cout << "Added " << cContacts << " entries to cache" << std::endl;
    std::cout << "------LoaderExample completed------" << std::endl;
    }

Managed<Contact>::View LoaderExample::readContact(std::istream& in) const
{
    char		   ch;
    std::string sFirstName;

    if (!std::getline(in, sFirstName, ',').eof() && !in.fail())
        {
        std::string sLastName;
        std::string sStreet1, sStreet2, sCity, sState, sZip, sCountry;
        std::string sWorkStreet1, sWorkStreet2, sWorkCity, sWorkState, sWorkZip,
        sWorkCountry;
        int		   nYear, nMonth, nDay;

        std::getline(in, sLastName, ',');

        in >> nYear >> ch >> nMonth >> ch >> nDay >> ch;
        struct tm tmDob = {0, 0, 0, nDay, nMonth-1, nYear-1900, 0, 0, 0};

        // Read the home address record
        std::getline(in, sStreet1, ',');
        std::getline(in, sStreet2, ',');
        std::getline(in, sCity, ',');
        std::getline(in, sState, ',');
        std::getline(in, sZip, ',');
        std::getline(in, sCountry, ',');
        Address addrHome(sStreet1, sStreet2, sCity, sState, sZip, sCountry);

        // Read the work address record
        std::getline(in, sStreet1, ',');
        std::getline(in, sStreet2, ',');
        std::getline(in, sCity, ',');
        std::getline(in, sState, ',');
        std::getline(in, sZip, ',');
        std::getline(in, sCountry, ',');
        Address addrWork(sStreet1, sStreet2, sCity, sState, sZip, sCountry);

        Contact::phone_map mapPhone;

        while (!(in.peek() == '\n' || in.peek() == '\r' || in.eof()))
            {
            std::string sType;
            short       nAccessCode, nCountryCode, nAreaCode;
            long        lLocalNumber = 0;

            std::getline(in, sType, ',');

            in >> nAccessCode >> ch >> nCountryCode >> ch >> nAreaCode >> ch
            >> lLocalNumber >> ch;
            mapPhone[sType] = PhoneNumber(nAccessCode, nCountryCode, nAreaCode,
                    lLocalNumber);
            }

        //ignore the trailing newline
        in.ignore();

        return Managed<Contact>::create(Contact(sFirstName, sLastName, addrHome,
                addrWork, mapPhone, tmDob));
        }
    return NULL;
    }

COH_CLOSE_NAMESPACE2
