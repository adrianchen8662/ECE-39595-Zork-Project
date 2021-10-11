#ifndef ITEM_H_
#define ITEM_H_
#include "turnon.h"
#include <string>
using namespace std;

class Item{
public:
    Item();
    void setName(string name);
    void setWriting(string writing);
    void setStatus(string status);
    void setTurnon(Turnon* turnon);

private:
    string name;
    string writing;
    string status;
    vector<Turnon> turnons;

};

#endif
