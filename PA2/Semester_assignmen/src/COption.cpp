/**
* @author Yana Paluyan <paluyyan@fit.cvut.cz>
* @date 5/10/20
*/

#include "COption.h"
#include "COptionGoTo.h"
#include "CController.h"
#include "COptionFight.h"

std::shared_ptr<CAction> COption::getOption(const COptionSave &option) {
    if (option.mType == "goto") {
        return std::make_shared<COptionGoTo>(
                CController::generateCommand(), option.mDescription, option.mTarget, option.mLoot);
    }
    if (option.mType == "fight") {
        return std::make_shared<COptionFight>(
                "fight", option.mDescription, option.mTarget, option.mLoot, option.mWinTarget);
    }
    IOManager::Print("ERROR: unknown option type: \"" + option.mType + "\"");
    return nullptr;
}

