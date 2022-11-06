/**
* @author Yana Paluyan <paluyyan@fit.cvut.cz>
* @date 6/4/20
*/

#pragma once


#include "CApplication.h"


class CActionLoadGame : public CAction {
public:
    CActionLoadGame()
            : CAction("load", "Load game") {}

    void DO() override {

        std::string vSaveName;
        CGameSave vSave;
        IOManager::Print("Input save's name to load:");

        while (true) {
            vSaveName = IOManager::Read();
            vSave = CFileManager::loadSave(("examples/" + vSaveName + ".xml").c_str());
            if (vSave.loadState) {
                break;
            }
        }
        IOManager::ClearWindow();
        std::shared_ptr<CWorld> vWorld = CFileManager::loadWorld(("examples/" + vSave.mWorldName + ".xml").c_str());
        CApplication::getInstance().setGame(std::make_shared<CGame>(vWorld, vSave));
        CApplication::getInstance().setFileManager(nullptr);
    }
};




