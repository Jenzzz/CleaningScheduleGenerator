#ifdef COMPILE_MYLIBRARY
#define MYLIBRARY_EXPORT __declspec(dllexport)
#else
#define MYLIBRARY_EXPORT __declspec(dllimport)
#endif

#include <vector>
#include "room.h"
#include "DatabaseBase.h"

using namespace std;

class MYLIBRARY_EXPORT RoomRepository : DatabaseBase
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