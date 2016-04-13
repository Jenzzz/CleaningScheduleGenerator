#ifndef __PERSON_H__
#define __PERSON_H__

#include <ostream>
#include <string>

using namespace std;

class Person
{
public:
	Person();
	Person(int id, string name, bool IsNestor = false);
	int Id;
	string Name;
	bool IsNestor;
	~Person();
};

inline ostream& operator<<(ostream &os, const Person &p)
{
	return os << p.Name;
}

#endif
