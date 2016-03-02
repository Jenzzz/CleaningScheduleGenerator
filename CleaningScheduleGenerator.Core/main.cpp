#include <ctime>
#include <string>
#include <vector>

#include "FilenameHelper.h"
#include "CleaningSchedule.h"
#include "WritePdf.h"

using namespace std;

int main(int argc, char* argv[])
{
	time_t t = time(0);   // get time now
	tm dateTime;
	localtime_s(&dateTime, &t);
	dateTime.tm_year;

//	if (argc < 4)
//	{
//		cerr << "Error argc needs 3 parameters, has parameter amount: " << argc << endl;
//		//return 1;
//	}
//
//	if (argc == 4)
//	{
//		cout << "argv[1] = " << argv[1] << endl;
//		dateTime.tm_mday = atoi(argv[1]);
//		cout << "argv[2] = " << argv[2] << endl;
//		dateTime.tm_mon = atoi(argv[2]);
//		cout << "argv[3] = " << argv[3] << endl;
//		dateTime.tm_year = atoi(argv[3]);
//		localtime_s(&dateTime, &t);
//	}
//
//	if (argc > 4)
//	{
//		cerr << "Error argc has more then 3 parameters, has parameter amount: " << argc << endl;
//		//return 1;
//	}

	//ReadIniFile("../CleaningScheduleGenerator/config.ini");

	// generate schedule
	CleaningSchedule* cleaningSchedule = new CleaningSchedule();
	vector<WeekSchedule> cleaningScheduleMap = cleaningSchedule->Generate(dateTime);

	// save schedule
	// TODO
	
	string fileName = ConstructFilename(dateTime);

	WritePdf* writePdf = new WritePdf();
	writePdf->WriteToFile(cleaningScheduleMap, fileName);
		
	//time_t t = time(0);   // get time now
	//tm tm;
	//localtime_s(&tm, &t);
	//cout << (tm.tm_year + 1900) << '-'
	//	<< (tm.tm_mon + 1) << '-'
	//	<< tm.tm_mday
	//	<< endl;

	return 0;
}

