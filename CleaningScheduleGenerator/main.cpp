#include <ctime>

#include "CleaningSchedule.h"

int main(int argc, char* argv[])
{
	time_t t = time(0);   // get time now
	tm dateTime;
	localtime_s(&dateTime, &t);
	dateTime.tm_year;

	// generate schedule
	CleaningSchedule* cleaningSchedule = new CleaningSchedule();
	cleaningSchedule->Generate(dateTime);
	cleaningSchedule->Save();

	return 0;
}