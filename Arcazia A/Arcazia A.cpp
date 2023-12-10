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
#include "GameInterface.h"

int main() {

    std::cout << " ____________________________________________________________  \n";
    std::cout << "|                     WELCOME TO ARCAZIA                     | \n";
    std::cout << "|                     Alpha 1.0 version                      | \n";
    std::cout << "|____________________________________________________________| \n";

        // __________________________
        //|    Welcome to Arcazia    |
        //|__________________________|
        //        ||
        //(\__/)  ||
        //(•ㅅ•)  ||
        /// 　 づ

    std::cout << "LOG : GAME MOTOR | UNIT SYSTEM | INFO : Configuration\n";

    BuildManager* bm = new BuildManager();
    KnightBuilder* kb = new KnightBuilder();
    OrcBuilder* ob = new OrcBuilder();

    std::cout << "LOG : GAME MOTOR | UNIT SYSTEM | INFO : Construction\n";
    for (auto &unit : bm->getUnitsConfig()) {

        switch (unit.type) {

        case CombatUnit::UnitType::KNIGHT:
            bm->constructKnight(kb, unit);
            //std::cout << "LOG : GAME INTERFACE | INFO : Unit " << unit.id << " is ready as Knight\n";
            break;

        case CombatUnit::UnitType::ORC:
            bm->constructOrc(ob, unit);
            //std::cout << "LOG : GAME INTERFACE | INFO : Unit " << unit.id << " is ready as Orc\n";
            break;
        }
    }

    // Get created units
    Knight* unit01 = kb->getKnight();
    Orc* unit02 = ob->getOrc();

    std::cout << "LOG : GAME MOTOR | UNIT SYSTEM | INFO : Initialized units\n";

    // Combat system initialization
    std::vector<CombatUnit*> opponents = { unit01, unit02 };
    CombatProtocol1v1* protocol = new CombatProtocol1v1(opponents);

    // Game interface initialization
    GameInterface* interface = new GameInterface(opponents, protocol);

    int player_input = 99;

    // Menu interaction
    while (player_input >= 0 || player_input <= 1) 
    {
        interface->displayMenu();
        std::cout << "LOG : GAME INTERFACE | INFO : Player input : ";

        std::cin >> player_input;

        if (player_input == 0) {

            if (interface->getState() == GameInterface::GameState::FINISHED) {
                std::cout << "LOG : GAME INTERFACE | INFO : Combat is done and game finished, please restart ARCAZIA for a new combat game\n";
            }
            else {
                interface->executeCommand(static_cast<GameInterface::CommandType>(player_input));
                interface->setState(GameInterface::GameState::FINISHED);

            }

        }
        else if (player_input == 1) {

            interface->executeCommand(static_cast<GameInterface::CommandType>(player_input));
        }
        else {
            std::cout << "LOG : GAME MOTOR | GAME INTERFACE | INFO : Command type doesn't exist\n";
        }
    }
}