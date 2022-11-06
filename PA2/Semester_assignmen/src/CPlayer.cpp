/**
* @author Yana Paluyan <paluyyan@fit.cvut.cz>
* @date 07.05.2020
*/

#include "CPlayer.h"
#include "CActionProfile.h"
#include "CActionInventory.h"
#include "CActionSave.h"
#include "CActionExit.h"

CPlayer::CPlayer(const std::string &name, int hp, int dmg, int def)
        : CFightable(name, hp, dmg, def) {}

int CPlayer::selectHit() {
    IOManager::Print("-Hit the monster in the chest  [c]");
    IOManager::Print("-Hit the monster in the head  [h]");
    IOManager::Print("-Kick the monster in the legs  [l]");

    return battleChoice();
}

int CPlayer::selectDefend() {
    IOManager::Print("It's your turn to defend yourself!");
    IOManager::Print("-Defend chest  [c]");
    IOManager::Print("-Defend head  [h]");
    IOManager::Print("-Defend legs  [l]");

    return battleChoice();
}

int CPlayer::battleChoice() {

    while (true) {
        std::string choice = IOManager::Read();
        if (choice == "c") {
            return 0;
        } else if (choice == "h") {
            return 1;
        } else if (choice == "l") {
            return 2;
        } else {
            IOManager::Print("Wrong command! Try again.");
        }
    }
}

void CPlayer::showState() {
    IOManager::Print("\nHealth: " + std::to_string(getHp()));
    IOManager::Print("Damage: " + std::to_string(getDmg()));
    IOManager::Print("Defend: " + std::to_string(getDef()) + "\n");
}

std::shared_ptr<std::map<std::string, std::shared_ptr<CAction> > > CPlayer::getActions() {
    if (mActions == nullptr) {
        mActions = std::make_shared<std::map<std::string, std::shared_ptr<CAction> >>();
        std::shared_ptr<CAction> vAct;

        vAct = std::make_shared<CActionProfile>();
        mActions->emplace(std::make_pair(vAct->getCommand(), vAct));

        vAct = std::make_shared<CActionInventory>();
        mActions->emplace(std::make_pair(vAct->getCommand(), vAct));

        vAct = std::make_shared<CActionSave>();
        mActions->emplace(std::make_pair(vAct->getCommand(), vAct));

        vAct = std::make_shared<CActionExit>();
        mActions->emplace(std::make_pair(vAct->getCommand(), vAct));
    }
    return mActions;
}

void CPlayer::backpackItem(const CItemSave *item) {
    mInventory.putItem(item);
}

void CPlayer::equippedItem(const CItemSave *item) {
    mInventory.equipItem(item);
}

CInventory &CPlayer::getInventory() {
    return mInventory;
}



