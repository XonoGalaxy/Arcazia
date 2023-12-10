/**

    \file       Arcazia.cpp
    \brief      Game entry point
    \copyright  © Copyright XONO GALAXY - 2023 - All rights reserved

    Reproduction, modification and/or use of this document without express written permission of XONO GALAXY is prohibited
    © Copyright XONO GALAXY - 2023
    All rights reserved - XONO GALAXY Proprietary Data.

 **/

#include <iostream>
#include "BuildManager.h"
#include "KnightBuilder.h"
#include "OrcBuilder.h"
#include "CombatProtocol1v1.h"

int main() {

    std::cout << "WELCOME TO ARCAZIA : Alpha version\n";

    std::cout << "LOG : GAME MOTOR | UNIT SYSTEM | INFO : Configuration\n";

    BuildManager* bm = new BuildManager();
    KnightBuilder* kb = new KnightBuilder();
    OrcBuilder* ob = new OrcBuilder();

    std::cout << "LOG : GAME MOTOR | UNIT SYSTEM | INFO : Construction\n";
    for (auto &unit : bm->getUnitsConfig()) {

        switch (unit.type) {

        case CombatUnit::UnitType::KNIGHT:
            bm->constructKnight(kb, unit);
            std::cout << "LOG : GAME INTERFACE | INFO : Unit " << unit.id << " is ready as Knight\n";
            break;

        case CombatUnit::UnitType::ORC:
            bm->constructOrc(ob, unit);
            std::cout << "LOG : GAME INTERFACE | INFO : Unit " << unit.id << " is ready as Orc\n";
            break;
        }
    }

    // Get created units
    Knight* unit01 = kb->getKnight();
    Orc* unit02 = ob->getOrc();

    // Show unit stats
 /* std::cout << "LOG : GAME MOTOR | UNIT SYSTEM | DEBUG : Unit " << unit01->getId() << " type : " << unit01->getType() << "\n";
    std::cout << "LOG : GAME MOTOR | UNIT SYSTEM | DEBUG : Unit " << unit01->getId() << " life point : " << unit01->getLife() << "\n";
    std::cout << "LOG : GAME MOTOR | UNIT SYSTEM | DEBUG : Unit " << unit02->getId() << " type : " << unit02->getType() << "\n";
    std::cout << "LOG : GAME MOTOR | UNIT SYSTEM | DEBUG : Unit " << unit02->getId() << " weapon type : " << unit02->getWeapon().getType() << "\n";
    std::cout << "LOG : GAME MOTOR | UNIT SYSTEM | DEBUG : Unit " << unit02->getId() << " weapon damage : " << unit02->getWeapon().getDamage() << "\n";*/

    // Combat system initialization
    std::vector<CombatUnit*> opponents = { unit01, unit02 };
    CombatProtocol1v1* protocol = new CombatProtocol1v1(opponents);

    // Launch combat
    //std::cout << "LOG : GAME INTERFACE | INFO : Would you like to start a combat ? [Y,N]\n";

    // Start protocol
    protocol->launchCombatProtocol1v1();

    // Show combat stats
    // Show unit stats


}

