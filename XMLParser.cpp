#include <XMLParser.h>

/*
//loads the XML file into a TiXMLElement pointer to the root, and passes on the values to others
void loadXMLFile(vector <Room> rooms, vector <Item> items, vector <Container> containers, vector <Creature> creatures) {
    std::string filename = "./sample.xml";
    TiXmlDocument doc (filename);
    doc.LoadFile();

    TiXmlElement* rootElement = doc.RootElement();
    if (rootElement != NULL && rootElement->ValueStr() == "map") {
        //this part is probably wrong idk what an element and node
        TiXmlElement* element = ;
        for (TiXmlNode* node = element->FirstChild(); node != NULL; node = node->NextSibling()) {
            TiXmlElement* childElement = node->ToElement();
            if(childElement != NULL)    
                //probably best to store all these pointers to classes in their own vectors, one for each type
                if (childElement->ValueStr() == "room")
                {
                    Room* room = new Room()
                    room = loadRooms(childElement);
                    rooms.push_back(room);
                }
                if (childElement->ValueStr() == "item")
                {
                    Item* item = new Item()
                    item = loadItems(childElement);
                    items.push_back(item);
                }
                if (chldElement->ValueStr() == "container")
                {
                    Container* container = new Container()
                    container = loadContainers(childElement);
                    containers.push_back(container);
                }
                if (childElement->ValueStr() == "creature")
                {
                    Creature* creature = new Creature()
                    creature = loadCreatures(childElement);
                    creature.push_back(creature);
                }
        }
    }
}
*/

void loadXMLFile (vector <Room> rooms, vector <Item> items, vector <Container> containers, vector <Creature> creatures)
{
    std::string filename = "./sample.xml";
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
                if (name == "item")
                {
                    Item item = loadItems();
                    items.push_back(item);
                }
                if (name == "container")
                {
                    Container container = loadContainers();
                    containers.push_back(container);
                }
                if (name == "creature")
                {
                    Creature creature = loadCreatures();
                    creatures.push_back(creature);
                }
            }
        }
    }
}

//loads the rooms in, attributes with multiple are stored in vectors
Room loadRooms(TiXmlElement* element) {
    Room room = new Room();
    for (TiXmlNode* node = element->FirstChild(); node != NULL; node = node->NextSibling())
    {
        TiXmlElement* childElement = node->ToElement();
        std::string name = childElement->ValueStr();
        std::string value = childElement->GetText();
        //update these later based on what values are needed for each set function
        if (name == "name")
        {
            room.setName(value);
        }
        if (name == "description")
        {
            room.setDesc(value);
        }
        if (name == "item")
        {
            room.setItem(value);
        }
        if (name == "trigger")
        {
            room.setTrigger(value);
        }
        if (name == "container")
        {
            room.setContainer(value);
        }
        if (name == "border")
        {
            room.setBorder(value);
        }
        if (name == "creature")
        {

        }
    }
}

//loads the items in, turnons are vectors
Item loadItems(TiXmlElement* element) {

}

Container loadContainers(TiXmlElement* element) {

}

//loads the creatures in, attacks and triggers are vectors
Creatures loadCreatures(TiXmlElement* element) {

}

/*
void loadXMLFile() {
    std::string filename = "./sample.xml";
    TiXmlDocument doc (filename);
    doc.LoadFile();
    TiXmlElement* rootElement = doc.RootElement();
    std::cout << rootElement->ValueStr() << std::endl;
    if (rootElement != NULL && rootElement->ValueStr() == "map")
    {
        std::cout << "Read Successfully" << std::endl;
    }
}

TiXmlElement* loadXMLFile() {
    std::string filename = "./sample.xml";
    TiXmlDocument doc (filename);
    doc.LoadFile();
    TiXmlElement* rootElement = doc.RootElement();
    std::cout << rootElement->ValueStr() << std::endl;
    if (rootElement != NULL && rootElement->ValueStr() == "map")
    {
        return rootElement;
    }
}

//in main, always keep a pointer to the rootELement map

TiXmlNode* goToXMLRooms(TiXmlElement* rootElement) {
    TiXmlNode* roomNode = rootElement -> FirstChild();
    return roomNode;
}

TiXmlElement* goToXMLitems(TiXmlElement* rootElement) {
    while (rootElement->ValueStr() != "item")
    {
        rootElement = rootElement->ToElement();
    if (rootElement != NULL)
    {
        return rootElement;
    }
}
*/