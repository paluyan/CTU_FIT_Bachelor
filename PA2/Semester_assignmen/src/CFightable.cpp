/**
* @author Yana Paluyan <paluyyan@fit.cvut.cz>
* @date 8/5/20
*/

#include "CFightable.h"
#include "IOManager.h"

CFightable::CFightable(std::string name, int hp, int dmg, int def)
        : mName(std::move(name)),
          mHP(hp),
          mDmg(dmg),
          mDef(def) {}



void CFightable::fight(CFightable &target) {
    int vMyHP = this->mHP;
    while (!this->isDead() && !target.isDead()) {
        target.defend(*this);
        if (target.isDead()) { break; }
        this->defend(target);
    }
    if (!this->isDead()) {
        this->setHP(vMyHP);
    }
}

bool CFightable::isDead() const {
    return mHP <= 0;
}


void CFightable::defend(CFightable &attacker) {
    if (attacker.selectHit() != this->selectDefend()) {
        int dmgTmp = (attacker.mDmg - this->mDef);
        if (dmgTmp <= 0) {
            dmgTmp = 5;
        }
        mHP = mHP - dmgTmp;
        if (this->mHP < 0) {
            this->mHP = 0;
        }
        IOManager::Print("\n" + this->getName() + " lost " + std::to_string(dmgTmp)
                                   + " hp points (" + std::to_string(this->mHP) + " points left)\n");

    } else {
        IOManager::Print("\n" + this->getName() + " repelled the attack!\n");
    }

}


