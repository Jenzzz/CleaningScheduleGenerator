#ifdef COMPILE_MYLIBRARY
#define MYLIBRARY_EXPORT __declspec(dllexport)
#else
#define MYLIBRARY_EXPORT __declspec(dllimport)
#endif

#include <ostream>
#include <string>

using namespace std;

class MYLIBRARY_EXPORT Task
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

