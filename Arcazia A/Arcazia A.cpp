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

int main()
{
    std::cout << "WELCOME TO ARCAZIA\n";

    std::cout << "LOG : GAME MOTOR | COMBAT UNIT SYSTEM | INFO : Construction\n";

    BuildManager* bm = new BuildManager();
    KnightBuilder* kb = new KnightBuilder();
    OrcBuilder* ob = new OrcBuilder();

    bm->constructKnight(kb, 3);
    bm->constructOrc(ob, 3);

    Knight* unit01 = kb->getKnight();
    Orc* unit02 = ob->getOrc();

    std::cout << "LOG : GAME MOTOR | COMBAT UNIT SYSTEM | INFO : Combat unit 01 ready \n";
    std::cout << "LOG : GAME MOTOR | COMBAT UNIT SYSTEM | DEBUG : Unit 01 type : " << unit01->getType() << "\n";
    std::cout << "LOG : GAME MOTOR | COMBAT UNIT SYSTEM | DEBUG : Unit 01 life point : " << unit01->getLife() << "\n";
    std::cout << "LOG : GAME MOTOR | COMBAT UNIT SYSTEM | DEBUG : Unit 01 weapon type : " << unit02->getWeapon().getType() << "\n";
    std::cout << "LOG : GAME MOTOR | COMBAT UNIT SYSTEM | DEBUG : Unit 01 weapon damage : " << unit02->getWeapon().getDamage() << "\n";

    //std::cout << "LOG : GAME MOTOR | COMBAT UNIT SYSTEM | INFO : System initialization\n";
    //std::cout << "LOG : GAME MOTOR | COMBAT UNIT SYSTEM | INFO : Configuration loading\n";
    //std::cout << "LOG : GAME MOTOR | COMBAT UNIT SYSTEM | INFO : Construction\n";
    //std::cout << "LOG : GAME MOTOR | COMBAT UNIT SYSTEM | INFO : Combat unit 01 ready : Knight\n";
    //std::cout << "LOG : GAME MOTOR | COMBAT UNIT SYSTEM | INFO : Combat unit 02 ready : Orc\n";
}
