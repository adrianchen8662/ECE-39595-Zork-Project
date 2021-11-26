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
    void addPrint(string stringToPrint);
    void addAction(string action);
    void addCommand(string command);
private:
    string type;
    vector<Condition*> conditions;
    vector<string> prints;
    vector<string> actions;
    vector<string> command;

};

#endif