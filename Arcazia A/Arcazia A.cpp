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

int main() {
    std::cout << "WELCOME TO ARCAZIA\n";

    std::cout << "LOG : GAME MOTOR | COMBAT UNIT SYSTEM | INFO : Configuration\n";

    BuildManager* bm = new BuildManager();
    KnightBuilder* kb = new KnightBuilder();
    OrcBuilder* ob = new OrcBuilder();

    std::cout << "LOG : GAME MOTOR | COMBAT UNIT SYSTEM | INFO : Construction\n";
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

    Knight* unit01 = kb->getKnight();
    Orc* unit02 = ob->getOrc();

    std::cout << "LOG : GAME MOTOR | COMBAT UNIT SYSTEM | DEBUG : Unit 01 type : " << unit01->getType() << "\n";
    std::cout << "LOG : GAME MOTOR | COMBAT UNIT SYSTEM | DEBUG : Unit 01 life point : " << unit01->getLife() << "\n";

    std::cout << "LOG : GAME MOTOR | COMBAT UNIT SYSTEM | DEBUG : Unit 02 type : " << unit02->getType() << "\n";
    std::cout << "LOG : GAME MOTOR | COMBAT UNIT SYSTEM | DEBUG : Unit 02 weapon type : " << unit02->getWeapon().getType() << "\n";
    std::cout << "LOG : GAME MOTOR | COMBAT UNIT SYSTEM | DEBUG : Unit 02 weapon damage : " << unit02->getWeapon().getDamage() << "\n";

    std::cout << "LOG : GAME MOTOR | INTERFACE SYSTEM | INFO : Choose 2 combat units \n";

    //std::cout << "LOG : GAME MOTOR | COMBAT UNIT SYSTEM | INFO : System initialization\n";
    //std::cout << "LOG : GAME MOTOR | COMBAT UNIT SYSTEM | INFO : Configuration loading\n";
    //std::cout << "LOG : GAME MOTOR | COMBAT UNIT SYSTEM | INFO : Construction\n";
    //std::cout << "LOG : GAME MOTOR | COMBAT UNIT SYSTEM | INFO : Combat unit 01 ready : Knight\n";
    //std::cout << "LOG : GAME MOTOR | COMBAT UNIT SYSTEM | INFO : Combat unit 02 ready : Orc\n";
}

