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
    string getCommand();
    string getPrint();
    Condition* getCondition();
private:
    string type;
    Condition* condition;
    string print;
    vector<string> actions;
    string command;

};

#endif