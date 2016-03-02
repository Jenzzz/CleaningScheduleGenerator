#include "SingleTaskRoom.h"

#include "task.h"
#include "room.h"

using namespace std;

SingleTaskRoom::SingleTaskRoom(Task* _task, Room* _room) : task(_task), room(_room)
{
}

SingleTaskRoom::~SingleTaskRoom()
{
}
