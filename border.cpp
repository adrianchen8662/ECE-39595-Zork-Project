#include <iostream>
#include <string>
#include <vector>
#include "border.h"
using namespace std;

Border::Border(){
    //cout<<"Created new border" << endl;
}

void Border::setName(string name){
    this -> name = name;
    //cout<<"Set Border name to " << name << endl;
} 

void Border::setDirection(string dir){
    this -> direction = dir;
    //cout<<"Set Border direction to " << dir << endl;
}

string Border::getDirection()
{
    return direction;
}

string Border::getName()
{
    return name;
}