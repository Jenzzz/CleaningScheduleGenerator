#include "WritePdf.h"

#include <ctime>
#include <iostream>
#include <fstream>
#include <QPdfWriter>

using namespace std;
using namespace jag;
using namespace jag::pdf;

WritePdf::WritePdf()
{
	const int dpi = 72;

//	QPageLayout* newPageLayout = new QPageLayout();
//	newPageLayout.

	QPdfWriter writer(a_strFileName);
	writer.setPageSize(QPagedPaintDevice::A4);
//	writer.setPageLayout();
	writer.setOrientation(QPageLayout::Orientation.Portrait);
	writer.setCreator("Jens");
	writer.setResolutio(dpi);
	writer.setTitle("Schoonmaakrooster");

	QPainter painter(&writer);
	
	painter.setPen(Qt::red);
	painter.drawText(0, 0, "THIS IS MY RED PDF TEXT..");
	
	painter.end();
}

void WritePdf::WriteToFile(vector<WeekSchedule> &schedule, string &fileName)
{
	if (ifstream(fileName))
	{
		cout << "Filename " << fileName << "already exists" << endl;
		return;
	}

	pdf::Document doc(pdf::create_file(fileName.append(".pdf").c_str()));
	doc.page_start(a4Paper_x, a4Paper_y);
	pdf::Canvas canvas = doc.page().canvas();

	DrawGrid(doc, schedule, canvas);

	doc.page_end();
	doc.finalize();
}

WritePdf::~WritePdf()
{
}

void WritePdf::DrawGrid(Document &doc, vector<WeekSchedule> &schedule, Canvas &canvas)
{
	const double margin_top = 36;
	const double margin_left = 36;
	const double margin_bot = 36;
	const double margin_right = 36;
	
	const double padding_top = 20;
	const double padding_left = 8;
	const double padding_bot = 10;
	const double padding_right = 10;

	vector<SingleTaskRoom> singleTaskRooms = schedule.at(0).TasksForRooms;

	const double widthItemX = (a4Paper_x - margin_left - margin_right) / (schedule.size() + 1);
	const double widthItemY = (a4Paper_y - margin_bot - margin_top) / (singleTaskRooms.size() + 1);

	reverse(singleTaskRooms.begin(), singleTaskRooms.end());

	for (unsigned int i = 0; i < 17; i++)
	{
		canvas.move_to(margin_left, a4Paper_y - (margin_top + widthItemY * i));
		canvas.line_to(a4Paper_x - margin_right, a4Paper_y - (margin_top + widthItemY *i));
		canvas.path_paint("s");
	}

	for (unsigned int x = 0; x < 6; x++)
	{
		canvas.move_to(margin_left + (widthItemX * x), a4Paper_y - margin_top);
		canvas.line_to(margin_left + (widthItemX * x), margin_bot);
		canvas.path_paint("s");
	}

	Font helv_12 = doc.font_load("standard; enc=iso-8859-2; name=Helvetica; size=12");
	Font helv_10 = doc.font_load("standard; enc=iso-8859-2; name=Helvetica; size=10");
	canvas.text_font(helv_12);

	canvas.text(margin_left + padding_left, a4Paper_y - margin_top - padding_top, "Taken");

	canvas.text_font(helv_10);

	// print all task names to pdf
	for each (SingleTaskRoom singleTaskRoom in singleTaskRooms)
	{
		// (a4Paper_y - margin_top) - widthItemY * (singleTaskRoom.task->Id)
		canvas.text(margin_left + padding_left, a4Paper_y - (margin_top + padding_top + widthItemY * (singleTaskRoom.task->Id)), singleTaskRoom.task->Name.c_str());
	}

	int sizeCheckbox = 10;

	double tempWidthItemX = widthItemX;
	
	for each (WeekSchedule weekSchedule in schedule)
	{	
		//weekSchedule->DateTime.tm_year -= 1900; // starting at year 1900
		char buffer[60] = { 0 };
		strftime(buffer, sizeof(buffer), "%d %B %Y", &(weekSchedule.DateTime));
		//strftime(buffer, sizeof(buffer), "%A %d %B %Y", &weekSchedule.DateTime);

		canvas.text_font(helv_12);
		canvas.text(margin_left + padding_left + tempWidthItemX, a4Paper_y - margin_top - padding_top, buffer);

		canvas.text_font(helv_10);

		for each (SingleTaskRoom singleTaskRoom in weekSchedule.TasksForRooms)
		{
			canvas.text(margin_left + padding_left + tempWidthItemX, a4Paper_y - (margin_top + 13 + widthItemY * (singleTaskRoom.task->Id)), singleTaskRoom.room->Habitant->Name.c_str());
			canvas.text(margin_left + padding_left + tempWidthItemX, a4Paper_y - (margin_top + 13 + 15 + widthItemY * (singleTaskRoom.task->Id)), singleTaskRoom.room->Overseer->Name.c_str());

			canvas.rectangle(margin_left + tempWidthItemX + widthItemX - sizeCheckbox - padding_right, a4Paper_y - (margin_top + 15 + widthItemY * (singleTaskRoom.task->Id)), sizeCheckbox, sizeCheckbox);
			canvas.path_paint("s");

			canvas.rectangle(margin_left + tempWidthItemX + widthItemX - sizeCheckbox - padding_right, a4Paper_y - (margin_top + 15 + 15 + widthItemY * (singleTaskRoom.task->Id)), sizeCheckbox, sizeCheckbox);
			canvas.path_paint("s");


			canvas.move_to(margin_left + padding_left + tempWidthItemX, a4Paper_y - (margin_top + 13 + 15 + 18 + widthItemY * (singleTaskRoom.task->Id)));
			canvas.line_to(margin_left + tempWidthItemX + widthItemX - sizeCheckbox - padding_right, a4Paper_y - (margin_top + 13 + 15 + 18 + widthItemY * (singleTaskRoom.task->Id)));
			canvas.path_paint("s");

			//				   margin_left + padding_left + tempWidthItemX,                              a4Paper_y - (margin_top + 13 + 15 + 15 + widthItemY * (singleTaskRoom.task->Id))
			/*canvas.rectangle(margin_left + tempWidthItemX + widthItemX - sizeCheckbox - padding_right, a4Paper_y - (margin_top + 15 + 15 + 15 + widthItemY * (singleTaskRoom.task->Id)), sizeCheckbox, sizeCheckbox);
			canvas.path_paint("s");*/
		}

		tempWidthItemX += widthItemX;
	}
}
