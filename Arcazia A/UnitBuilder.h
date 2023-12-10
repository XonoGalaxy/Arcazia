#pragma once
/**

    \file       UnitBuilder.h
    \brief      Declaration of UnitBuilder class
    \copyright  © Copyright XONO GALAXY - 2023 - All rights reserved

    Reproduction, modification and/or use of this document without express written permission of XONO GALAXY is prohibited
    © Copyright XONO GALAXY - 2023
    All rights reserved - XONO GALAXY Proprietary Data.

 **/

#include "Weapon.h"
#include "Skills.h"
#include "CombatUnit.h"

class UnitBuilder
{
public:
    /****************************************************************************/
    /** \name       Types aliases
    **/ /** @{ ******************************************************************/

    /** @}*/ /*******************************************************************/
    /** \name       Constructors, destructor
    **/ /** @{ ******************************************************************/

    /// \brief      Default constructor
    UnitBuilder();

    /// \brief      Copy constructor
    //UnitBuilder(const UnitBuilder& rhs_) = delete;

    /// \brief      Move constructor
    //UnitBuilder(UnitBuilder&& rhs_) = delete;

    /// \brief      Assign constructor
    //UnitBuilder();

    /// \brief      Destructor
    ~UnitBuilder();

    /** @}*/ /*******************************************************************/
    /** \name       Operators
    **/ /** @{ ******************************************************************/

    /// \brief      Copy operator, use default implementation
    //UnitBuilder& operator=(const UnitBuilder& rhs_) = delete;

    /// \brief      Move operator, use default implementation
    //UnitBuilder& operator=(UnitBuilder&& rhs_) = delete;

    /** @}*/ /*******************************************************************/
    /** \name       Getters, Setters
    **/ /** @{ ******************************************************************/


    /** @}*/ /*******************************************************************/
    /** \name       Methods, Functions
    **/ /** @{ ******************************************************************/

    /// \brief      Reset builder instance
    virtual void    reset();

    /// \brief      Equip weapon on combat Unit
    virtual void    setWeapon(Weapon* w_);

    /// \brief      Equip skills on combat unit
    virtual void    setSkills(Skills skills_);

    /// \brief      Set unit life point
    virtual void    setLifePoint(int life_);

    /// \brief      Set unit shield point
    virtual void    setShieldPoint(int shield_);

    /// \brief      Set unit id
    virtual void    setId(int id_);

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
    /** \name       Private Data members
    **/ /** @{ ******************************************************************/

    /** @} **/
};

