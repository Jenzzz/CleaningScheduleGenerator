#ifdef COMPILE_MYLIBRARY
#define MYLIBRARY_EXPORT __declspec(dllexport)
#else
#define MYLIBRARY_EXPORT __declspec(dllimport)
#endif

#include <vector>

#include "SingleTaskRoom.h"

using namespace std;

class MYLIBRARY_EXPORT WeekSchedule
{
public:
	WeekSchedule();
	tm DateTime;
	vector<SingleTaskRoom> TasksForRooms;
	~WeekSchedule();
};
