/**
* @author Yana Paluyan <paluyyan@fit.cvut.cz>
* @date 6/10/20
*/

#pragma once

#include "CAction.h"
#include "CApplication.h"

class CActionExit : public CAction {
public:
    CActionExit()
            : CAction("exit", "Exit Game") {}

    void DO() override {
        CApplication::getInstance().setExitFlag(true);
    }
};