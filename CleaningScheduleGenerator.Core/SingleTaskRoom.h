#ifdef COMPILE_MYLIBRARY
#define MYLIBRARY_EXPORT __declspec(dllexport)
#else
#define MYLIBRARY_EXPORT __declspec(dllimport)
#endif

#include "task.h"
#include "room.h"

using namespace std;

class MYLIBRARY_EXPORT SingleTaskRoom
{
public:
	SingleTaskRoom(Task*, Room*);
	Task* task;
	Room* room;
	~SingleTaskRoom();
};