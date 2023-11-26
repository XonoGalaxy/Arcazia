#pragma once
/**

    \file       Sword.h
    \brief      Declaration of Sword class
    \copyright  © Copyright XONO GALAXY - 2023 - All rights reserved

    Reproduction, modification and/or use of this document without express written permission of XONO GALAXY is prohibited
    © Copyright XONO GALAXY - 2023
    All rights reserved - XONO GALAXY Proprietary Data.

 **/


#include "Weapon.h"
class Sword :
    public Weapon
{
public:
    /****************************************************************************/
    /** \name       Types aliases
    **/ /** @{ ******************************************************************/



    /** @}*/ /*******************************************************************/
    /** \name       Constructors, destructor
    **/ /** @{ ******************************************************************/

    /// \brief      Default constructor
    Sword();

    /// \brief      Copy constructor
    Sword(const Sword& rhs_) = delete;

    /// \brief      Move constructor
    Sword(Sword&& rhs_) = delete;

    /// \brief      Assign constructor
    //Sword();

    /// \brief      Destructor
    ~Sword();

    /** @}*/ /*******************************************************************/
    /** \name       Operators
    **/ /** @{ ******************************************************************/

    /// \brief      Copy operator, use default implementation
    Sword& operator=(const Sword& rhs_) = delete;

    /// \brief      Move operator, use default implementation
    Sword& operator=(Sword&& rhs_) = delete;

    /** @}*/ /*******************************************************************/
    /** \name       Getters, Setters
    **/ /** @{ ******************************************************************/


    /** @}*/ /*******************************************************************/
    /** \name       Methods, Functions
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

