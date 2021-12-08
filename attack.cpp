#include <iostream>
#include <string>
#include <vector>
#include "attack.h"
using namespace std;

Attack::Attack(){
    //cout<<"Created new attack";
}
void Attack::setCondition(Condition* condition){
    this -> condition.push_back(condition);
}
void Attack::setPrint(string print){
    this -> print.push_back(print);
}
void Attack::setAction(string action){
    this->actions.push_back(action);
}

vector<string> Attack::getPrint(){
    return this->print;
}

vector<string> Attack::getAction(){
    return this->actions;
}

vector<Condition*> Attack::getCondition(){
    return this->condition;
}