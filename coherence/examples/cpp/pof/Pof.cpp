/*
 * #%L
 * Pof.cpp
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

#include <stdlib.h>

#include "Pof.hpp"


size_t hash(const char* csp)
   {
   size_t hash = 0;
   if (csp != NULL)
      {
      for (; *csp ; hash = (*csp++ << ((hash & 0xF) + 0x4))
            + (hash << 0x4) + (hash << 0xF) - (hash >> 0x8));
      }
   return hash;
   }
