#ifndef __ROOMREPOSITORY_H__
#define __ROOMREPOSITORY_H__

#include <vector>
#include "room.h"

using namespace std;

class RoomRepository
{
public:
	RoomRepository();
	vector<Room*>GetAll();
	~RoomRepository();
};

#endif __ROOMREPOSITORY_H__