/**
* @author Yana Paluyan <paluyyan@fit.cvut.cz>
* @date 5/7/20
*/

#include "CItem.h"
#include "CGame.h"
#include "CApplication.h"

CItem::CItem(const CItemSave &item)
        : mName(item.mName), mType(item.mType), mPWR(item.mPower) {
    CGame *tmpGame = &CApplication::getInstance().getGame();
    if (tmpGame != nullptr) {
        affect(CApplication::getInstance().getGame().getPlayer());
    }
}

CItem::~CItem() {
    removeEffect(CApplication::getInstance().getGame().getPlayer());
}

void CItem::affect(CPlayer &player) {
    if (mType == "weapon") {
        player.changeDmg(mPWR);
    } else if (mType == "armor") {
        player.changeDef(mPWR);
    } else {
        IOManager::Print("ERROR: unknown item type \"" + mType + "\"");
    }
}

void CItem::removeEffect(CPlayer &player) {
    if (mType == "weapon") {
        player.changeDmg(-mPWR);
    } else if (mType == "armor") {
        player.changeDef(-mPWR);
    } else {
        IOManager::Print("ERROR: unknown item type \"" + mType + "\"");
    }
}

void CItem::print() const {
    IOManager::Print(mName + ", " + mType + ", power: " + std::to_string(mPWR));
}

const std::string &CItem::getName() const {
    return mName;
}

const int &CItem::getPwr() const {
    return mPWR;
}

const std::string &CItem::getType() const {
    return mType;
}

