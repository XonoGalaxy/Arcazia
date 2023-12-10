#pragma once
/**

    \file       Orc.h
    \brief      Declaration of Orc class
    \copyright  © Copyright XONO GALAXY - 2023 - All rights reserved

    Reproduction, modification and/or use of this document without express written permission of XONO GALAXY is prohibited
    © Copyright XONO GALAXY - 2023
    All rights reserved - XONO GALAXY Proprietary Data.

 **/

#include "CombatUnit.h"
class Orc :
    public CombatUnit
{
public:
    /****************************************************************************/
    /** \name       Types aliases
    **/ /** @{ ******************************************************************/



    /** @}*/ /*******************************************************************/
    /** \name       Constructors, destructor
    **/ /** @{ ******************************************************************/

    /// \brief      Default constructor
    Orc();

    /// \brief      Copy constructor
    //Orc(const Orc& rhs_) = delete;

    /// \brief      Move constructor
    //Orc(Orc&& rhs_) = delete;

    /// \brief      Assign constructor
    //Orc();

    /// \brief      Destructor
    ~Orc();

    /** @}*/ /*******************************************************************/
    /** \name       Operators
    **/ /** @{ ******************************************************************/

    /// \brief      Copy operator, use default implementation
    //Orc& operator=(const Orc& rhs_) = delete;

    /// \brief      Move operator, use default implementation
    //Orc& operator=(Orc&& rhs_) = delete;

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

