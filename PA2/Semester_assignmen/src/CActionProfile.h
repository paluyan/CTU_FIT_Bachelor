/**
* @author Yana Paluyan <paluyyan@fit.cvut.cz>
* @date 6/10/20
*/

#pragma once


#include "CApplication.h"

class CActionProfile : public CAction {
public:
    CActionProfile()
            : CAction("profile", "Show profile") {}

    void DO() override {
        CApplication::getInstance().getGame().getPlayer().showState();
    }
};