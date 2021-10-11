#include <iostream>
#include <string>
#include <vector>
#include "Condition.h"
using namespace std;

Condition::Condition(bool has, string objectName, string ownerName){
    this -> has = has;
    this -> objectName = objectName;
    this -> ownerName = ownerName;
}
