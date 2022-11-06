/**
* @author Yana Paluyan <paluyyan@fit.cvut.cz>
* @date 6/2/20
*/

#pragma once


#include <list>
#include <string>
#include "IControllable.h"

/**
 * Provide interaction between user and game process
 */
class CController {
public:
    /**
     * Generates consistent command for any interaction.
     * @return number for command
     */
    static std::string generateCommand() {
        return std::to_string(sCOMMAND++);
    }
    /**
     * Makes controllable object active.
     * @param controllable
     */
    void registerControllable(IControllable &controllable);

    /**
     * Provide interaction with the user
     */
    void doInteraction();

private:
    static int sCOMMAND;

    std::list<std::weak_ptr<std::map<std::string, std::shared_ptr<CAction>>>> mActionMaps;

    /**
     * prints actions currently possible
     */
    void printActions();
    /**
     * read and execute user command
     */
    void executeUserCommand();
    /**
     * clean up expired controllable
     */
    void cleanUp();
};




