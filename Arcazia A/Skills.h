#pragma once

/**

    \file       Skills.h
    \brief      Declaration of Skills class
    \copyright  © Copyright XONO GALAXY - 2023 - All rights reserved

    Reproduction, modification and/or use of this document without express written permission of XONO GALAXY is prohibited
    © Copyright XONO GALAXY - 2023
    All rights reserved - XONO GALAXY Proprietary Data.

 **/


class Skills
{
public:
    /****************************************************************************/
    /** \name       Types aliases
    **/ /** @{ ******************************************************************/

    enum SkillState { READY = 0, LOADING = 1 };

    /** @}*/ /*******************************************************************/
    /** \name       Constructors, destructor
    **/ /** @{ ******************************************************************/

    /// \brief      Default constructor
    Skills();

    /// \brief      Copy constructor
    //Skills(const Skills& rhs_) = delete;

    /// \brief      Move constructor
    //Skills(Skills&& rhs_) = delete;

    /// \brief      Assign constructor
    Skills(int success_, int loading_, SkillState state_);

    /// \brief      Destructor
    ~Skills();

    /** @}*/ /*******************************************************************/
    /** \name       Operators
    **/ /** @{ ******************************************************************/

    /// \brief      Copy operator, use default implementation
    //Skills& operator=(const Skills& rhs_) = delete;

    /// \brief      Move operator, use default implementation
    //Skills& operator=(Skills&& rhs_) = delete;

    /** @}*/ /*******************************************************************/
    /** \name       Getters, Setters
    **/ /** @{ ******************************************************************/


    /** @}*/ /*******************************************************************/
    /** \name       Methods, Functions
    **/ /** @{ ******************************************************************/

protected:
    /** @}*/ /*******************************************************************/
    /** \name       Protected Methods, Functions
    **/ /** @{ ******************************************************************/


    /** @}*/ /*******************************************************************/
    /** \name       Protected Data members
    **/ /** @{ ******************************************************************/

    /// \brief      Skill success rate
    int             m_success;

    /// \brief      Skill loading time
    int             m_loading;

    /// \brief      Skill state
    SkillState      m_state;


private:
    /** @}*/ /*******************************************************************/
    /** \name       Private Methods, Functions
    **/ /** @{ ******************************************************************/


    /** @}*/ /*******************************************************************/
    /** \name       Private Data members
    **/ /** @{ ******************************************************************/

    /** @} **/
};

