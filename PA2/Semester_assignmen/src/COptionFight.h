/**
* @author Yana Paluyan <paluyyan@fit.cvut.cz>
* @date 5/15/20
*/

#pragma once

#include <string>
#include "COption.h"

/**
 * Fight -> get items -> go to next location
 */

class COptionFight : public COption {
public:
    COptionFight() = delete;

    COptionFight(std::string command, std::string description, std::string target, std::vector<std::string> loot,
                 std::string winTarget);

    void DO() override;

    std::string mWinTargetLocation;
};




