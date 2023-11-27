/**

    \file       Knight.cpp
    \brief      Implementation of Knight class
    \copyright  © Copyright XONO GALAXY - 2023 - All rights reserved

    Reproduction, modification and/or use of this document without express written permission of XONO GALAXY is prohibited
    © Copyright XONO GALAXY - 2023
    All rights reserved - XONO GALAXY Proprietary Data.

 **/

#include "Knight.h"

Knight::Knight() : CombatUnit(20, 60, UnitState::ALIVE)
{
    m_type = KNIGHT;
}

Knight::~Knight()
{
}
