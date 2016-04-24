#include "room.h"

Room::Room()
{
}

Room::Room(int roomNumber, Person &habitant) : RoomNumber(roomNumber), Habitant(&habitant)
{
}

Room::Room(int roomNumber, Person &habitant, Person &overseer) : RoomNumber(roomNumber), Habitant(&habitant), Overseer(&overseer)
{
}


Room::~Room()
{
}