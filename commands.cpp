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

void whichCommand(string command, Player* player)
{
    if (command.compare("n") == 0)
    {
        moveNorthCommand(player);
    }
    if (command.compare("s") == 0)
    {
        moveSouthCommand(player);
    }
    if (command.compare("e") == 0)
    {
        moveEastCommand(player);
    }
    if (command.compare("w") == 0)
    {
        moveWestCommand(player);
    }
    if (command.compare("i") == 0)
    {
        inventoryCommand(player);
    }
    if ((command.substr(0,3)).compare("take") == 0)
    {
        takeCommand();
    }
    if (command.compare("open exit") == 0)
    {
        exitCommand();
    }
    if ((command.substr(0,3)).compare("drop") == 0)
    {
        dropCommand();
    }
    cout << "Command not recognized!" << endl;
}

//for movement 
void moveNorthCommand()
{

}

void moveSouthCommand()
{

}

void moveEastCommand()
{

}

void moveWestCommand()
{

}

void inventoryCommand()
{

}

void takeCommand()
{

}

void openCommand()
{

}

void exitCommand()
{

}

void readCommand()
{

}

void dropCommand()
{

}

void putCommand() 
{

}

void turnOnCommand()
{

}

void attackCommand() 
{

}

