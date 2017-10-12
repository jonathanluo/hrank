/*
 * #%L
 * AddressSerializer.cpp
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

/**
* This file defines serializers for the Address class and registers its
* managed form (Managed<Address>) with Coherence.
*
* @author ch  2009.02.17
*/
#include "coherence/lang/String.hpp"
#include "coherence/io/pof/PofWriter.hpp"
#include "coherence/io/pof/PofReader.hpp"
#include "coherence/io/pof/SystemPofContext.hpp"

using coherence::lang::String;
using coherence::io::pof::PofReader;
using coherence::io::pof::PofWriter;

#include "Address.hpp"
#include "PofConfig.hpp"

/**
* The POF index for the Street1 property
*/
#define STREET_1 0

/**
* The POF index for the Street2 property
*/
#define STREET_2 1

/**
* The POF index for the City property
*/
#define CITY 2

/**
* The POF index for the State property
*/
#define STATE 3

/**
* The POF index for the Zip property
*/
#define ZIP 4

/**
* The POF index for the Country property
*/
#define COUNTRY 5

/**
 * Register Address as a managed class so that it can be serialized.
 */
COH_REGISTER_MANAGED_CLASS(POF_TYPE_ADDRESS, Address);

/**
* Serialize an Address into Portable object format.
*
* @param hOut     the serializer to write the object to
* @param address  the Address to serialize
*/
template<> void serialize<Address>(PofWriter::Handle hOut, const Address& address)
   {
   hOut->writeString(STREET_1, address.getStreet1());
   hOut->writeString(STREET_2, address.getStreet2());
   hOut->writeString(CITY, address.getCity());
   hOut->writeString(STATE, address.getState());
   hOut->writeString(ZIP, address.getZipCode());
   hOut->writeString(COUNTRY, address.getCountry());
   }

/**
* Deserialize an Address from Portable object format.
*
* @param hIn  the serializer to write the object to
* @return     a new Address instance
*/
template<> Address deserialize<Address>(PofReader::Handle hIn)
   {
   String::View vsStreet1 = hIn->readString(STREET_1);
   String::View vsStreet2 = hIn->readString(STREET_2);
   String::View vsCity    = hIn->readString(CITY);
   String::View vsState   = hIn->readString(STATE);
   String::View vsZip     = hIn->readString(ZIP);
   String::View vsCountry = hIn->readString(COUNTRY);

   return Address(vsStreet1, vsStreet2, vsCity, vsState, vsZip, vsCountry);
   }
