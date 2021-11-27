#include <iostream>
#include <string>
#include <vector>
#include "turnon.h"
using namespace std;


Turnon::Turnon(){
    //cout<<"Created new Turnon";
}
void Turnon::setPrint(string print){
    this -> print = print;
}
void Turnon::setAction(string action){
    this -> action = action;
}

string Turnon::getPrint()
{
    return this->print;
}

string Turnon::getAction()
{
    return this->action;
}