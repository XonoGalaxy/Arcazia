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

        if (unit_->getAffection().second == CombatUnit::UnitAffection::STUNNED) {
        
            std::cout << "LOG : GAME MOTOR | COMBAT SYSTEM | INFO : Unit " << unit_->getId() << " is stunned and can't launch a skill\n";
            return ActionHandler::CombatAction::NO;
        
        }
        else {
        
            std::cout << "LOG : GAME MOTOR | COMBAT SYSTEM | INFO : Unit " << unit_->getId() << " is able to launch a skill\n";
            return ActionHandler::CombatAction::YES;
        
        }
    }
    else {
        std::cout << "LOG : GAME MOTOR | COMBAT SYSTEM | INFO : Unit " << unit_->getId() << " skill : " << unit_->getSkills().at(0).getType() << " is " << unit_->getSkills().at(0).getState() << "(0:READY/1:LOADING)\n";
    }
}

ActionHandler::CombatAction ActionHandler::checkBasicAttackAction(CombatUnit* unit_)
{

    if (unit_->getAffection().second == CombatUnit::UnitAffection::STUNNED) {

        std::cout << "LOG : GAME MOTOR | COMBAT SYSTEM | INFO : Unit " << unit_->getId() << " is stunned and can't launch a basic attack\n";
        return ActionHandler::CombatAction::NO;

    }
    else {

        std::cout << "LOG : GAME MOTOR | COMBAT SYSTEM | INFO : Unit " << unit_->getId() << " is able to launch a basic attack\n";
        return ActionHandler::CombatAction::YES;
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
            std::cout << "LOG : GAME MOTOR | COMBAT SYSTEM | INFO : Unit " << unit->getId() << " is " << unit->getState() << " (0:ALIVE/1:DEAD) \n";

        }

        else if (unit->getLife() > 0) {

            unit->setState(CombatUnit::UnitState::ALIVE);
            std::cout << "LOG : GAME MOTOR | COMBAT SYSTEM | INFO : Unit " << unit->getId() << " is " << unit->getState() << " (0:ALIVE/1:DEAD) \n";

        }
    }
}

void ActionHandler::updateAffections(std::vector<CombatUnit*> units_)
{
    std::pair<int, CombatUnit::UnitAffection> tmp;

    for (auto& unit : units_) {

        if (unit->getAffection().first != 0) {

            tmp = unit->getAffection();
            tmp.first--;

            if (tmp.first == 0) {

                if (tmp.second == CombatUnit::UnitAffection::STUNNED) {

                    // Reset stun effect on unit 
                    tmp.second = CombatUnit::UnitAffection::NONE;
                    unit->setAffection(tmp);

                    std::cout << "LOG : GAME MOTOR | COMBAT SYSTEM | INFO : Unit " << unit->getId() << " is no more stunned\n";

                }
                else {
                    //Do nothing
                }
            }
            else {
                // Do nothing

            }
        }
        else {
            //Do nothing
        }
    }

    std::cout << "LOG : GAME MOTOR | UNIT SYSTEM | INFO : Updated units weapon buffs \n";


    //for (auto& unit : units_) {

    //    // Check if unit has affection
    //    if (unit->getAffection().empty()) {

    //        std::cout << "LOG : GAME MOTOR | COMBAT SYSTEM | INFO : Unit " << unit->getId() << " has no affection\n";
    //        // No update possible
    //    }
    //    else {

    //        std::vector<std::pair<int, CombatUnit::UnitAffection>>::iterator it;

    //        for (it = unit->getAffection().begin(); it != unit->getAffection().end(); it++) {
    //            if (it->first == 0) {
    //                unit->getAffection().erase(it);
    //                std::cout << "LOG : GAME MOTOR | COMBAT SYSTEM | INFO : Unit " << unit->getId() << " is not more affected by : " << it->second << "\n";
    //            }
    //            else if (it->first != 0) {
    //                it->first = it->first--;
    //                std::cout << "LOG : GAME MOTOR | COMBAT SYSTEM | INFO : Unit " << unit->getId() << " is affected by : " << it->second << " within : " << it->first << " turns remaining \n";
    //            }
    //        }

    //    }
    //}

    //std::cout << "LOG : GAME MOTOR | UNIT SYSTEM | INFO : Updated units affections turns effect \n";
}

void ActionHandler::updateSkills(std::vector<CombatUnit*> units_)
{

    int count;

    for (auto& unit : units_) {

        for (auto& skill : unit->getSkills()) {

            // Update skills turn cooldown
            count = skill.getCount();
            skill.setCount(count - 1);

            if (skill.getCount() == 0) {

                skill.setState(Skills::SkillState::READY);
                std::cout << "LOG : GAME MOTOR | COMBAT SYSTEM | INFO : Unit " << unit->getId() << " has skill : " << skill.getType() << " with state : " << skill.getState() << " (0:READY/1:LOADING)\n";

            }

            else if (skill.getCount() > 0) {

                std::cout << "LOG : GAME MOTOR | COMBAT SYSTEM | INFO : Unit " << unit->getId() << " has skill : " << skill.getType() << " within : " << skill.getCount() << " turns remaining \n";

            }
        }
    }

    std::cout << "LOG : GAME MOTOR | UNIT SYSTEM | INFO : Updated units skills turns cooldown \n";
}

