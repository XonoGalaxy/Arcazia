/**

    \file       CombatManager.h
    \brief      Implementation of CombatManager class
    \copyright  © Copyright XONO GALAXY - 2023 - All rights reserved

    Reproduction, modification and/or use of this document without express written permission of XONO GALAXY is prohibited
    © Copyright XONO GALAXY - 2023
    All rights reserved - XONO GALAXY Proprietary Data.

 **/

#include "CombatManager.h"

CombatManager::CombatManager()
{
}

CombatManager::~CombatManager()
{
}

CombatUnit* CombatManager::getOpponent1()
{
    return m_opponent1;
}

CombatUnit* CombatManager::getOpponent2()
{
    return m_opponent2;
}

void CombatManager::setOpponent1(CombatUnit* opponent_)
{
    m_opponent1 = opponent_;
}

void CombatManager::setOpponent2(CombatUnit* opponent_)
{
    m_opponent2 = opponent_;
}

CombatManager::CombatAction CombatManager::checkSkillAction(Skills skill_)
{
    if (m_opponent1->getSkills()[0].getState() == Skills::SkillState::READY) {

        for (auto& affection : m_opponent1->getAffection()) {

            if (affection == CombatUnit::UnitAffection::STUNNED) {

                return CombatManager::CombatAction::NO;
            }
            else {

                return CombatManager::CombatAction::YES;
            }
        }
    }
    else {
        return CombatManager::CombatAction::NO;
    }
}

CombatManager::CombatAction CombatManager::checkBasicAttackAction(CombatUnit* unit_)
{
    return CombatManager::CombatAction::NO;

}
