#pragma once
/**

    \file       CombatManager.h
    \brief      Declaration of CombatManager class
    \copyright  © Copyright XONO GALAXY - 2023 - All rights reserved

    Reproduction, modification and/or use of this document without express written permission of XONO GALAXY is prohibited
    © Copyright XONO GALAXY - 2023
    All rights reserved - XONO GALAXY Proprietary Data.

 **/

#include "CombatUnit.h"

class CombatManager
{
public:
    /****************************************************************************/
    /** \name       Types aliases
    **/ /** @{ ******************************************************************/

    enum CombatAction { NO = 0, YES = 1 };

    /** @}*/ /*******************************************************************/
    /** \name       Constructors, destructor
    **/ /** @{ ******************************************************************/

    /// \brief      Default constructor
    CombatManager();

    /// \brief      Copy constructor
    //CombatManager(const CombatManager& rhs_) = delete;

    /// \brief      Move constructor
    //CombatManager(CombatManager&& rhs_) = delete;

    /// \brief      Assign constructor
    //CombatManager();

    /// \brief      Destructor
    ~CombatManager();

    /** @}*/ /*******************************************************************/
    /** \name       Operators
    **/ /** @{ ******************************************************************/

    /// \brief      Copy operator, use default implementation
    //CombatManager& operator=(const CombatManager& rhs_) = delete;

    /// \brief      Move operator, use default implementation
    //CombatManager& operator=(CombatManager&& rhs_) = delete;

    /** @}*/ /*******************************************************************/
    /** \name       Getters, Setters
    **/ /** @{ ******************************************************************/

    CombatUnit*         getOpponent1();

    CombatUnit*         getOpponent2();

    void                setOpponent1(CombatUnit* opponent_);

    void                setOpponent2(CombatUnit* opponent_);

    /** @}*/ /*******************************************************************/
    /** \name       Methods, Functions
    **/ /** @{ ******************************************************************/

    CombatAction        checkSkillAction(Skills skill_);

    CombatAction        checkBasicAttackAction(CombatUnit* unit_);


protected:
    /** @}*/ /*******************************************************************/
    /** \name       Protected Methods, Functions
    **/ /** @{ ******************************************************************/               


    /** @}*/ /*******************************************************************/
    /** \name       Protected Data members
    **/ /** @{ ******************************************************************/

    /// \brief      Number of turns made by the protocol
    int             m_turns;

    /// \brief      First oppoenent of 1v1 combat protocol 
    CombatUnit*     m_opponent1;

    /// \brief      Second oppenent of 1v1 combat protocol 
    CombatUnit*     m_opponent2;


private:
    /** @}*/ /*******************************************************************/
    /** \name       Private Methods, Functions
    **/ /** @{ ******************************************************************/


    /** @}*/ /*******************************************************************/
    /** \name       Private Data memberss
    **/ /** @{ ******************************************************************/


    /** @} **/
};

