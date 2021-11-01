#include "player.h"

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

