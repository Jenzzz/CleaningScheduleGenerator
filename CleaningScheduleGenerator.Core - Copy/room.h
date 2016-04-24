#ifndef __ROOM_H__
#define __ROOM_H__

#include <ostream>
#include "person.h"

using namespace std;

class Room
{
public:
	Room();
	Room(int roomNumber, Person &habitant);
	Room(int roomNumber, Person &habitant, Person &overseer);
	int RoomNumber;
	Person* Habitant;
	Person* Overseer;
	~Room();
};

inline ostream& operator<<(ostream &os, const Room &r)
{
	return os << r.RoomNumber;
}

#endif
