#ifndef ATTACK_H_
#define ATTACK_H_
#include <string>
#include <vector>
#include "condition.h"
using namespace std;

class Attack{
public:
    Attack();
    void setCondition(Condition* condition);
    void setPrint(string print);
    void setAction(string action);

private:
    vector<Condition*> condition;
    vector<string> print;
    vector<string> actions;
};

#endif