#include <iostream>
#include <string>
#include <vector>
#include "condition.h"
using namespace std;

Condition::Condition(bool has, string objectName, string ownerName){
    this -> has = has;
    this -> objectName = objectName;
    this -> ownerName = ownerName;
}
