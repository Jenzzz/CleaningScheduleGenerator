#include "RoomRepository.h"

#include "readIniFile.h"

using namespace std;

RoomRepository::RoomRepository()
{
}

vector<Room*> RoomRepository::GetAll()
{
	ReadIniFile *readIniFile = new ReadIniFile("config.ini");
	map<string, string> roomNumbers = readIniFile->ReadRoomNumbers();
	int nestorRoomNumber = readIniFile->ReadNestor();

	vector<Room*> rooms; // = new vector<Room*>();

	Room* nestorRoom = new Room();

	for each (pair<string, string> pair in roomNumbers)
	{
		Person* p = new Person(pair.second);

		int roomNumber = stoi(pair.first);

		Room* room = new Room(roomNumber, *p);

		if (room->RoomNumber == nestorRoomNumber)
		{
			p->IsNestor = true;
			room->Overseer = new Person("Iedereen");
			nestorRoom = room;
			continue;
		}

		rooms.push_back(room);
	}

	//set Overseers
	for (unsigned int i = 0; i < rooms.size(); i++)
		rooms.at(i)->Overseer = rooms.at((i+1) % rooms.size())->Habitant;
	
	rooms.push_back(nestorRoom);

	return rooms;
}


RoomRepository::~RoomRepository()
{
}
