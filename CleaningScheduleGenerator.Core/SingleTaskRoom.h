#ifndef __SINGLETASKROOM_H__
#define __SINGLETASKROOM_H__

#include "task.h"
#include "room.h"

using namespace std;

class SingleTaskRoom
{
public:
	SingleTaskRoom(Task*, Room*);
	Task* task;
	Room* room;
	~SingleTaskRoom();
};

#endif // !__SINGLETASKROOM_H__