#include "readIniFile.h"

#include <fstream>
#include <Windows.h>

#include <iostream>

using namespace std;

ReadIniFile::ReadIniFile(string fileName) : FileName(fileName)
{
	/*std::cout << "Config loaded from 'test.ini': version="
		<< reader.GetInteger("protocol", "version", -1) << ", name="
		<< reader.Get("user", "name", "UNKNOWN") << ", email="
		<< reader.Get("user", "email", "UNKNOWN") << ", pi="
		<< reader.GetReal("user", "pi", -1) << ", active="
		<< reader.GetBoolean("user", "active", true) << "\n";*/
	/*std::cout << "Config loaded from 'test.ini': RoomNumbers="
		<< reader.Get("RoomNumbers", "241", "") << "\n";*/
	
	//char *dbserver;
	//GetPrivateProfileString("RoomNumber", "1", "", dbserver, sizeof(dbserver) / sizeof(dbserver[0]), fileName);
}

map<string, string> ReadIniFile::ReadRoomNumbers()
{
	map<string, string> roomNumbers;

	INIReader reader(FileName);

	if (reader.ParseError() < 0) {
		std::cerr << strcat_s("Can't load", sizeof("Can't load"), FileName.c_str()) << endl;
		return roomNumbers;
	}

	roomNumbers["241"] = reader.Get("RoomNumbers", "241", "Name undefined");
	roomNumbers["242"] = reader.Get("RoomNumbers", "242", "Name undefined");
	roomNumbers["243"] = reader.Get("RoomNumbers", "243", "Name undefined");
	roomNumbers["244"] = reader.Get("RoomNumbers", "244", "Name undefined");
	roomNumbers["246"] = reader.Get("RoomNumbers", "246", "Name undefined");
	roomNumbers["251"] = reader.Get("RoomNumbers", "251", "Name undefined");
	roomNumbers["252"] = reader.Get("RoomNumbers", "252", "Name undefined");
	roomNumbers["253"] = reader.Get("RoomNumbers", "253", "Name undefined");
	roomNumbers["254"] = reader.Get("RoomNumbers", "254", "Name undefined");
	roomNumbers["255"] = reader.Get("RoomNumbers", "255", "Name undefined");
	roomNumbers["256"] = reader.Get("RoomNumbers", "256", "Name undefined");
	roomNumbers["257"] = reader.Get("RoomNumbers", "257", "Name undefined");
	roomNumbers["258"] = reader.Get("RoomNumbers", "258", "Name undefined");
	roomNumbers["259"] = reader.Get("RoomNumbers", "259", "Name undefined");
	roomNumbers["260"] = reader.Get("RoomNumbers", "260", "Name undefined");
	
	return roomNumbers;
}

vector<string> ReadIniFile::ReadTasks()
{
	vector<string> tasks;// = new vector<string>();

	INIReader reader(FileName);

	if (reader.ParseError() < 0) {
		std::cerr << strcat_s("Can't load", sizeof("Can't load"), FileName.c_str()) << endl;
		return tasks;
	}

	tasks.push_back(reader.Get("Tasks", "1", "Task undefined"));
	tasks.push_back(reader.Get("Tasks", "2", "Task undefined"));
	tasks.push_back(reader.Get("Tasks", "3", "Task undefined"));
	tasks.push_back(reader.Get("Tasks", "4", "Task undefined"));
	tasks.push_back(reader.Get("Tasks", "5", "Task undefined"));
	tasks.push_back(reader.Get("Tasks", "6", "Task undefined"));
	tasks.push_back(reader.Get("Tasks", "7", "Task undefined"));
	tasks.push_back(reader.Get("Tasks", "8", "Task undefined"));
	tasks.push_back(reader.Get("Tasks", "9", "Task undefined"));
	tasks.push_back(reader.Get("Tasks", "10", "Task undefined"));
	tasks.push_back(reader.Get("Tasks", "11", "Task undefined"));
	tasks.push_back(reader.Get("Tasks", "12", "Task undefined"));
	tasks.push_back(reader.Get("Tasks", "13", "Task undefined"));
	tasks.push_back(reader.Get("Tasks", "14", "Task undefined"));
	tasks.push_back(reader.Get("Tasks", "15", "Task undefined"));
	
	//tasks->push_back("Afwas donderdag");
	//tasks->push_back("Afwas maandag");
	//tasks->push_back("Resttaak donderdag");
	//tasks->push_back("Woonkamer");
	//tasks->push_back("Oud papier");
	//tasks->push_back("Vloer gangen");
	//tasks->push_back("Keuken");
	//tasks->push_back("WC lange gang");
	//tasks->push_back("Douche lange gang");
	//tasks->push_back("Wastafels lange gang");
	//tasks->push_back("Voorraadhok");
	//tasks->push_back("Douche korte gang");
	//tasks->push_back("Wastafels korte gang");
	//tasks->push_back("WC korte gang");
	//tasks->push_back("Huisrekening");

	return tasks;
}

int ReadIniFile::ReadNestor()
{
	INIReader reader(FileName);

	if (reader.ParseError() < 0) {
		std::cerr << strcat_s("Can't load", sizeof("Can't load"), FileName.c_str()) << endl;
		return -1;
	}

	return reader.GetInteger("Nestor", "Nestor", -1);
}

ReadIniFile::~ReadIniFile()
{
}
