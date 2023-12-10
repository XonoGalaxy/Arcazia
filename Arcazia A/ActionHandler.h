#pragma once
/**

    \file       ActionHandler.h
    \brief      Declaration of ActionHandler class
    \copyright  © Copyright XONO GALAXY - 2023 - All rights reserved

    Reproduction, modification and/or use of this document without express written permission of XONO GALAXY is prohibited
    © Copyright XONO GALAXY - 2023
    All rights reserved - XONO GALAXY Proprietary Data.

 **/
#include <random>

#include "Skills.h"
#include "CombatUnit.h"


class ActionHandler
{
public:
    /****************************************************************************/
    /** \name       Types aliases
    **/ /** @{ ******************************************************************/

    enum CombatAction { NO = 0, YES = 1 };
    enum SkillAction { LAUNCHED = 0, FAILED = 1 };

    /** @}*/ /*******************************************************************/
    /** \name       Constructors, destructor
    **/ /** @{ ******************************************************************/

    /// \brief      Default constructor
    ActionHandler();

    /// \brief      Copy constructor
    //ActionHandler(const ActionHandler& rhs_) = delete;

    /// \brief      Move constructor
    //ActionHandler(ActionHandler&& rhs_) = delete;

    /// \brief      Assign constructor
    //ActionHandler();

    /// \brief      Destructor
    ~ActionHandler();

    /** @}*/ /*******************************************************************/
    /** \name       Operators
    **/ /** @{ ******************************************************************/

    /// \brief      Copy operator, use default implementation
    //ActionHandler& operator=(const ActionHandler& rhs_) = delete;

    /// \brief      Move operator, use default implementation
    //ActionHandler& operator=(ActionHandler&& rhs_) = delete;

    /** @}*/ /*******************************************************************/
    /** \name       Getters, Setters
    **/ /** @{ ******************************************************************/


    /** @}*/ /*******************************************************************/
    /** \name       Methods, Functions
    **/ /** @{ ******************************************************************/

    /// \brief          Check if skill action is possible
    CombatAction        checkSkillAction(CombatUnit* unit_);

    /// \brief          Check if basic attack action is possible
    CombatAction        checkBasicAttackAction(CombatUnit* unit_);

    /// \brief                           Check units state
    CombatUnit::UnitState                checkUnitsDeath(std::vector<CombatUnit*> units_);

    /// \brief          Update units state
    void                updateUnitsState(std::vector<CombatUnit*> units_);

    /// \brief          Update units affections effect turns
    void                updateAffections(std::vector<CombatUnit*> units_);

    /// \brief          Update units skills 
    void                updateSkills(std::vector<CombatUnit*> units_);

    void                updateWeaponsBuffs(std::vector<CombatUnit*> units_);

    /// \brief          Unit launch a skill
    SkillAction         launchSkill(CombatUnit* unit_);

    /// \brief          Launcher unit applies skill on receiver unit
    void                applySkill(CombatUnit* launcher_, CombatUnit* receiver_);

    /// \brief          Launcher unit applies basic attack on receiver unit 
    void                applyBasicAttack(CombatUnit* launcher_, CombatUnit* receiver_);

protected:
    /** @}*/ /*******************************************************************/
    /** \name       Protected Methods, Functions
    **/ /** @{ ******************************************************************/


    /** @}*/ /*******************************************************************/
    /** \name       Protected Data members
    **/ /** @{ ******************************************************************/



private:
    /** @}*/ /*******************************************************************/
    /** \name       Private Methods, Functions
    **/ /** @{ ******************************************************************/


    /** @}*/ /*******************************************************************/
    /** \name       Private Data memberss
    **/ /** @{ ******************************************************************/


    /** @} **/
};

