/**
* @author Yana Paluyan <paluyyan@fit.cvut.cz>
* @date 6/7/20
*/

#pragma once

#include "IControllable.h"
#include "CFightable.h"
#include "CItemSave.h"
#include "CInventory.h"

/**
 *  Hero within the game world
 */
class CPlayer : public CFightable, public IControllable {
public:
    CPlayer(const std::string &name, int hp, int dmg, int def);

    void backpackItem(const CItemSave *item);

    void equippedItem(const CItemSave *item);

    void showState();

    CInventory &getInventory();

    std::shared_ptr<std::map<std::string, std::shared_ptr<CAction> > > getActions() override;

private:

    int selectHit() override;

    int selectDefend() override;

    int battleChoice();

    CInventory mInventory;

    std::shared_ptr<std::map<std::string, std::shared_ptr<CAction> > > mActions;
};




