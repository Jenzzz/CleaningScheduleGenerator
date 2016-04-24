#ifndef __TASK_H__
#define __TASK_H__

#include <ostream>
#include <string>

using namespace std;

class Task
{
public:
	Task(int id, string name, string descrption);
	int Id;
	string Name;
	string Description;
	~Task();
};

inline MYLIBRARY_EXPORT ostream& operator<<(ostream &os, const Task &t)
{
	return os << t.Name.c_str();
}

#endif