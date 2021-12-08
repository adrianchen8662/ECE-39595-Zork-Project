#include <iostream>
#include <string>
#include <vector>
#include "container.h"
using namespace std;

Container::Container(){
    //cout << "Created Container";
    setClosed();
}

void Container::setName(string name){
    this -> name = name;
    //cout<<"Set Container name to " << name << endl;
}

void Container::setStatus(string status){
    this -> status = status;
    //cout<<"Set Container status to " << status << endl;
}

void Container::setDesc(string desc){
    this -> desc = desc;
    //cout<<"Set Container description to " << desc << endl;
}

void Container::setAccept(string accept){
    this -> accept.push_back(accept);
    //cout << "Added " << accept << " to list of accepted items";
}

void Container::setItem(Item* item){
    this -> items.push_back(item);
}

void Container::setTrigger(Trigger* trigger){
    this -> triggers.push_back(trigger);
}

vector<Trigger*> Container::getTriggers()
{
    return this->triggers;
}

vector<Item*> Container::getItems()
{
    return this->items;
}

string Container::getName()
{
    return this->name;
}

void Container::setOpen(){
    this->open = 1;
}

void Container::setClosed(){
    this->open = 0;
}

int Container::getOpen(){
    return this->open;
}