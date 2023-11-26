/**

    \file       BuildManager.cpp
    \brief      Declaration of BuildManager class
    \copyright  © Copyright XONO GALAXY - 2023 - All rights reserved

    Reproduction, modification and/or use of this document without express written permission of XONO GALAXY is prohibited
    © Copyright XONO GALAXY - 2023
    All rights reserved - XONO GALAXY Proprietary Data.

 **/

#include "BuildManager.h"

BuildManager::BuildManager()
{
}

BuildManager::~BuildManager()
{
}

void BuildManager::constructKnight(UnitBuilder* builder_, int config_)
{
    builder_->reset();
    builder_->setLifePoint(config_);
    builder_->setShieldPoint(config_);
    //builder_.setSkills();
    //builder_.setWeapon();
}

void BuildManager::constructOrc(UnitBuilder* builder_, int config_)
{
    builder_->reset();
    builder_->setLifePoint(config_);
    builder_->setShieldPoint(config_);
    //builder_.setSkills(config_);
    //builder_.setWeapon(config_);
}
