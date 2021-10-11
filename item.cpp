#include <iostream>
#include <string>
#include <vector>
#include "item.h"
using namespace std;



Item::Item(){
    cout<<"Created Item";
}
void Item::setName(string name){
    this -> name = name;
}
void Item::setStatus(string status){
    this -> status = status;
}
void Item::setDesc(string desc){
    this -> desc = desc;
}
void Item::setWriting(string writing){
    this -> writing = writing;
}
void Item::setTurnon(Turnon turnon){
    this -> turnon = turnon;
}
void Item::setTrigger(Trigger trigger){
    this -> triggers.push_back(trigger);
}