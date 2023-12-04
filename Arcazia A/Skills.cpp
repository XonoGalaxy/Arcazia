/**

    \file       Skills.cpp
    \brief      Implementation of Skills class
    \copyright  © Copyright XONO GALAXY - 2023 - All rights reserved

    Reproduction, modification and/or use of this document without express written permission of XONO GALAXY is prohibited
    © Copyright XONO GALAXY - 2023
    All rights reserved - XONO GALAXY Proprietary Data.

 **/

#include "Skills.h"

Skills::Skills()
{
}

Skills::Skills(int success_, int loading_, SkillState state_, int turns_, Skills::SkillType type_)
{
    m_success   = success_;
    m_load      = loading_;
    m_state     = state_;
    m_turns     = turns_;
    m_type      = type_;
}

Skills::~Skills()
{
}

Skills::SkillState Skills::getState()
{
    return m_state;
}

Skills::SkillType Skills::getType()
{
    return m_type;
}

int Skills::getCount()
{
    return m_count;
}

int Skills::getLoad()
{
    return m_load;
}

int Skills::getSuccess()
{
    return m_success;
}

int Skills::getTurns()
{
    return m_turns;
}

void Skills::setState(SkillState state_)
{
    m_state = state_;
}

void Skills::setType(SkillType type_)
{
    m_type = type_;
}

void Skills::setCount(int count_)
{
    m_count = count_;
}

void Skills::setLoad(int load_)
{
    m_load = load_;
}

void Skills::setSuccess(int success_)
{
    m_success = success_;
}

void Skills::setTurns(int turns_)
{
    m_turns = turns_;
}
