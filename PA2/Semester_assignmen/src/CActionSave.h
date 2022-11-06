/**
* @author Yana Paluyan <paluyyan@fit.cvut.cz>
* @date 6/15/20
*/

#pragma once


#include <fstream>
#include "CApplication.h"
#include <libxml/xmlwriter.h>


class CActionSave : public CAction {
public:
    CActionSave()
            : CAction("save", "Save game") {}

    void DO() override {
        IOManager::Print("Enter a name to save the game :");
        std::string saveName = IOManager::Read();

        xmlTextWriterPtr writer;
        writer = xmlNewTextWriterFilename(("examples/" + saveName + ".xml").c_str(), 0);
        xmlTextWriterSetIndent(writer, 1);

        xmlTextWriterStartDocument(writer, nullptr, "UTF-8", nullptr);
        xmlTextWriterStartElement(writer, BAD_CAST ("saveWorld"));
        xmlTextWriterWriteFormatElement(writer, BAD_CAST "worldName", "%s",
                                        CApplication::getInstance().getGame().getWorld().getWorldName().c_str());
        xmlTextWriterWriteFormatElement(writer, BAD_CAST "curLoc", "%s",
                                        CApplication::getInstance().getGame().getCurrentLocation()->getName().c_str());
        xmlTextWriterWriteFormatElement(writer, BAD_CAST "playerName", "%s",
                                        CApplication::getInstance().getGame().getPlayer().getName().c_str());
        xmlTextWriterWriteFormatElement(writer, BAD_CAST "hp", "%d",
                                        CApplication::getInstance().getGame().getPlayer().getHp());
        xmlTextWriterWriteFormatElement(writer, BAD_CAST "dmg", "%d",
                                        CApplication::getInstance().getGame().getPlayer().getDmg());
        xmlTextWriterWriteFormatElement(writer, BAD_CAST "def", "%d",
                                        CApplication::getInstance().getGame().getPlayer().getDef());

        auto backPack = CApplication::getInstance().getGame().getPlayer().getInventory().getBackItems();
        if (!backPack.empty()) {
            xmlTextWriterStartElement(writer, BAD_CAST ("backpack"));
            for (auto &it : backPack) {
                xmlTextWriterWriteFormatElement(writer, BAD_CAST "item", "%s", it->mName.c_str());
            }
            xmlTextWriterEndElement(writer);
        }


        auto equipItems = CApplication::getInstance().getGame().getPlayer().getInventory().getEquipped();
        if (!equipItems.empty()) {
            xmlTextWriterStartElement(writer, BAD_CAST ("equipped"));
            for (auto &it : equipItems) {
                xmlTextWriterWriteFormatElement(writer, BAD_CAST "item", "%s",
                                                it->getName().c_str());
            }
            xmlTextWriterEndElement(writer);
        }
        xmlTextWriterEndDocument(writer);
        xmlFreeTextWriter(writer);

    }
};




