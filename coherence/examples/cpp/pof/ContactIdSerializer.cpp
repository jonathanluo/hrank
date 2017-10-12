/*
 * #%L
 * ContactIdSerializer.cpp
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
* This file defines serializers for the ContactId class and registers its
* managed form (Managed<ContactId>) with Coherence.
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

#include "ContactId.hpp"
#include "PofConfig.hpp"

/**
* The POF index for the FirstName property
*/
#define FIRSTNAME  0

/**
* The POF index for the LastName property
*/
#define LASTNAME  1

/**
* Register ContactId as a managed class so that it can be serialized.
*/
COH_REGISTER_MANAGED_CLASS(POF_TYPE_CONTACT_ID, ContactId);

/**
* Serialize a ContactId into Portable object format.
*
* @param hOut      the serializer to write the object to
* @param contactId the contactId to serialize
*/
template<> void serialize<ContactId>(PofWriter::Handle hOut,
   const ContactId& contactId)
   {
   hOut->writeString(FIRSTNAME, contactId.getFirstName());
   hOut->writeString(LASTNAME, contactId.getLastName());
   }

/**
* Deserialize a ContactId from Portable object format.
*
* @param hIn  the serializer to write the object to
* @return     a new ContactId instance
*/
template<> ContactId deserialize<ContactId>(PofReader::Handle hIn)
   {
   String::View vsFirstName = hIn->readString(FIRSTNAME);
   String::View vsLastName  = hIn->readString(LASTNAME);

   return ContactId(vsFirstName, vsLastName);
   }
