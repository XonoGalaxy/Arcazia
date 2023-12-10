#pragma once
/**

    \file       GameInterface.h
    \brief      Declaration of GameInterface class
    \copyright  © Copyright XONO GALAXY - 2023 - All rights reserved

    Reproduction, modification and/or use of this document without express written permission of XONO GALAXY is prohibited
    © Copyright XONO GALAXY - 2023
    All rights reserved - XONO GALAXY Proprietary Data.

 **/

#include "CombatProtocol1v1.h"
#include "CombatUnit.h"

class GameInterface
{
public:
    /****************************************************************************/
    /** \name       Types aliases
    **/ /** @{ ******************************************************************/

    enum CommandType { LAUNCH_COMBAT = 0, DISPLAY_UNITS_STATS = 1 };
    enum GameState { STARTED = 0, FINISHED = 1 };

    /** @}*/ /*******************************************************************/
    /** \name       Constructors, destructor
    **/ /** @{ ******************************************************************/

    /// \brief      Default constructor
    GameInterface();

    /// \brief      Copy constructor
    //CombatUnit(const CombatUnit& rhs_) = delete;

    /// \brief      Move constructor
    //CombatUnit(CombatUnit&& rhs_) = delete;

    /// \brief      Assign constructor
    GameInterface(std::vector<CombatUnit*> units_, CombatProtocol1v1* protocol_);

    /// \brief      Destructor
    ~GameInterface();

    /** @}*/ /*******************************************************************/
    /** \name       Operators
    **/ /** @{ ******************************************************************/

    /** @}*/ /*******************************************************************/
    /** \name       Getters, Setters
    **/ /** @{ ******************************************************************/

    GameState       getState();

    void            setState(GameState state_);


    /** @}*/ /*******************************************************************/
    /** \name       Methods, Functions
    **/ /** @{ ******************************************************************/

    void	        displayMenu();

    void 	        executeCommand(CommandType command_);


protected:
    /** @}*/ /*******************************************************************/
    /** \name       Protected Methods, Functions
    **/ /** @{ ******************************************************************/

    /** @}*/ /*******************************************************************/
    /** \name       Protected Data members
    **/ /** @{ ******************************************************************/
    
    CombatProtocol1v1*          m_protocol;

    std::vector<CombatUnit*>    m_units;

    GameState                   m_state;


private:
    /** @}*/ /*******************************************************************/
    /** \name       Private Methods, Functions
    **/ /** @{ ******************************************************************/


    /** @}*/ /*******************************************************************/
    /** \name       Private Data members
    **/ /** @{ ******************************************************************/

    /** @} **/
};

