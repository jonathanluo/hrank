/*
 * #%L
 * ContactChangeListener.cpp
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
#include "ContactChangeListener.hpp"

#include <iostream>

#include "Contacts.hpp"

COH_OPEN_NAMESPACE2(coherence,examples)

void ContactChangeListener::entryInserted(MapEvent::View vEvent)
    {
    std::cout << "entry inserted:" << std::endl;
    Managed<Contact>::View vContact =
            cast<Managed<Contact>::View>(vEvent->getNewValue());
    std::cout << vContact << std::endl;
    }

void ContactChangeListener::entryUpdated(MapEvent::View vEvent)
    {
    std::cout << "entry updated:" << std::endl;
    Managed<Contact>::View vContactOld =
            cast<Managed<Contact>::View>(vEvent->getOldValue());
    Managed<Contact>::View vContactNew =
            cast<Managed<Contact>::View>(vEvent->getNewValue());

    std::cout << "old value:" << std::endl;
    std::cout << vContactOld << std::endl;

    std::cout << "new value:" << std::endl;
    std::cout << vContactNew << std::endl;
    }

void ContactChangeListener::entryDeleted(MapEvent::View vEvent)
    {
    std::cout << "entry deleted:" << std::endl;
    Managed<Contact>::View vContact =
            cast<Managed<Contact>::View>(vEvent->getOldValue());
    std::cout << vContact << std::endl;
    }

COH_CLOSE_NAMESPACE2
