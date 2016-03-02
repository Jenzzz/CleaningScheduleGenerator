#ifndef __TASK_H__
#define __TASK_H__

#include <ostream>

using namespace std;

class Task
{
public:
	Task(int id, string name);
	int Id;
	string Name;
	string Description;
	~Task();
};

inline ostream& operator<<(ostream &os, const Task &t)
{
	return os << t.Name.c_str();
}

#endif __TASK_H__

