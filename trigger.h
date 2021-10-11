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
    void addCommand(string commandName);
    void addCondition(Condition* conditionObj);
    void addCondition(Condition conditionObj);
    void addString(string stringToPrint);

private:
    string type;
    string command;
    vector<Condition> conditions;
    string stringToPrint;

};

#endif