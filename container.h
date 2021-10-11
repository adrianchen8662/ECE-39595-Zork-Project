#ifndef CONTAINER_H_
#define CONTAINER_H_
#include <string>
#include "trigger.h"
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
    vector<string> items;
    string status;
    string accept;
    vector<Trigger> triggers;


};

#endif
