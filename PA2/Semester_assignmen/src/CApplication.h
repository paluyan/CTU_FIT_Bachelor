/**
* @author Yana Paluyan <paluyyan@fit.cvut.cz>
* @date 5/31/20
*/

#pragma once

#include <memory>
#include "CGame.h"
#include "CController.h"
#include "CFileManager.h"

/**
 * Singleton object representing application
 */
class CApplication {
private:
    static CApplication *mInstance;

    CApplication() = default;

    ~CApplication() = default;

public:

    static CApplication &getInstance();
    static void clearInstance();

    CApplication(const CApplication &) = delete;
    CApplication &operator=(const CApplication &) = delete;
/**
 * Contains game loop
 */
    void runApp();

    CGame &getGame() const{
        return *mGame;
    }

    CController &getController() const{
        return *mController;
    }

    void setController(const std::shared_ptr<CController> &controller) {
        mController = controller;
        if (mController != nullptr && mFileManager != nullptr) {
            mController->registerControllable(*mFileManager);
        }
    }

    void setGame(const std::shared_ptr<CGame> &game) {
        mGame = game;
    }

    void setFileManager(const std::shared_ptr<CFileManager> &fmanager) {
        mFileManager = fmanager;
        if (mController != nullptr && mFileManager != nullptr) {
            mController->registerControllable(*mFileManager);
        }
    }

    void setExitFlag(bool exit) {
        mExitFlag = exit;
    }

private:
    std::shared_ptr<CGame> mGame;
    std::shared_ptr<CController> mController;
    std::shared_ptr<CFileManager> mFileManager;
    bool mExitFlag = false;
};





