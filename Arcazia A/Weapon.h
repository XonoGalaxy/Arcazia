#pragma once
/**

    \file       Weapon.h
    \brief      Declaration of Weapon class
    \copyright  © Copyright XONO GALAXY - 2023 - All rights reserved

    Reproduction, modification and/or use of this document without express written permission of XONO GALAXY is prohibited
    © Copyright XONO GALAXY - 2023
    All rights reserved - XONO GALAXY Proprietary Data.

 **/


class Weapon
{
public:
    /****************************************************************************/
    /** \name       Types aliases
    **/ /** @{ ******************************************************************/

    enum WeaponType { SWORD = 0, AXE = 1 };

    /** @}*/ /*******************************************************************/
    /** \name       Constructors, destructor
    **/ /** @{ ******************************************************************/

    /// \brief      Default constructor
    Weapon();

    /// \brief      Copy constructor
    //Weapon(const Weapon& rhs_) = delete;

    /// \brief      Move constructor
    //Weapon(Weapon&& rhs_) = delete;

    /// \brief      Assign constructor
    Weapon(int damage_, WeaponType type_);

    /// \brief      Destructor
    ~Weapon();

    /** @}*/ /*******************************************************************/
    /** \name       Operators
    **/ /** @{ ******************************************************************/

    /// \brief      Copy operator, use default implementation
    //Weapon& operator=(const Weapon& rhs_);

    /// \brief      Move operator, use default implementation
    //Weapon& operator=(Weapon&& rhs_) = delete;

    /** @}*/ /*******************************************************************/
    /** \name       Getters, Setters
    **/ /** @{ ******************************************************************/

    /// \brief      Getter : m_damage
    int             getDamage() const;

    WeaponType      getType() const;

    /// \brief      Setter : m_damage
    void            setDamage(int damage_);

    void            setType(WeaponType type_);


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

    /// \brief      Weapon damage
    int             m_damage; 

    /// \brief      Weapon type
    WeaponType      m_type;

private:
    /** @}*/ /*******************************************************************/
    /** \name       Private Methods, Functions
    **/ /** @{ ******************************************************************/


    /** @}*/ /*******************************************************************/
    /** \name       Private Data members
    **/ /** @{ ******************************************************************/


    /** @} **/
};

