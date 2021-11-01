#ifndef ROOM_H_
#define ROOM_H_
#include "trigger.h"
#include "border.h"
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
    void setItem(Item* itemName);
    void setContainer(Container* containerName);
    void setCreature(Creature* creature);
    void setTrigger(Trigger* trigger);
    void setBorder(Border* border);
    void deleteItem(string object);
    string getName();
    string getDesc();
    vector<Border*> getBorders();
    vector<Item*> getItems();
private:
    string name;
    string status;
    string type;
    string desc;
    vector<Border*> borders;
    vector<Container*> containers;
    vector<Item*> items;
    vector<Creature*> creatures;
    vector<Trigger*> triggers;
};

#endif