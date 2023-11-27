#pragma once
/**

    \file       UnitsConfig.h
    \brief      Declaration of Header UnitsConfig
    \copyright  � Copyright XONO GALAXY - 2023 - All rights reserved

    Reproduction, modification and/or use of this document without express written permission of XONO GALAXY is prohibited
    � Copyright XONO GALAXY - 2023
    All rights reserved - XONO GALAXY Proprietary Data.

 **/

 /**

    When adding units : 
        - Update macro AVAILABLE_UNITS to indicate current units to construct
        - Add hardcoded unit structure
        - Update units units vector UNITS_CONFIG

  **/

#include "CombatUnit.h"
#include "Skills.h"
#include "Weapon.h"
#include "BuildManager.h"

constexpr int AVAILABLE_UNITS = 2; // Available units;

/* List of hardcoded units */
constexpr BuildManager::UnitConfig unit01 = { 1, CombatUnit::UnitType::KNIGHT, 20, 50, Skills::SkillType::CHARGE, Weapon::WeaponType::SWORD };
constexpr BuildManager::UnitConfig unit02 = { 2, CombatUnit::UnitType::ORC, 60, 0, Skills::SkillType::STUN, Weapon::WeaponType::AXE };

/* Hardcoded units vector */
std::vector<BuildManager::UnitConfig> UNITS_CONFIG = { unit01, unit02 };




