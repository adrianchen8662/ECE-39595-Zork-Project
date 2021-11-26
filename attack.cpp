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
