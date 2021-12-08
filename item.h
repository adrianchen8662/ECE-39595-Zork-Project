#ifndef ITEM_H_
#define ITEM_H_
#include "turnon.h"
#include "trigger.h"
#include <string>
using namespace std;

class Item{
public:
    Item();
    void setName(string name);
    void setStatus(string status);
    void setDesc(string desc);
    void setWriting(string writing);
    void setTurnon(Turnon* turnon);
    void setTrigger(Trigger* trigger);
    string getName();
    string getWriting();
    string getStatus();
    Turnon* getTurnon();
    vector<Trigger*> getTriggers();
private:
    string name;
    string status;
    string desc;
    string writing;
    Turnon* turnon;
    vector<Trigger*> triggers;

};

#endif
