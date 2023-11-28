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

    // Faire un vecteur d'unité construit et prêt pour le combat
    // CombatProtocol1v1 combat01;
    // combat01->m_opponent01 = kb->getKnight();
    // combat01->m_opponent02 = ob->getKnight();
    Knight* unit01 = kb->getKnight();
    Orc* unit02 = ob->getOrc();

    // Afficher un tableau de statistique pour chaque unité de combat prêt
    std::cout << "LOG : GAME MOTOR | UNIT SYSTEM | DEBUG : Unit " << bm->getUnitsConfig()[0].id << " type : " << unit01->getType() << "\n";
    std::cout << "LOG : GAME MOTOR | UNIT SYSTEM | DEBUG : Unit " << bm->getUnitsConfig()[0].id << " life point : " << unit01->getLife() << "\n";
    std::cout << "LOG : GAME MOTOR | UNIT SYSTEM | DEBUG : Unit " << bm->getUnitsConfig()[1].id << " type : " << unit02->getType() << "\n";
    std::cout << "LOG : GAME MOTOR | UNIT SYSTEM | DEBUG : Unit " << bm->getUnitsConfig()[1].id << " weapon type : " << unit02->getWeapon().getType() << "\n";
    std::cout << "LOG : GAME MOTOR | UNIT SYSTEM | DEBUG : Unit " << bm->getUnitsConfig()[1].id << " weapon damage : " << unit02->getWeapon().getDamage() << "\n";

    // Le joueur lance un combat en choisissant 2 unités de combat
    std::cout << "LOG : GAME INTERFACE | INFO : Would you like to start a combat ? \n";
    std::cout << "LOG : GAME INTERFACE | INFO : Choose 2 combat units \n";

    // Lancement du système de combat
    std::cout << "LOG : GAME MOTOR | COMBAT SYSTEM | INFO : Combat initialization \n";
    std::cout << "LOG : GAME MOTOR | COMBAT SYSTEM | INFO : Combat configuration \n";
    std::cout << "LOG : GAME INTERFACE | INFO : Combat starts \n";

    // Display combat information to player


    //std::cout << "LOG : GAME MOTOR | COMBAT UNIT SYSTEM | INFO : System initialization\n";
    //std::cout << "LOG : GAME MOTOR | COMBAT UNIT SYSTEM | INFO : Configuration loading\n";
    //std::cout << "LOG : GAME MOTOR | COMBAT UNIT SYSTEM | INFO : Construction\n";
    //std::cout << "LOG : GAME MOTOR | COMBAT UNIT SYSTEM | INFO : Combat unit 01 ready : Knight\n";
    //std::cout << "LOG : GAME MOTOR | COMBAT UNIT SYSTEM | INFO : Combat unit 02 ready : Orc\n";
}

