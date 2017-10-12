/*
 * #%L
 * FilterFetcher.cpp
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

#include "FilterFetcher.hpp"

#include "PofConfig.hpp"

#include "coherence/io/pof/PofHelper.hpp"
#include "coherence/io/pof/SystemPofContext.hpp"


COH_OPEN_NAMESPACE2(coherence,examples)

using coherence::io::pof::PofHelper;

COH_REGISTER_PORTABLE_CLASS(POF_TYPE_FILTERFETCHER, FilterFetcher);


// ----- constructors -------------------------------------------------------

FilterFetcher::FilterFetcher()
  : m_fExtractor(false), m_vsQuery(self()), m_vaEnv(self()), m_vbindings(self())
    {
    }
   
FilterFetcher::FilterFetcher(String::View vsQuery, bool fExtractor,
               ObjectArray::View vaEnv, Map::View vbindings)
  : m_fExtractor(fExtractor), m_vsQuery(self(), vsQuery), m_vaEnv(self(), vaEnv),
    m_vbindings(self(), vbindings)
    {
    COH_ENSURE_PARAM(vsQuery);
    }


// ----- PortableObject interface -------------------------------------------

void FilterFetcher::readExternal(PofReader::Handle hIn)
    {
    m_fExtractor = hIn->readBoolean(0);
    m_vsQuery    = hIn->readString(1);
    m_vaEnv      = hIn->readObjectArray(2);
    m_vbindings  = hIn->readMap(3);
    }

void FilterFetcher::writeExternal(PofWriter::Handle hOut) const
    {
    hOut->writeBoolean(0, m_fExtractor);
    hOut->writeString(1,m_vsQuery);
    hOut->writeObjectArray(2, m_vaEnv);
    hOut->writeMap(3, m_vbindings);
    }

COH_CLOSE_NAMESPACE2
