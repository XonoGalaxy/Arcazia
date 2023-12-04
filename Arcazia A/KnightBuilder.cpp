/**

	\file       KnightBuilder.cpp
	\brief      Implementation of KnightBuilder class
	\copyright  © Copyright XONO GALAXY - 2023 - All rights reserved

	Reproduction, modification and/or use of this document without express written permission of XONO GALAXY is prohibited
	© Copyright XONO GALAXY - 2023
	All rights reserved - XONO GALAXY Proprietary Data.

 **/

#include "KnightBuilder.h"

KnightBuilder::KnightBuilder()
{
	this->reset();
}

KnightBuilder::~KnightBuilder()
{
}

void KnightBuilder::reset()
{
	this->m_knight = new Knight();
}

void KnightBuilder::setWeapon(Weapon w_)
{
	m_knight->setWeapon(w_);
}

void KnightBuilder::setSkills(Skills skill_)
{
	m_knight->setSkills(skill_);
}

void KnightBuilder::setLifePoint(int life_)
{
	m_knight->setLife(life_);
}

void KnightBuilder::setShieldPoint(int shield_)
{
	m_knight->setShield(shield_);
}

void KnightBuilder::setId(int id_)
{
	m_knight->setId(id_);
}

Knight* KnightBuilder::getKnight()
{
	return m_knight;
}

