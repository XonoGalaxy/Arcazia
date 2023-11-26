#pragma once
/**

    \file       BuildManager.h
    \brief      Declaration of BuildManager class
    \copyright  © Copyright XONO GALAXY - 2023 - All rights reserved

    Reproduction, modification and/or use of this document without express written permission of XONO GALAXY is prohibited
    © Copyright XONO GALAXY - 2023
    All rights reserved - XONO GALAXY Proprietary Data.

 **/

#include "UnitBuilder.h"

class BuildManager
{
public:
    /****************************************************************************/
    /** \name       Types aliases
    **/ /** @{ ******************************************************************/

    /** @}*/ /*******************************************************************/
    /** \name       Constructors, destructor
    **/ /** @{ ******************************************************************/

    /// \brief      Default constructor
    BuildManager();

    /// \brief      Copy constructor
    //BuildManager(const BuildManager& rhs_) = delete;

    /// \brief      Move constructor
    //BuildManager(BuildManager&& rhs_) = delete;

    /// \brief      Assign constructor
    //BuildManager();

    /// \brief      Destructor
    ~BuildManager();

    /** @}*/ /*******************************************************************/
    /** \name       Operators
    **/ /** @{ ******************************************************************/

    /// \brief      Copy operator, use default implementation
    //BuildManager& operator=(const BuildManager& rhs_) = delete;

    /// \brief      Move operator, use default implementation
    //BuildManager& operator=(BuildManager&& rhs_) = delete;

    /** @}*/ /*******************************************************************/
    /** \name       Getters, Setters
    **/ /** @{ ******************************************************************/


    /** @}*/ /*******************************************************************/
    /** \name       Methods, Functions
    **/ /** @{ ******************************************************************/

    /// \brief      Knight build method depending on configuration
    void            constructKnight(UnitBuilder* builder_, int config_);

    /// \brief      Orc build method depending on configuration
    void            constructOrc(UnitBuilder* builder_, int config_);


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

    /// \brief      Builder configurations
    int             configuration;

    /** @} **/
};

