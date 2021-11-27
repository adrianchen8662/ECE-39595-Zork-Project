#include <iostream>
#include <string>
#include <vector>
#include "condition.h"
using namespace std;

Condition::Condition(){
    this -> setHas(false);
}

Condition::Condition(bool has, string objectName, string ownerName){
    this -> has = has;
    this -> objectName = objectName;
    this -> ownerName = ownerName;
}

void Condition::setHas(bool has){
    this -> has = has;
}

void Condition::setObject(string objectName){
    this -> objectName = objectName;
}

void Condition::setOwner(string ownerName){
    this -> ownerName = ownerName;
}

void Condition::setStatus(string status){
    this -> status = status;
}

bool Condition::getHas()
{
    return this->has;
}

string Condition::getObject()
{
    return this->objectName;
}

string Condition::getOwner()
{
    return this->ownerName;
}

string Condition::getStatus()
{
    return this->status; 
}