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
#include "Stun.h"
#include "Charge.h"
#include "Sword.h"
#include "Axe.h"

class BuildManager
{
public:
    /****************************************************************************/
    /** \name       Types aliases
    **/ /** @{ ******************************************************************/

    struct UnitConfig {
        int id;
        CombatUnit::UnitType type;
        int life;
        int shield;
        Skills::SkillType skill;
        Weapon::WeaponType weapon;
    };


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

    int             getNumber();

    void            setNumber(int nb_);

    void            setUnitConfig(UnitConfig config_);

    std::vector<UnitConfig>  getUnitsConfig();


    /** @}*/ /*******************************************************************/
    /** \name       Methods, Functions
    **/ /** @{ ******************************************************************/

    /// \brief      Knight build method
    void            constructKnight(UnitBuilder* builder_, UnitConfig config_);

    /// \brief      Orc build method
    void            constructOrc(UnitBuilder* builder_, UnitConfig config_);

    /// \brief      Make units depending on configuration file
    //void          makeUnits(UnitsExtractor* extractor_);


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

    /// \brief      Available units
    int             m_nb;

    /// \brief          Units configuration
    std::vector<UnitConfig>   m_units;

    /** @} **/
};

