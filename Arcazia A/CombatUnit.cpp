/**

    \file       CombatUnit.cpp
    \brief      Implementation of CombatUnit class
    \copyright  © Copyright XONO GALAXY - 2023 - All rights reserved

    Reproduction, modification and/or use of this document without express written permission of XONO GALAXY is prohibited
    © Copyright XONO GALAXY - 2023
    All rights reserved - XONO GALAXY Proprietary Data.

 **/

#include "CombatUnit.h"

CombatUnit::CombatUnit()
{
    m_life = 0;
    m_shield = 0;
    m_state = ALIVE;
}

CombatUnit::CombatUnit(int life_, int shield_, UnitState state_)
{
    m_life      = life_;
    m_shield    = shield_;
    m_state     = state_;
}

CombatUnit::~CombatUnit()
{
}

int CombatUnit::getLife() const
{
    return m_life;
}

int CombatUnit::getShield() const
{
    return m_shield;
}

Weapon* CombatUnit::getWeapon() const
{
    return m_weapon;
}

CombatUnit::UnitState CombatUnit::getState() const
{
    return m_state;
}

CombatUnit::UnitType CombatUnit::getType() const
{
    return m_type;
}

std::vector<Skills> CombatUnit::getSkills() const
{
    return m_skills;
}

std::pair<int,CombatUnit::UnitAffection> CombatUnit::getAffection() const
{
    return m_affection;
}

int CombatUnit::getId() const
{
    return m_id;
}

void CombatUnit::setLife(int life_)
{
    m_life = life_;
}

void CombatUnit::setShield(int shield_)
{
    m_shield = shield_;
}

void CombatUnit::setWeapon(Weapon* weapon_)
{
    m_weapon = weapon_;
}

void CombatUnit::setState(UnitState state_)
{
    m_state = state_;
}

void CombatUnit::setType(UnitType type_)
{
    m_type = type_;
}

void CombatUnit::setSkills(Skills skill_)
{
    m_skills.push_back(skill_);
}

void CombatUnit::setAffection(std::pair<int, UnitAffection> affection_)
{
    m_affection = affection_;
}

void CombatUnit::setId(int id_)
{
    m_id = id_;
}

void CombatUnit::showStats()
{
    std::cout << "LOG : GAME INTERFACE |         _______________________________________________________________\n";
    std::cout << "LOG : GAME INTERFACE |        |           |  Unit " << this->getId() << " statistics          \n";
    std::cout << "LOG : GAME INTERFACE |        |___________|___________________________________________________\n";
    std::cout << "LOG : GAME INTERFACE |        | Type      |   " << this->getType() << "   (0:KNIGHT/1:ORC)    \n";
    std::cout << "LOG : GAME INTERFACE |        | Life      |   " << this->getLife() << "                       \n";
    std::cout << "LOG : GAME INTERFACE |        | Shield    |   " << this->getShield() << "                     \n";
    std::cout << "LOG : GAME INTERFACE |        | Skill     |   " << this->getSkills().at(0).getType() << "     \n";
    std::cout << "LOG : GAME INTERFACE |        |___________|___________________________________________________\n";
}
