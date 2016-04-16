#include "PersonRepository.h"

#include <string>
#include <sstream>
#include <QSqlQuery>

using namespace std;

PersonRepository::PersonRepository()
{
}

/*
* Arguments:
*
*   unused - Ignored in this case, see the documentation for sqlite3_exec
*    count - The number of columns in the result set
*     data - The row's data
*  columns - The column names
*/
int my_special_callback(void* param, int count, char **data, char **columns)
{
	int idx;

	printf("There are %d column(s)\n", count);

	for (idx = 0; idx < count; idx++) {
		printf("The data in column \"%s\" is: %s\n", columns[idx], data[idx]);
	}

	printf("\n");

	return 0;
}

vector<Person*> PersonRepository::GetAll()
{
	char* sql = "SELECT * FROM Habitants";

	vector<Person*> persons;

	return persons;
}

//bool AddPerson(Person* person)
//{
//	ostringstream queryStream;
//	queryStream << "INSERT INTO Habitants (Id,Name,IsNestor) VALUES (" << person->Name << "," << person->IsNestor << ")";
//	const char* query = queryStream.str().c_str();
//
//	return DatabaseBase().ExecuteQuery(query, my_special_callback);
//}
//
//bool UpdatePerson(Person* person)
//{
//	ostringstream queryStream;
//
//	queryStream << "UPDATE Habitants set Name = " << person->Name << " AND IsNestor = " << person->IsNestor << " where Id = " << person->Id << " SELECT * from Habitants";
//
//	const char* query = queryStream.str().c_str();
//
//	return DatabaseBase().ExecuteQuery(query, my_special_callback);
//}
//
//bool DeletePerson(Person* person)
//{
//	ostringstream queryStream;
//	queryStream << "Delete from Habitants where Id = " << person->Id << " SELECT * from Habitants";
//
//	const char* query = queryStream.str().c_str();
//
//	return DatabaseBase().ExecuteQuery(query, my_special_callback);
//}

PersonRepository::~PersonRepository()
{
}
