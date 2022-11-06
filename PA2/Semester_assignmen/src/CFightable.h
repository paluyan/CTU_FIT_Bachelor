/**
* @author Yana Paluyan <paluyyan@fit.cvut.cz>
* @date 8/5/20
*/

#pragma once

#include <string>

/**
 * Implementation of fighting system
 */
class CFightable {
public:
    CFightable() = delete;

    CFightable(std::string name, int hp, int dmg, int def);
    /**
     * Does fight between player and creature
     * @param target
     */
    void fight(CFightable &target);

    bool isDead() const;

    void changeDmg(int value) {
        mDmg += value;
    }

    void changeDef(int value) {
        mDef += value;
    }
    std::string getName() const{
        return mName;
    }

    int getHp() const{
        return mHP;
    }

    int getDmg() const{
        return mDmg;
    }

    int getDef() const{
        return mDef;
    }
protected:
    void setHP(int hp) {
        mHP = hp;
    }

private:
    std::string mName;
    int mHP;
    int mDmg;
    int mDef;

    void defend(CFightable &attacker);

    virtual int selectHit() = 0;

    virtual int selectDefend() = 0;
};




