/**
* @author Yana Paluyan <paluyyan@fit.cvut.cz>
* @date 6/13/20
*/

#include <algorithm>
#include "CInventory.h"
#include "CApplication.h"

void CInventory::putItem(const CItemSave *item) {
    mBackItems.push_back(item);
}

void CInventory::equipItem(const CItemSave *item) {
    mEquipped.push_back(std::make_shared<CItem>(*item));
}

void CInventory::showInventory() {
    IOManager::Print("Equipped weapon:");
    int cntWeapon = 0;
    if (!mEquipped.empty()) {
        for (auto &equip : mEquipped) {
            if (equip->getType() == "weapon") {
                equip->print();
                cntWeapon++;
            }
        }
    }
    if (!cntWeapon) {
        IOManager::Print("NONE");
    }
    int cntArmor = 0;
    IOManager::Print("Equipped armor:");
    if (!mEquipped.empty()) {
        for (auto &equip : mEquipped) {
            if (equip->getType() == "armor") {
                equip->print();
                cntArmor++;
            }
        }
    }
    if (!cntArmor) {
        IOManager::Print("NONE");
    }

    IOManager::Print("BackPack :");
    int i = 0;
    if (!mBackItems.empty()) {
        for (auto &item: mBackItems) {
            item->print(i++);
        }
    } else {
        IOManager::Print("NONE (loser)");
    }
    IOManager::Print("[exit] Exit inventory");
    IOManager::Print("[some number] equip item");
    IOManager::Print("[item name] unequip item");


}

bool CInventory::interactInventory() {
    int i = 0;
    while (true) {
        std::string vAns = IOManager::Read();
        if (vAns == "exit") {
            return false;
        }
        for (auto &equip : mEquipped) {
            if (vAns == equip->getName()) {
                CApplication::getInstance().getGame().getPlayer().backpackItem(
                        CApplication::getInstance().getGame().getWorld().getItem(vAns));
                IOManager::Print("\nYou unequipped " + equip->getName() + ". -" + std::to_string(equip->getPwr()) +
                                 " damage.\n");

                mEquipped.erase(std::remove(mEquipped.begin(), mEquipped.end(), equip), mEquipped.end());
                return true;
            }
        }
        try {
            i = std::stoi(vAns);
        } catch (std::invalid_argument &e) {
            IOManager::Print("Wrong input! Try again.");
            continue;
        }
        if (i < 0 || i >= (int) mBackItems.size()) {
            IOManager::Print("Wrong input! Try again.");
            continue;
        }
        equipItem(mBackItems[i]);
        if (mBackItems[i]->mType == "weapon") {
            IOManager::Print("\nYou equipped " + mBackItems[i]->mName + ". +" + std::to_string(mBackItems[i]->mPower) +
                             " damage.\n");
            mBackItems.erase(mBackItems.begin() + i);
            return true;
        }
        if (mBackItems[i]->mType == "armor") {
            IOManager::Print("\nYou equipped " + mBackItems[i]->mName + ". +" + std::to_string(mBackItems[i]->mPower) +
                             " armor.\n");
            mBackItems.erase(mBackItems.begin() + i);
            return true;
        }
    }
}

void CInventory::openInventory() {
    while (true) {
        showInventory();
        if (!interactInventory()) {
            return;
        }
    }
}
