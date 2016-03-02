#include "TaskRepository.h"

#include "readIniFile.h"

using namespace std;

TaskRepository::TaskRepository()
{
}

vector<Task*> TaskRepository::GetAll()
{
	ReadIniFile* readIniFile = new ReadIniFile("config.ini");
	vector<string> tasksText = readIniFile->ReadTasks();

	vector<Task*> tasks; // = new vector<Task*>();

	for (unsigned int i = 0; i < tasksText.size(); i++)
	{
		Task* t = new Task(i, tasksText.at(i));
		tasks.push_back(t);
	}

	return tasks;
}


TaskRepository::~TaskRepository()
{
}
