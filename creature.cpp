#include <iostream>
#include <string>
#include <vector>
#include "creature.h"
using namespace std;


Creature::Creature(){
    //cout<<"Created new Creature"<<endl;
}
void Creature::setName(string name){
    this -> name = name;
}
void Creature::setStatus(string status){
    this -> status = status;
}
void Creature::setVulnerability(string vul){
    this -> vul.push_back(vul);
}
void Creature::setAttack(Attack* attack){
    this -> attacks.push_back(attack);
}
void Creature::setTrigger(Trigger* trigger){
    this -> triggers.push_back(trigger);
}

vector<Trigger*> Creature::getTriggers()
{
    return triggers;
}

string Creature::getName()
{
    return name;
}

vector<string> Creature::getVulnerabilities(){
    return this->vul;
}

vector<Attack*> Creature::getAttacks(){
    return this->attacks;
}