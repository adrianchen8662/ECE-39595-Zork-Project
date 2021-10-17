#ifndef TURNON_H_
#define TURNON_H_
#include <string>
#include <vector>

using namespace std;

class Turnon{
public:
    Turnon();
    void setPrint(string print);
    void setAction(string action);
private:
    vector<string> print;
    vector<string> actions;
};


#endif