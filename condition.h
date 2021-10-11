#ifndef CONDITION_H_
#define CONDITION_H_
#include <string>
using namespace std;

class Condition{
public:
    Condition(bool has, string objectName, string ownerName);
    bool checkCondition();
private:
    bool has;
    string objectName;
    string ownerName;

};


#endif