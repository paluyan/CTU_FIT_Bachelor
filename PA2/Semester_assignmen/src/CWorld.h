/**
* @author Yana Paluyan <paluyyan@fit.cvut.cz>
* @date 5/8/20
*/

#pragma once


#include <vector>
#include <map>

#include "CLocationSave.h"
#include "CCreatureSave.h"
#include "CItemSave.h"

/**
 * InRAM database with custom-defined game objects
 */
class CWorld {
public:
    CWorld() = delete;

    CWorld(std::string name,
           std::map<std::string, const CLocationSave> locations,
           std::map<std::string, const CCreatureSave> creatures,
           std::map<std::string, const CItemSave> items);
    /**
     * Searches for location info in the loaded world.
     * @param locationName location name to search
     * @return pointer to the found locationSave, or null if not found
     */
    const CLocationSave *getLocation(const std::string &locationName);
    /**
     * Searches for creature info in the loaded world.
     * @param creatureName creature name to search
     * @return pointer to the found creatureSave, or null if not found
     */
    const CCreatureSave *getCreature(const std::string &creatureName);
    /**
     * Searches for item info in the loaded world.
     * @param itemName item name to search
     * @return pointer to the found itemSave, or null if not found
     */
    const CItemSave *getItem(const std::string &itemName);

    const std::string &getWorldName();

private:
    std::string mName;
    std::map<std::string, const CLocationSave> mLocations;
    std::map<std::string, const CCreatureSave> mCreatures;
    std::map<std::string, const CItemSave> mItems;

};


