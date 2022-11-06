/**
* @author Yana Paluyan <paluyyan@fit.cvut.cz>
* @date 6/13/20
*/

#pragma once

#include <vector>
/**
 * Holder for game state information
 */
class CGameSave {
public:
    std::string mWorldName;
    std::string mCurrentLoc;
    std::string mPlayerName;
    int mGamePoints;
    int mPlayerHP;
    int mPlayerDMG;
    int mPlayerDEF;
    bool loadState;

    std::vector<std::string> mInventory;
    std::vector<std::string> mEquipped;
};




