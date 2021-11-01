#include "XMLParser.h"

//Search function
//for anything we need to search, it'll always be level 1 of the xml file. 
//Start from the root, and look at each valuestr until you find the type you want.
//check if that node contains an element with the name you want
//then, return that node

//asks for a name i.e. torch, type i.e. item, and the root element
//returns the element where the name is at
//used for creature, container, item when found in the room 
TiXmlElement* findElement(std::string nameToFind, std::string typeToFind, TiXmlElement* rootElement)
{
    //searches one level after root node to find something with that type
    for (TiXmlNode* node = rootElement->FirstChild(); node != NULL; node = node->NextSibling())
    {
        TiXmlElement* childElement = node->ToElement();
        std::string name = childElement->ValueStr();
        if (name == typeToFind)
        {
            //if the thing has the same types, look one level deeper to see if it's the same name
            for (TiXmlNode* childNode = childElement->FirstChild(); childNode != NULL; childNode = childNode->NextSibling())
            {
                TiXmlElement* secondChild = childNode->ToElement();
                std::string name = secondChild->ValueStr();
                std::string value = secondChild->GetText() ? secondChild->GetText() : "";
                if (value == nameToFind)
                {

                    return childElement;
                }
            }
        } 
    }
    return NULL;
}

Room* loadRoom(TiXmlElement* element, TiXmlElement* rootElement)
{
    Room* room = new Room();

    for (TiXmlNode* node = element->FirstChild(); node != NULL; node = node->NextSibling())
    {
        TiXmlElement* childElement = node->ToElement();
        std::string name = childElement->ValueStr();
        std::string value = childElement->GetText() ? childElement->GetText() : "";
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
        if (name == "item") //search here
        {
            room -> setItem(loadItems(findElement(value, name, rootElement)));
        }
        if (name == "trigger") 
        {
            cout<<"Trigger"<<endl;
            room -> setTrigger(loadTrigger(childElement));
        }
        if (name == "container") //search here
        {
            room -> setContainer(loadContainers(findElement(value, name, rootElement), rootElement));
        }
        if (name == "border")
        {
            room -> setBorder(loadBorder(childElement));
        }
        if (name == "creature") //search here
        {
            room -> setCreature(loadCreatures(findElement(value, name, rootElement)));
        }
    }
    return room;
}

//convert all of these to pointers
Border* loadBorder(TiXmlElement* element)
{
    Border* border = new Border(); //this one wants a pointer
    for (TiXmlNode* node = element->FirstChild(); node != NULL; node = node->NextSibling())
    {
        TiXmlElement* childElement = node->ToElement();
        std::string name = childElement->ValueStr();
        std::string value = childElement->GetText();
        if (name == "name")
        {
            border->setName(value);
        }
        if (name == "direction")
        {
            border->setDirection(value);
        }
    }
    return border;
}


Condition* loadCondition(TiXmlElement* element)
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
Trigger* loadTrigger(TiXmlElement* element)
{
    cout<<"Starting Trigger load" <<endl;
    Trigger* trigger = new Trigger();
    for (TiXmlNode* node = element->FirstChild(); node != NULL; node = node->NextSibling())
    {
        TiXmlElement* childElement = node->ToElement();
        std::string name = childElement->ValueStr();
        std::string value = childElement->GetText() ? childElement->GetText() : "";
        if (name == "command")
        {
            trigger->addCommand(value);
        }
        if (name == "type")
        {
            trigger->addType(value);
        }
        if (name == "condition")
        {
            trigger->addCondition(loadCondition(childElement));
        }
        if (name == "print")
        {
            trigger->addPrint(value);
        }
        if (name == "action")
        {
            trigger->addAction(value);
        }
    }
    return trigger;
}

//change to pointers
Turnon* itemTurnOn(TiXmlElement* childElement)
{
    Turnon* itemTurnOn = new Turnon();
    TiXmlNode* node = childElement->FirstChild();
    itemTurnOn->setPrint((node->ToElement())->GetText());
    itemTurnOn->setAction((node->NextSibling())->ToElement()->GetText());
    return itemTurnOn;
}

//change to pointers
Item* loadItems(TiXmlElement* element)
{
    Item* item = new Item();
    cout<<"Starting Item load" <<endl;
    cout<<element -> FirstChild() ->ToElement()-> GetText();
    for (TiXmlNode* node = element->FirstChild(); node != NULL; node = node->NextSibling())
    {
        TiXmlElement* childElement = node->ToElement();
        std::string name = childElement->ValueStr();
        std::string value = childElement->GetText() ? childElement->GetText() : "";
        if (name == "trigger")
        {
            item->setTrigger(loadTrigger(childElement));
        }
        if (name == "name")
        {
            item->setName(value);
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
Turnon* loadItemTurnOn(TiXmlElement* childElement)
{
    Turnon* itemTurnOn = new Turnon();
    TiXmlNode* node = childElement->FirstChild();
    itemTurnOn->setPrint(node->ToElement()->GetText());
    itemTurnOn->setAction((node->NextSibling())->ToElement()->GetText());
    return itemTurnOn;
}

Container* loadContainers(TiXmlElement* element, TiXmlElement* rootElement)
{
    Container* container = new Container();

    for (TiXmlNode* node = element->FirstChild(); node != NULL; node = node->NextSibling())
    {
        TiXmlElement* childElement = node->ToElement();
        std::string name = childElement->ValueStr();
        std::string value = childElement->GetText() ? childElement->GetText() : "";
        if (name == "name")
        {
            container->setName(value);
        }
        if (name == "item")
        {
            container->setItem(loadItems(findElement(value, name, rootElement)));
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
            container->setTrigger(loadTrigger(childElement)); 
        }
    }
    return container;
}

Attack* loadAttack(TiXmlElement* element)
{
    Attack* attack = new Attack();

    for (TiXmlNode* node = element->FirstChild(); node != NULL; node = node->NextSibling())
    {
        TiXmlElement* childElement = node->ToElement();
        std::string name = childElement->ValueStr();
        std::string value = childElement->GetText() ? childElement->GetText() : "";
        if (name == "condition")
        {
            attack->setCondition(loadCondition(childElement));
        }
        if (name == "print")
        {
            attack->setPrint(value);
        }
        if (name == "action")
        {
            attack->setAction(value);
        }
    }
    return attack;
}

Creature* loadCreatures(TiXmlElement* element)
{
    Creature* creature = new Creature();

    for (TiXmlNode* node = element->FirstChild(); node != NULL; node = node->NextSibling())
    {
        TiXmlElement* childElement = node->ToElement();
        std::string name = childElement->ValueStr();
        std::string value = childElement->GetText() ? childElement->GetText() : "";
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
            creature->setTrigger(loadTrigger(childElement));
        }
    }
    return creature;
}

vector<Room*> loadXMLFile (const std::string filename)
{
    vector <Room*> rooms;
    TiXmlDocument doc(filename); //this is literally a std::sting
    doc.LoadFile();
    TiXmlElement* rootElement = doc.RootElement();

    //idk why ValueStr() isn't defined its literally right there in the documentation
    if (rootElement != NULL && rootElement->ValueStr() == "map")
    {
        for (TiXmlNode *node = rootElement->FirstChild(); node != NULL; node = node->NextSibling())
        {
            TiXmlElement* childElement = node->ToElement();
            if (childElement != NULL)
            {
                std::string name = childElement->ValueStr();
                if (name == "room")
                {
                    Room* room = loadRoom(childElement, rootElement);
                    rooms.push_back(room);
                }
            }
        }
    }
    return rooms;
}