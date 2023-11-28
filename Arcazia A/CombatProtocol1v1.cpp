/**

    \file       CombatProtocol1v1.cpp
    \brief      Implementation of CombatProtocol1v1 class
    \copyright  © Copyright XONO GALAXY - 2023 - All rights reserved

    Reproduction, modification and/or use of this document without express written permission of XONO GALAXY is prohibited
    © Copyright XONO GALAXY - 2023
    All rights reserved - XONO GALAXY Proprietary Data.

 **/

#include "CombatProtocol1v1.h"

CombatProtocol1v1::CombatProtocol1v1()
{
}

CombatProtocol1v1::~CombatProtocol1v1()
{
}

void CombatProtocol1v1::launchCombatProtocol1v1()
{
    //Opponent 1 always start
    //Opponent 1 launch its first skills
    if (checkSkillAction(m_opponent1->getSkills()[0]) == CombatManager::CombatAction::YES) {

        m_opponent1->launchSkill();

        // opponent2 get affected by skill
        //if(m_opponent1->getSkills()[0] == AFFECTION_SKILLS)
        //m_opponent2->
    }

    // Oppoenent 1 can't launch a skill
    //else {
        // No skill launch action
    //}

    // Opponenet 1 launch a basic attack
    //if (m_opponent1->getAffection)
  
    // Oppoenent 2 receive skills effect
    //M_opponent2->

}
