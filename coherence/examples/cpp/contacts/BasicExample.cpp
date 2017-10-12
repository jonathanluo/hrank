/*
 * #%L
 * BasicExample.cpp
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


#include "BasicExample.hpp"

COH_OPEN_NAMESPACE2(coherence,examples)

void BasicExample::execute(NamedCache::Handle hCache)
    {
    std::cout << "------BasicExample begins------" << std::endl;
    Contact contact(generateContact());
    Managed<Contact>::View vContact = Managed<Contact>::create(contact);

    ContactId contactId = ContactId(contact.getFirstName(),
            contact.getLastName());

    Managed<ContactId>::View vContactId = Managed<ContactId>::create(contactId);

    // associate a ContactId with a Contact in the cache
    hCache->put(vContactId, vContact);

    // retrieve the Contact associated with a ContactId from the cache
    vContact = cast<Managed<Contact>::View>(hCache->get(vContactId));

    // remove mapping of ContactId to Contact from the cache.
    hCache->remove(vContactId);
    std::cout << "------BasicExample completed------" << std::endl;
    }

Contact BasicExample::generateContact() const
    {
    Contact::phone_map phones;
    struct tm tmDob = {0, 0, 0, 24, 5, 40, 0, 0, 0};

    phones["home"]  = PhoneNumber(11, 1, 617, 5551212);

    return Contact("John", "Bigboote", Address("10 My St.", "",
            "Boston", "MA", "01111", "US"), Address(), phones,
            tmDob);
    }

COH_CLOSE_NAMESPACE2
