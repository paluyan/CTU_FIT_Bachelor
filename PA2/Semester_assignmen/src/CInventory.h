/**
* @author Yana Paluyan <paluyyan@fit.cvut.cz>
* @date 6/13/20
*/

#pragma once

#include <vector>
#include "CItemSave.h"
#include "CItem.h"

/**
 * Inventory containing various items in backpack and equipped items
 */
class CInventory {
public:
    void putItem(const CItemSave *item);

    void equipItem(const CItemSave *item);

    std::vector<const CItemSave *> getBackItems() const{
        return mBackItems;
    }

    std::vector<std::shared_ptr<CItem>> getEquipped() const{
        return mEquipped;
    }

    void openInventory();

private:
    std::vector<std::shared_ptr<CItem>> mEquipped;

    std::vector<const CItemSave *> mBackItems;

    void showInventory();

    bool interactInventory();
};




