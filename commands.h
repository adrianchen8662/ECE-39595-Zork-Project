#ifndef COMMANDS_H_
#define COMMANDS_H_
#include <iostream>
#include <string>
#include "player.h"
#include "room.h"
#include "border.h"
using namespace std;

bool whichCommand(string command, Player* player, vector<Room*> rooms, Room* JunkyardR);
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
template <typename T>
void addCommand(T* temp, Item* item);
void deleteCommand(Item* item);
void updateCommand(Player* player, string action);
void gameOverCommand();
void openCommand(Player* player, string command);
void readCommand(Player* player, string item);
void putCommand(Player* player, string item, string container);
void turnOnCommand(Player* player, vector<Room*> rooms, string item);
void attackCommand(Player* player, string creature, string item);
bool conditionChecker(Trigger* trigger, Player* player, vector<Room*> rooms);
Trigger* findCommands(vector<Trigger*> triggers, string command);

#endif