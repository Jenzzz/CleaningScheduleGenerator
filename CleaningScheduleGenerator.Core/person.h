#ifndef __PERSON_H__
#define __PERSON_H__

#include <ostream>

using namespace std;

class Person
{
public:
	Person(string name, bool IsNestor = false);
	string Name;
	bool IsNestor;
	~Person();
};

inline ostream& operator<<(ostream &os, const Person &p)
{
	return os << p.Name;
}

#endif
