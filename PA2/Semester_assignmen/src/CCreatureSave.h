/**
* @author Yana Paluyan <paluyyan@fit.cvut.cz>
* @date 6/2/20
*/

#pragma once

#include <string>

/**
 * Holder of custom definition of creature inside the world
 */
class CCreatureSave {
public:
    std::string mName;
    int mHP;
    int mDMG;
    int mDEF;
};