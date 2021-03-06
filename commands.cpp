#include "commands.h"

extern bool gameOver;
Room* Junkyard = NULL;
int counter;

// helper function that searches a vector of triggers if the command matches
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

// recieves a trigger to check and sees if it still applies based on conditions
bool conditionChecker(Trigger* trigger, Player* player, vector<Room*> rooms)
{
    if (trigger->getCondition()->getOwner().compare("Void") != 0)
    {
        if (trigger->getCondition()->getOwner().compare("inventory") == 0) // if its in the inventory
        {
            vector<Item*> items = player->checkInventory();
            for (Item* i: items) // if the player doesn't have it, it's ok
            {
                if (i->getName() == trigger->getCondition()->getObject())
                {
                    if (trigger->getCondition()->getHas())
                    {
                        return false;
                    }
                    else
                    {
                        return true;
                    }
                }
            }
            if (trigger->getCondition()->getHas() == false)
            {
                return false;
            } 
        }
        else
        {
            for (Room* i: rooms)
            {
                vector<Container*> containers = i->getContainers();
                for (Container* x: containers)
                {
                    if (x->getName().compare(trigger->getCondition()->getOwner()))
                    {
                        vector<Item*> items = x->getItems();
                        for (Item* y: items)
                        if (y->getName().compare(trigger->getCondition()->getObject()))
                        {
                            if (trigger->getCondition()->getHas() == true)
                            {
                                return true;
                            }
                            else
                            {
                                return false;
                            }
                        }
                    }
                }
            }
        }
    }
    else
    {
        for (Room* i: rooms)
        {
            vector<Trigger*> triggers = i->getTriggers();
            vector<Creature*> creatures = i->getCreatures();
            
            for (Creature* x: creatures)
            {
                if (x->getName().compare(trigger->getCondition()->getObject()) == 0)
                {
                    return false;
                }
                
                for(Trigger* y: x->getTriggers())
                {
                    for (Item* items: player->checkInventory())
                    {
                        //cout << y->getCondition()->getObject() + " + " + items->getName() << endl;
                        //cout << y->getCondition()->getStatus() + " + " + items->getStatus() << endl;
                        if (y->getCondition()->getObject() == items->getName())
                        {
                            if (items->getStatus() != y->getCondition()->getStatus())
                            {
                                if (y->getType().compare("single") == 0 && y->counter == 0)
                                {
                                    return false;
                                    y->counter++;
                                }
                                return true;
                            }
                            // cout<<"You assault "<<x->getName()<<" with "<<items->getName()<<endl;
                        }
                    }
                }
            }

            vector<Item*> items = i->getItems();
            for (Item* x: items)
            {
                if (x->getName().compare(trigger->getCondition()->getObject()) == 0)
                {
                    return false;
                }
            }
            vector<Container*> containers = i->getContainers();
            for (Container* x: containers)
            {
                vector<Item*> items = x->getItems();
                for (Item* y: items)
                {
                    if (y->getName().compare(trigger->getCondition()->getObject()) == 0)
                    {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}
// has object owner
void conditionFromPut(Player* player, vector<Room*> rooms, Item* item, Container* container)
{
    for (Room* a: rooms)
    {
        for (Item* b: a->getItems())
        {
            for (Trigger* c: b->getTriggers())
            {
                if (c->getCondition()->getObject().compare(item->getName()) == 0)
                {
                    if (c->getCondition()->getOwner().compare(container->getName()) == 0)
                    {
                        for (string d: c->getActions())
                        {
                            b->setStatus(d.substr(d.find(" to ") + 4));
                        }
                        cout << c->getPrint() << endl;
                    }
                }
            }
        }
        for (Creature* b: a->getCreatures())
        {
            for (Trigger* c: b->getTriggers())
            {
                if (c->getCondition()->getObject().compare(item->getName()) == 0)
                {
                    if (c->getCondition()->getOwner().compare(container->getName()) == 0)
                    {
                        for (string d: c->getActions())
                        {
                            b->setStatus(d.substr(d.find(" to ") + 4));
                        }
                        cout << c->getPrint() << endl;
                    }
                }
            }
        }
        for (Container* b: a->getContainers())
        {
            for (Trigger* c: b->getTriggers())
            {
                if (c->getCondition()->getObject().compare(item->getName()) == 0)
                {
                    if (c->getCondition()->getOwner().compare(container->getName()) == 0)
                    {
                        for (string d: c->getActions())
                        {
                            b->setStatus(d.substr(d.find(" to ") + 4));
                        }
                        cout << c->getPrint() << endl;
                    }
                }
            }
        }
        for (Trigger* b: a->getTriggers())
        {
            if (b->getCondition()->getObject().compare(item->getName()) == 0)
            {
                if (b->getCondition()->getOwner().compare(container->getName()) == 0)
                {
                    for (string c: b->getActions())
                    {
                        a->setStatus(c.substr(c.find(" to ") + 4));
                    }
                    cout << b->getPrint() << endl;
                }
            }
        }
        for (Container* b: a->getContainers())
        {
            for (Item* c: b->getItems())
            {
                for (Trigger* d: c->getTriggers())
                {
                    if (d->getCondition()->getObject().compare(item->getName()) == 0)
                    {
                        if (d->getCondition()->getOwner().compare(container->getName()) == 0)
                        {
                            for (string e: d->getActions())
                            {
                                b->setStatus(e.substr(e.find(" to ") + 4));
                            }
                            cout << d->getPrint() << endl;
                        }
                    }
                }
            }
        }
    }
}

void conditionFromTurnOn(Player* player, vector<Room*> rooms, Item* itemUpdated, string action)
{
    for (Room* a: rooms)
    {
        for (Item* b: a->getItems())
        {
            for (Trigger* c: b->getTriggers())
            {
                if (c->getCondition()->getObject().compare(itemUpdated->getName()) == 0)
                {
                    if (c->getCondition()->getStatus().compare(action) == 0)
                    {
                        cout << c->getPrint() << endl;
                    }
                }
            }
        }
        for (Creature* b: a->getCreatures())
        {
            for (Trigger* c: b->getTriggers())
            {
                if (c->getCondition()->getObject().compare(itemUpdated->getName()) == 0)
                {
                    if (c->getCondition()->getStatus().compare(action) == 0)
                    {
                        if (player->getRoom()->getName().compare(a->getName()) == 0)
                        {
                            if (c->getType().compare("single") == 0 && c->counter == 0)
                            {

                                c->counter++;
                                cout << c->getPrint() << endl;
                            }
                        }
                        
                    }
                }
            }
        }
        for (Container* b: a->getContainers())
        {
            for (Trigger* c: b->getTriggers())
            {
                if (c->getCondition()->getObject().compare(itemUpdated->getName()) == 0)
                {
                    if (c->getCondition()->getStatus().compare(action) == 0)
                    {
                        if (c->getType().compare("single") == 0 && c->counter == 0)
                        {
                            cout << c->getPrint() << endl;
                        }
                    }
                }
            }
        }
        for (Trigger* b: a->getTriggers())
        {
            if (b->getCondition()->getObject().compare(itemUpdated->getName()) == 0)
            {
                if (b->getCondition()->getStatus().compare(action) == 0)
                {
                    cout << b->getPrint() << endl;
                }
            }
        }
        for (Container* b: a->getContainers())
        {
            for (Item* c: b->getItems())
            {
                for (Trigger* d: c->getTriggers())
                {
                    if (d->getCondition()->getObject().compare(itemUpdated->getName()) == 0)
                    {
                        if (d->getCondition()->getStatus().compare(action) == 0)
                        {
                            cout << d->getPrint() << endl;
                        }
                    }
                }
            }
        }
    }
}



bool whichCommand(string command, Player* player, vector<Room*> rooms, Room* JunkyardR)
{
    Junkyard = JunkyardR;

    // searches triggers in room
    Trigger* triggerToFind = findCommands(player->getRoom()->getTriggers(),command);

    if (triggerToFind != NULL)
    {
        if(!conditionChecker(triggerToFind, player, rooms)){
            cout << triggerToFind->getPrint() << endl;
            return false;
        }
    }
    if (gameOver)
    {
        return true;
    }
    // searches triggers in inventory
    vector<Item*> items = player->checkInventory();
    for (Item* i: items)
    {
        triggerToFind = findCommands(i->getTriggers(),command);

        if (triggerToFind != NULL)
        {
            if(conditionChecker(triggerToFind, player, rooms)){
                cout << triggerToFind->getPrint() << endl;
                return false;
            }
        }
    }
    if (gameOver)
    {
        return true;
    }
    //searches triggers in creatures in room
    vector<Creature*> creatures = player->getRoom()->getCreatures();
    for (Creature* i: creatures)
    {
        triggerToFind = findCommands(i->getTriggers(), command);
        if (triggerToFind != NULL)
        {
            if(conditionChecker(triggerToFind, player, rooms))
            {
                cout << triggerToFind->getPrint() << endl;
                for (string q: triggerToFind->getActions())
                {
                    if (q == "Game Over")
                    {
                        gameOverCommand();
                    }
                }
                return false;
            }
        }
    }
    if (gameOver)
    {
        return true;
    }
    //searches triggers in containers in room
    vector<Container*> containers = player->getRoom()->getContainers();
    for (Container* i: containers)
    {
        triggerToFind = findCommands(i->getTriggers(), command);
        if (triggerToFind != NULL)
        {
            if(conditionChecker(triggerToFind, player, rooms))
            {
            cout << triggerToFind->getPrint() << endl;
            return false;
            }
        }
    }
    if (gameOver)
    {
        return true;
    }
    // searches triggers in items in containers in room
    for (Container* i : containers)
    {
        for (Item* j: i->getItems())
        {
            triggerToFind = findCommands(j->getTriggers(), command);
            if (triggerToFind != NULL)
            {
                if (conditionChecker(triggerToFind, player, rooms))
                {
                cout << triggerToFind->getPrint() << endl;
                return false;
                }
            }
        }
    }
    if (gameOver)
    {
        return true;
    }
    if (command.compare("axe") == 0)
    {
        for (Item* i: player->checkInventory())
        {
            cout << i->getName() + ": " + i->getStatus() << endl;
            return false;
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
    if (command.compare("containers") == 0) //debug command
    {
        vector<Container*> containers = player->getRoom()->getContainers();
        for (Container* i: containers)
        {
            cout << i->getName() << endl;
        }
        return false;
    }
    if (command.compare("check") == 0)
    {
        vector<Container*> containers = player->getRoom()->getContainers();
        for (Container* i: containers)
        {
            for (Item* x: i->getItems())
            {
                cout << x->getName() << endl;
            }
        }
    }
    if (command.compare("n") == 0)
    {
        moveNorthCommand(player, rooms);
        return false;
    }
    if (command.compare("s") == 0)
    {
        moveSouthCommand(player, rooms);
        return false;
    }
    if (command.compare("e") == 0)
    {
        moveEastCommand(player, rooms);
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
        takeCommand(player, command.substr(5), rooms); //player has room data, just look for that room
        return false;
    }
    if (command.compare("open exit") == 0)
    { 
        if((player->getRoom()->getType()).compare("exit") == 0)            
            return true;
        cout<<"Error"<<endl;
        return false;
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
        putCommand(player, rooms, command.substr(4,command.find(" in ") - 4), command.substr(command.find(" in ") + 4));
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
        turnOnCommand(player, rooms, command.substr(8));
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
        attackCommand(player, command.substr(7,command.find(" with ") - 7), command.substr(command.find(" with ") + 6), rooms);
        if (gameOver == true)
        {
            return true;
        }
        return false;
    }
    if (gameOver)
    {
        return true;
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


Item* searchItems(vector<Item*> items, string name){
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

vector<Container*> searchOpenContainers(vector<Container*> containers)
{
    vector<Container*> res;
    for (Container* i: containers)
    {
        if (i->getOpen())
        {
            res.push_back(i);
        }
    }
    return res;
}

void takeCommand(Player* player, string item, vector<Room*> rooms)
{
    Item* itemToFind = searchItems(player->getRoom()->getItems(), item);
    vector<Container*> containersInRoom = searchOpenContainers(player->getRoom()->getContainers());
    if (itemToFind == NULL && containersInRoom.size() == 0)
    {
        cout << item + " not in room" << endl;
        return;
    }
    if(itemToFind == NULL){
        for(auto i : containersInRoom){
            for(auto j: i->getItems()){
                if(j->getName().compare(item) == 0){
                    player->setItem(j);
                    i->deleteItem(item);
                    cout << "Item " + item + " added to the inventory" << endl;
                    
                    for (Room* i: rooms)
                    {
                        //cout << "first onion" << endl;
                        for (Creature* a: i->getCreatures())
                        {
                            //cout << "second onion" << endl;
                            for (Trigger* b: a->getTriggers())
                            {
                                //cout << "third onion" << endl;
                                if (b->getCondition()->getObject() == item)
                                {
                                    //cout << "fourth onion" << endl;
                                    if (b->getCondition()->getOwner() == "inventory")
                                    {
                                        //cout << "fifth onion" << endl;
                                        if (b->getCondition()->getHas())
                                        {
                                            //cout << "sixth onion" << endl;
                                            //cout << b->getPrint() << endl;
                                            for (string x: b->getActions())
                                            {
                                                //cout << "seventh onion" << endl;
                                                updateCommand(player,x);
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                    return;
                }
            }
            cout << item + " not in room" << endl;
            return;
        }
    }
    player->setItem(itemToFind);
    player->getRoom()->deleteItem(itemToFind->getName()); //use pocket dimension instead
    cout << "Item " + item + " added to the inventory" << endl;
    // cout << itemToFind->getName() << endl;
    for (Room* i: rooms)
    {
        for (Creature* a: i->getCreatures())
        {
            for (Trigger* b: a->getTriggers())
            {
                if (b->getCondition()->getObject() == itemToFind->getName())
                {
                    if (b->getCondition()->getOwner() == "inventory")
                    {
                        if (b->getCondition()->getHas())
                        {
                            // cout << b->getPrint() << endl;
                            for (string x: b->getActions())
                            updateCommand(player,x);
                        }
                    }
                }
            }
        }
    }
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

void openCommand(Player* player, string command)
{
    Container* container = searchContainers(player->getRoom()->getContainers(), command);
    if(!container){
        cout<<command<<" not in room"<<endl;
        return;
    }
    container->setOpen();
    cout<<container->getName()<<" contains ";
    for(auto* i : container->getItems()){
        cout<<i->getName();
        //player->getRoom()->setItem(i);
        //container->deleteItem(i->getName());
    }
    cout<<endl;
    return;
}

void readCommand(Player* player, string item)
{
    Item* itemToFind = searchItems(player->checkInventory(), item);
    if (itemToFind == NULL)
    {
        cout << item + " not in inventory" << endl;
        return;
    }
    string toPrint = itemToFind->getWriting().length() == 0 ? "Nothing Written" : itemToFind->getWriting();
    cout << toPrint << endl;
}

void putCommand(Player* player, vector<Room*> rooms, string item, string container)
{
    // needs add and delete, probably
    Item* itemToFind = searchItems(player->checkInventory(), item);
    if (itemToFind == NULL)
    {
        cout << item + " not in inventory" << endl;
        return;
    }
    // need a search container only needs to be in the room the player is in
    Container* containerToFind = searchContainers(player->getRoom()->getContainers(), container);
    if (containerToFind == NULL)
    {
        cout << container + " not in current room" << endl;
        return;
    }
    addCommand(containerToFind, itemToFind);
    conditionFromPut(player, rooms, itemToFind, containerToFind);
    openCommand(player, container);
    player->removeItem(itemToFind);
    //containerToFind->deleteItem(itemToFind);
    //deleteCommand(itemToFind);
    // place item in container
    // delete item from player's inventory
}

void turnOnCommand(Player* player, vector<Room*> rooms, string item)
{
    Item* itemToFind = searchItems(player->checkInventory(), item);
    if (itemToFind == NULL)
    {
        cout << item + " not in inventory" << endl;
        return;
    }
    //then, attempt to turn on, whatever that means
    updateCommand(player,itemToFind->getTurnon()->getAction());
    cout << itemToFind->getTurnon()->getPrint() << endl;
    conditionFromTurnOn(player, rooms, itemToFind, itemToFind->getTurnon()->getAction().substr(itemToFind->getTurnon()->getAction().find(" to ") + 4));
}

bool attackCondition(Condition* condition, Item* item){
    if(condition->getObject().compare(item->getName()) == 0){
        if(condition->getStatus().compare(item->getStatus()) == 0){
            return true;
        }
    }
    return false;
}

void attackAction(string command, Player* player, Item* item, Creature* creature, vector<Room*>rooms){
     if(command.compare("n") == 0){
        moveNorthCommand(player, rooms);
        return;
    }
    if(command.compare("s") == 0){
        moveSouthCommand(player, rooms);
        return;
    }
    if(command.compare("e") == 0){
        moveEastCommand(player, rooms);
        return;
    }
    if(command.compare("w") == 0){
        moveWestCommand(player, rooms); //check west from player's current room and find anything
        return;
    }
    if(command.compare("i") == 0){
        inventoryCommand(player); //player has inventory data as a vector
        return;
    }
    if((command.substr(0,3)).compare("Add") == 0){
        string itemname = command.substr(4,command.find(" to ") - 4);
        string newPlace = command.substr(command.find(" to ") + 4);
        //itemToMove -> setName = 
        Item* itemToMove = searchItems(Junkyard->getItems(), itemname);
        if(itemToMove){
            cout<<itemname<<endl;
            Room* roomToAdd = searchRoom(rooms, newPlace);
            roomToAdd->setItem(itemToMove);
            Junkyard->deleteItem(itemToMove->getName());
            return;
        }
        Creature* creatureToMove = searchCreatures(Junkyard->getCreatures(), itemname);
        if(creatureToMove){
            cout<<"creature:"<<itemname<<endl;
            Room* roomToAdd = searchRoom(rooms, newPlace);
            roomToAdd->setCreature(creatureToMove);
            //Junkyard->deleteCreature(itemname);
            return;
        }
    }
    if((command.substr(0,6)).compare("Delete") == 0){
        string creaturename = command.substr(7);
        Creature* creatureToDelete = searchCreatures(player->getRoom()->getCreatures(), creaturename);
        Creature* ifExists = searchCreatures(Junkyard->getCreatures(), creaturename);
        if(!ifExists){
            Junkyard->setCreature(creatureToDelete);
        }
        for(Room* roomT : rooms){
            for(Creature* creatureT : roomT->getCreatures()){
                if((creatureT->getName()).compare(creaturename) == 0){
                    roomT->deleteCreature(creaturename);
                    return;
                }
            }
        }
    }if(command.compare("Game Over") == 0){
        gameOverCommand();
        gameOver = true;
        return;
    }
    return;
}

void attackCommand(Player* player, string creature, string item, vector<Room*> rooms)
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
    for(string str : creatureToFind->getVulnerabilities()){
        if(str.compare(item) == 0){
            // cout<<"Is vul\n";
            for(Attack* att: creatureToFind->getAttacks()){
                cout<<"You assault "<<creature<<" with "<<item<<endl;
                if(att->getCondition().size() > 0){
                    for(Condition* cond : att->getCondition()){
                        if(attackCondition(cond, itemToFind)){
                            //cout << "goes here"<< endl;
                            for(string str : att->getPrint()){
                                cout<<str<<endl;
                            }
                            for(string str : att->getAction()){
                                attackAction(str, player, itemToFind, creatureToFind, rooms);
                            }
                            return;
                        }
                    }
                }else{
                    //cout << "goes here" << endl;
                    for(string str : att->getPrint()){
                        cout<<str<<endl;
                    }
                    for(string str : att->getAction()){
                        attackAction(str, player, itemToFind, creatureToFind, rooms);
                    }
                    return;
                }
            }
            
            for(auto i : creatureToFind->getTriggers()){
                cout<<"You assault "<<creature<<" with "<<item<<endl;
                if(i->getCommand().compare("attack "+creature+" with "+item) == 0){
                    //cout<<"Command match";
                    if(conditionChecker(i, player, rooms)){
                        //cout<<"TRIGGERED\n";
                    }
                }
                
            }
        }
    }
    
    cout<<"Error"<<endl;
    return;
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

template <typename T>
void addCommand(T* temp, Item* item)
{
    temp->setItem(item);
}

// instead of messing around with generic pointers, give the delete command a name and have it dig to find what's being deleted
// the description isn't correct. I can't just delete <object>, it can fit a lot of things, like <item> or <creature>
void deleteCommand(Item* item)
{
    Junkyard->setItem(item);
}

// update <object> to <status>
void updateCommand(Player* player, string action)
{
    if(action.substr(0,4).compare("drop") == 0){
        string item = action.substr(5);
        Item* droppedItem = searchItems(player->checkInventory(), item);
        player->getRoom()->setItem(droppedItem);
        player->removeItem(droppedItem);
        return;
    }
    string itemname = action.substr(7,action.find(" to ") - 7);
    cout << action << endl;
    // cout << action.substr(7,action.find(" to ") -7);
    string status = action.substr(action.find(" to ") + 4);
    // THIS ONLY CHECKS THE PLAYER INVENTORY AND ROOM THEY INHABIT, NOT GLOBAL SEARCH
    Item* itemToFind = searchItems(player->checkInventory(),itemname);
    if (itemToFind == NULL)
    {
        itemToFind = searchItems(player->getRoom()->getItems(), itemname);
        if (itemToFind == NULL)
        {
            cout << "internal command update Command failed" << endl;
            return;
        }
    }
    itemToFind->setStatus(status);
}

void gameOverCommand()
{
    // deleteCommand on everything
    cout << "Victory!" << endl;
    gameOver = true;
    return;
}