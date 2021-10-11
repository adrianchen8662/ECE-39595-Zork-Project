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
    void setItem(string item);
    void setStatus(string status);
    void setAccept(string accept);
    void setTrigger(Trigger trigger);
    void setTrigger(Trigger* trigger);

private:
    string name;
    string status;
    string desc;
    vector<string> accept;
    vector<Item> items;
    vector<Trigger> triggers;
};

#endif
