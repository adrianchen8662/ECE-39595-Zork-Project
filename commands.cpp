//this file will store all the commands for movement and actions

//which command was run, accepts string from input and picks out the command needed

//most of these need an inventory vector to hold items
//vector<Item*> inventory or something in main

//solution 1: make the player a new class with things to hold items, location and other stuff needed to know where they are and what they can do

//get things from cin as a string
//funtion that does visual things

#include "commands.h"

bool whichCommand(string command, Player* player, vector<Room*> rooms)
{
    if (command.compare("where") == 0) //debug command
    {
        cout << player->getRoom()->getName() << endl;
        cout << player->getRoom()->getDesc() << endl;
    }
    else if (command.compare("borders") == 0) //debug command
    {
        vector<Border*> borders = player->getRoom()->getBorders();
        for (Border* i: borders)
        {
            cout << i->getName() + " - ";
            cout << i->getDirection() << endl;
        }
    }
    else if (command.compare("n") == 0)
    {
        moveNorthCommand(player, rooms);
    }
    else if (command.compare("s") == 0)
    {
        moveSouthCommand(player, rooms); //yada yada
    }
    else if (command.compare("e") == 0)
    {
        moveEastCommand(player, rooms); //check east
    }
    else if (command.compare("w") == 0)
    {
        moveWestCommand(player, rooms); //check west from player's current room and find anything
    }
    else if (command.compare("i") == 0)
    {
        inventoryCommand(player); //player has inventory data as a vector
    }
    else if ((command.substr(0,4)).compare("take") == 0)
    {
        takeCommand(player, command.substr(5)); //player has room data, just look for that room
    }
    else if (command.compare("open exit") == 0)
    {
        return true;
    }
    else if ((command.substr(0,4)).compare("drop") == 0)
    {
        dropCommand(player, command.substr(5));
    }
    else
    {
        cout << "command not recognized" << endl;
    }
    return false;
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
    return NULL;
}

Item* searchItems(vector<Item*> items, string name)
{
    for (Item* i: items)
    {
        if (i->getName().compare(name) == 0)
        {
            return i;
        }
    }
    return NULL;
}

//for movement 
void moveNorthCommand(Player* player, vector<Room*> rooms)
{
    vector<Border*> borders = player->getRoom()->getBorders();
    for (Border* i: borders)
    {
        if (i->getDirection().compare("north") == 0)
        {
            player->setRoom(searchRoom(rooms,i->getName()));
            cout << "moved to " + player->getRoom()->getName() << endl;
            return;
        }
    }
    cout << "cannot move that way" << endl;
}

void moveSouthCommand(Player* player, vector<Room*> rooms)
{
    vector<Border*> borders = player->getRoom()->getBorders();
    for (Border* i: borders)
    {
        if (i->getDirection().compare("south") == 0)
        {
            player->setRoom(searchRoom(rooms, i->getName()));
            cout << "moved to " + player->getRoom()->getName() << endl;
            return;
        }
    }
    cout << "cannot move that way" << endl;
}


void moveEastCommand(Player* player, vector<Room*> rooms)
{
    vector<Border*> borders = player->getRoom()->getBorders();
    for (Border* i: borders)
    {
        if (i->getDirection().compare("east") == 0)
        {
            player->setRoom(searchRoom(rooms, i->getName()));
            cout << "moved to " + player->getRoom()->getName() << endl;
            return;
        }
    }
    cout << "cannot move that way" << endl;
}

void moveWestCommand(Player* player, vector<Room*> rooms)
{
    vector<Border*> borders = player->getRoom()->getBorders();
    for (Border* i: borders)
    {
        if (i->getDirection().compare("west") == 0)
        {
            player->setRoom(searchRoom(rooms, i->getName()));
            cout << "moved to " + player->getRoom()->getName() << endl;
            return;
        }
    }
    cout << "cannot move that way" << endl;
}

void inventoryCommand(Player* player)
{
    vector<Item*> items = player->checkInventory();
    if (items.size() == 0)
    {
        cout << "Inventory: empty" << endl;
        return;
    }
    for (Item* i: items)
    {
        cout << i->getName() << endl;
    }
}

void takeCommand(Player* player, string item)
{
    Item* itemToFind = searchItems(player->getRoom()->getItems(), item);
    if (itemToFind == NULL)
    {
        cout << item + "not in room" << endl;
        return;
    }
    player->setItem(itemToFind);
    // put deleteCommand here for that room
    player->getRoom()->deleteItem(itemToFind->getName());
    cout << "Item " + item + " added to the inventory" << endl;

}

void dropCommand(Player* player, string item)
{
    Item* itemToFind = searchItems(player->checkInventory(), item);
    if (itemToFind == NULL)
    {
        cout << item + " not in inventory" << endl;
        return;
    }
    player->getRoom()->setItem(searchItems(player->checkInventory(), item));
    player->removeItem(itemToFind);
    cout << item + " dropped" << endl;
}

/*
Add <object> to <room/container>: creates an instance of <object> with the specified room or container
being the owner. This does not work with the inventory
*/

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