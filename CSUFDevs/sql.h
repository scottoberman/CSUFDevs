#ifndef SQL_H_
#define SQL_H_



#define OTL_STL
#define OTL_ODBC
#define OTL_ODBC_SELECT_STM_EXECUTE_BEFORE_DESCRIBE
#define OTL_UNICODE

#include <iostream>
#include <sstream>
#include <string>
#include "otlv4.h" // ALL SQL FUNCTIONALITY WITHIN THIS HEADER FILE

std::string SelectAll(const std::string TABLE);
std::string SelectSingleElementFromTableByString(const std::string VAL_TO_GET,
												 const std::string TABLE,
												 const std::string ID_VAL,
												 const std::string CHECK_VAL);
std::string StreamToString(otl_stream& sqlStream);

std::string Select(const std::string SELECT_STATEMENT);

bool ModifyingQuery(const std::string QUERY,
					int& errorCode,
					std::string& errorMessage);

void sqlTesting();

#endif