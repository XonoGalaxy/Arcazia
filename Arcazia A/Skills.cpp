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
