/**
* @author Yana Paluyan <paluyyan@fit.cvut.cz>
* @date 6/2/20
*/

#pragma once

#include <string>
#include <vector>
#include "COptionSave.h"

/**
 * Holder of custom definition of game location inside the world
 */
class CLocationSave {
public:
    std::string mName;
    std::string mDescription;
    std::vector<COptionSave> mOptions;
};