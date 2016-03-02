#include "room.h"

Room::Room()
{
}

Room::Room(int roomNumber, Person &habitant) : RoomNumber(roomNumber), Habitant(&habitant)
{
}


Room::~Room()
{
}