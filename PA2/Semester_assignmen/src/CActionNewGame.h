/**
* @author Yana Paluyan <paluyyan@fit.cvut.cz>
* @date 6/4/20
*/

#pragma once


#include "CApplication.h"
#include <stdexcept>

class CActionNewGame : public CAction {
public:
    CActionNewGame()
            : CAction("new", "New game") {}

    void DO() override {

        std::string vWorldName;
        std::shared_ptr<CWorld> vWorld = nullptr;
        IOManager::Print("Input world's name to load:");
        while (true) {
            vWorldName = IOManager::Read();

            vWorld = CFileManager::loadWorld(("examples/" + vWorldName + ".xml").c_str());

            if (!vWorld);
            else {
                break;
            }
        }
        CGameSave vSave = CFileManager::loadSave(("examples/" + vWorldName + ".xml_initial").c_str());
        createPlayer(vSave);
        CApplication::getInstance().setGame(std::make_shared<CGame>(vWorld, vSave));
        CApplication::getInstance().setFileManager(nullptr);
    }

private:
    static void createPlayer(CGameSave &gameSave) {
        std::string tmpName;
        int vGamePoints = gameSave.mGamePoints;
        int tmpDmg = 1, tmpHP = 1, tmpDef = 1;

        IOManager::Print("\nWhat is your name?");
        tmpName = IOManager::Read();
        IOManager::ClearWindow();

        IOManager::Print("Hello, " + tmpName + "!\n");
        IOManager::Print("Now you have " + std::to_string(vGamePoints) +
                         " points! Divide them between health, damage and defense.");

        std::cout << "Health: ";
        tmpHP = ReadInt(vGamePoints);
        vGamePoints -= tmpHP;
        IOManager::Print(std::to_string(vGamePoints) + " points left");
        if (vGamePoints > 0) {

            std::cout << "Damage: ";
            tmpDmg = ReadInt(vGamePoints);
            vGamePoints -= tmpDmg;
            IOManager::Print(std::to_string(vGamePoints) + " points left");
        }
        if (vGamePoints > 0) {
            std::cout << "Defense: ";
            tmpDef = ReadInt(vGamePoints);
            vGamePoints -= tmpDef;
        }
        IOManager::Print("\nYou have " + std::to_string(tmpHP) + " HP, " + std::to_string(tmpDmg) + " Dmg, " +
                         std::to_string(tmpDef) + " Def.\n");
        IOManager::Print("Let`s start!");
        IOManager::PressToContinue();
        gameSave.mPlayerHP = tmpHP;
        gameSave.mPlayerName = tmpName;
        gameSave.mPlayerDMG = tmpDmg;
        gameSave.mPlayerDEF = tmpDef;
    }

    static int ReadInt(int points) {
        int num;
        while (true) {
            std::cout << ">> ";
            if (!(std::cin >> num) || num > points || num < 0) {
                std::cin.clear();
                std::cin.ignore(32767, '\n');
                IOManager::Print("Wrong input! Try again.");
            } else {
                break;
            }
        }
        return num;
    }
};

