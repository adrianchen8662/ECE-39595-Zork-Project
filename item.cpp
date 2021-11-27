#include <iostream>
#include <string>
#include <vector>
#include "item.h"
using namespace std;



Item::Item(){
    //cout<<"Created Item"<<endl;
}
void Item::setName(string name){
    //cout<<"Set name to "<< name<<endl;
    this -> name = name;
}
void Item::setStatus(string status){
    //cout<<"Set status to "<< status<<endl;
    this -> status = status;
}
void Item::setDesc(string desc){
    //cout<<"Set desc to "<< desc<<endl;
    this -> desc = desc;
}
void Item::setWriting(string writing){
    //cout<<"Set writing to "<< writing<<endl;
    this -> writing = writing;
}
void Item::setTurnon(Turnon* turnon){
    this -> turnon = turnon;
}
void Item::setTrigger(Trigger* trigger){
    this -> triggers.push_back(trigger);
}

vector<Trigger*> Item::getTriggers()
{
    return this->triggers;
}

string Item::getName()
{
    return name;
}

string Item::getWriting()
{
    return writing;
}

Turnon* Item::getTurnon()
{
    return turnon;
}
