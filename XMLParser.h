#pragma once
#include <iostream>
#include "tinyxml.h"
#include "string"
#include "room.h"
#include "item.h"
#include "creature.h"
#include "container.h"
#include "turnon.h"
#include "trigger.h"
#include "border.h"

Room* loadRoom(TiXmlElement* element);
Border* loadBorder(TiXmlElement* Element);
Condition* loadCondition(TiXmlElement* element);
Trigger* loadTrigger(TiXmlElement* element);
Turnon* itemTurnOn(TiXmlElement* childElement);
Item* loadItems(TiXmlElement* element);
Turnon* loadItemTurnOn(TiXmlElement* childElement);
Container* loadContainers(TiXmlElement* element, TiXmlElement* rootElement);
Attack* loadAttack(TiXmlElement* element);
Creature* loadCreatures(TiXmlElement* element);
vector<Room*> loadXMLFile (const std::string filename);

