#include <iostream>
#include <string>
#include <vector>
#include "trigger.h"
using namespace std;


Trigger::Trigger(){
    //cout<<"Created new trigger";
}

void Trigger::addType(string type){
    this -> type = type;
    //cout<<"Set trigger type to " << type << endl;
}

void Trigger::addCondition(Condition* condition){
    this -> condition = condition;
    //cout<<"Added condition to trigger" << endl;
}

void Trigger::addPrint(string print){
    this -> print = print;
}

void Trigger::addAction(string action){
    this -> actions.push_back(action);
}

void Trigger::addCommand(string command){
    this -> command = command;
}

string Trigger::getCommand()
{
    return command;
}

string Trigger::getPrint()
{
    return print;
}

Condition* Trigger::getCondition()
{
    return condition;
}

string Trigger::getType()
{
    return type;
}

vector<string> Trigger::getActions()
{
    return actions;
}