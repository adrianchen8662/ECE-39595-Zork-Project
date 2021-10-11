#include <XMLParser.h>

//loads the XML file into a TiXMLElement pointer to the root, and passes on the values to others
void loadXMLFile() {
    std::string filename = "./sample.xml";
    TiXmlDocument doc (filename);
    doc.LoadFile();

    TiXmlElement* rootElement = doc.RootElement();
    if (rootElement != NULL && rootElement->ValueStr() == "map") {
        TiXmlElement* element = ;
        for (TiXmlNode* node = element->FirstChild(); node != NULL; node = node->NextSibling()) {
            TiXmlElement* childElement = node->ToElement();
            if(childElement != NULL)    
                //probably best to store all these pointers to classes in their own vectors, one for each type
                //vector <Room> rooms
                //vector <Item> items
                //vector <Container> containers
                //vector <Creature> creatures
                if (childElement->ValueStr() == "room")
                {
                    Room* room = new Room()
                    room = loadRooms(childElement);
                }
                if (childElement->ValueStr() == "item")
                {
                    Item* item = new Item()
                    item = loadItems(childElement);
                }
                if (chldElement->ValueStr() == "container")
                {
                    Container* container = new Container()
                    container = loadContainers(childElement);
                }
                if (childElement->ValueStr() == "creature")
                {
                    Creature* creature = new Creature()
                    creature = loadCreatures(childElement);
                }
        }
    }
}

//loads the rooms in, attributes with multiple are stored in vectors
void loadRooms() {

}

//loads the items in, turnons are vectors
void loadItems() {

}

void loadContainers() {

}

//loads the creatures in, attacks and triggers are vectors
void loadCreatures() {

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