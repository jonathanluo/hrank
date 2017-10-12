/*
 * #%L
 * PasswordIdentityTransformer.cpp
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

#include "PasswordIdentityTransformer.hpp"

#include "coherence/security/Principal.hpp"
#include "coherence/util/Iterator.hpp"
#include "coherence/util/Set.hpp"

COH_OPEN_NAMESPACE2(coherence,examples)

using coherence::security::Principal;
using coherence::util::Iterator;
using coherence::util::Set;

COH_REGISTER_TYPED_CLASS(PasswordIdentityTransformer);

// ----- IdentityTransformer interface --------------------------------------

Object::View PasswordIdentityTransformer::transformIdentity(
        Subject::View vSubject, Service::View vService) const
    {
        // The service is not needed so the service argument is being ignored.
        // It could be used, for example, if there were different token types
        // required per service.
		if (vSubject == NULL)
        {
        COH_THROW(SecurityException::create("Incomplete Subject"));
        }

    Set::View vsetPrincipals = vSubject->getPrincipals();

    if (vsetPrincipals->isEmpty())
        {
        COH_THROW(SecurityException::create("Incomplete Subject"));
        }

    ObjectArray::Handle hao = ObjectArray::create(vsetPrincipals->size() + 1);
    size32_t            i   = 0;

    hao[i++] = System::getProperty("coherence.password", "secret-password");
    for (Iterator::Handle hIter = vsetPrincipals->iterator();
            hIter->hasNext();)
        {
        Principal::View vPrincipal = cast<Principal::View>(hIter->next());
        hao[i++] = vPrincipal->getName();
        }

    // The token consists of the password plus the principal names as an
    // array of pof-able types, in this case strings.
    return hao;
    }

COH_CLOSE_NAMESPACE2
