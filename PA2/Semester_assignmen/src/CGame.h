/**
* @author Yana Paluyan <paluyyan@fit.cvut.cz>
* @date 6/7/20
*/

#pragma once

#include <memory>
#include "CGameSave.h"
#include "CWorld.h"
#include "CPlayer.h"
#include "CLocation.h"

/**
 * Instance of the active game
 */
class CGame {
public:
    CGame() = delete;

    CGame(std::shared_ptr<CWorld> world, const CGameSave &gameSave); //load Game

    /**
     * Activate location for game controller
     * @param locationName
     */
    void setCurrentLoc(const std::string &locationName);

    void startFight(const std::string &creatureName);

    CWorld &getWorld() {
        return *mWorld;
    }

    CPlayer &getPlayer() {
        return *mPlayer;
    }

    std::shared_ptr<CLocation> getCurrentLocation() {
        return mCurrentLocation;
    }

    void print();

private:
    std::shared_ptr<CWorld> mWorld;
    std::shared_ptr<CPlayer> mPlayer;
    std::shared_ptr<CLocation> mCurrentLocation;
};




