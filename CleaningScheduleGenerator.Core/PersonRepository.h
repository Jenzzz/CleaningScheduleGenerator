#ifndef PERSONREPOSITORY_H
#define PERSONREPOSITORY_H

#include <vector>
#include "person.h"
#include "DatabaseBase.h"

using namespace std;

class PersonRepository : DatabaseBase
{
public:
	PersonRepository();
	vector<Person*>GetAll();
	bool AddTask(Person* person);
	bool UpdateTask(Person* person);
	bool DeleteTask(Person* person);
	//static int my_special_callback(void* param, int count, char **data, char **columns);
	~PersonRepository();
};

#endif // !PERSONREPOSITORY_H