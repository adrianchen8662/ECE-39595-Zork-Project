#ifndef BORDER_H_
#define BORDER_H_
#include <string>
using namespace std;

class Border{
public:
    Border();
    void setDirection(string direction);
    void setName(string name);

private:
    string direction;
    string name;

};


#endif