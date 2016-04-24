#include "RoomRepository.h"

#include <sstream>
#include <algorithm>

#include "DatabaseBase.h"
#include "BooleanHelper.h"

using namespace std;

RoomRepository::RoomRepository()
{
	DatabaseBase databaseBase;
}

vector<Room*> rooms;

bool SortRoom(Room* lhs, Room* rhs)
{
	return (lhs->Habitant->IsNestor < rhs->Habitant->IsNestor);
}

int RoomRepository::callback(void *data, int argc, char **argv, char **azColName)
{

	int i;
	fprintf(stderr, "%s: ", (const char*)data);
	for (i = 0; i<argc; i++) {
		printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
	}
	printf("\n");

	RoomRepository* roomRepository = reinterpret_cast<RoomRepository*>(data);
	roomRepository->RoomRepositoryCallback(argc, argv, azColName);

	return 0;
}

void RoomRepository::RoomRepositoryCallback(int argc, char **argv, char **azColName)
{
	int roomNumber = atoi(argv[0]);
	string habitantName = argv[1];
	int habitantId = atoi(argv[2]);
	bool habitantIsNestor = String2Bool(argv[3]);
	string overseerName = argv[4];
	int overseerId = atoi(argv[5]);
	bool overseerIsNestor = String2Bool(argv[6]);

	Person* personHabitant = new Person(habitantId, habitantName, habitantIsNestor);
	Person* personOverseer = new Person(overseerId, overseerName, overseerIsNestor);

	ConvertToRoom(roomNumber, *personHabitant, *personOverseer);
}

void RoomRepository::ConvertToRoom(int roomNumber, Person &person, Person &overseer)
{
	Room* room = new Room(roomNumber, person, overseer);
	rooms.push_back(room);
}

vector<Room*> RoomRepository::GetAll()
{
	rooms.clear();

	//sqlite3 *db;
	//char *zErrMsg = 0;
	//int rc;
	//const char* data = "Callback function called";

	///* Open database */
	//rc = sqlite3_open("cleaningschedule.db", &db);
	//if (rc) {
	//	fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
	//	exit(0);
	//}
	//else {
	//	fprintf(stderr, "Opened database successfully\n");
	//}
	///* Create SQL statement */
	//char* query = "SELECT r.Id, a.Name as Habitant, a.Id as HabitantId, a.IsNestor as HabitantIsNestor, c.Name as Overseer, c.Id as OverseerId, c.IsNestor as OverseerIsNestor from Rooms r INNER JOIN Habitants a ON r.Habitant = a.Id INNER JOIN Habitants c ON r.Overseer = c.Id; ";
	//	
	///* Execute SQL statement */
	//rc = sqlite3_exec(db, query, callback, &data, &zErrMsg);
	//if (rc != SQLITE_OK) {
	//	fprintf(stderr, "SQL error: %s\n", zErrMsg);
	//	sqlite3_free(zErrMsg);
	//}
	//else {
	//	fprintf(stdout, "Operation done successfully\n");
	//}
	//sqlite3_close(db);


	//ReadIniFile *readIniFile = new ReadIniFile("config.ini");
	//map<string, string> roomNumbers = readIniFile->ReadRoomNumbers();
	//int nestorRoomNumber = readIniFile->ReadNestor();

	//vector<Room*> rooms; // = new vector<Room*>();

	//Room* nestorRoom = new Room();

	//for each (pair<string, string> pair in roomNumbers)
	//{
	//	Person* p = new Person(pair.second);

	//	int roomNumber = stoi(pair.first);

	//	Room* room = new Room(roomNumber, *p);

	//	if (room->RoomNumber == nestorRoomNumber)
	//	{
	//		p->IsNestor = true;
	//		room->Overseer = new Person("Iedereen");
	//		nestorRoom = room;
	//		continue;
	//	}

	//	rooms.push_back(room);
	//}

	////set Overseers
	//for (unsigned int i = 0; i < rooms.size(); i++)
	//	rooms.at(i)->Overseer = rooms.at((i+1) % rooms.size())->Habitant;
	//
	//rooms.push_back(nestorRoom);

	sort(rooms.begin(), rooms.end(), SortRoom);

	/*Room* nestorRoom;

	for each (Room* room in rooms)
	{
		if (room->Habitant->IsNestor)
		{
			nestorRoom = room;
			rooms.pop_back();
		}
	}

	rooms.push_back(nestorRoom);*/


	return rooms;
}
//
//bool AddRoom(int number, Person* habitant, Person* overseer)
//{
//	std::ostringstream queryStream;
//	queryStream << "INSERT INTO Room (Id,Habitant,Overseer) VALUES (" << number << "," << habitant->Id << "," << overseer->Id << ")";
//	const char* query = queryStream.str().c_str();
//
//	return DatabaseBase().ExecuteQuery(query, my_special_callback);
//}
//
//bool UpdateRoom(Room* room, Person* habitant, Person* overseer)
//{
//	std::ostringstream queryStream;
//
//	queryStream << "UPDATE Rooms set Habitant = " << habitant->Id << " AND Overseer = " << overseer->Id << " where Id = " << room->RoomNumber << " SELECT * from Rooms";
//
//	const char* query = queryStream.str().c_str();
//
//	return DatabaseBase().ExecuteQuery(query, my_special_callback);
//}
//
//bool DeleteRoom(Room* room)
//{
//	std::ostringstream queryStream;
//	queryStream << "UPDATE from Rooms where Id = " << room->RoomNumber << " SELECT * from Rooms";
//
//	const char* query = queryStream.str().c_str();
//
//	return DatabaseBase().ExecuteQuery(query, my_special_callback);
//}


RoomRepository::~RoomRepository()
{
}
