#ifndef CREATURE_H_
#define CREATURE_H_
#include <string>
#include "attack.h"
using namespace std;

class Creature{
public:
    Creature();
    void setName(string name);
    void setVulnerability(string vul);
    void setAttack(Attack attack);
    void setAttack(Attack* attack);
    void setTrigger(Trigger trigger);
    void setTrigger(Trigger* trigger);
private:
    string name;
    string status;
    vector<string> vul;
    string attack;
    vector<Trigger> triggers;
};

#endif