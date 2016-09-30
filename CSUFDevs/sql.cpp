#define OTL_ODBC
#define OTL_ODBC_SELECT_STM_EXECUTE_BEFORE_DESCRIBE
#define OTL_UNICODE

#include <iostream>
#include <string>
#include <otlv4.h> // ALL SQL FUNCTIONALITY WITHIN THIS HEADER FILE

otl_connect db; // connect object

char someChar1;
char someChar2;
char* pointer;

// Sample of how selections are collected(number indicates position in stream except for row and column labels)
// So its on a row by row basis
//	c1	c2	c3	c4	c5	c6	c7
//r1 1	2	3	4	5	6	7
//r2 8	9	10	11	12	13	14
//r3 15	16	17	18	19	20	21
//
// Selects a table of row format INT CHAR
void select(const std::string TABLE)
{
	char query[80];
	strcpy(query, "SELECT * FROM ");
	strcat(query, TABLE.c_str());


	otl_stream test(64, query, db);

	int f1;
	unsigned short f2[320];

	while (!test.eof()) { // while not end-of-data
		test >> f1;
		test >> (unsigned char*)(f2);
		// overloaded operator>>(unsigned char*) in the case of Unicode
		// OTL accepts a pointer to a Unicode chracter array.
		// operator>>(unsigned short*) wasn't overloaded 
		// in order to avoid ambiguity in C++ type casting.

		std::cout << f1;
		for (int j = 0; f2[j] != 0; ++j)
			std::cout << " " << (char)f2[j];
		std::cout << std::endl;
	}
}

void sqlTesting()
{
	otl_connect::otl_initialize();
	try
	{
		db.rlogon("DRIVER=MySQL ODBC 5.3 Unicode Driver;SERVER=localhost;PORT=3306;USER=root;PASSWORD="); // You will need to install the 32-bit oracle MySql Connector
																										  // for this (and the entire program) to function
		db.direct_exec("USE TEST");

		select("TEST");
		
		std::cout << "here";


	}
	catch(otl_exception& e)
	{
		std::cout << e.msg;
		std::cout << e.code;
	}
	
	std::cin.get();

}