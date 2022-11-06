/**
* @author Yana Paluyan <paluyyan@fit.cvut.cz>
* @date 6/2/20
*/

#pragma once

#include <string>
#include "IOManager.h"

/**
 * Holder of custom definition of item inside the world
 */
class CItemSave {
public:
    /**
     * Print info about the item from players backpack
     * @param idx
     */
    void print(int idx) const {
        IOManager::Print(
                "[" + std::to_string(idx) + "] " + mName + ", " + mType + ", power: " + std::to_string(mPower));
    }

    std::string mName;
    std::string mType;
    int mPower;
};