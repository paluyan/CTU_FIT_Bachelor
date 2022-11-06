/**
* @author Yana Paluyan <paluyyan@fit.cvut.cz>
* @date 6/2/20
*/

#pragma once

#include <string>

/**
 * Holder of custom definition of game location inside the world
 */
class COptionSave {
public:
//    std::string mCommand;
    std::string mDescription;
    std::string mTarget;
    std::string mType;
    std::string mWinTarget;
    std::vector<std::string> mLoot;
};