#ifndef ROOM_H_
#define ROOM_H_
#include "Trigger.h"
#include "Border.h"
#include "container.h"
#include "creature.h"
#include "item.h"
#include <string>


using namespace std;

class Room {
public:
    Room();
    void setName(string name);
    void setStatus(string status);
    void setType(string type);
    void setDesc(string desc);
    void setItem(Item itemName);
    void setContainer(string containerName);
    void setCreature(string creatureName);
    void setTrigger(Trigger* trigger);
    void setTrigger(Trigger trigger);
    void setBorder(Border* border);
    void setBorder(Border border);
private:
    string name;
    string status;
    string type;
    string desc;
    vector<Border> borders;
    vector<Container> containers;
    vector<Item> items;
    vector<Creature> creatures;
    vector<Trigger> triggers;
};

#endif