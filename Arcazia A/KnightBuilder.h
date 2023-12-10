#pragma once
/**

    \file       KnightBuilder.h
    \brief      Declaration of KnightBuilder class
    \copyright  © Copyright XONO GALAXY - 2023 - All rights reserved

    Reproduction, modification and/or use of this document without express written permission of XONO GALAXY is prohibited
    © Copyright XONO GALAXY - 2023
    All rights reserved - XONO GALAXY Proprietary Data.

 **/

#include "UnitBuilder.h"
#include "Knight.h"

class KnightBuilder :
    public UnitBuilder
{
public:
    /****************************************************************************/
    /** \name       Types aliases
    **/ /** @{ ******************************************************************/

    /** @}*/ /*******************************************************************/
    /** \name       Constructors, destructor
    **/ /** @{ ******************************************************************/

    /// \brief      Default constructor
    KnightBuilder();

    /// \brief      Copy constructor
    //KnightBuilder(const KnightBuilder& rhs_) = delete;

    /// \brief      Move constructor
    //KnightBuilder(KnightBuilder&& rhs_) = delete;

    /// \brief      Assign constructor
    //KnightBuilder();

    /// \brief      Destructor
    ~KnightBuilder();

    /** @}*/ /*******************************************************************/
    /** \name       Operators
    **/ /** @{ ******************************************************************/

    /// \brief      Copy operator, use default implementation
    //KnightBuilder& operator=(const KnightBuilder& rhs_) = delete;

    /// \brief      Move operator, use default implementation
    //KnightBuilder& operator=(KnightBuilder&& rhs_) = delete;

    /** @}*/ /*******************************************************************/
    /** \name       Getters, Setters
    **/ /** @{ ******************************************************************/


    /** @}*/ /*******************************************************************/
    /** \name       Methods, Functions
    **/ /** @{ ******************************************************************/

    Knight*         getKnight();

protected:
    /** @}*/ /*******************************************************************/
    /** \name       Protected Methods, Functions
    **/ /** @{ ******************************************************************/

    /// \brief      Reset builder instance
    void            reset();

    /// \brief      Equip weapon on combat Unit
    void            setWeapon(Weapon* w_);

    /// \brief      Equip skills on combat unit
    void            setSkills(Skills skill_);

    /// \brief      Set unit life point
    void            setLifePoint(int life_);

    /// \brief      Set unit shield point
    void            setShieldPoint(int shield_);

    /// \brief      Set unit id 
    void            setId(int id_);


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

    /// \brief      Knight  unit to equip
    Knight*         m_knight;

    /** @} **/
};

