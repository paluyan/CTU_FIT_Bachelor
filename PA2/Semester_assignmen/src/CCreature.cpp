/**
* @author Yana Paluyan <paluyyan@fit.cvut.cz>
* @date 5/15/20
*/

#include "CCreature.h"

int CCreature::selectHit() {
    int choice = rand() % 3;
    return choice;
}

int CCreature::selectDefend() {
    int choice = rand() % 3;
    return choice;
}

CCreature::CCreature(const CCreatureSave &creature)
        : CFightable(creature.mName, creature.mHP, creature.mDMG, creature.mDEF) {}