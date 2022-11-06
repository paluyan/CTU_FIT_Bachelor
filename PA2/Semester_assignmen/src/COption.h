/**
* @author Yana Paluyan <paluyyan@fit.cvut.cz>
* @date 5/10/20
*/

#pragma once

#include "CAction.h"
#include "COptionSave.h"

/**
 * Materialization of custom-defined location's specific action
 */
class COption : public CAction {
public:
    COption() = delete;

    /**
     * Materialize one of custom-defined option type
     * @param option
     * @return pointer to one of option type
     */
    static std::shared_ptr<CAction> getOption(const COptionSave &option);

    std::string getTarget() const {
        return mTarget;
    }

    std::vector<std::string> getLoot() {
        return mLoot;
    }

protected:
    std::string mTarget;
    std::vector<std::string> mLoot;

    COption(std::string command, std::string desc, std::string target, std::vector<std::string> loot)
            : CAction(std::move(command), std::move(desc)),
              mTarget(std::move(target)), mLoot(std::move(loot)) {}

};


