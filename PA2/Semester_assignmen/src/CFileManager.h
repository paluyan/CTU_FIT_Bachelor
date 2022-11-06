/**
* @author Yana Paluyan <paluyyan@fit.cvut.cz>
* @date 5/30/20
*/

#pragma once



#include <libxml/tree.h>
#include <memory>
#include "CGameSave.h"
#include "IControllable.h"
#include "CWorld.h"

/**
 * Holder of static methods for load world from file.
 */
class CFileManager : public IControllable {
public:
    /**
     * Load world from the initial file
     * @param docName name of the load file
     * @return pointer to the loaded world
     */
    static std::shared_ptr<CWorld> loadWorld(const char *docName);
    /**
     * Loads information about the saved game from save file
     * @param docName save`s file name
     * @return object with information about saved game
     */
    static CGameSave loadSave(const char *docName);

    std::shared_ptr<std::map<std::string, std::shared_ptr<CAction> > > getActions() override;

private:
    std::shared_ptr<std::map<std::string, std::shared_ptr<CAction> > > mActions;
    /**
     * Search desired xml tag for extract tag value
     * @param tag desired tag
     * @param cur current xml node
     * @param doc xml file
     * @param key tag key
     * @param str string for save tag value
     * @return true if the tag was found
     */
    static bool findByTag(const char *tag, xmlNodePtr cur, xmlDocPtr doc, xmlChar *key, std::string &str);

    static CCreatureSave parseCreature(xmlDocPtr doc, xmlNodePtr cur);

    static COptionSave parseOptions(xmlDocPtr doc, xmlNodePtr cur);

    static CLocationSave parseLocations(xmlDocPtr doc, xmlNodePtr cur);

    static CItemSave parseItem(xmlDocPtr doc, xmlNodePtr cur);

    static std::shared_ptr<CWorld> parseWorld(xmlDocPtr doc, xmlNodePtr cur);

    static void parseInventory(xmlDocPtr doc, xmlNodePtr cur, std::vector<std::string> &backPack);

    static bool checkDoc(xmlDocPtr doc, xmlNodePtr cur);

};






