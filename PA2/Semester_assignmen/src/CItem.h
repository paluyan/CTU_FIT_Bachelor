/**
* @author Yana Paluyan <paluyyan@fit.cvut.cz>
* @date 5/7/20
*/

#pragma once

#include "CItemSave.h"

class CPlayer;
/**
 * Materialization of custom-defined item
 */
class CItem {
public:

    CItem() = delete;

    explicit CItem(const CItemSave &item);

    ~CItem();

    void affect(CPlayer &player);

    void removeEffect(CPlayer &player);

    void print() const;

    const std::string &getName() const;

    const std::string &getType() const;

    const int &getPwr() const;


private:
    std::string mName;
    std::string mType;
    int mPWR;
};





