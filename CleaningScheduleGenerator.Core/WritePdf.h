#ifdef COMPILE_MYLIBRARY
#define MYLIBRARY_EXPORT __declspec(dllexport)
#else
#define MYLIBRARY_EXPORT __declspec(dllimport)
#endif

#include <vector>
#include <map>
#include <string>

#include "WeekSchedule.h"
#include "jagpdf\api.h"

using namespace std;
using namespace jag;
using namespace jag::pdf;

class MYLIBRARY_EXPORT WritePdf
{
public:
	WritePdf();
	void WriteToFile(vector<WeekSchedule> &schedule, string &fileName);
	~WritePdf();
private:
	void DrawGrid(Document &doc, vector<WeekSchedule> &schedule, Canvas &canvas);
	const double a4Paper_x = 597.6;
	const double a4Paper_y = 848.68;
};