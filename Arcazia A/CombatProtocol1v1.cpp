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
    /* Initiate protocol */
    m_turns = 0;
    m_state = CombatState::STARTED;

    // Set all skills to READY
    
    // Set all affection to NONE
}

CombatProtocol1v1::CombatProtocol1v1(std::vector<CombatUnit*> opponents_)
{
    m_opponents = opponents_;

    /* Initiate protocol */
    m_turns = 0;
    m_state = CombatState::STARTED;

    // Set all skills to READY

    // Set all affection to NONE
    std::cout << "LOG : GAME MOTOR | COMBAT SYSTEM | INFO : Initializated protocol\n";

}

CombatProtocol1v1::~CombatProtocol1v1()
{

}

std::vector<CombatUnit*> CombatProtocol1v1::getOpponents()
{
    return m_opponents;
}


void CombatProtocol1v1::setOpponent(CombatUnit* opponent_)
{
    m_opponents.push_back(opponent_);
}


void CombatProtocol1v1::launchCombatProtocol1v1()
{

    std::cout << "LOG : GAME MOTOR | COMBAT SYSTEM | INFO : Combat Protocol 1v1 with Unit "  << m_opponents.at(0)->getId() << " vs " << m_opponents.at(1)->getId() <<  " is starting\n";

    /* Start protcol */
    while (m_state != CombatState::ENDED) {

        std::cout << "LOG : GAME MOTOR | COMBAT SYSTEM | INFO : Combat Protocol 1v1 turn number : " << m_turns << " is starting\n";
        /* Start Opponent 1 turn */
        // Step 1 : Opponent 1 launch a skill on opponent 2
        // Check if opponent 1 can launch a skill
        if (m_actionHandler->checkSkillAction(m_opponents.at(0)) == ActionHandler::CombatAction::YES) {

            // Launch skill and check if launched
            if (m_actionHandler->launchSkill(m_opponents.at(0)) == ActionHandler::SkillAction::LAUNCHED) {

                // Apply skill effect
                m_actionHandler->applySkill(m_opponents.at(0), m_opponents.at(1));
            }
            else {
                // No skill application because skill launch failed
            }
        }

        else {
            // No skill action possible
        }
        // Step 2 : Opponent 1 launch a basic attack on opponent 2
        if (m_actionHandler->checkBasicAttackAction(m_opponents.at(0)) == ActionHandler::CombatAction::YES) {

            // Launch basic attack on opponent 2
            m_actionHandler->applyBasicAttack(m_opponents.at(0), m_opponents.at(1));
        }

        else {
            // No basic attack action possible 
        }

        /* End turn */
        // Step 1 : Update all units stats

        // Upadate affection turns cooldown
        m_actionHandler->updateAffections(m_opponents);

        // Update skills 
        m_actionHandler->updateSkills(m_opponents);
    
        // Update units state
        m_actionHandler->updateUnitsState(m_opponents);

        // Update units weapon buffs
        m_actionHandler->updateWeaponsBuffs(m_opponents);

        // Check if one unit is dead
        if (m_actionHandler->checkUnitsDeath(m_opponents) == CombatUnit::UnitState::DEAD) {

            m_state = CombatState::ENDED;
            std::cout << "LOG : GAME MOTOR | COMBAT SYSTEM | INFO : Combat Protocol 1v1 with Unit" << m_opponents.at(0)->getId() << " vs " << m_opponents.at(1)->getId() << " finished\n";

            // Look for the survivor which is the winner
            for (auto& unit : m_opponents) {
                if (unit->getState() == CombatUnit::UnitState::ALIVE) {
                    std::cout << "LOG : GAME MOTOR | COMBAT SYSTEM | INFO : The winner is Unit " << unit->getId() <<  "!\n";
                }
            }
        }

        else {
            // Do nothing
        }

        //Step 2 : Update protocol turns
        m_turns++;

        std::cout << "LOG : GAME MOTOR | COMBAT SYSTEM | INFO : Combat Protocol 1v1 turn number : " << m_turns << " is starting\n";
        /* Start Opponent 2 turn */
        // Check if opponent 2 can launch a skill
        if (m_actionHandler->checkSkillAction(m_opponents.at(1)) == ActionHandler::CombatAction::YES) {

            // Launch skill and check if launched
            if (m_actionHandler->launchSkill(m_opponents.at(1)) == ActionHandler::SkillAction::LAUNCHED) {

                // Apply skill effect
                m_actionHandler->applySkill(m_opponents.at(1), m_opponents.at(0));

            }
            else {
                // No skill application because skill launch failed
            }
        }

        else {
            // No skill action possible
        }

        // Step 2 : Opponent 2 launch a basic attack on opponent 1
        if (m_actionHandler->checkBasicAttackAction(m_opponents.at(1)) == ActionHandler::CombatAction::YES) {

            // Launch basic attack on opponent 1
            m_actionHandler->applyBasicAttack(m_opponents.at(1), m_opponents.at(0));
        }

        else {
            // No basic attack action possible 
        }

        /* End turn */
        // Step 1 : Update all units stats

        // Upadate affection turns cooldown
        m_actionHandler->updateAffections(m_opponents);

        // Update skills 
        m_actionHandler->updateSkills(m_opponents);

        // Update units state
        m_actionHandler->updateUnitsState(m_opponents);

        // Update units weapon buffs
        m_actionHandler->updateWeaponsBuffs(m_opponents);
 

        // Check if one unit is dead
        if (m_actionHandler->checkUnitsDeath(m_opponents) == CombatUnit::UnitState::DEAD) {

            m_state = CombatState::ENDED;
            std::cout << "LOG : GAME MOTOR | COMBAT SYSTEM | INFO : Combat Protocol 1v1 with Unit" << m_opponents.at(0)->getId() << " vs " << m_opponents.at(1)->getId() << " finished\n";

            // Look for the survivor which is the winner
            for (auto& unit : m_opponents) {
                if (unit->getState() == CombatUnit::UnitState::ALIVE) {
                    std::cout << "LOG : GAME MOTOR | COMBAT SYSTEM | INFO : The winner is Unit " << unit->getId() << "!\n";
                }
            }
        }

        else {
            // Do nothing
        }

        //Step 2 : Update protocol turns
        m_turns++;

    }
}
