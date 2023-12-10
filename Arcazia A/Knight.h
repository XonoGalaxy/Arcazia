#pragma once
/**

    \file       Knight.h
    \brief      Declaration of Knight class
    \copyright  © Copyright XONO GALAXY - 2023 - All rights reserved

    Reproduction, modification and/or use of this document without express written permission of XONO GALAXY is prohibited
    © Copyright XONO GALAXY - 2023
    All rights reserved - XONO GALAXY Proprietary Data.

 **/

#include "CombatUnit.h"

class Knight :
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
    Knight();

    /// \brief      Copy constructor
    //Knight(const Knight& rhs_) = delete;

    /// \brief      Move constructor
    //Knight(Knight&& rhs_) = delete;

    /// \brief      Assign constructor
    //Knight();

    /// \brief      Destructor
    ~Knight();

    /** @}*/ /*******************************************************************/
    /** \name       Operators
    **/ /** @{ ******************************************************************/

    /// \brief      Copy operator, use default implementation
    //Knight& operator=(const Knight& rhs_) = delete;

    /// \brief      Move operator, use default implementation
    //Knight& operator=(Knight&& rhs_) = delete;

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


