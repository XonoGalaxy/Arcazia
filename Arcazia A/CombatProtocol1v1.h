#pragma once
/**

    \file       CombatProtocol1v1.h
    \brief      Declaration of CombatProtocol1v1 class
    \copyright  © Copyright XONO GALAXY - 2023 - All rights reserved

    Reproduction, modification and/or use of this document without express written permission of XONO GALAXY is prohibited
    © Copyright XONO GALAXY - 2023
    All rights reserved - XONO GALAXY Proprietary Data.

 **/

#include "CombatUnit.h"
#include "ActionHandler.h"

class CombatProtocol1v1
{
public:
    /****************************************************************************/
    /** \name       Types aliases
    **/ /** @{ ******************************************************************/

    enum CombatState { STARTED = 0, ENDED = 1 };

    /** @}*/ /*******************************************************************/
    /** \name       Constructors, destructor
    **/ /** @{ ******************************************************************/

    /// \brief      Default constructor
    CombatProtocol1v1();

    /// \brief      Copy constructor
    //CombatProtocol1v1(const CombatProtocol1v1& rhs_) = delete;

    /// \brief      Move constructor
    //CombatProtocol1v1(CombatProtocol1v1&& rhs_) = delete;

    /// \brief      Assign constructor
    //CombatProtocol1v1();

    /// \brief      Destructor
    ~CombatProtocol1v1();

    /** @}*/ /*******************************************************************/
    /** \name       Operators
    **/ /** @{ ******************************************************************/

    /// \brief      Copy operator, use default implementation
    //CombatProtocol1v1& operator=(const CombatProtocol1v1& rhs_) = delete;

    /// \brief      Move operator, use default implementation
    //CombatProtocol1v1& operator=(CombatProtocol1v1&& rhs_) = delete;

    /** @}*/ /*******************************************************************/
    /** \name       Getters, Setters
    **/ /** @{ ******************************************************************/

    std::vector<CombatUnit*>        getOpponents();

    void                setOpponent(CombatUnit* opponent_);


    /** @}*/ /*******************************************************************/
    /** \name       Methods, Functions
    **/ /** @{ ******************************************************************/

    void                launchCombatProtocol1v1();


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

    /// \brief      Number of turns made by the protocol
    int             m_turns;

    /// \brief               Opponent
    std::vector<CombatUnit*> m_opponents;

    /// \brief      Second oppenent of 1v1 combat protocol
    ActionHandler*  m_actionHandler;

    /// \brief      Combat protocol state
    CombatState     m_state;


    /** @} **/
};

