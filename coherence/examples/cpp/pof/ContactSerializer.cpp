/*
 * #%L
 * ContactSerializer.cpp
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
* This file defines serializers for the Contact class and registers its
* managed form (Managed<Contact>) with Coherence.
*
* @author ch  2009.02.17
*/

#include <time.h>

#include "coherence/lang/Managed.hpp"
#include "coherence/lang/String.hpp"
#include "coherence/io/pof/PofWriter.hpp"
#include "coherence/io/pof/PofReader.hpp"
#include "coherence/io/pof/SystemPofContext.hpp"
#include "coherence/stl/boxing_map.hpp"
#include "coherence/util/HashMap.hpp"

using namespace coherence::lang;

using coherence::io::pof::PofReader;
using coherence::io::pof::PofWriter;
using coherence::io::pof::RawDate;
using coherence::stl::boxing_map;
using coherence::util::HashMap;

#include "Address.hpp"
#include "Contact.hpp"
#include "PhoneNumber.hpp"
#include "PofConfig.hpp"

/**
* The POF index for the FirstName property
*/
#define FIRSTNAME 0

/**
* The POF index for the LastName property
*/
#define LASTNAME 1

/**
* The POF index for the HomeAddress property
*/
#define HOME_ADDRESS 2

/**
* The POF index for the WorkAddress property
*/
#define WORK_ADDRESS 3

/**
* The POF index for the PhoneNumbers property
*/
#define PHONE_NUMBERS 4

/**
* The POF index for the BirthDate property
*/
#define BIRTH_DATE 5

/**
* The POF index for the Age property
*/
#define AGE 6

/**
* Typedef a boxing map to box the stl map into a managed
* Coherence map.
*/
typedef boxing_map<String, Managed<PhoneNumber> > managed_phone_map;

/**
* Register Contact as a managed class so that it can be serialized.
*/
COH_REGISTER_MANAGED_CLASS(POF_TYPE_CONTACT, Contact);

/**
* Serialize a contact into Portable object format.
*
* @param hOut   the serializer to write the object to
* @param contact  the contact to serialize
*/
template<> void serialize<Contact>(PofWriter::Handle hOut, const Contact& contact)
   {
   hOut->writeString(FIRSTNAME, contact.getFirstName());
   hOut->writeString(LASTNAME, contact.getLastName());
   // Wrap the user types into a managed type
   hOut->writeObject(HOME_ADDRESS, Managed<Address>::create(contact.getHomeAddress()));
   hOut->writeObject(WORK_ADDRESS, Managed<Address>::create(contact.getWorkAddress()));

   // First we must create a managed map type to serialize the phone_map
   managed_phone_map phoneMapManaged(HashMap::create());
   // Copy the data from the the Contact's phone map into the managed map.
   coherence::stl::copy_map(contact.getTelephoneNumbers(), phoneMapManaged);
   // Write the managed map to the stream.
   hOut->writeMap(PHONE_NUMBERS, phoneMapManaged.delegate());
   hOut->writeRawDate(BIRTH_DATE, RawDate::create(contact.getBirthDate()));
   hOut->writeInt16(AGE, contact.getAge());
   }

/**
* Deserialize a contact from Portable object format.
*
* @param hIn  the serializer to write the object to
* @return     a new Contact instance
*/
template<> Contact deserialize<Contact>(PofReader::Handle hIn)
   {
   String::View vsFirstName         = hIn->readString(FIRSTNAME);
   String::View vsLastName          = hIn->readString(LASTNAME);
   Managed<Address>::View vaddrHome = cast<Managed<Address>::View>
   (hIn->readObject(HOME_ADDRESS));
   Managed<Address>::View vaddrWork = cast<Managed<Address>::View>
   (hIn->readObject(WORK_ADDRESS));
   managed_phone_map phoneMapManaged(hIn->readMap(PHONE_NUMBERS));

   // Place holder for the stl map
   Contact::phone_map phoneMapStl;
   // Copy the managed map into a stl map
   coherence::stl::copy_map(phoneMapManaged, phoneMapStl);

   struct tm dtBirthday = *hIn->readRawDate(BIRTH_DATE);

   // we don't read back age is this will be calculated via constructor
   return Contact(vsFirstName, vsLastName,
       *vaddrHome, *vaddrWork, phoneMapStl, dtBirthday);
   }
