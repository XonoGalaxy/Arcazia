/**

    \file       BuildManager.cpp
    \brief      Declaration of BuildManager class
    \copyright  © Copyright XONO GALAXY - 2023 - All rights reserved

    Reproduction, modification and/or use of this document without express written permission of XONO GALAXY is prohibited
    © Copyright XONO GALAXY - 2023
    All rights reserved - XONO GALAXY Proprietary Data.

 **/

#include "BuildManager.h"
#include "UnitsConfig.h"

BuildManager::BuildManager()
{
    //Extract hardcoded units from UnitsConfig.h file
    m_units = UNITS_CONFIG;
    m_nb = AVAILABLE_UNITS;

    std::cout << "LOG : GAME MOTOR | UNIT SYSTEM | INFO : " << AVAILABLE_UNITS << " available units \n";
}

BuildManager::~BuildManager()
{
}

int BuildManager::getNumber()
{
    return m_nb;
}

void BuildManager::setNumber(int nb_)
{
    m_nb = nb_;
}

void BuildManager::setUnitConfig(UnitConfig config_)
{
    m_units.push_back(config_);
}

std::vector<BuildManager::UnitConfig> BuildManager::getUnitsConfig()
{
    return m_units;
}

void BuildManager::constructKnight(UnitBuilder* builder_, UnitConfig config_)
{
    builder_->reset();
    builder_->setLifePoint(config_.life);
    builder_->setShieldPoint(config_.shield);

    switch (config_.skill) {

    case Skills::SkillType::STUN:
        builder_->setSkills(Stun());
        break;

    case Skills::SkillType::CHARGE:
        builder_->setSkills(Charge());
        break;
    }

    switch (config_.weapon) {

    case Weapon::WeaponType::AXE:
        builder_->setWeapon(Axe());
        break;

     case Weapon::WeaponType::SWORD:
        builder_->setWeapon(Sword());
        break;
    }
}

void BuildManager::constructOrc(UnitBuilder* builder_, UnitConfig config_)
{
    builder_->reset();
    builder_->setLifePoint(config_.life);
    builder_->setShieldPoint(config_.shield);

    switch (config_.skill) {

    case Skills::SkillType::STUN:
        builder_->setSkills(Stun());
        break;

    case Skills::SkillType::CHARGE:
        builder_->setSkills(Charge());
        break;
    }

    switch (config_.weapon) {

    case Weapon::WeaponType::AXE:
        builder_->setWeapon(Axe());
        break;

    case Weapon::WeaponType::SWORD:
        builder_->setWeapon(Sword());
        break;
    }
}
