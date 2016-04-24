#ifndef __DATABASEBASE_H__
#define __DATABASEBASE_H__

#include <string>
#include <functional>

using namespace std;

class DatabaseBase
{
public:
	DatabaseBase();
//	bool ExecuteQuery(const char* query, sqlite3_stmt *stmt);
	//bool ExecuteQuery(const char* query, function<int (void*, int, char**, char**)> callback);
	~DatabaseBase();
private:
	//static int callback(void *data, int argc, char **argv, char **azColName);
};

#endif