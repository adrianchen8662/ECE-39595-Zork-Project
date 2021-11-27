//this file will store all the commands for movement and actions

//which command was run, accepts string from input and picks out the command needed

//most of these need an inventory vector to hold items
//vector<Item*> inventory or something in main

//solution 1: make the player a new class with things to hold items, location and other stuff needed to know where they are and what they can do

//get things from cin as a string
//funtion that does visual things

#include "commands.h"

Trigger* findCommands(vector<Trigger*> triggers, string command)
{
    for (Trigger* i: triggers)
    {
        if (i->getCommand().compare(command) == 0)
        {
            return i;
        }
    }
    return NULL;
}

bool whichCommand(string command, Player* player, vector<Room*> rooms)
{
    //first check if it does a trigger, like if i move north then it wouldn't let me move until i got the torch
    // need getTriggers for room and a searchTriggers for a trigger that has a condition that matches with the command
    // Room can have triggers
    // creatures can have triggers
    // containers can have triggers
    // items in room can have triggers
    // items in containers can have triggers
    // items in inventory can have triggers

    //commandcompare should check the command versus the commands of the triggers

    // TODO #1:
    // make a triggerhandler function
    // find some way to figure out the owner for conditions, probably by searching rooms
    // find some way to figure out the has/object/status conditions
    // has = bool, false = no, true = yes
    // object = string, easy to find because attached to owner
    // owner = string, hard to find, might need to search all rooms and containers plus player
    // status = status of the object, easy to find

    Trigger* triggerToFind = findCommands(player->getRoom()->getTriggers(),command);
    if (triggerToFind != NULL)
    {
        cout << triggerToFind->getPrint() << endl;
        return false;
    }

    vector<Item*> items = player->checkInventory();
    for (Item* i: items)
    {
        triggerToFind = findCommands(i->getTriggers(),command);
        if (triggerToFind != NULL)
        {
            cout << triggerToFind->getPrint() << endl;
            return false;
        }
    }

    vector<Creature*> creatures = player->getRoom()->getCreatures();
    for (Creature* i: creatures)
    {
        triggerToFind = findCommands(i->getTriggers(), command);
        if (triggerToFind != NULL)
        {
            cout << triggerToFind->getPrint() << endl;
            return false;
        }
    }

    vector<Container*> containers = player->getRoom()->getContainers();
    for (Container* i: containers)
    {
        triggerToFind = findCommands(i->getTriggers(), command);
        if (triggerToFind != NULL)
        {
            cout << triggerToFind->getPrint() << endl;
            return false;
        }
    }

    for (Container* i : containers)
    {
        for (Item* j: i->getItems())
        {
            triggerToFind = findCommands(j->getTriggers(), command);
            if (triggerToFind != NULL)
            {
                cout << triggerToFind->getPrint() << endl;
                return false;
            }
        }
    }
    
    if (command.compare("where") == 0) //debug command
    {
        cout << player->getRoom()->getName() << endl;
        cout << player->getRoom()->getDesc() << endl;
        return false;
    }
    if (command.compare("borders") == 0) //debug command
    {
        vector<Border*> borders = player->getRoom()->getBorders();
        for (Border* i: borders)
        {
            cout << i->getName() + " - ";
            cout << i->getDirection() << endl;
        }
        return false;
    }
    if (command.compare("n") == 0)
    {
        moveNorthCommand(player, rooms);
        return false;
    }
    if (command.compare("s") == 0)
    {
        moveSouthCommand(player, rooms); //yada yada
        return false;
    }
    if (command.compare("e") == 0)
    {
        moveEastCommand(player, rooms); //check east
        return false;
    }
    if (command.compare("w") == 0)
    {
        moveWestCommand(player, rooms); //check west from player's current room and find anything
        return false;
    }
    if (command.compare("i") == 0)
    {
        inventoryCommand(player); //player has inventory data as a vector
        return false;
    }
    if ((command.substr(0,4)).compare("take") == 0)
    {
        if (command.compare("take") == 0 || command.compare("take ") == 0)
        {
            cout << "no item named to take" << endl;
            return false;
        }
        takeCommand(player, command.substr(5)); //player has room data, just look for that room
        return false;
    }
    if (command.compare("open exit") == 0)
    { 
        return true;
    }
    if ((command.substr(0,4)).compare("drop") == 0)
    {
        if (command.compare("drop") == 0 || command.compare("drop") == 0)
        {
            cout << "no item named to drop" << endl;
            return false;
        }
        dropCommand(player, command.substr(5));
        return false;
    }
    // this has to happen after open exit to not confuse open commands
    if ((command.substr(0,4)).compare("open") == 0)
    {
        // open <container>
        if (command.compare("open") == 0 || command.compare("open ") == 0)
        {
            cout << "no container named to open" << endl;
            return false;
        }
        openCommand(player, command.substr(5));
        return false;
    }
    if ((command.substr(0,4)).compare("read") == 0)
    {
        // read <item>
        if (command.compare("read") == 0 || command.compare("read ") == 0)
        {
            cout << "no item named to read" << endl;
            return false;
        }
        readCommand(player, command.substr(5)); // add catches if the only input is "read"
        return false;
    }
    if ((command.substr(0,3)).compare("put") == 0)
    {
        // put <item> in <container>
        if (command.compare("put") == 0 || command.compare("put ") == 0)
        {
            cout << "missing item name, \" in \" delimiter and container name" << endl;
            return false;
        }
        if (command.find(" in ") == string::npos)
        {
            cout << "missing \" in \" delimiter" << endl;
            return false;
        }
        if (command.substr(command.find(" in ")).length() == 0)
        {
            cout << "missing item name" << endl;
            return false;
        }
        putCommand(player, command.substr(4,command.find(" in ") - 4), command.substr(command.find(" in ") + 4));
        return false;
    }
    if ((command.substr(0,7)).compare("turn on") == 0)
    {
        // turn on <item>
        if (command.compare("turn on") == 0 || command.compare("turn on ") == 0)
        {
            cout << "no item named to turn on" << endl;
            return false;
        }
        turnOnCommand(player, command.substr(8));
        return false;
    }
    if ((command.substr(0,6)).compare("attack") == 0)
    {
        // attack <creature> with <item>
        if (command.compare("attack") == 0 || command.compare("attack ") == 0)
        {
            cout << "missing creature name, \" with \" delimiter and item name" << endl;
            return false;
        }
        if (command.find(" with ") == string::npos)
        {
            cout << "missing \" with \" delimiter" << endl;
            return false;
        }
        if (command.substr(command.find(" with ")).length() == 0)
        {
            cout << "missing item name" << endl;
            return false;
        }
        attackCommand(player, command.substr(7,command.find(" with ") - 7), command.substr(command.find(" with ") + 6));
        return false;
    }
    cout << "command not recognized" << endl;
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

Container* searchContainers(vector<Container*> containers, string name)
{
    for (Container* i: containers)
    {
        if (i->getName().compare(name) == 0)
        {
            return i;
        }
    }
    return NULL;
}

void moveNorthCommand(Player* player, vector<Room*> rooms)
{
    vector<Border*> borders = player->getRoom()->getBorders();
    for (Border* i: borders)
    {
        if (i->getDirection().compare("north") == 0)
        {
            player->setRoom(searchRoom(rooms,i->getName()));
            cout << "moved to " + player->getRoom()->getName() << endl;
            cout << player->getRoom()->getDesc() << endl;
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
            cout << player->getRoom()->getDesc() << endl;
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
            cout << player->getRoom()->getDesc() << endl;
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
            cout << player->getRoom()->getDesc() << endl;
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
    player->getRoom()->deleteItem(itemToFind->getName()); //use pocket dimension instead
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
    player->removeItem(itemToFind); // use pocket dimension instead
    cout << item + " dropped" << endl;
}

void openCommand(Player* player, string item)
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

void putCommand(Player* player, string item, string container)
{
    // needs add and delete, probably
    Item* itemToFind = searchItems(player->checkInventory(), item);
    if (itemToFind == NULL)
    {
        cout << item + " not in inventory" << endl;
        return;
    }
    // need a search container only needs to be in the room the player is in
    Container* containerToFind = searchContainers(player->getRoom()->getContainers(), item);
    if (containerToFind == NULL)
    {
        cout << container + " not in current room" << endl;
        return;
    }
    // place item in container
    // delete item from player's inventory
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
    updateCommand(player,itemToFind->getTurnon()->getAction());
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
    Creature* creatureToFind =  searchCreatures(player->getRoom()->getCreatures(), creature);
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