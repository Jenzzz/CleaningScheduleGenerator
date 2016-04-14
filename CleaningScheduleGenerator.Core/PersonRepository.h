#ifdef COMPILE_MYLIBRARY
#define MYLIBRARY_EXPORT __declspec(dllexport)
#else
#define MYLIBRARY_EXPORT __declspec(dllimport)
#endif


#include <vector>
#include "person.h"
#include "DatabaseBase.h"

using namespace std;

class MYLIBRARY_EXPORT PersonRepository : DatabaseBase
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