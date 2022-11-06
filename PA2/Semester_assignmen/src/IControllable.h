/**
* @author Yana Paluyan <paluyyan@fit.cvut.cz>
* @date 5/10/20
*/

#pragma once

#include <string>
#include <map>
#include <memory>
#include "CAction.h"

/**
 * User controllable object.
 * Works in pair with CController, provides map of commands and actions
 */
class IControllable {
public:
    /**
     * Creates an container of possible commands and corresponding actions
     * @return map of commands and corresponding actions
     */
    virtual std::shared_ptr<std::map<std::string, std::shared_ptr<CAction>>> getActions() = 0;
};