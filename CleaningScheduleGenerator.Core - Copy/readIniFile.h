#ifndef __READINIFILE_H__
#define __READINIFILE_H__

#include <vector>
#include <map>
#include <string>

#include "inih\cpp\INIReader.h"

using namespace std;

class ReadIniFile
{
public:
	ReadIniFile(string fileName);
	map<string, string> ReadRoomNumbers();
	vector<string> ReadTasks();
	int ReadNestor();
	~ReadIniFile();
private:
	string FileName;
};

#endif
