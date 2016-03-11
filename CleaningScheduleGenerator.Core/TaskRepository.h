#ifndef __TaskRepository_H_
#define __TaskRepository_H_

#include <vector>

#include "task.h"
#include "DatabaseBase.h"

using namespace std;

class TaskRepository : DatabaseBase
{
public:
	TaskRepository();
	vector<Task*> GetAll();
	bool AddTask(Task* task);
	bool UpdateTask(Task* task);
	bool DeleteTask(Task* task);
	void TaskRepositoryCallback(int argc, char **argv, char **azColName);
	static int callback(void *data, int argc, char **argv, char **azColName);
	void ConvertToTask(int taskId, string taskName, string taskDescrption);
	//static int my_special_callback(void* param, int count, char **data, char **columns);
	~TaskRepository();
};

#endif __TaskRepository_H_