#ifndef BOOLEANHELPER_H
#define BOOLEANHELPER_H

#include <string>

using namespace std;

bool String2Bool(string s)
{
	if (s == "true" || s == "TRUE")
		return true;
	else if (s == "false" || s == "FALSE")
		return false;
	throw exception("bad string");
}

#endif // !BOOLEANHELPER_H