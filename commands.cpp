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
    //first check if it does a trigger, like if i move north then it wouldn't let me move until i got the torch
    // need getTriggers for room and a searchTriggers for a trigger that has a condition that matches with the command
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
    // this has to happen after open exit to not confuse open commands
    else if ((command.substr(0,4)).compare("open") == 0)
    {
        // open <container>
        openCommand(player, command.substr(5));
    }
    else if ((command.substr(0,4)).compare("read") == 0)
    {
        // read <item>
        readCommand(player, command.substr(5));
    }
    else if ((command.substr(0,3)).compare("put") == 0)
    {
        // put <item> in <container>
        // NOT GOING TO WORK, NEED NEW WAY TO GET COMPOUND COMMANDS
        putCommand(player, command.substr(4));
    }
    else if ((command.substr(0,4)).compare("turn") == 0)
    {
        // turn on <item>
        turnOnCommand(player, command.substr(7));
    }
    else if ((command.substr(0,6)).compare("attack") == 0)
    {
        // attack <creature> with <item>
        attackCommand();
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

Creature* searchCreatures(vector<Creature*> creatures, string name)
{
    for (Creature* i: creatures)
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

// update command to include adding the dropped item to the pocket dimension
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

void openCommand()
{

}

void readCommand(Player* player, string item)
{
    Item* itemToFind = searchItems(player->checkInventory(), item);
    if (itemToFind == NULL)
    {
        cout << item + " not in inventory" << endl;
        return;
    }
    cout << itemToFind->getWriting() << endl;
}

void putCommand()
{

}

void turnOnCommand(Player* player, string item)
{
    Item* itemToFind = searchItems(player->checkInventory(), item);
    if (itemToFind == NULL)
    {
        cout << item + " not in inventory" << endl;
        return;
    }
    //then, attempt to turn on, whatever that means

}

void attackCommand(Player* player, string creature, string item)
{
    // check if item exists in inventory
    Item* itemToFind = searchItems(player->checkInventory(), item);
    if (itemToFind == NULL)
    {
        cout << item + " not in inventory" << endl;
        return;
    }
    //check if creature exists in room
    Creature* creatureToFind =  searchCreatures(player->getRoom(), creature)
    if (creatureToFind == NULL)
    {
        cout << creature + " not in room" << endl;
        return;
    }
    //check if item interacts with creature

}

/*
Add <object> to <room/container>: creates an instance of <object> with the specified room or container
being the owner. This does not work with the inventory
*/
/*
Conversely, deleted objects shouldn't just vanish. Placing them in another room class that can hold it all would be good, since rooms
cannot be returned
Needs to happen in main
*/

void addCommand()
{
    
}

// instead of messing around with generic pointers, give the delete command a name and have it dig to find what's being deleted
// the description isn't correct. I can't just delete <object>, it can fit a lot of things, like <item> or <creature>
void deleteCommand()
{

}

// update <object> to <status>
void updateCommand(Player* player, string action)
{
    string itemname = action.substr(7,action.find(" to ") - 7);
    string status = action.substr(action.find(" to ") + 4);
    // THIS ONLY CHECKS THE PLAYER INVENTORY AND ROOM THEY INHABIT, NOT GLOBAL SEARCH
    Item* itemToFind = searchItems(player->checkInventory(),itemname);
    if (itemToFind == NULL)
    {
        itemToFind = searchItems(player->getRoom()->getItems(), itemname);
        if (itemToFind == NULL)
        {
            cout << "internal command updateCommand failed" << endl;
            return;
        }
    }
    itemToFind->setStatus(status);
}

void gameOverCommand()
{
    // deleteCommand on everything
    cout << "Victory!" << endl;
}