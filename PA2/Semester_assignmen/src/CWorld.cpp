/**
* @author Yana Paluyan <paluyyan@fit.cvut.cz>
* @date 5/8/20
*/

#include "CWorld.h"

CWorld::CWorld(std::string name, std::map<std::string, const CLocationSave> locations,
               std::map<std::string, const CCreatureSave> creatures, std::map<std::string, const CItemSave> items)
        : mName(std::move(name)), mLocations(std::move(locations)), mCreatures(std::move(creatures)),
          mItems(std::move(items)) {}

const CLocationSave *CWorld::getLocation(const std::string &locationName) {
    auto vFound = mLocations.find(locationName);
    if (vFound == mLocations.end()) {
        IOManager::Print("ERROR in world definition! No such location \"" + locationName + "\"");
        return nullptr;
    }
    return &vFound->second;
}

const CCreatureSave *CWorld::getCreature(const std::string &creatureName) {
    auto vFound = mCreatures.find(creatureName);
    if (vFound == mCreatures.end()) {
        IOManager::Print("ERROR in world definition! No such creature \"" + creatureName + "\"");
        return nullptr;
    }
    return &vFound->second;
}

const CItemSave *CWorld::getItem(const std::string &itemName) {
    auto vFound = mItems.find(itemName);
    if (vFound == mItems.end()) {
        IOManager::Print("ERROR in world definition! No such item \"" + itemName + "\"");
        return nullptr;
    }
    return &vFound->second;
}

const std::string &CWorld::getWorldName() {
    return mName;
}



