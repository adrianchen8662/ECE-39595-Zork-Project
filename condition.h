#ifndef CONDITION_H_
#define CONDITION_H_
#include <string>
using namespace std;

class Condition{
public:
    Condition();
    Condition(bool has, string objectName, string ownerName);
    void setHas(bool has);
    void setObject(string objectName);
    void setOwner(string ownerName);
    void setStatus(string status);
    bool getHas();
    string getObject();
    string getOwner();
    string getStatus();
private:
    bool has;
    string objectName;
    string ownerName;
    string status;

};


#endif