/*
 * #%L
 * OfficeUpdater.cpp
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

#include "contacts/Contacts.hpp"
#include "OfficeUpdater.hpp"


COH_OPEN_NAMESPACE2(coherence,examples)

using coherence::util::processor::UpdaterProcessor;

/**
* Register OfficeUpdater as a Managed type that can be serialized.
*/
COH_REGISTER_PORTABLE_CLASS(POF_TYPE_OFFICEUPDATER, OfficeUpdater);

Object::Holder OfficeUpdater::process(InvocableMap::Entry::Handle hEntry) const
    {
    Managed<Contact>::Handle vContact =
            cast<Managed<Contact>::Handle>(hEntry->getValue());
    vContact->setWorkAddress(*m_addrWork);
    hEntry->setValue(vContact);
    return hEntry;
    }


// ----- PortableObject interface -------------------------------------------

void OfficeUpdater::readExternal(PofReader::Handle hReader)
    {
    initialize(m_addrWork,
            cast<Managed<Address>::View>(hReader->readObject(POF_WORK_ADDRESS)));
    }

void OfficeUpdater::writeExternal(PofWriter::Handle hWriter) const
    {
    hWriter->writeObject(POF_WORK_ADDRESS, m_addrWork);
    }

COH_CLOSE_NAMESPACE2

