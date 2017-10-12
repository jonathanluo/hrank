/*
 * #%L
 * ContactId.cpp
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
#include "ContactId.hpp"

#include "coherence/lang/Array.hpp"

using coherence::lang::Array;

// ----- constructors -------------------------------------------------------

ContactId::ContactId(const std::string& sFirstName, const std::string& sLastName)
    : m_sFirstName(sFirstName), m_sLastName(sLastName)
    {
    }

ContactId::ContactId(const ContactId& that)
    : m_sFirstName(that.m_sFirstName), m_sLastName(that.m_sLastName)
    {
    }

// ----- free functions -----------------------------------------------------

std::ostream& operator<<(std::ostream& out, const ContactId& contactId)
    {
    out << contactId.getFirstName() << " " << contactId.getLastName();
    return out;
    }

bool operator==(const ContactId& contactIdA, const ContactId& contactIdB)
	{
    return contactIdA.getFirstName()  == contactIdB.getFirstName() &&
            contactIdA.getLastName()  == contactIdB.getLastName();
	}

size32_t hash_value(const ContactId& contactId)
    {
    std::string sFirstName = contactId.getFirstName();
    std::string sLastName  = contactId.getLastName();

    // Using the optional built-in hashing implementation of Coherence.
    return Array<char>::hashCode(sFirstName.data(),
            (size32_t) sFirstName.length())
        ^  Array<char>::hashCode(sLastName.data(),
            (size32_t) sLastName.length());
    }

