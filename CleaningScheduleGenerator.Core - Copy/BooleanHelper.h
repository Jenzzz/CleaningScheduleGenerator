#ifdef COMPILE_MYLIBRARY
#define MYLIBRARY_EXPORT __declspec(dllexport)
#else
#define MYLIBRARY_EXPORT __declspec(dllimport)
#endif

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