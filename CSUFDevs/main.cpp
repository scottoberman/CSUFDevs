#include <iostream>
#include <iomanip>
#include "sql.h"

otl_connect db; // Connection to database

int main()
{
	// Connect to server
	otl_connect::otl_initialize();

	std::string errorMsg; // For exceptions from SQL statements
	int			errorCode;// For exceptions from SQL statements

	errorCode = 0;

	try
	{
		// You will need to install the 32-bit oracle MySql Connector for this (and the entire program) to function
		db.rlogon("DRIVER=MySQL ODBC 5.3 Unicode Driver;SERVER=ims.cj2zvsooupan.us-west-2.rds.amazonaws.com;PORT=3306;USER=imsmaster;PASSWORD=S0ftwareEngineeringDog!");
		db.direct_exec("USE ims");

		// Call the menu from which the user may interface with the database.
		ScottMenu();

	}
	catch (otl_exception& e)
	{
		std::cout << e.msg;
		std::cout << e.code;
	}

	return 0;
}