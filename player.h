#ifndef PLAYER_H_
#define PLAYER_H_
#include "room.h"
#include "item.h"
#include <string>
using namespace std;

class Player {
public:
    Player();
    void setItem(Item* itemName); //adds an item to the player's inventory SEPARATE FROM ADD/DELETE
    void setRoom(Room* roomName); //sets the room which the player is in
    Room* getRoom(); //returns the room the player is currently in
    vector<Item*> checkInventory(); //returns a vector of all items currently in the player's inventory
    void removeItem(Item* itemName);
private:
    vector<Item*> inventory;
    Room* room;
    string name;
};
#endif