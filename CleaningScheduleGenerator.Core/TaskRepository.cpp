#include "TaskRepository.h"

#include <string>
#include <sstream>

#include "readIniFile.h"

using namespace std;

vector<Task*> tasks;

TaskRepository::TaskRepository()
{
}

int TaskRepository::callback(void *data, int argc, char **argv, char **azColName)
{

	int i;
	fprintf(stderr, "%s: ", (const char*)data);
	for (i = 0; i<argc; i++) {
		printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
	}
	printf("\n");

	TaskRepository* taskRepository = reinterpret_cast<TaskRepository*>(data);
	taskRepository->TaskRepositoryCallback(argc, argv, azColName);

	return 0;
}

void TaskRepository::TaskRepositoryCallback(int argc, char **argv, char **azColName)
{
	int taskId = atoi(argv[0]);
	string taskName = argv[1];
	string taskDescription = argv[2] ? argv[2] : "";

	ConvertToTask(taskId, taskName, taskDescription);
}

void TaskRepository::ConvertToTask(int taskId, string taskName, string taskDescrption)
{
	Task* task = new Task(taskId, taskName, taskDescrption);
	tasks.push_back(task);
}


vector<Task*> TaskRepository::GetAll()
{

	sqlite3 *db;
	char *zErrMsg = 0;
	int rc;
	char *sql;
	const char* data = "Callback function called";

	/* Open database */
	rc = sqlite3_open("cleaningschedule.db", &db);
	if (rc) {
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		exit(0);
	}
	else {
		fprintf(stderr, "Opened database successfully\n");
	}

	const char* query = "SELECT * FROM Tasks";
	
	/* Execute SQL statement */
	rc = sqlite3_exec(db, query, callback, &data, &zErrMsg);
	if (rc != SQLITE_OK) {
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	}
	else {
		fprintf(stdout, "Operation done successfully\n");
	}
	sqlite3_close(db);




	//ReadIniFile* readIniFile = new ReadIniFile("config.ini");
	//vector<string> tasksText = readIniFile->ReadTasks();

	 // = new vector<Task*>();

	/*for (unsigned int i = 0; i < tasksText.size(); i++)
	{
		Task* t = new Task(i, tasksText.at(i));
		tasks.push_back(t);
	}*/

	return tasks;
}

int callback(int argc, char **argv, char **azColName)
{
	/*int i;
	fprintf(stderr, "%s: ", (const char*)data);
	for (i = 0; i<argc; i++) {
		printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
	}
	printf("\n");*/
	return 0;
}



//bool AddTask(Task* task)
//{
//	ostringstream queryStream;
//	queryStream << "INSERT INTO Tasks (Id,Name,Descrption) VALUES (" << task->Name << "," << task->Description << ")";
//	const char* query = queryStream.str().c_str();
//
//	return DatabaseBase().ExecuteQuery(query, my_special_callback);
//}
//
//bool UpdateTask(Task* task)
//{
//	ostringstream queryStream;
//
//	queryStream << "UPDATE Tasks set Name = " << task ->Name << " AND Description = " << task->Description << " where Id = " << task->Id << " SELECT * from Tasks";
//
//	const char* query = queryStream.str().c_str();
//
//	return DatabaseBase().ExecuteQuery(query, my_special_callback);
//}
//
//bool DeleteTask(Task* task)
//{
//	ostringstream queryStream;
//	queryStream << "Delete from Tasks where Id = " << task->Id << " SELECT * from Tasks";
//
//	const char* query = queryStream.str().c_str();
//
//	return DatabaseBase().ExecuteQuery(query, my_special_callback);
//}


TaskRepository::~TaskRepository()
{
}
