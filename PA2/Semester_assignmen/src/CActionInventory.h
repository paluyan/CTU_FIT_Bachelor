/**
* @author Yana Paluyan <paluyyan@fit.cvut.cz>
* @date 6/10/20
*/

#pragma once

#include "CAction.h"
#include "CApplication.h"


class CActionInventory : public CAction {
public:
    CActionInventory()
            : CAction("open", "Open inventory") {}

    void DO() override {
        CApplication::getInstance().getGame().getPlayer().getInventory().openInventory();
    }
};

