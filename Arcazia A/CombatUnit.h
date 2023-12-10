#pragma once
/**

    \file       CombatUnit.h
    \brief      Declaration of CombatUnit class
    \copyright  © Copyright XONO GALAXY - 2023 - All rights reserved

    Reproduction, modification and/or use of this document without express written permission of XONO GALAXY is prohibited
    © Copyright XONO GALAXY - 2023
    All rights reserved - XONO GALAXY Proprietary Data.

 **/

#include <vector>
#include <iostream>

#include "Weapon.h"
#include "Skills.h"

class CombatUnit
{
public:
    /****************************************************************************/
    /** \name       Types aliases
    **/ /** @{ ******************************************************************/

    enum UnitState { ALIVE = 0, DEAD = 1 };
    enum UnitAffection { NONE = 0, STUNNED = 1, POISONED = 2 };
    enum UnitType { KNIGHT = 0, ORC = 1 };

    /** @}*/ /*******************************************************************/
    /** \name       Constructors, destructor
    **/ /** @{ ******************************************************************/

    /// \brief      Default constructor
    CombatUnit();

    /// \brief      Copy constructor
    //CombatUnit(const CombatUnit& rhs_) = delete;

    /// \brief      Move constructor
    //CombatUnit(CombatUnit&& rhs_) = delete;

    /// \brief      Assign constructor
    CombatUnit(int m_life, int m_shield, UnitState m_state);

    /// \brief      Destructor
    ~CombatUnit();

    /** @}*/ /*******************************************************************/
    /** \name       Operators
    **/ /** @{ ******************************************************************/

    /// \brief      Copy operator, use default implementation
    //CombatUnit& operator=(const CombatUnit& rhs_) = delete;

    /// \brief      Move operator, use default implementation
    //CombatUnit& operator=(CombatUnit&& rhs_) = delete;

    /** @}*/ /*******************************************************************/
    /** \name       Getters, Setters
    **/ /** @{ ******************************************************************/

    /// \brief      Getter : m_life
    int             getLife() const;

    int             getShield() const;

    Weapon*         getWeapon() const;

    UnitState       getState() const;

    UnitType        getType() const;

    std::vector<Skills>                         getSkills() const;

    std::pair<int, UnitAffection>  getAffection() const;

    int             getId() const;


    /// \brief      Setter : m_life
    void            setLife(int life_);

    void            setShield(int shield_);

    void            setWeapon(Weapon* weapon_);

    void            setState(UnitState state_);

    void            setType(UnitType type_);

    void            setSkills(Skills skill_);

    void            setAffection(std::pair<int,UnitAffection> affection_);

    void            setId(int id_);


    /** @}*/ /*******************************************************************/
    /** \name       Methods, Functions
    **/ /** @{ ******************************************************************/

    void            showStats();

protected:
    /** @}*/ /*******************************************************************/
    /** \name       Protected Methods, Functions
    **/ /** @{ ******************************************************************/

    /** @}*/ /*******************************************************************/
    /** \name       Protected Data members
    **/ /** @{ ******************************************************************/

    /// \brief      Unit identification umber
    int             m_id;

    /// \brief      Life point
    int             m_life;

    /// \brief      Shield point
    int             m_shield;

    /// \brief      Weapon
    Weapon*         m_weapon;

    /// \brief      Combat unit state
    UnitState       m_state;

    /// \brief      Combat unit type
    UnitType        m_type;

    /// \brief                     Combat unit skills
    std::vector<Skills>            m_skills;

    /// \brief                     Combat unit affection associated with number turns that effect lasts
    std::pair<int,UnitAffection>   m_affection;

private:
    /** @}*/ /*******************************************************************/
    /** \name       Private Methods, Functions
    **/ /** @{ ******************************************************************/


    /** @}*/ /*******************************************************************/
    /** \name       Private Data members
    **/ /** @{ ******************************************************************/

    /** @} **/
};

