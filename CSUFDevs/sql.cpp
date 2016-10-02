#include "sql.h"

otl_connect db; // connect object

char someChar1;
char someChar2;
char* pointer;

// Try not to edit this ungodly abomination
std::string SelectAll(std::string TABLE)
{
	char query[100];		// Contains the query sent to the SQL database
	std::string result;		// The "result" from the SQL database (rows are on seperate lines and columns are seperated by whitespace)
	otl_stream sqlStream;	// Raw source of SQL result
	otl_var_desc* nextVar;	// Contains the information regarding the datatype of the next piece of data to be read from the database.

	strcpy(query, "SELECT * FROM ");
	strcat(query, TABLE.c_str());
	sqlStream.open(100, query, db);
	nextVar = sqlStream.describe_next_out_var();

	// Determine the datatype of each variable and append it to the result string (Datatypes that I don't know how to handle yet are commented out).
	while (!sqlStream.eof())
	{
		switch (nextVar->ftype)
		{
//#ifdef OTL_BIGINT
//		case(20) : // BIG INT
//		{
//			OTL_UBIGINT temp;
//			sqlStream >> temp;
//			break;
//		}
//#endif
		//case(12) : // BLOB
		//{
		//	otl_lob_stream temp;
		//	sqlStream >> temp;
		//	result.append((std::string)temp)
		//	break;
		//}

		case(1) :  // CHAR // CANNOT OUTPUT THE ENTIRE STRINGS OK
		{
			unsigned short temp[25];
			sqlStream >> (unsigned char*)temp;

			result.append(reinterpret_cast<char*>(temp));
			break;
		}
		case(11) :  // CLOB
		{
			otl_lob_stream temp;
			sqlStream >> temp;
			break;
		}
		//case(17) : // DB2DATE
		//{
		//	otl_datetime temp; // May not be correct type for this case
		//	sqlStream >> temp;
		//	result.append((std::string)temp)
		//	break;
		//}

		//case(16) : // DB2TIME
		//{
		//	otl_datetime temp; // May not be correct type for this case
		//	sqlStream >> temp;
		//	result.append((std::string)temp)
		//	break;
		//}
		case(2) : // DOUBLE
		{
			double temp;
			sqlStream >> temp;
			result.append(std::to_string(temp));
			break;
		}
		case(3) : // FLOAT
		{
			float temp;
			sqlStream >> temp;
			break;
		}
		case(4) : // INT
		{
			int temp;
			char tempCh;
				sqlStream >> temp;
			sqlStream >> tempCh;
			result.append(std::to_string(temp));
			break;
		}
		case(7) : // LONG INT
		{
			long int temp;
			sqlStream >> temp;
			result.append(std::to_string(temp));
			break;
		}
		//case(19) : // LTZ TIMESTAMP
		//	break;
		//case(23) : // RAW
		//	break;
		//case(10) : // RAW LONG
		//	break;
		case(6) : // SHORT
		{
			short temp;
			sqlStream >> temp;
			result.append(std::to_string(temp));
			break;
		}
		//case(8) : // TIMESTAMP
		//	break;
		//case(18) : // TZ TIMESTAMP
		//	break;
//#ifdef OTL_BIGINT
//		case(27) : // U BIG INT
//
//			OTL_UBIGINT temp;
//			sqlStream >> temp;
//			break;
//#endif
		case(5) : // UNSIGNED INT
		{
			unsigned temp;
			sqlStream >> temp;
			result.append(std::to_string(temp));
			break;
		}
		case(9) : // VAR CHAR LONG
		{
			otl_long_unicode_string temp; // May not work
			std::stringstream tempStream;
			sqlStream >> temp;
			for (int x = 0; x < temp.len(); x++)
			{
				tempStream<<(char)temp[x];
			}

			result.append(tempStream.str());
			
			break;
		}
		default:
			std::cerr << "Unknown output type detected.";
		}

		// If the end of the row has been reached, enter a newline char so the next row will be on its own line.
		// Else, add a whitespace character to seperate the column data.
		try
		{
			sqlStream.check_end_of_row();
			result.append("\n");
			
		}
		catch (otl_exception& )
		{
			result.append(" ");
		}
		nextVar = sqlStream.describe_next_out_var();
		
	}

	// Remove the extra newline from the back of the string.
	result.pop_back();

	return result;
}

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

	char output[100];

	while (!test.eof())
	{

	}
}

// For testing purposes only
void SelectFixedStructure()
{
	
}

void sqlTesting()
{
	otl_connect::otl_initialize();
	try
	{
		db.rlogon("DRIVER=MySQL ODBC 5.3 Unicode Driver;SERVER=localhost;PORT=3306;USER=root;PASSWORD="); // You will need to install the 32-bit oracle MySql Connector
																										  // for this (and the entire program) to function
		db.direct_exec("USE TEST");

		std::cout << SelectAll("TEST");
		
		std::cout << "here";


	}
	catch(otl_exception& e)
	{
		std::cout << e.msg;
		std::cout << e.code;
	}
	
	std::cin.get();

}