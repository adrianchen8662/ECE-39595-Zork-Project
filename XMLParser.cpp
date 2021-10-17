#include "XMLParser.h"

//for anything we need to search, it'll always be level 1 of the xml file. 
//Start from the root, and look at each valuestr until you find the type you want.
//check if that node contains an element with the name you want
//then, return that node
vector<Room*> loadXMLFile (const std::string filename)
{
    vector <Room*> rooms;
    TiXmlDocument doc(filename); //this is literally a std::sting
    doc.LoadFile();
    TiXmlElement* rootElement = doc.RootElement();

    //idk why ValueStr() isn't defined its literally right there in the documentation
    if (rootElement != NULL && rootElement->ValueStr() == "map")
    {
        for (TiXmlNode *node = rootElement->FirstChild(); node != NULL; node->NextSibling())
        {
            TiXmlElement* childElement = node->ToElement();
            if (childElement != NULL)
            {
                std::string name = childElement->ValueStr();
                if (name == "room")
                {
                    Room* room = loadRooms(childElement);
                    rooms.push_back(room);
                }
            }
        }
    }
    return rooms;
}

Room* loadRooms(TiXmlElement* element)
{
    Room* room = new Room();

    for (TiXmlNode* node = element->FirstChild(); node != NULL; node = node->NextSibling())
    {
        TiXmlElement* childElement = node->ToElement();
        std::string name = childElement->ValueStr();
        std::string value = childElement->GetText();
        if (name == "name")
        {
            room -> setName(value);
        }
        if (name == "description")
        {
            room -> setDesc(value);
        }
        if (name == "type")
        {
            room -> setType(value);
        }
        if (name == "item")
        {
            room -> setItem(loadItems(childElement));
        }
        if (name == "trigger")
        {
            room -> setTrigger(roomsTrigger(childElement));
        }
        if (name == "container")
        {
            room -> setContainer(loadContainers(childElement));
        }
        if (name == "border")
        {
            room -> setBorder(loadBorder(childElement));
        }
        if (name == "creature")
        {
            room -> setCreature(loadCreatures(childElement));
        }
    }
    return room;
}

//convert all of these to pointers
Border* loadBorder(TiXmlElement* Element)
{
    Border* border = new Border(); //this one wants a pointer
    TiXmlNode* node = Element->FirstChild();
    border->setDirection(node->ToElement()->GetText());
    border->setName((node->NextSibling())->ToElement()->GetText());
    return border;
}

Condition* setCondition(TiXmlElement* element)
{
    Condition* condition = new Condition();
    for (TiXmlNode* node = element->FirstChild(); node != NULL; node = node->NextSibling())
    {
        TiXmlElement* childElement = node->ToElement();
        std::string name = childElement->ValueStr();
        std::string value = childElement->GetText();
        if (name == "has")
        {
            if (value == "yes")
            {
                condition->setHas(true);
            }
            else
            {
                condition->setHas(false);
            }
        }
        if (name == "owner")
        {
            condition->setOwner(value);
        }
        if (name == "object")
        {
            condition->setObject(value);
        }
        if (name == "status")
        {
            condition->setStatus(value);
        }

    }
    return condition;
}

//change to pointers
Trigger* roomsTrigger(TiXmlElement* element)
{
    Trigger* roomTrigger = new Trigger();
    for (TiXmlNode* node = element->FirstChild(); node != NULL; node = node->NextSibling())
    {
        TiXmlElement* childElement = node->ToElement();
        std::string name = childElement->ValueStr();
        std::string value = childElement->GetText();
        if (name == "command")
        {
            roomTrigger->addCommand(value);
        }
        if (name == "type")
        {
            roomTrigger->addType(value);
        }
        if (name == "condition")
        {
            roomTrigger->addCondition(setCondition(childElement));
        }
        if (name == "print")
        {
            roomTrigger->addPrint(value);
        }
        if (name == "action")
        {
            roomTrigger->addAction(value);
        }
    }
    return roomTrigger;
}

//change to pointers
Turnon* itemTurnOn(TiXmlElement* childElement)
{
    Turnon* itemTurnOn = new Turnon();
    TiXmlNode* node = childElement->FirstChild();
    itemTurnOn->setPrint((node->ToElement()));
    itemTurnOn->setAction((node->NextSibling())->ToElement());
    return itemTurnOn;
}

//change to pointers
Item* loadItems(TiXmlElement* element)
{
    Item* item = new Item();

    for (TiXmlNode* node = element->FirstChild(); node != NULL; node = node->NextSibling())
    {
        TiXmlElement* childElement = node->ToElement();
        std::string name = childElement->ValueStr();
        std::string value = childElement->GetText();
        if (name == "name")
        {
            item->setTrigger(roomsTrigger(childElement));
        }
        if (name == "writing")
        {
            item->setWriting(value);
        }
        if (name == "status")
        {
            item->setStatus(value);
        }
        if (name == "turnon")
        {
            item->setTurnon(itemTurnOn(childElement));
        }
    }
    return item;
}

//change to pointers, look above for fix
Turnon* itemTurnOn(TiXmlElement* childElement)
{
    Turnon* itemTurnOn = new Turnon();
    TiXmlNode* node = childElement->FirstChild();
    itemTurnOn->setPrint(node->ToElement());
    itemTurnOn->setAction((node->NextSibling())->ToElement());
    return itemTurnOn;
}

Container* loadContainers(TiXmlElement* element)
{
    Container* container = new Container();

    for (TiXmlNode* node = element->FirstChild(); node != NULL; node = node->NextSibling())
    {
        TiXmlElement* childElement = node->ToElement();
        std::string name = childElement->ValueStr();
        std::string value = childElement->GetText();
        if (name == "name")
        {
            container->setName(value);
        }
        if (name == "item")
        {
            container->setItem(loadItems(childElement));
        }
        if (name == "status")
        {
            container->setStatus(value); 
        }
        if (name == "accept")
        {
            container->setAccept(value);
        }
        if (name == "trigger")
        {
            container->setTrigger(roomsTrigger(childElement)); 
        }
    }
    return container;
}

Attack* loadAttack(TiXmlElement* element)
{
    Attack** attack = new Attack();

    for (TiXmlNode* node = element->FirstChild(); node != NULL; node = node->NextSibling())
    {
        TiXmlElement* childElement = node->ToElement();
        std::string name = childElement->ValueStr();
        std::string value = childElement->GetText();
        if (name == "name")
        {

        }
    }
}

Creature* loadCreatures(TiXmlElement* element)
{
    Creature* creature = new Creature();

    for (TiXmlNode* node = element->FirstChild(); node != NULL; node = node->NextSibling())
    {
        TiXmlElement* childElement = node->ToElement();
        std::string name = childElement->ValueStr();
        std::string value = childElement->GetText();
        if (name == "name")
        {
            creature->setName(value);
        }
        if (name == "vulnerability")
        {
            creature->setVulnerability(value);
        }
        if (name == "attack")
        {
            creature->setAttack(loadAttack(childElement)); //nested
        }
        if (name == "trigger")
        {
            creature->setTrigger(roomsTrigger(childElement));
        }
    return creature;
}