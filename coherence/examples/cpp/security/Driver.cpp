/*
 * #%L
 * Driver.cpp
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
* Driver executes all the security examples.
* <p>
* Examples are invoked in this order <p/>
* 1) Password enforcement<br/>
* 2) Cache access control<br/>
* 3) InvocationService access control<br/>
*
* @author dag  2010.04.30
*/

#include "coherence/lang/Exception.hpp"

#include "PasswordExample.hpp"
#include "AccessControlExample.hpp"

using coherence::lang::Exception;

using namespace coherence::examples;


/**
* Execute Security examples.
*
* @param argc number of command line arguments
* @param argv command line arguments
*/
int main(int argc, char** argv)
    {
    try
        {
        std::cout << "------security examples begin------" << std::endl;

        PasswordExample passwordExample;

        // Run password example
        passwordExample.getCache();

        AccessControlExample accessControlExample;

        // Run cache access control example
        accessControlExample.accessCache();
        // Run invocation service access control example
        accessControlExample.accessInvocationService();

        std::cout << "------security examples completed------" << std::endl;
        }
    catch (Exception::View ex)
        {
        std::cout << ex << std::endl;
        }
    return 0;
    }
