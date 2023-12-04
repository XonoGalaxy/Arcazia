/**

    \file       ActionHandler.cpp
    \brief      Implementation of ActionHandler class
    \copyright  © Copyright XONO GALAXY - 2023 - All rights reserved

    Reproduction, modification and/or use of this document without express written permission of XONO GALAXY is prohibited
    © Copyright XONO GALAXY - 2023
    All rights reserved - XONO GALAXY Proprietary Data.

 **/

#include "ActionHandler.h"

ActionHandler::ActionHandler()
{
}

ActionHandler::~ActionHandler()
{
}

ActionHandler::CombatAction ActionHandler::checkSkillAction(CombatUnit* unit_)
{
    if (unit_->getSkills().at(0).getState() == Skills::SkillState::READY) {

        for (auto& affection : unit_->getAffection()) {

            if (affection.second == CombatUnit::UnitAffection::STUNNED) {

                std::cout << "LOG : GAME MOTOR | COMBAT SYSTEM | INFO : Unit " << unit_->getId() << " is stunned and can't launch a skill\n";
                return ActionHandler::CombatAction::NO;
            
            }
            else {

                std::cout << "LOG : GAME MOTOR | COMBAT SYSTEM | INFO : Unit " << unit_->getId() << " is able to launch a skill\n";
                return ActionHandler::CombatAction::YES;
             
            }
        }
    }
    else {
        std::cout << "LOG : GAME MOTOR | COMBAT SYSTEM | INFO : Unit " << unit_->getId() << " skill : " << unit_->getSkills().at(0).getType() << " is " << unit_->getSkills().at(0).getState() << "(0:READY/1:LOADING)\n";
    }
}

ActionHandler::CombatAction ActionHandler::checkBasicAttackAction(CombatUnit* unit_)
{
    for (auto& affection : unit_->getAffection()) {

        if (affection.second == CombatUnit::UnitAffection::STUNNED) {

            std::cout << "LOG : GAME MOTOR | COMBAT SYSTEM | INFO : Unit " << unit_->getId() << " is stunned and can't launch a basic attack\n";
            return ActionHandler::CombatAction::NO;
           
        }
        else {

            std::cout << "LOG : GAME MOTOR | COMBAT SYSTEM | INFO : Unit " << unit_->getId() << " is able to launch a basic attack\n";
            return ActionHandler::CombatAction::YES;
        }
    }
}

CombatUnit::UnitState ActionHandler::checkUnitsDeath(std::vector<CombatUnit*> units_)
{
    for (auto& unit : units_) {

        if (unit->getState() == CombatUnit::UnitState::DEAD) {

            std::cout << "LOG : GAME MOTOR | COMBAT SYSTEM | INFO : Unit " << unit->getId() << " is dead\n";
            return CombatUnit::UnitState::DEAD;
        }

        else {

            // Do nothing

        }
    }
}

void ActionHandler::updateUnitsState(std::vector<CombatUnit*> units_)
{

    for (auto& unit : units_) {

        if (unit->getLife() <= 0) {

            unit->setState(CombatUnit::UnitState::DEAD);
            std::cout << "LOG : GAME MOTOR | COMBAT SYSTEM | INFO : Unit " << unit->getId() << " is " << unit->getState() << "(0:ALIVE/1:DEAD) \n";

        }

        else if (unit->getLife() > 0) {

            unit->setState(CombatUnit::UnitState::ALIVE);
            std::cout << "LOG : GAME MOTOR | COMBAT SYSTEM | INFO : Unit " << unit->getId() << " is " << unit->getState() << "(0:ALIVE/1:DEAD) \n";

        }
    }
}

void ActionHandler::updateAffections(std::vector<CombatUnit*> units_)
{

    for (auto& unit : units_) {

        std::vector<std::pair<int, CombatUnit::UnitAffection>>::iterator it;

        for (it = unit->getAffection().begin(); it != unit->getAffection().end(); it++) {
            if (it->first == 0) {
                unit->getAffection().erase(it);
                std::cout << "LOG : GAME MOTOR | COMBAT SYSTEM | INFO : Unit " << unit->getId() << " is not more affected by : " << it->second << "\n";
            }
            else if (it->first != 0) {
                it->first = it->first--;
                std::cout << "LOG : GAME MOTOR | COMBAT SYSTEM | INFO : Unit " << unit->getId() << " is affected by : " << it->second << " within : " << it->first << " turns remaining \n";
            }
        }
    }

    std::cout << "LOG : GAME MOTOR | UNIT SYSTEM | INFO : Updated units affections turns effect \n";
}

