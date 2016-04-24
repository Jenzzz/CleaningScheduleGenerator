#ifndef __WRITEODF_H__
#define __WRITEODF_H__

#include <vector>
#include <map>
#include <string>

#include "WeekSchedule.h"

using namespace std;

class WritePdf
{
public:
	WritePdf();
	void WriteToFile(vector<WeekSchedule> &schedule, string &fileName);
	~WritePdf();
private:
//	void DrawGrid(Document &doc, vector<WeekSchedule> &schedule, Canvas &canvas);
	const double a4Paper_x = 597.6;
	const double a4Paper_y = 848.68;
};

#endif