#ifndef __FILENAMEHELPER_H__
#define __FILENAMEHELPER_H__

#include <iostream>
#include <ctime>
#include <string>
#include "dateHelper.h"

using namespace std;

string ConstructFilename(tm &dateTime)
{
	int weekNumber = GetWeek(dateTime.tm_mday, dateTime.tm_mon + 1, dateTime.tm_year);
	
	//char buffer[32];
	char buffer[60];

	//sprintf_s(buffer, "Schoonmaakrooster_%d_%d_%d", weekNumber, weekNumber + 8, dateTime.tm_year); // Change to year
	sprintf_s(buffer, "Schoonmaakrooster_%d_%d_%d_%d_%d", weekNumber, weekNumber + 8, dateTime.tm_year, dateTime.tm_mday, dateTime.tm_min);

	return buffer;
}

#endif
