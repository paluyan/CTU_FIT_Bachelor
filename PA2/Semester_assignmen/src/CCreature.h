/**
* @author Yana Paluyan <paluyyan@fit.cvut.cz>
* @date 5/15/20
*/

#pragma once


#include "CFightable.h"
#include "CCreatureSave.h"

/**
 * Materialization of custom-defined creature
 */
class CCreature : public CFightable {
public:

    explicit CCreature(const CCreatureSave &creature);

private:
    int selectHit() override;

    int selectDefend() override;
};




