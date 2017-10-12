/*
 * #%L
 * SecurityExampleHelper.cpp
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

#include "SecurityExampleHelper.hpp"

#include "coherence/security/GenericPrincipal.hpp"
#include "coherence/security/auth/GenericSubject.hpp"
#include "coherence/util/HashMap.hpp"
#include "coherence/util/HashSet.hpp"
#include "coherence/util/Map.hpp"
#include "coherence/util/Set.hpp"

COH_OPEN_NAMESPACE2(coherence,examples)

using namespace coherence::lang;

using coherence::security::GenericPrincipal;
using coherence::security::auth::GenericSubject;
using coherence::util::HashMap;
using coherence::util::HashSet;
using coherence::util::Map;
using coherence::util::Set;


namespace
    {
    /**
    * The map keyed by user name with the value being the user's role.
    * Represents which user is in which role.
    */
    Map::Handle getUserRoleMap()
        {
        static FinalHandle<Map> s_hMapUserToRole(System::common(),
                HashMap::create());
        static bool fInit = false;

        if (!fInit)
            {
            // User to role mapping
            s_hMapUserToRole->put(String::create("BuckarooBanzai"),
                    String::create("role_admin"));
            s_hMapUserToRole->put(String::create("JohnWhorfin"),
                    String::create("role_writer"));
            s_hMapUserToRole->put(String::create("JohnBigboote"),
                    String::create("role_reader"));
            fInit = true;
            }
        return s_hMapUserToRole;
        }
    COH_STATIC_INIT(getUserRoleMap());
    }


Subject::View SecurityExampleHelper::login(String::View vsName)
    {
    // For simplicity, just create a Subject. Normally, this would be
    // done using a platform dependent authentication method.
    String::View vsUserDN       = COH_TO_STRING("CN=" << vsName << ",OU=Yoyodyne");
    Set::Handle  hSetPrincipals = HashSet::create();

    hSetPrincipals->add(GenericPrincipal::create(vsUserDN));
    hSetPrincipals->add(GenericPrincipal::create(
            cast<String::View>(getUserRoleMap()->get(vsName))));

    return GenericSubject::create((Set::View) hSetPrincipals);
    }

COH_CLOSE_NAMESPACE2

