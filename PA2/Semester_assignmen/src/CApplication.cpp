/**
* @author Yana Paluyan <paluyyan@fit.cvut.cz>
* @date 5/31/20
*/

#include "CApplication.h"


CApplication *CApplication::mInstance = nullptr;

void CApplication::runApp() {
    if (mController == nullptr) {
        IOManager::Print("OMG!!! You have set no Controller for this Application!!!");
        return;
    }
    IOManager::Print("*tip* Write a word from square brackets to make a choice\n");
    while (!mExitFlag) {
        if (mGame != nullptr) {
            mGame->print();
            if (mGame->getCurrentLocation()->getName() == "finish") {
                break;
            }
        }

        mController->doInteraction();
    }
}

CApplication &CApplication::getInstance() {
    if (mInstance == nullptr) {
        mInstance = new CApplication();
    }
    return *mInstance;
}

void CApplication::clearInstance() {
    delete mInstance;
    mInstance = nullptr;
}