void ActionHandler::updateWeaponsBuffs(std::vector<CombatUnit*> units_)
{

    std::pair<int, Weapon::WeaponBuff> tmp;
    int dmg;

    for (auto& unit : units_) {

        if (unit->getWeapon()->getBuff().first != 0) {

            tmp = unit->getWeapon()->getBuff();
            tmp.first--;

            if (tmp.first == 0) {

                if (tmp.second == Weapon::WeaponBuff::CHARGE) {

                    // Reset charged weapong effect
                    dmg = unit->getWeapon()->getDamage();
                    unit->getWeapon()->setDamage(dmg / 2);

                    tmp.second = Weapon::WeaponBuff::NONE;
                    unit->getWeapon()->setBuff(tmp);

                    std::cout << "LOG : GAME MOTOR | COMBAT SYSTEM | INFO : Unit " << unit->getId() << " has no more enhanced weapon\n";

                }
                else {
                    //Do nothing
                }
            }
            else {
                // Do nothing

            }
        }
        else {
            //Do nothing
        }
    }

    std::cout << "LOG : GAME MOTOR | UNIT SYSTEM | INFO : Updated units weapon buffs \n";
}

ActionHandler::SkillAction ActionHandler::launchSkill(CombatUnit* unit_)
{
    int result;
    int count;

    result = std::rand() < unit_->getSkills().at(0).getSuccess()* (RAND_MAX + 1.0);

    if (result == 0) {

        std::cout << "LOG : GAME MOTOR | COMBAT SYSTEM | INFO : Unit " << unit_->getId() << " failed its skill : " << unit_->getSkills().at(0).getType() << " (0:STUN/1:CHARGE)\n";
        unit_->getSkills().at(0).setState(Skills::SkillState::LOADING);
        return SkillAction::FAILED;
    }
    else if (result != 0) {

        std::cout << "LOG : GAME MOTOR | COMBAT SYSTEM | INFO : Unit " << unit_->getId() << " successfully launched its skill : " << unit_->getSkills().at(0).getType() << " (0:STUN/1:CHARGE)\n";
        
        // Set counting for skills turn cooldown depending on its load turns
        count = unit_->getSkills().at(0).getLoad();

        unit_->getSkills().at(0).setCount(count);

        //std::cout << "LOG : Count " << unit_->getSkills().at(0).getCount() << "\n";

        unit_->getSkills().at(0).setState(Skills::SkillState::LOADING);

        return SkillAction::LAUNCHED;
    }
}

void ActionHandler::applySkill(CombatUnit* launcher_, CombatUnit* receiver_)
{
    // Caches
    std::pair<int, CombatUnit::UnitAffection> affection = { launcher_->getSkills().at(0).getTurns(), CombatUnit::UnitAffection::STUNNED };
    std::pair<int, Weapon::WeaponBuff> buff = { launcher_->getSkills().at(0).getTurns() , Weapon::WeaponBuff::CHARGE };
    
    int dmg;

    switch (launcher_->getSkills().at(0).getType()) {

    case Skills::SkillType::STUN:

        receiver_->setAffection(affection);
        launcher_->getSkills().at(0).setState(Skills::SkillState::LOADING);

        std::cout << "LOG : GAME MOTOR | COMBAT SYSTEM | INFO : Unit " << launcher_->getId() << " stunned unit " << receiver_->getId() << "\n";

        break;

    case Skills::SkillType::CHARGE:

        dmg = launcher_->getWeapon()->getDamage();

        launcher_->getWeapon()->setBuff(buff);
        
        // Apply charge buff effect on weapon
        launcher_->getWeapon()->setDamage(dmg * 2);
       
        std::cout << "LOG : GAME MOTOR | COMBAT SYSTEM | INFO : Unit " << launcher_->getId() << " enchanced its weapon : " << launcher_->getWeapon()->getType() << " (0:SWORD/1:AXE) with buff : " << launcher_->getWeapon()->getBuff().second << " (0:CHARGE)\n";
        break;
    }
}

void ActionHandler::applyBasicAttack(CombatUnit* launcher_, CombatUnit* receiver_)
{
    int dmg;
    int rec_life;
    int rec_shield;
    int diff;

    dmg = launcher_->getWeapon()->getDamage();
    
    rec_shield = receiver_->getShield();
    rec_life = receiver_->getLife();

    if (rec_shield < dmg) {
        diff = dmg - rec_shield;
        // Set shield to 0
        receiver_->setShield(0);

        // Apply difference on unit life
        receiver_->setLife(rec_life - diff);

        std::cout << "LOG : GAME MOTOR | COMBAT SYSTEM | INFO : Unit " << launcher_->getId() << " did " << launcher_->getWeapon()->getDamage() << " basic damage on unit " << receiver_->getId() << "\n";
        std::cout << "LOG : GAME MOTOR | COMBAT SYSTEM | INFO : Unit " << receiver_->getId() << " shield : " << receiver_->getShield() << " life : " << receiver_->getLife() << "\n";

    }
    else if (rec_shield == dmg) {
        // Apply basic attack damage on unit life
        receiver_->setShield(rec_shield - dmg);

        std::cout << "LOG : GAME MOTOR | COMBAT SYSTEM | INFO : Unit " << launcher_->getId() << " did " << dmg << " basic damage on unit " << receiver_->getId() << "\n";
        std::cout << "LOG : GAME MOTOR | COMBAT SYSTEM | INFO : Unit " << receiver_->getId() << " shield : " << receiver_->getShield() << " life : " << receiver_->getLife() << "\n";
    }

    else if (rec_shield > dmg) {
        // Apply basic attack damage on unit shield
        receiver_->setShield(rec_shield - dmg);

        std::cout << "LOG : GAME MOTOR | COMBAT SYSTEM | INFO : Unit " << launcher_->getId() << " did " << dmg << " basic damage on unit " << receiver_->getId() << "\n";
        std::cout << "LOG : GAME MOTOR | COMBAT SYSTEM | INFO : Unit " << receiver_->getId() << " shield : " << receiver_->getShield() << " life : " << receiver_->getLife() << "\n";
    }

}