void ActionHandler::updateSkills(std::vector<CombatUnit*> units_)
{

    for (auto& unit : units_) {

        std::vector<Skills>::iterator it;

        for (it = unit->getSkills().begin(); it != unit->getSkills().end(); it++) {
            if (it->getCount() == 0) {

                it->setState(Skills::SkillState::READY);
                std::cout << "LOG : GAME MOTOR | COMBAT SYSTEM | INFO : Unit " << unit->getId() << " has skill : " << it->getType() << " with state : " << it->getState() << " (0:READY/1:LOADING)\n";

            }

            else if (it->getCount() > 0) {

                it->setCount(it->getCount() - 1);
                std::cout << "LOG : GAME MOTOR | COMBAT SYSTEM | INFO : Unit " << unit->getId() << " has skill : " << it->getType() << " within : " << it->getCount() << " turns remaining \n";

            }
        }
    }

    std::cout << "LOG : GAME MOTOR | UNIT SYSTEM | INFO : Updated units skills turns cooldown \n";
}

ActionHandler::SkillAction ActionHandler::launchSkill(CombatUnit* unit_)
{
    int result;

    result = std::rand() < unit_->getSkills().at(0).getSuccess()* (RAND_MAX + 1.0);

    if (result == 0) {

        std::cout << "LOG : GAME MOTOR | COMBAT SYSTEM | INFO : Unit " << unit_->getId() << " failed its skill : " << unit_->getSkills().at(0).getType() << "\n";
        unit_->getSkills().at(0).setState(Skills::SkillState::LOADING);
        return SkillAction::FAILED;
    }
    else if (result != 0) {

        std::cout << "LOG : GAME MOTOR | COMBAT SYSTEM | INFO : Unit " << unit_->getId() << " successfully launched skill : " << unit_->getSkills().at(0).getType() << "\n";
        unit_->getSkills().at(0).setState(Skills::SkillState::LOADING);
        return SkillAction::LAUNCHED;
    }
}

void ActionHandler::applySkill(CombatUnit* launcher_, CombatUnit* receiver_)
{

    // Caches
    std::pair<int, CombatUnit::UnitAffection> affection = { launcher_->getSkills().at(0).getTurns(), CombatUnit::UnitAffection::STUNNED};
    std::pair<int, Weapon::WeaponBuff> buff = { launcher_->getSkills()[0].getTurns(), Weapon::WeaponBuff::CHARGE };
    int dmg;

    switch (launcher_->getSkills()[0].getType()) {

    case Skills::SkillType::STUN:
        receiver_->setAffection(affection);
        launcher_->getSkills().at(0).setState(Skills::SkillState::LOADING);

        std::cout << "LOG : GAME MOTOR | COMBAT SYSTEM | INFO : Unit " << launcher_->getId() << " stunned unit " << receiver_->getId() << "\n";

        break;
    case Skills::SkillType::CHARGE:
        dmg = launcher_->getWeapon().getDamage();
        launcher_->getWeapon().setBuff(buff);

        std::cout << "LOG : GAME MOTOR | COMBAT SYSTEM | INFO : Unit " << launcher_->getId() << " enchanced its weapon : " << launcher_->getWeapon().getType() << " with buff : " << launcher_->getWeapon().getBuffs().at(0).second << "\n";
        break;
    }
}

void ActionHandler::applyBasicAttack(CombatUnit* launcher_, CombatUnit* receiver_)
{
    int dmg;
    int rec_life;
    int rec_shield;
    int diff;

    dmg = launcher_->getWeapon().getDamage();
    rec_shield = receiver_->getShield();
    rec_life = receiver_->getLife();

    if (rec_shield < dmg) {
        diff = dmg - rec_shield;
        // Set shield to 0
        receiver_->setShield(0);

        // Apply difference on unit life
        receiver_->setLife(rec_life - diff);

        std::cout << "LOG : GAME MOTOR | COMBAT SYSTEM | INFO : Unit " << launcher_->getId() << " did " << dmg << " basic damage on unit " << receiver_->getId() << "\n";
        std::cout << "LOG : GAME MOTOR | COMBAT SYSTEM | INFO : Unit " << receiver_->getId() << " shield : " << receiver_->getShield() << " life : " << receiver_->getLife() << "\n";

    }
    else if (rec_shield == dmg) {
        // Apply basic attack damage on unit life
        receiver_->setShield(rec_life - dmg);

        std::cout << "LOG : GAME MOTOR | COMBAT SYSTEM | INFO : Unit " << launcher_->getId() << " did " << dmg << " basic damage on unit " << receiver_->getId() << "\n";
        std::cout << "LOG : GAME MOTOR | COMBAT SYSTEM | INFO : Unit " << receiver_->getId() << " shield : " << receiver_->getShield() << " life : " << receiver_->getLife() << "\n";
    }

    else if (rec_shield > dmg) {
        // Apply basic attack damage on unit shield
        receiver_->setShield(rec_life - dmg);

        std::cout << "LOG : GAME MOTOR | COMBAT SYSTEM | INFO : Unit " << launcher_->getId() << " did " << dmg << " basic damage on unit " << receiver_->getId() << "\n";
        std::cout << "LOG : GAME MOTOR | COMBAT SYSTEM | INFO : Unit " << receiver_->getId() << " shield : " << receiver_->getShield() << " life : " << receiver_->getLife() << "\n";
    }

}
