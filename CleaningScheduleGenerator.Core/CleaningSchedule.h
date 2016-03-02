#ifndef __CLEANINGSCHEDULE_H__
#define __CLEANINGSCHEDULE_H__

#include <map>
#include <vector>

#include "WeekSchedule.h"

using namespace std;

class CleaningSchedule
{
public:
	CleaningSchedule();
	vector<WeekSchedule> Generate(tm &startDate, unsigned int weekAmount = 4);
	~CleaningSchedule();
private:
	WeekSchedule GenerateWeekSchedule(tm date, vector<Room*> rooms, vector<Task*> tasks);
};

#endif __CLEANINGSCHEDULE_H__