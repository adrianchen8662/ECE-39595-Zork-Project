#ifndef CREATURE_H_
#define CREATURE_H_
#include <string>
#include <vector>
#include "condition.h"
using namespace std;

class Attack{
public:
    Attack();
    void setCondition(Condition* condition);
    void setCondition(Condition condition);
    void setPrint(string print);
    void setAction(string action);

private:
    Condition* condition;
    string print;
    vector<string> actions;
};

#endif