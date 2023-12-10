/**

    \file       Weapon.h
    \brief      Implementation of Weapon class
    \copyright  © Copyright XONO GALAXY - 2023 - All rights reserved

    Reproduction, modification and/or use of this document without express written permission of XONO GALAXY is prohibited
    © Copyright XONO GALAXY - 2023
    All rights reserved - XONO GALAXY Proprietary Data.

 **/

#include "Weapon.h"

Weapon::Weapon()
{
    m_damage = 0;
}

Weapon::Weapon(int damage_, Weapon::WeaponType type_)
{
    m_damage = damage_;
    m_type = type_;
}

Weapon::~Weapon()
{
}

/**
    Get weapon damage
**/
int Weapon::getDamage() const
{
    return m_damage;
}

Weapon::WeaponType Weapon::getType() const
{
    return m_type;
}

std::vector<std::pair<int, Weapon::WeaponBuff>> Weapon::getBuffs() const
{
    return m_buffs;
}

/**
    Set weapon damage

    param[in] damage_   : Weapon damage
**/
void Weapon::setDamage(int damage_)
{
    m_damage = damage_;
}

void Weapon::setType(WeaponType type_)
{
    m_type = type_;
}

void Weapon::setBuffs(std::vector<std::pair<int, WeaponBuff>> buff_)
{
    m_buffs = buff_;
}
