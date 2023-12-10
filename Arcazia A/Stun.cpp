/**

    \file       Stun.cpp
    \brief      Implementation of Stun class
    \copyright  © Copyright XONO GALAXY - 2023 - All rights reserved

    Reproduction, modification and/or use of this document without express written permission of XONO GALAXY is prohibited
    © Copyright XONO GALAXY - 2023
    All rights reserved - XONO GALAXY Proprietary Data.

 **/

#include "Stun.h"

Stun::Stun() : Skills(0.20, 5, SkillState::READY, 1, Skills::SkillType::STUN, 0)
{
}

Stun::~Stun()
{
}
