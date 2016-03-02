#ifndef __WEEKSCHEDULE_H__
#define __WEEKSCHEDULE_H__

#include <vector>

#include "SingleTaskRoom.h"

using namespace std;

class WeekSchedule
{
public:
	WeekSchedule();
	tm DateTime;
	vector<SingleTaskRoom> TasksForRooms;
	~WeekSchedule();
};

#endif __WEEKSCHEDULE_H__
