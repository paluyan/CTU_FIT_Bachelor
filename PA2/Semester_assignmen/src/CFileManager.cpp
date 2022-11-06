/**
* @author Yana Paluyan <paluyyan@fit.cvut.cz>
* @date 5/30/20
*/

#include "CFileManager.h"
#include "CActionNewGame.h"
#include "CActionLoadGame.h"
#include <stdexcept>

bool CFileManager::findByTag(const char *tag, xmlNodePtr cur, xmlDocPtr doc, xmlChar *key, std::string &str) {
    if ((!xmlStrcmp(cur->name, (const xmlChar *) tag))) {
        key = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);
        str = ((char *) key);
        free(key);
        return true;
    }
    return false;
}

CItemSave CFileManager::parseItem(xmlDocPtr doc, xmlNodePtr cur) {
    CItemSave vRes;
    std::string tmpPWR;
    xmlChar *key = nullptr;
    cur = cur->xmlChildrenNode;
    while (cur != nullptr) {
        findByTag("name", cur, doc, key, vRes.mName);
        findByTag("type", cur, doc, key, vRes.mType);
        findByTag("power", cur, doc, key, tmpPWR);
        cur = cur->next;
    }
    vRes.mPower = std::stoi(tmpPWR);
    return vRes;
}

CCreatureSave CFileManager::parseCreature(xmlDocPtr doc, xmlNodePtr cur) {
    CCreatureSave vRes;
    std::string tmpHP, tmpDmg, tmpDef;
    xmlChar *key = nullptr;
    cur = cur->xmlChildrenNode;
    while (cur != nullptr) {
        findByTag("name", cur, doc, key, vRes.mName);
        findByTag("hp", cur, doc, key, tmpHP);
        findByTag("dmg", cur, doc, key, tmpDmg);
        findByTag("def", cur, doc, key, tmpDef);
        cur = cur->next;
    }
    vRes.mHP = std::stoi(tmpHP);
    vRes.mDMG = std::stoi(tmpDmg);
    vRes.mDEF = std::stoi(tmpDef);
    return vRes;
}

COptionSave CFileManager::parseOptions(xmlDocPtr doc, xmlNodePtr cur) {
    COptionSave vRes;
    std::string tmpLoot;
    xmlChar *key = nullptr;
    cur = cur->xmlChildrenNode;
    while (cur != nullptr) {
        findByTag("optionDesc", cur, doc, key, vRes.mDescription);
        findByTag("type", cur, doc, key, vRes.mType);
        findByTag("target", cur, doc, key, vRes.mTarget);
        if (findByTag("loot", cur, doc, key, tmpLoot)) {
            vRes.mLoot.push_back(tmpLoot);
        }

        findByTag("winTarget", cur, doc, key, vRes.mWinTarget);
        cur = cur->next;
    }
    return vRes;
}

CLocationSave CFileManager::parseLocations(xmlDocPtr doc, xmlNodePtr cur) {
    CLocationSave vRes;
    xmlChar *key = nullptr;
    cur = cur->xmlChildrenNode;
    while (cur != nullptr) {
        findByTag("name", cur, doc, key, vRes.mName);
        findByTag("description", cur, doc, key, vRes.mDescription);
        if ((!xmlStrcmp(cur->name, (const xmlChar *) "options"))) {
            vRes.mOptions.push_back(parseOptions(doc, cur));
        }
        cur = cur->next;
    }
    return vRes;
}

std::shared_ptr<CWorld> CFileManager::parseWorld(xmlDocPtr doc, xmlNodePtr cur) {
    std::string tmpName;
    std::map<std::string, const CLocationSave> tmpLocations;
    std::map<std::string, const CCreatureSave> tmpCreatures;
    std::map<std::string, const CItemSave> tmpItems;
    xmlChar *key = nullptr;
    cur = cur->xmlChildrenNode;

    while (cur != nullptr) {
        findByTag("name", cur, doc, key, tmpName);
        if ((!xmlStrcmp(cur->name, (const xmlChar *) "location"))) {
            auto vLoc = parseLocations(doc, cur);
            tmpLocations.emplace(vLoc.mName, vLoc);
        }
        if ((!xmlStrcmp(cur->name, (const xmlChar *) "creature"))) {
            auto vCre = parseCreature(doc, cur);
            tmpCreatures.emplace(vCre.mName, vCre);
        }
        if ((!xmlStrcmp(cur->name, (const xmlChar *) "item"))) {
            auto vItm = parseItem(doc, cur);
            tmpItems.emplace(vItm.mName, vItm);
        }
        cur = cur->next;
    }

    xmlFreeDoc(doc);
    return std::make_shared<CWorld>(tmpName, tmpLocations, tmpCreatures, tmpItems);
}

