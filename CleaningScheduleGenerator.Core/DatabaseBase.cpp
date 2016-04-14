#include "DatabaseBase.h"

#include <iostream>

using namespace std;

DatabaseBase::DatabaseBase()
{
	sqlite3 *db;
	char *zErrMsg = 0;
	int rc;
	
	//strcat_s("Can't load", sizeof("Can't load"), FileName.c_str())

	rc = sqlite3_open("cleaningschedule.db", &db);

	if (rc) 
	{
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		exit(0);
	}
	else 
	{
		fprintf(stderr, "Opened database successfully\n");
	}
	sqlite3_close(db);
}

bool DatabaseBase::ExecuteQuery(const char* query, sqlite3_stmt *stmt)
{
	sqlite3 *db;
	char *zErrMsg = 0;
	//int rc;
	const char* data = "Callback function called";

	sqlite3_open("cleaningschedule.db", &db);

	/*rc = sqlite3_exec(db, query, callback.target<int(void*, int, char**, char**)>(), 0, &zErrMsg);

	if (rc != SQLITE_OK) {
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
		return false;
	}

	cout << "ExecuteQuery done successfully" << endl;

	sqlite3_close(db);*/

	//sqlite3_stmt *stmt;
	int rc = sqlite3_prepare_v2(db, query, -1, &stmt, NULL);
	if (rc != SQLITE_OK)
		throw string(sqlite3_errmsg(db));

	//rc = sqlite3_bind_int(stmt, 1, id);    // Using parameters ("?") is not
	//if (rc != SQLITE_OK) {                 // really necessary, but recommended
	//	string errmsg(sqlite3_errmsg(db)); // (especially for strings) to avoid
	//	sqlite3_finalize(stmt);            // formatting problems and SQL
	//	throw errmsg;                      // injection attacks.
	//}

	rc = sqlite3_step(stmt);
	if (rc != SQLITE_ROW && rc != SQLITE_DONE) {
		string errmsg(sqlite3_errmsg(db));
		sqlite3_finalize(stmt);
		throw errmsg;
	}
	if (rc == SQLITE_DONE) {
		sqlite3_finalize(stmt);
		throw string("Item not found");
	}

	
	cout << sqlite3_column_text(stmt, 0) << endl;
	cout << sqlite3_column_text(stmt, 1) << endl;

	/*this->id = id;
	this->first_name = string(sqlite3_column_text(stmt, 0));
	this->last_name = string(sqlite3_column_text(stmt, 1));
	this->age = sqlite3_column_int(stmt, 2);*/

	sqlite3_finalize(stmt);
	
	return true;
}


DatabaseBase::~DatabaseBase()
{
}
