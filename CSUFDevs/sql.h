#define OTL_STL
#define OTL_ODBC
#define OTL_ODBC_SELECT_STM_EXECUTE_BEFORE_DESCRIBE
#define OTL_UNICODE

#include <iostream>
#include <sstream>
#include <string>
#include <otlv4.h> // ALL SQL FUNCTIONALITY WITHIN THIS HEADER FILE

// Sample of how selections are collected(number indicates position in stream except for row and column labels)
// So its on a row by row basis
//	c1	c2	c3	c4	c5	c6	c7
//r1 1	2	3	4	5	6	7
//r2 8	9	10	11	12	13	14
//r3 15	16	17	18	19	20	21
//
// Selects a table of row format INT CHAR


std::string SelectAll(const std::string TABLE);
void SelectFixedStructure();
std::string SelectSingleElementFromTableByString(const std::string VAL_TO_GET,
												 const std::string TABLE,
												 const std::string ID_VAL,
												 const std::string CHECK_VAL);
std::string StreamToString(otl_stream& sqlStream);

void sqlTesting();