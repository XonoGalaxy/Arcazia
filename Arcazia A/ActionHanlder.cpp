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

        // Check if unit has affection
        if (unit_->getAffection().empty()) {
            // No affaction then action possible
            return ActionHandler::CombatAction::YES;
        }
        else {

            for (auto& affection : unit_->getAffection()) {
                std::cout << "LOG : GAME MOTOR | COMBAT SYSTEM | DEBUG : I AM HERE\n";
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
    }
    else {
        std::cout << "LOG : GAME MOTOR | COMBAT SYSTEM | INFO : Unit " << unit_->getId() << " skill : " << unit_->getSkills().at(0).getType() << " is " << unit_->getSkills().at(0).getState() << "(0:READY/1:LOADING)\n";
    }
}

ActionHandler::CombatAction ActionHandler::checkBasicAttackAction(CombatUnit* unit_)
{
        // Check if unit has affection
        if (unit_->getAffection().empty()) {

            // No affaction then action possible
            return ActionHandler::CombatAction::YES;
        }

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

    for (auto& unit : units_) {

        // Check if unit has affection
        if (unit->getAffection().empty()) {

            std::cout << "LOG : GAME MOTOR | COMBAT SYSTEM | INFO : Unit " << unit->getId() << " has no affection\n";
            // No update possible
        }
        else {

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
    }

    std::cout << "LOG : GAME MOTOR | UNIT SYSTEM | INFO : Updated units affections turns effect \n";
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

    std::vector<std::pair<int, Weapon::WeaponBuff>> tmp;

    for (int a = 0; a <= units_.size(); a++) {

        for (int b = 0; b <= units_.at(a)->getWeapon()->getBuffs().size(); b++) {

            std::cout << "LOG : HERE 1\n";

            if (units_.at(a)->getWeapon()->getBuffs().at(b).first != 0) {

                std::cout << "LOG : HERE 2\n";

                std::cout << "LOG : Buff turn : " << units_.at(a)->getWeapon()->getBuffs().at(b).first << "\n";

                tmp = units_.at(a)->getWeapon()->getBuffs();
                tmp.at(b) = std::make_pair(units_.at(a)->getWeapon()->getBuffs().at(b).first - 1, units_.at(a)->getWeapon()->getBuffs().at(b).second);

                units_.at(a)->getWeapon()->setBuffs(tmp);

                std::cout << "LOG : Buff turn : " << units_.at(a)->getWeapon()->getBuffs().at(b).first << "\n";

                if (units_.at(a)->getWeapon()->getBuffs().at(b).first == 0) {

                    std::cout << "LOG : HERE 4\n";

                    if (units_.at(a)->getWeapon()->getBuffs().at(b).second == Weapon::WeaponBuff::CHARGE) {

                        int dmg;
                        dmg = units_.at(a)->getWeapon()->getDamage();
                        units_.at(a)->getWeapon()->setDamage(dmg / 2);

                        units_.at(a)->getWeapon()->getBuffs().at(b).second = Weapon::WeaponBuff::NONE;

                        std::cout << "LOG : Buff turn : " << units_.at(a)->getWeapon()->getBuffs().at(b).first << "\n";
                        std::cout << "LOG : Buff type : " << units_.at(a)->getWeapon()->getBuffs().at(b).second << "\n";
                        std::cout << "LOG : Damage : " << units_.at(a)->getWeapon()->getDamage() << "\n";

                    }

                }
            }
            else {
                // Do nothing
            }
        }

    }

    //for (auto& unit : units_) {

    //    for (auto& buff : unit->getWeapon()->getBuffs()) {

    //        std::cout << "LOG : Buff turn : " << buff.first << "\n";
    //        std::cout << "LOG : Buff type : " << buff.second << "\n";
    //        
    //        if (buff.first != 0) {
    //            
    //            // Update weapon buff turns effect
    //            buff.first--;

    //            if (buff.first == 0) {

    //                if (buff.second == Weapon::WeaponBuff::CHARGE) {

    //                    int dmg;
    //                    dmg = unit->getWeapon()->getDamage();
    //                    unit->getWeapon()->setDamage(dmg / 2);

    //                    buff.second = Weapon::WeaponBuff::NONE;
    //                    buff.first = 10;
    //                    std::cout << "LOG : Buff turn : " << buff.first << "\n";
    //                    std::cout << "LOG : Buff type : " << buff.second << "\n";
    //                    std::cout << "LOG : Damage : " << unit->getWeapon()->getDamage() << "\n";
    //                }
    //                else {
    //                    // Do nothing
    //                }

    //                buff.second = Weapon::WeaponBuff::NONE;
    //            }
    //            else {
    //                 // Do nothing
    //            }
    //        }
    //    }

        //if (!unit->getWeapon()->getBuffs().empty()) {

        //    unit->getWeapon()->getBuffs().at(0).first = 5;
        //    unit->getWeapon()->getBuffs().at(0).second = Weapon::WeaponBuff::NONE;


        //    std::cout << "LOG : Buff turn 2 : " << unit->getWeapon()->getBuffs().at(0).first << "\n";
        //    std::cout << "LOG : Buff type 2 : " << unit->getWeapon()->getBuffs().at(0).second << "\n";

        //}

    //}

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
    std::pair<int, CombatUnit::UnitAffection> affection = { launcher_->getSkills().at(0).getTurns(), CombatUnit::UnitAffection::STUNNED};

    std::vector<std::pair<int, Weapon::WeaponBuff>> tmp_buff = launcher_->getWeapon()->getBuffs();
    tmp_buff.push_back(std::make_pair(launcher_->getSkills().at(0).getTurns(), Weapon::WeaponBuff::CHARGE));
    
    int dmg;

    switch (launcher_->getSkills().at(0).getType()) {

    case Skills::SkillType::STUN:

        receiver_->setAffection(affection);
        launcher_->getSkills().at(0).setState(Skills::SkillState::LOADING);

        std::cout << "LOG : GAME MOTOR | COMBAT SYSTEM | INFO : Unit " << launcher_->getId() << " stunned unit " << receiver_->getId() << "\n";

        break;

    case Skills::SkillType::CHARGE:

        dmg = launcher_->getWeapon()->getDamage();

        // Push back a new buff is empty
        //if (launcher_->getWeapon()->getBuffs().empty()) {

            launcher_->getWeapon()->setBuffs(tmp_buff);
        //}
        // Reset buff if not empty
        //else {
         //   launcher_->getWeapon()->getBuffs().at(0).first = buff.first;
        //    launcher_->getWeapon()->getBuffs().at(0).second = buff.second;
        //}
        
        launcher_->getWeapon()->setDamage(dmg * 2);

        std::cout << "LOG : Enchanded Damage : " << launcher_->getWeapon()->getDamage() << "\n";
       
        std::cout << "LOG : GAME MOTOR | COMBAT SYSTEM | INFO : Unit " << launcher_->getId() << " enchanced its weapon : " << launcher_->getWeapon()->getType() << " (0:SWORD/1:AXE) with buff : " << launcher_->getWeapon()->getBuffs().at(0).second << " (0:CHARGE)\n";
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
