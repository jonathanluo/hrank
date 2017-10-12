/*
 * #%L
 * PhoneNumberSerializer.cpp
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
 * This file defines a serializer for the PhoneNumber type and registers its
 * managed form (Managed<PhoneNumber>) with Coherence.
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

#include "PhoneNumber.hpp"
#include "PofConfig.hpp"

/**
* The POF index for the AccessCode property
*/
#define ACCESS_CODE 0

/**
* The POF index for the CountryCode property
*/
#define COUNTRY_CODE 1

/**
* The POF index for the AreaCode property
*/
#define AREA_CODE 2

/**
* The POF index for the LocalNumber property
*/
#define LOCAL_NUMBER 3

/**
* Register PhoneNumber as a managed class so that it can be serialized.
*/
COH_REGISTER_MANAGED_CLASS(POF_TYPE_PHONE_NUMBER, PhoneNumber);

/**
* Serialize a phone number into Portable object format.
*
* @param hOut   the serializer to write the object to
* @param phone  the phone number to serialize
*/
template<> void serialize<PhoneNumber>(PofWriter::Handle hOut,
      const PhoneNumber& phone)
   {
   hOut->writeInt16(ACCESS_CODE, phone.getAccessCode());
   hOut->writeInt16(COUNTRY_CODE, phone.getCountryCode());
   hOut->writeInt16(AREA_CODE, phone.getAreaCode());
   hOut->writeInt32(LOCAL_NUMBER, phone.getLocalNumber());
   }

/**
* Deserialize a phone number from Portable object format.
*
* @param hIn   the serializer to write the object to
* @return      a new Phone number instance
*/
template<> PhoneNumber deserialize<PhoneNumber>(PofReader::Handle hIn)
   {
   int16_t nAccesCode   = hIn->readInt16(ACCESS_CODE);
   int16_t nCountryCode = hIn->readInt16(COUNTRY_CODE);
   int16_t nAreaCode    = hIn->readInt16(AREA_CODE);
   int32_t nLocalNumber = hIn->readInt32(LOCAL_NUMBER);

   return PhoneNumber(nAccesCode, nCountryCode, nAreaCode, nLocalNumber);
   }
