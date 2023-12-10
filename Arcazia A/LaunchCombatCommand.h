#pragma once
/**

	\file       LaunchCombatCommand.h
	\brief      Implementation of LaunchCombatCommand class
	\copyright  © Copyright XONO GALAXY - 2023 - All rights reserved

	Reproduction, modification and/or use of this document without express written permission of XONO GALAXY is prohibited
	© Copyright XONO GALAXY - 2023
	All rights reserved - XONO GALAXY Proprietary Data.

 **/
#include "Command.h"
class LaunchCombatCommand :
    public Command
{
public:
    /****************************************************************************/
    /** \name       Types aliases
    **/ /** @{ ******************************************************************/


    /** @}*/ /*******************************************************************/
    /** \name       Constructors, destructor
    **/ /** @{ ******************************************************************/

    /// \brief      Assign constructor
    LaunchCombatCommand(std::vector<CombatUnit*> units_, GameInterface* interface_);

    /// \brief      Destructor
    ~LaunchCombatCommand();

    /** @}*/ /*******************************************************************/
    /** \name       Getters, Setters
    **/ /** @{ ******************************************************************/


    /** @}*/ /*******************************************************************/
    /** \name       Methods, Functions
    **/ /** @{ ******************************************************************/

    void        execute();

    void        show();

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

