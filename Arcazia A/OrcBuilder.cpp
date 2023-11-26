/**

	\file       OrcBuilder.cpp
	\brief      Implementation of OrcBuilder class
	\copyright  © Copyright XONO GALAXY - 2023 - All rights reserved

	Reproduction, modification and/or use of this document without express written permission of XONO GALAXY is prohibited
	© Copyright XONO GALAXY - 2023
	All rights reserved - XONO GALAXY Proprietary Data.

 **/

#include "OrcBuilder.h"

OrcBuilder::OrcBuilder()
{
	this->reset();
}

OrcBuilder::~OrcBuilder()
{
}

void OrcBuilder::reset()
{
	this->m_orc = new Orc();
}

void OrcBuilder::setWeapon(Weapon w_)
{
	m_orc->setWeapon(w_);
}

void OrcBuilder::setSkills(Skills skill_)
{
	m_orc->setSkills(skill_);
}

void OrcBuilder::setLifePoint(int life_)
{
	m_orc->setLife(life_);
}

void OrcBuilder::setShieldPoint(int shield_)
{
	m_orc->setShield(shield_);
}

Orc* OrcBuilder::getOrc()
{
	return m_orc;
}

