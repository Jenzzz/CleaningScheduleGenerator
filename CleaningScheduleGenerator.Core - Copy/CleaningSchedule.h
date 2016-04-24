#ifdef COMPILE_MYLIBRARY
#define MYLIBRARY_EXPORT __declspec(dllexport)
#else
#define MYLIBRARY_EXPORT __declspec(dllimport)
#endif

#include <map>
#include <vector>

#include "FilenameHelper.h"
#include "RoomRepository.h"
#include "TaskRepository.h"
#include "WeekSchedule.h"
#include "WritePdf.h"

using namespace std;

class MYLIBRARY_EXPORT CleaningSchedule
{
public:
	CleaningSchedule();
	void Generate(tm &startDate, unsigned int weekAmount = 4);
	void Save();
	~CleaningSchedule();
private:
	WeekSchedule GenerateWeekSchedule(tm date, vector<Room*> rooms, vector<Task*> tasks);
	vector<WeekSchedule>* cleaningScheduleMap;
	tm startDate;
};