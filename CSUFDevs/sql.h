#ifndef SQL_H_
#define SQL_H_

#define OTL_STL
#define OTL_ODBC
#define OTL_ODBC_SELECT_STM_EXECUTE_BEFORE_DESCRIBE
#define OTL_UNICODE

#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include "otlv4.h" // ALL SQL FUNCTIONALITY WITHIN THIS HEADER FILE
#include "stock.h"

using namespace std;

std::string SelectAll(const std::string TABLE,
					  const std::string::size_type FORMAT_WIDTH = 0);
std::string SelectSingleElementFromTableByString(const std::string VAL_TO_GET,
												 const std::string TABLE,
												 const std::string ID_VAL,
												 const std::string CHECK_VAL);
std::string StreamToString(otl_stream& sqlStream);

std::string Select(const std::string SELECT_STATEMENT,
				   const std::string::size_type FORMAT_WIDTH = 0);

bool ModifyingQuery(const std::string QUERY,
					int& errorCode,
					std::string& errorMessage);

void GetItemsFromDatabase(map<std::string, Stock>& WAREHOUSE);

void ScottMenu();

bool InitConnection();

void DeleteItemByID(const int ID);

void sqlTesting();

#endif