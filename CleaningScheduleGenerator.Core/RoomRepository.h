#ifndef __ROOMREPOSITORY_H__
#define __ROOMREPOSITORY_H__

#include <vector>
#include "room.h"
#include "DatabaseBase.h"

using namespace std;

class RoomRepository : DatabaseBase
{
public:
	RoomRepository();
	vector<Room*> GetAll();
	bool AddRoom(int number, Person* habitant, Person* overseer);
	bool UpdateRoom(Room* room);
	bool DeleteRoom(Room* room);
	static int callback(void *data, int argc, char **argv, char **azColName);
	void RoomRepositoryCallback(int argc, char **argv, char **azColName);
	void ConvertToRoom(int roomNumber, Person &person, Person &overseer);
	~RoomRepository();
private:
	
};



#endif __ROOMREPOSITORY_H__
