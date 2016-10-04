#include "sql.h"

otl_connect db; // connect object

// Output all the contents of a table. Currently, there is no formatting and the tables/columns/rows are not labeled.
std::string SelectAll(std::string TABLE)
{
	std::string query;		// Contains the query sent to the SQL database
	std::string colNames;	// Label for each column.
	std::string result;		// The "result" from the SQL database (rows are on seperate lines and columns are seperated by whitespace)
	std::string curResult;	// The individual output received from the stream.
	otl_stream sqlStream;	// Raw source of SQL result
	otl_var_desc* nextVar;	// Contains the information regarding the datatype of the next piece of data to be read from the database.
	int outputLen;			// The "width" of each element of output.
	int tempResultWidth;	// Size of output before padding is added (used for formatting).

	query.append("select column_name from INFORMATION_SCHEMA.COLUMNS where table_name = \'");
	query.append(TABLE);
	query.append("\'");
	sqlStream.open(100, query.c_str(), db);
	outputLen = 10;

	while (!sqlStream.eof())
	{
		curResult = StreamToString(sqlStream);
		tempResultWidth = curResult.size();
		curResult.insert(tempResultWidth, outputLen - tempResultWidth, ' ');
		result.append(curResult);
		//sqlStream.skip_to_end_of_row();
	}
	result.append("\n");
	sqlStream.close();
	query.clear();
	
	query.append("SELECT * FROM ");
	query.append(TABLE);
	sqlStream.open(100, query.c_str(), db);
	nextVar = sqlStream.describe_next_out_var();

	while (!sqlStream.eof())
	{
		curResult = StreamToString(sqlStream);
		tempResultWidth = curResult.size();
		curResult.insert(tempResultWidth, outputLen - tempResultWidth, ' ');
		result.append(curResult);
		
		// If the end of the row has been reached, enter a newline char so the next row will be on its own line.
		// Else, add a whitespace character to seperate the column data.
		try
		{
			sqlStream.check_end_of_row();
			result.append("\n");
			
		}
		// This block adds a space between elements of the row but this is handled elsewhere now.
		catch (otl_exception& )
		{
			//result.append(" ");
		}
		nextVar = sqlStream.describe_next_out_var();
		
	}

	// Remove the extra newline from the back of the string.
	result.pop_back();

	return result;
}

// For testing only
void SelectFixedStructure()
{
	
}

// To be used when expecting a single response from a query (ie: Get a name, id, price, float, etc from a table).
// Format: select VAL_TO_GET from TABLE where ID_VAL = CHECK_VAL
std::string SelectSingleElementFromTableByString(const std::string VAL_TO_GET,
												 const std::string TABLE,
												 const std::string ID_VAL,
												 const std::string CHECK_VAL)
{
	otl_stream sqlStream;
	std::stringstream conversionStream;
	std::string query;

	query = "SELECT ";
	query.append(VAL_TO_GET);
	query.append(" FROM ");
	query.append(TABLE);
	query.append(" WHERE ");
	query.append(ID_VAL);
	query.append(" = \'");
	query.append(CHECK_VAL);
	query.append("\'");

	sqlStream.open(100, query.c_str(), db);

	return StreamToString(sqlStream);
}

// Returns an element from the response of the query.
std::string StreamToString(otl_stream& sqlStream)
{
	std::string result;
	int outputType = sqlStream.describe_next_out_var()->ftype;
		switch (outputType)
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

		case(1) :  // CHAR (ALSO USED FOR VARCHARS)
		{
			unsigned short temp[25];
			sqlStream >> (unsigned char*)temp;
			for (int x = 0; temp[x] != 0; x++)
			{
				result.push_back((char)(temp[x]));
			}
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

		return result;
}

// Playground for testing sql functions etc.
void sqlTesting()
{
	otl_connect::otl_initialize();

	try
	{
		db.rlogon("DRIVER=MySQL ODBC 5.3 Unicode Driver;SERVER=localhost;PORT=3306;USER=root;PASSWORD="); // You will need to install the 32-bit oracle MySql Connector
																										  // for this (and the entire program) to function
		db.direct_exec("USE TEST");


		std::cout << SelectAll("TEST");

		std::cout << std::endl << std::endl;
		std::cout << SelectSingleElementFromTableByString("ID","TEST", "SEX", "f");


	}
	catch(otl_exception& e)
	{
		std::cout << e.msg;
		std::cout << e.code;
	}
	
}