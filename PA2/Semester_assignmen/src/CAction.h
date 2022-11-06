/**
* @author Yana Paluyan <paluyyan@fit.cvut.cz>
* @date 6/2/20
*/

#pragma once


#include "IOManager.h"

/**
 * A piece of user-application interaction
 */
class CAction {
public:
    CAction() = delete;

    CAction(std::string command, std::string desc)
            : mCommand(std::move(command)), mDescription(std::move(desc)) {}
    /**
     * Print possible commands for user
     */
    virtual void print() {
        IOManager::Print("- [" + mCommand + "] : " + mDescription);
    };
    /**
     * Reacts to a command depending on the user's choice
     */
    virtual void DO() = 0;

    const std::string &getCommand() {
        return mCommand;
    }

private:
    std::string mCommand;
    std::string mDescription;
};




