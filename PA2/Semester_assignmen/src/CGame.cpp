/**
* @author Yana Paluyan <paluyyan@fit.cvut.cz>
* @date 6/7/20
*/

#include "CGame.h"
#include "CApplication.h"
#include "CCreature.h"

CGame::CGame(std::shared_ptr<CWorld> world, const CGameSave &gameSave)
        : mWorld(std::move(world)) {
    mPlayer = std::make_shared<CPlayer>(gameSave.mPlayerName, gameSave.mPlayerHP, gameSave.mPlayerDMG,
                                        gameSave.mPlayerDEF);
    for (auto &vItem: gameSave.mInventory) {
        mPlayer->backpackItem(mWorld->getItem(vItem));
    }
    for (auto &vItem: gameSave.mEquipped) {
        mPlayer->equippedItem(mWorld->getItem(vItem));
    }
    CApplication::getInstance().getController().registerControllable(*mPlayer);
    setCurrentLoc(gameSave.mCurrentLoc);
}

void CGame::setCurrentLoc(const std::string &locationName) {
    mCurrentLocation = std::make_shared<CLocation>(*mWorld->getLocation(locationName));
    CApplication::getInstance().getController().registerControllable(*mCurrentLocation);
}

void CGame::startFight(const std::string &creatureName) {
    CCreature vCreature = CCreature(*mWorld->getCreature(creatureName));
    mPlayer->fight(vCreature);
    if (mPlayer->isDead()) {
        IOManager::Print("You are dead. No one cares.");
        CApplication::getInstance().setExitFlag(true);
    } else {
        IOManager::Print("Well done, you killed him!\n");
    }
}

void CGame::print() {
    IOManager::Print("\033[1;32mNow you location is : \033[0m" + mCurrentLocation->getDescription() + "\n");
}

