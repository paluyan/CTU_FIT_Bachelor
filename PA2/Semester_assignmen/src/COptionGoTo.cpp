/**
* @author Yana Paluyan <paluyyan@fit.cvut.cz>
* @date 5/8/20
*/

#include "COptionGoTo.h"
#include "CApplication.h"

COptionGoTo::COptionGoTo(std::string command, std::string description, std::string target,
                         std::vector<std::string> loot)
        : COption(std::move(command), std::move(description), std::move(target), std::move(loot)) {}

void COptionGoTo::DO() {
    auto vLoot = this->getLoot();
    if (!vLoot.empty()) {
        IOManager::Print("\nLucky! you got :");
        for (const auto &loot : vLoot) {
            auto tmpLoot = CApplication::getInstance().getGame().getWorld().getItem(loot);
            CApplication::getInstance().getGame().getPlayer().backpackItem(tmpLoot);
            IOManager::Print(
                    tmpLoot->mType + " - " + tmpLoot->mName + ", power : " + std::to_string(tmpLoot->mPower) + "\n");
        }
        IOManager::PressToContinue();
    }
    CApplication::getInstance().getGame().setCurrentLoc(getTarget());


}

