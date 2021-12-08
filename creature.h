#ifndef CREATURE_H_
#define CREATURE_H_
#include <string>
#include "attack.h"
#include "trigger.h"
using namespace std;

class Creature{
public:
    Creature();
    void setName(string name);
    void setStatus(string status);
    void setVulnerability(string vul);
    void setAttack(Attack* attack);
    void setTrigger(Trigger* trigger);
    string getName();
    vector<Attack*> getAttacks();
    vector<string> getVulnerabilities();
    vector<Trigger*> getTriggers();
private:
    string name;
    string status;
    vector<string> vul;
    vector<Attack*> attacks;
    vector<Trigger*> triggers;
    vector<Condition*> conditions;
};

#endif