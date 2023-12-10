/**

    \file       GameInterface.cpp
    \brief      Implementation of GameInterface class
    \copyright  © Copyright XONO GALAXY - 2023 - All rights reserved

    Reproduction, modification and/or use of this document without express written permission of XONO GALAXY is prohibited
    © Copyright XONO GALAXY - 2023
    All rights reserved - XONO GALAXY Proprietary Data.

 **/

#include "GameInterface.h"

GameInterface::GameInterface()
{
}

GameInterface::GameInterface(std::vector<CombatUnit*> units_, CombatProtocol1v1* protocol_)
{
    m_units     = units_;
    m_protocol  = protocol_;
}

GameInterface::~GameInterface()
{
}

void GameInterface::displayMenu() 
{
    std::cout << "LOG : GAME INTERFACE | INFO : Menu\n";
    std::cout << "LOG : GAME INTERFACE | INFO : Please select a command\n";
    std::cout << "LOG : GAME INTERFACE |         ___________________________________________________________________________\n";
    std::cout << "LOG : GAME INTERFACE |        | Launch a combat with the current units configuration -> Command input : "<< CommandType::LAUNCH_COMBAT <<" |\n";
    std::cout << "LOG : GAME INTERFACE |        | Display current units statistics                     -> Command input : " << CommandType::DISPLAY_UNITS_STATS << " |\n";
    std::cout << "LOG : GAME INTERFACE |        |___________________________________________________________________________|\n";
}

void GameInterface::executeCommand(CommandType command_) 
{
    switch (command_) {

    case CommandType::LAUNCH_COMBAT:

        m_protocol->launchCombatProtocol1v1();

        break;

    case CommandType::DISPLAY_UNITS_STATS:

        for (auto& unit : m_units) {

            //unit->showStats();

        }

        break;
    }

}
