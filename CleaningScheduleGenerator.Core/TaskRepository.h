#ifndef __TaskRepository_H_
#define __TaskRepository_H_

#include <vector>

#include "task.h"

using namespace std;

class TaskRepository
{
public:
	TaskRepository();
	vector<Task*> GetAll();
	~TaskRepository();
};

#endif __TaskRepository_H_