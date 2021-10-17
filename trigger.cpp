#include <iostream>
#include <string>
#include <vector>
#include "trigger.h"
using namespace std;


Trigger::Trigger(){
    cout<<"Created new trigger";
}

void Trigger::addType(string type){
    this -> type = type;
    cout<<"Set trigger type to " << type << endl;
}
