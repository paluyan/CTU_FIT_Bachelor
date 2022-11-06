/**
* @author Yana Paluyan <paluyyan@fit.cvut.cz>
* @date 5/8/20
*/

#pragma once

#include <string>
#include "COption.h"

/**
 * get items -> next location
 */

class COptionGoTo : public COption {
public:
    COptionGoTo() = delete;

    COptionGoTo(std::string command, std::string description, std::string target, std::vector<std::string> loot);

    void DO() override;
};

