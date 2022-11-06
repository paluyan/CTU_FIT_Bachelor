/**
* @author Yana Paluyan <paluyyan@fit.cvut.cz>
* @date 5/15/20
*/

#include "COptionFight.h"
#include "CApplication.h"


COptionFight::COptionFight(std::string command, std::string description, std::string target,
                           std::vector<std::string> loot, std::string winTarget)
        : COption(std::move(command), std::move(description), std::move(target), std::move(loot)),
          mWinTargetLocation(std::move(winTarget)) {}

void COptionFight::DO() {

    CApplication::getInstance().getGame().startFight(getTarget());
    if (!CApplication::getInstance().getGame().getPlayer().isDead()) {
        auto vLoot = this->getLoot();
        if (!vLoot.empty()) {
            IOManager::Print("\nCongratulations! You defeated " + getTarget() + " and got :");
            for (const auto &loot : vLoot) {
                auto tmpLoot = CApplication::getInstance().getGame().getWorld().getItem(loot);
                IOManager::Print(
                        tmpLoot->mType + " - " + tmpLoot->mName + ", power : " + std::to_string(tmpLoot->mPower));

                CApplication::getInstance().getGame().getPlayer().backpackItem(tmpLoot);
            }
            IOManager::PressToContinue();
        }
    }
    CApplication::getInstance().getGame().setCurrentLoc(mWinTargetLocation);

}
