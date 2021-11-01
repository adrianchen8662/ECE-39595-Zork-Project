#include "player.h"

Player::Player()
{
    this->name = "player";
}

void Player::setItem(Item* itemname)
{
    this->inventory.push_back(itemname);
}

void Player::setRoom(Room* roomname)
{
    this->room = roomname;
}

Room* Player::getRoom()
{
    return this->room;
}

vector<Item*> Player::checkInventory()
{
    return this->inventory;
}

void Player::removeItem(Item* itemname)
{
    for (Item* i: inventory)
    {
        if (i->getName().compare(itemname->getName()) == 0)
        {
            delete itemname;
        }
    }
}