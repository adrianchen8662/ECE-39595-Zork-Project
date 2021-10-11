#ifndef TURNON_H_
#define TURNON_H_
#include <string>

using namespace std;

class Turnon{
public:
    Turnon();
    void setPrint(string print);
    void setAction(string action);
private:
    string print;
    string action;
};


#endif