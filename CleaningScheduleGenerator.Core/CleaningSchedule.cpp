#include "CleaningSchedule.h"

#include "RoomRepository.h"
#include "TaskRepository.h"
#include "dateHelper.h"

#include <time.h>
#include <iostream>

using namespace std;

CleaningSchedule::CleaningSchedule()
{
}

vector<WeekSchedule> CleaningSchedule::Generate(tm &startDate, unsigned int weekAmount)
{
	RoomRepository* roomRepository = new RoomRepository();
	vector<Room*> rooms = roomRepository->GetAll();

	TaskRepository* taskRepository = new TaskRepository();
	vector<Task*> tasks = taskRepository->GetAll();

	vector<WeekSchedule> generatedSchedule;
	// Check if day is Thursday
	if (startDate.tm_wday == 0)
		startDate.tm_mday -= 3;

	vector<tm> dateTimes;

	dateTimes.push_back(startDate);
		
	for (unsigned int i = 0; i < weekAmount; i++)
	{
		DatePlusDays(&startDate, 7);
		tm* t = new tm(startDate);
		
		dateTimes.push_back(*t);
	}

	for (unsigned int i = 0; i < weekAmount; i++)
	{
		//tm *t = new tm(startDate);
		//t->tm_yday += (7 * i);
		cout << "Generate" << endl;
		cout << dateTimes.at(i).tm_yday << endl;
		cout << &dateTimes.at(i) << endl;
		cout << "/Generate" << endl;

		WeekSchedule weekSchedule = GenerateWeekSchedule(dateTimes.at(i), rooms, tasks);
		weekSchedule.DateTime = dateTimes.at(i);

		generatedSchedule.push_back(weekSchedule);
	}

	return generatedSchedule;
}


CleaningSchedule::~CleaningSchedule()
{
}

WeekSchedule CleaningSchedule::GenerateWeekSchedule(tm dateTime, vector<Room*> rooms, vector<Task*> tasks)
{
	tm t = { 0 };
	time_t referenceTime;

	t.tm_year = 2013 - 1900;
	t.tm_mon = 0;
	t.tm_mday = 1;
	referenceTime = mktime(&t);

	time_t currentWeekTime;
	currentWeekTime = mktime(&dateTime);

	double weekDifference = difftime(currentWeekTime, referenceTime) / (60 * 60 * 24 * 7);

	Room* overSeerRoom = rooms.back();
	rooms.pop_back();

	Task* overSeerTask = tasks.back();
	tasks.pop_back();

	WeekSchedule weekSchedule; // = new WeekSchedule();

	unsigned int j = (unsigned int)weekDifference;

	for (unsigned int i = 0; i < 14; i++)
	{
		weekSchedule.TasksForRooms.push_back(*new SingleTaskRoom(tasks.at(i), rooms.at(j % rooms.size())));

		j++;
	}

	weekSchedule.TasksForRooms.push_back(*new SingleTaskRoom(overSeerTask, overSeerRoom));
	
	return weekSchedule;
}