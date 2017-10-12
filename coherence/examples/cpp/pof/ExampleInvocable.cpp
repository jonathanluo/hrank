/*
 * #%L
 * ExampleInvocable.cpp
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

#include "ExampleInvocable.hpp"
#include "contacts/Contacts.hpp"

COH_OPEN_NAMESPACE2(coherence,examples)

/**
* Register ExampleInvocable as a Managed type that can be serialized.
*/
COH_REGISTER_PORTABLE_CLASS(POF_TYPE_EXAMPLEINVOCABLE, ExampleInvocable);


// ----- constructors -------------------------------------------------------

ExampleInvocable::ExampleInvocable()
        : m_nValue(0)
    {
    }


// ----- Invocable interface ------------------------------------------------

void ExampleInvocable::init(InvocationServiceHandle /*hService*/)
    {
    }

Object::Holder ExampleInvocable::getResult() const
    {
    return Integer32::valueOf(m_nValue);
    }

void ExampleInvocable::run()
    {
    ++m_nValue;
    }

// ----- PortableObject interface -------------------------------------------

void ExampleInvocable::readExternal(PofReader::Handle hReader)
    {
    m_nValue = hReader->readInt32(0);
    }

void ExampleInvocable::writeExternal(PofWriter::Handle hWriter) const
    {
    hWriter->writeInt32(0, m_nValue);
    }

COH_CLOSE_NAMESPACE2
