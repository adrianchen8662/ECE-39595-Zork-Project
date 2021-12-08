#ifndef CONTAINER_H_
#define CONTAINER_H_
#include <string>
#include "trigger.h"
#include "item.h"
using namespace std;

class Container{
public:
    Container();
    void setName(string name);
    void setStatus(string status);
    void setOpen();
    void setClosed();
    void setDesc(string desc);
    void setAccept(string accept);
    void setItem(Item* item);
    void setTrigger(Trigger* trigger);
    vector<Trigger*> getTriggers();
    vector<Item*> getItems();
    string getName();
    int getOpen();
    void deleteItem(string object);
private:
    string name;
    int open;
    string status;
    string desc;
    vector<string> accept;
    vector<Item*> items;
    vector<Trigger*> triggers;
};

#endif
