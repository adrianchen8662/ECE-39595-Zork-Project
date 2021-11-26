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
    this -> conditions.push_back(condition);
    //cout<<"Added condition to trigger" << endl;
}

void Trigger::addPrint(string print){
    this -> prints.push_back(print);
}

void Trigger::addAction(string action){
    this -> actions.push_back(action);
}

void Trigger::addCommand(string command){
    this -> command.push_back(command);
}