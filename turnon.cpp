#include <iostream>
#include <string>
#include <vector>
#include "turnon.h"
using namespace std;


Turnon::Turnon(){
    cout<<"Created new Turnon";
}
void Turnon::setPrint(string print){
    this -> print.push_back(print);
}
void Turnon::setAction(string action){
    this -> actions.push_back(action);
}