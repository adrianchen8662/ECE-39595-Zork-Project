#include <iostream>
#include <string>
#include <vector>
#include "room.h"
using namespace std;

Room::Room(){
    this -> type = "Regular";
    //cout<<"Room Created" << endl;
}
void Room::setName(string name){
    this->name = name;
    //cout<<"Set Room name to " << name << endl;
}

void Room::setStatus(string status){
    this -> status = status;
    //cout<<"Set Room status to " << status << endl;
}

void Room::setType(string type){
    this -> type = type;
    //cout<<"Set Room type to " << type << endl;
}

void Room::setDesc(string desc){
    this -> desc = desc;
    //cout<<"Set Room description to " << desc << endl;
}

void Room::setBorder(Border* border){
    this -> borders.push_back(border);
    //cout << "Added border to room " << this -> name << endl;
}

void Room::setContainer(Container* container){
    this -> containers.push_back(container);
    //cout << "Added container to room " << this -> name << endl;
}

void Room::setItem(Item* item){
    this->items.push_back(item);
    ////cout<<"Added " << item.getName() << " to list of items in Room " << this->name << endl;
}

void Room::setCreature(Creature* creature){
    this -> creatures.push_back(creature);
    //cout << "Added creature to room " << this -> name << endl;
}

void Room::setTrigger(Trigger* trigger){
    this -> triggers.push_back(trigger);
    //cout << "Added trigger to room " << this -> name << endl;
}


string Room::getName(){
    return this->name;
}

string Room::getDesc(){
    return this->desc;
}

vector<Border*> Room::getBorders()
{
    return this->borders;
}

vector<Item*> Room::getItems()
{
    return this->items;
}

vector<Creature*> Room::getCreatures()
{
    return this->creatures;
}

vector<Trigger*> Room::getTriggers()
{
    return this->triggers;
}

vector<Container*> Room::getContainers()
{
    return this->containers;
}

string Room::getType(){
    return this->type;
}

void Room::deleteItem(string object)
{
    int i = 0;
    for(; i < (int)(this->items.size()); i++){
        if(this->items[i]->getName() == object){
            break;
        }
    }  
    this->items.erase(this->items.begin() + i);
    
}

void Room::deleteCreature(string creature)
{
    int i = 0;
    for(; i < (int)(this->creatures.size()); i++){
        if(this->creatures[i]->getName() == creature){
            break;
        }
    }  
    this->creatures.erase(this->creatures.begin() + i);
    
}