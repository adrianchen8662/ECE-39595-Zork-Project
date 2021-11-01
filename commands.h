#ifndef COMMANDS_H_
#define COMMANDS_H_
#include <iostream>
#include <string>
#include "player.h"
#include "room.h"
#include "border.h"
using namespace std;

bool whichCommand(string command, Player* player, vector<Room*> rooms);
Room* searchRoom(vector<Room*> rooms, string name);
Item* searchItems(vector<Item*> items, string name);
void moveNorthCommand(Player* player, vector<Room*> rooms);
void moveSouthCommand(Player* player, vector<Room*> rooms);
void moveEastCommand(Player* player, vector<Room*> rooms);
void moveWestCommand(Player* player, vector<Room*> rooms);
void inventoryCommand(Player* player);
void takeCommand(Player* player, string item);
void exitCommand();
void dropCommand(Player* player, string item);
void addCommand();
void deleteCommand();
void updateCommand();
void gameOverCommand();

#endif