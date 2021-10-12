#include <XMLParser.h>

vector<Room> loadXMLFile (std::string filename)
{
    vector <Room> rooms;
    TiXmlDocument doc(filename);
    doc.LoadFile();
    TiXmlElement* rootElement = doc.RootElement();

    if (rootElement != NULL && rootElement->ValueStr() == "map")
    {
        for (TiXmlNode *node = rootElement->FirstChild(); node != NULL; node->nodeNextSibling())
        {
            TiXmlElement* childElement = node->ToElement();
            if (childElement != NULL)
            {
                std::string name = childElement->ValueStr;
                if (name == "room")
                {
                    Room room = loadRooms();
                    rooms.push_back(room);
                }
            }
        }
    }
    return rooms;
}

Room loadRooms(TiXmlElement* element)
{
    Room room = new Room();

    for (TiXmlNode* node = element->FirstChild(); node != NULL; node = node->NextSibling())
    {
        TiXmlElement* childElement = node->ToElement();
        std::string name = childElement->ValueStr();
        std::string value = childElement->GetText();
        if (name == "name")
        {
            room.setName(value);
        }
        if (name == "description")
        {
            room.setDesc(value);
        }
        if (name == "type")
        {
            room.setType(value);
        }
        if (name == "item")
        {
            room.setItem(value);
        }
        if (name == "trigger")
        {
            room.setTrigger(roomsTrigger(childElement));
        }
        if (name == "container")
        {
            room.setContainer(loadContainers(childElement));
        }
        if (name == "border")
        {
            room.setBorder(loadBorder(childElement));
        }
        if (name == "creature")
        {
            room.setCreature(loadCreatures(childElement));
        }
    }
    return room;
}

Border loadBorder(TiXmlElement* Element)
{
    Border border = new Border();
    TiXmlNode* node = childElement->FirstChild();
    border.setDirection(node->ToElement());
    border.setName((node->NextSibling())->ToElement());
    return border;
}

Condition setCondition(TiXmlElement* element)
{
    Condition condition = new Condition();
    for (TiXmlNode* node = element->FirstChild(); node != NULL; node = node->NextSibling())
    {
        TiXmlElement* childElement = node->ToElement();
        std::string name = childElement->ValueStr();
        std::string value = childElement->GetText();
        if (name == "has")
        {
            condition.setHas(value);
        }
        if (name == "owner")
        {
            condition.setOwner(value);
        }
        if (name == "object")
        {
            condition.setObject(value);
        }
        if (name == "status")
        {
            condition.setStatus(value);
        }

    }
}

Trigger roomsTrigger(TiXmlElement* element)
{
    Trigger roomTrigger = new Trigger();
    for (TiXmlNode* node = element->FirstChild(); node != NULL; node = node->NextSibling())
    {
        TiXmlElement* childElement = node->ToElement();
        std::string name = childElement->ValueStr();
        std::string value = childElement->GetText();
        if (name == "command")
        {
            roomTrigger.setCommand(value);
        }
        if (name == "type")
        {
            roomTrigger.setType(value);
        }
        if (name == "condition")
        {
            roomTrigger.setType(setCondition(childElement));
        }
        if (name == "print")
        {
            roomTrigger.setPrint(value);
        }
        if (name == "action")
        {
            roomTrigger.setAction(value);
        }
    }
}

Turnon itemTurnOn(TiXmlElement* childElement)
{
    Turnon itemTurnOn = new Turnon();
    TiXmlNode* node = childElement->FirstChild();
    itemTurnOn.setPrint(node->ToElement());
    itemTurnon.setAction((node->NextSibling())->ToElement());
    return itemTurnOn;
}

Item loadItems(TiXmlElement* element)
{
    Item item = new Item();

    for (TiXmlNode* node = element->FirstChild(); node != NULL; node = node->NextSibling())
    {
        TiXmlElement* childElement = node->ToElement();
        std::string name = childElement->ValueStr();
        std::string value = childElement->GetText();
        if (name == "name")
        {
            item.setName(value);
        }
        if (name == "writing")
        {
            item.setWriting(value);
        }
        if (name == "status")
        {
            item.setStatus(value);
        }
        if (name == "turnon")
        {
            item.setTurnon(itemTurnOn(childElement));
        }
    }
    return item;
}

Turnon itemTurnOn(TiXmlElement* childElement)
{
    Turnon itemTurnOn = new Turnon();
    TiXmlNode* node = childElement->FirstChild();
    itemTurnOn.setPrint(node->ToElement());
    itemTurnon.setAction((node->NextSibling())->ToElement());
    return itemTurnOn;
}

Container loadContainers(TiXmlElement* element)
{
    Container container = new Container();

    for (TiXmlNode* node = element->FirstChild(); node != NULL; node = node->NextSibling())
    {
        TiXmlElement* childElement = node->ToElement();
        std::string name = childElement->ValueStr();
        std::string value = childElement->GetText();
        if (name == "name")
        {
            container.setName(value);
        }
        if (name == "item")
        {
            container.setItem(loadItems(value));
        }
        if (name == "status")
        {
            container.setStatus(value); 
        }
        if (name == "accept")
        {
            container.setAccept(value);
        }
        if (name == "trigger")
        {
            container.setTrigger(roomsTrigger(childElement)); 
        }
    }
    return container;
}

Creature loadCreatures(TiXmlElement* element)
{
    Creature creature = new Creature();

    for (TiXmlNode* node = element->FirstChild(); node != NULL; node = node->NextSibling())
    {
        TiXmlElement* childElement = node->ToElement();
        std::string name = childElement->ValueStr();
        std::string value = childElement->GetText();
        if (name == "name")
        {
            creature.setName(value);
        }
        if (name == "vulnerability")
        {
            creature.setVulnerability(value);
        }
        if (name == "attack")
        {
            creature.setAttack(value); //nested
        }
        if (name == "trigger")
        {
            creature.setTrigger(roomsTrigger(childElement));
        }
        
}