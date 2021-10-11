#ifndef ROOM_H_
#define ROOM_H_
#include "Trigger.h"
#include "Border.h"
#include "container.h"
#include "creature.h"
#include <string>


using namespace std;

class Room {
public:
    Room();
    void setName(string name);
    void setDesc(string desc);
    void setItem(string itemName);
    void setContainer(string containerName);
    void setCreature(string creatureName);
    void setTrigger(Trigger* trigger);
    void setTrigger(Trigger trigger);
    void setBorder(Border* border);
    void setBorder(Border border);
private:
    string name;
    string desc;
    vector<string> items;
    vector<Container> containers;
    vector<Creature> creatures;
    vector<Border> borders;
    vector<Trigger> triggers;
};

#endif