/**
* @author Yana Paluyan <paluyyan@fit.cvut.cz>
* @date 6/2/20
*/

#include "CController.h"

int CController::sCOMMAND = 0;

void CController::registerControllable(IControllable &controllable) {
    mActionMaps.push_back(controllable.getActions());
}

void CController::executeUserCommand() {
    while (true) {
        std::string command = IOManager::Read();
        for (auto &it: mActionMaps) {
            if (it.expired()) { continue; }
            auto vFound = it.lock()->find(command);
            if (vFound != it.lock()->end()) {
                vFound->second->DO();
                return;
            }
        }
        IOManager::Print("Wrong input! Try again.");
    }
}

void CController::cleanUp() {
    mActionMaps.remove_if(
            [](std::weak_ptr<std::map<std::string, std::shared_ptr<CAction>>> &a) { return a.expired(); }
    );
}

void CController::printActions() {
    for (auto &it: mActionMaps) {
        if (it.expired()) { continue; }
        for (auto &itA: *it.lock()) {
            itA.second->print();
        }
        IOManager::Print("");
    }
}

void CController::doInteraction() {
    printActions();
    executeUserCommand();
    cleanUp();
}