void structuredErrorFunc(void *userData, xmlErrorPtr error) {
    (void)userData;
    (void)error;
    IOManager::Print("Wrong input! Try again.");

}

std::shared_ptr<CWorld> CFileManager::loadWorld(const char *docName) {

    xmlSetStructuredErrorFunc(nullptr, structuredErrorFunc);
    xmlDocPtr doc = xmlParseFile(docName);
    xmlNodePtr cur = xmlDocGetRootElement(doc);

    if (!checkDoc(doc, cur)) { return nullptr; }

    while (cur != nullptr) {
        if ((!xmlStrcmp(cur->name, (const xmlChar *) "world"))) {
            return parseWorld(doc, cur);
        }
        cur = cur->next;
    }
    return nullptr;
}

void CFileManager::parseInventory(xmlDocPtr doc, xmlNodePtr cur, std::vector<std::string> &itemContainer) {
    std::string tmpItem;
    xmlChar *key = nullptr;
    cur = cur->xmlChildrenNode;
    while (cur != nullptr) {
        if (findByTag("item", cur, doc, key, tmpItem)) {
            itemContainer.push_back(tmpItem);
        }
        cur = cur->next;
    }
}

CGameSave CFileManager::loadSave(const char *docName) {
    xmlSetStructuredErrorFunc(nullptr, structuredErrorFunc);
    xmlDocPtr doc = xmlParseFile(docName);
    xmlNodePtr cur = xmlDocGetRootElement(doc);
    CGameSave vSave;
    if (!checkDoc(doc, cur)) {
        vSave.loadState = false;
        return vSave;
    }

    xmlChar *key = nullptr;
    xmlNodePtr tmpCur;
    std::string tmpHP, tmpDmg, tmpDef, tmpPoints;
    while (cur != nullptr) {
        if ((!xmlStrcmp(cur->name, (const xmlChar *) "saveWorld"))) {
            tmpCur = cur->xmlChildrenNode;
            while (tmpCur) {
                findByTag("worldName", tmpCur, doc, key, vSave.mWorldName);
                findByTag("curLoc", tmpCur, doc, key, vSave.mCurrentLoc);
                findByTag("playerName", tmpCur, doc, key, vSave.mPlayerName);
                if (findByTag("gamePoints", tmpCur, doc, key, tmpPoints)) {
                    vSave.mGamePoints = std::stoi(tmpPoints);
                }
                findByTag("hp", tmpCur, doc, key, tmpHP);
                findByTag("dmg", tmpCur, doc, key, tmpDmg);
                findByTag("def", tmpCur, doc, key, tmpDef);
                if ((!xmlStrcmp(tmpCur->name, (const xmlChar *) "backpack"))) {
                    parseInventory(doc, tmpCur, vSave.mInventory);
                }
                if ((!xmlStrcmp(tmpCur->name, (const xmlChar *) "equipped"))) {
                    parseInventory(doc, tmpCur, vSave.mEquipped);
                }
                tmpCur = tmpCur->next;
            }
        }
        cur = cur->next;
    }
    vSave.mPlayerHP = std::stoi(tmpHP);
    vSave.mPlayerDMG = std::stoi(tmpDmg);
    vSave.mPlayerDEF = std::stoi(tmpDef);
    vSave.loadState = true;
    xmlFreeDoc(doc);
    return vSave;
}

bool CFileManager::checkDoc(xmlDocPtr doc, xmlNodePtr cur) {

    if (doc == nullptr) {
        return false;
    }
    if (cur == nullptr) {
        xmlFreeDoc(doc);
        return false;
    }
    return true;
}
std::shared_ptr<std::map<std::string, std::shared_ptr<CAction> > > CFileManager::getActions() {
    if (mActions == nullptr) {
        mActions = std::make_shared<std::map<std::string, std::shared_ptr<CAction>>>();
        std::shared_ptr<CAction> vTmp;

        vTmp = std::make_shared<CActionNewGame>();
        mActions->emplace(std::make_pair(vTmp->getCommand(), vTmp));

        vTmp = std::make_shared<CActionLoadGame>();
        mActions->emplace(std::make_pair(vTmp->getCommand(), vTmp));
    }
    return mActions;
}