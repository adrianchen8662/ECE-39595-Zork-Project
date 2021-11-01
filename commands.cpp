//this file will store all the commands for movement and actions

//which command was run, accepts string from input and picks out the command needed

//most of these need an inventory vector to hold items
//vector<Item*> inventory or something in main

//solution 1: make the player a new class with things to hold items, location and other stuff needed to know where they are and what they can do

//get things from cin as a string
//funtion that does visual things

#include <iostream>
#include <string>
#include <player.h>

using namespace std;

void whichCommand(string command, Player* player, vector<Room*> rooms)
{
    if (command.compare("n") == 0)
    {
        moveNorthCommand(player, rooms);
    }
    if (command.compare("s") == 0)
    {
        moveSouthCommand(player, rooms); //yada yada
    }
    if (command.compare("e") == 0)
    {
        moveEastCommand(player, rooms); //check east
    }
    if (command.compare("w") == 0)
    {
        moveWestCommand(player, rooms); //check west from player's current room and find anything
    }
    if (command.compare("i") == 0)
    {
        inventoryCommand(player); //player has inventory data as a vector
    }
    if ((command.substr(0,3)).compare("take") == 0)
    {
        takeCommand(player, command.substr(5)); //player has room data, just look for that room
    }
    if (command.compare("open exit") == 0)
    {
        exitCommand();
    }
    if ((command.substr(0,3)).compare("drop") == 0)
    {
        dropCommand(player, command.substr(5));
    }
    cout << "Command not recognized!" << endl;
}

//finding which room it's in based on room name
Room* searchRoom(vector<Room*> rooms, string name)
{
    for (Room* i: rooms)
    {
        if (i->getName().compare(name) == 0)
        {
            return i;
        }
    }
}

//for movement 
void moveNorthCommand(Player* player, vector<Room*> rooms)
{
    Room* room = player->getRoom();
    vector<Border*> borders = room->getBorders();
    for (Border* i: borders)
    {
        if (i->getDirection().compare("West") == 0)
        {
            player->setRoom(searchRoom(rooms,i->getName())); //need room search here
        }
    }
}

void moveSouthCommand(Player* player, vector<Room*> rooms)
{
    Room* room = player->getRoom();
    vector<Border*> borders = room->getBorders();
    for (Border* i: borders)
    {
        if (i->getDirection().compare("West") == 0)
        {
            player->setRoom(searchRoom(rooms, i->getName())); //need room search here, getting a name of a room from borders
        }
    }
}



void moveEastCommand(Player* player, vector<Room*> rooms)
{
    Room* room = player->getRoom();
    vector<Border*> borders = room->getBorders();
    for (Border* i: borders)
    {
        if (i->getDirection().compare("West") == 0)
        {
            player->setRoom(searchRoom(rooms, i->getName())); //need room search here
        }
    }
}

void moveWestCommand(Player* player, vector<Room*> rooms)
{
    //need a getBorder command in room
    //need a getDirection command in border
    Room* room = player->getRoom();
    vector<Border*> borders = room->getBorders();
    for (Border* i: borders)
    {
        if (i->getDirection().compare("West") == 0)
        {
            player->setRoom(searchRoom(rooms, i->getName())); //need room search here
        }
    }
}

void inventoryCommand(Player* player)
{
    vector<Item*> items = player->checkInventory();
    for (Item* i: items)
    {
        cout << i->getName() << endl;
    }
}

void takeCommand(Player* player, string item)
{
    //need a getItems command in room
    Room* room = player->getRoom();
    cout << room->getName() << endl;
}

void exitCommand()
{

}

void dropCommand(Player* player, string item)
{
    
}

void addCommand()
{

}

void deleteCommand()
{

}

void updateCommand()
{

}

void gameOverCommand()
{

}