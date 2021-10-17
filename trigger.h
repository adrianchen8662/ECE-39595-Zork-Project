#ifndef TRIGGER_H_
#define TRIGGER_H_
#include "condition.h"
#include <string>
#include <vector>
using namespace std;

class Trigger{
public:
    Trigger();
    void addType(string triggerType);
    void addCondition(Condition* conditionObj);
    void addString(string stringToPrint);

private:
    string type;
    vector<Condition*> conditions;
    vector<string> prints;
    vector<string> actions;

};

#endif