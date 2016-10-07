#include "sql.h"

otl_connect db; // connect object

/****************************************************************************
* FUNCTION SelectAll
* ---------------------------------------------------------------------------
* Selects an entire table and returns a string with some formatting as
* well as the column labels. If you wish to get the entire table without
* the column labels, use the Select function instead.
* ---------------------------------------------------------------------------
* ARGS   : TABLE: The table to be selected.
* OUTPUTS: Nothing
* RETURNS: The table with minor formatting and column labels. If the table
*		   does not exist, an empty string will be returned(NEEDS TO BE IMPLEMENTED TODO).
* NOTES  : Do not use in cases where an element could be longer than 18
*		   units.
*		   If you wish to get the entire table without the column labels,
*		   use the Select function instead.
*****************************************************************************/
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
	outputLen = 18;

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
	query.append(";");
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

// To be used when expecting a single response from a query (ie: Get a name,
// id, price, float, etc from a table).
// Use with primary keys only (CHECK_VAL should be a primary key since only
// one element is returned).
// Format: select VAL_TO_GET from TABLE where ID_VAL = CHECK_VAL
std::string SelectSingleElementFromTableByString(const std::string VAL_TO_GET,
												 const std::string TABLE,
												 const std::string ID_VAL,
												 const std::string CHECK_VAL)
{
	otl_stream sqlStream;
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

/****************************************************************************
* FUNCTION StreamToString
* ---------------------------------------------------------------------------
* When a query is executed that returns some value, this function converts
* one element from the returned statement to a string. Used to help in
* "select" functions.
* ---------------------------------------------------------------------------
* ARGS   : sqlStream: The stream from the sql query (THE STREAM CURSOR
*					  POSITION IS SHIFTED FORWARD BY THIS FUNCTION).
* OUTPUTS: Nothing
* RETURNS: One element of an sql stream (from a query) as a string.
* NOTES  : Unsupported types are commented out within the interior switch
*		   statement.
*****************************************************************************/
std::string StreamToString(otl_stream& sqlStream)
{
	std::string result;
	int outputType = sqlStream.describe_next_out_var()->ftype;
		switch (outputType)
		{


		//case(20) : // BIG INT
		//{
		//	OTL_UBIGINT temp;
		//	sqlStream >> temp;
		//	break;
		//}

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
		case(19) : // LTZ TIMESTAMP
		{
			otl_datetime temp;
			sqlStream >> temp;
			result.append(std::to_string(temp.year));
			result.append("-");
			result.append(std::to_string(temp.month));
			result.append("-");
			result.append(std::to_string(temp.day));
			result.append(" ");
			result.append(std::to_string(temp.hour));
			result.append(":");
			result.append(std::to_string(temp.minute));
			result.append(":");
			result.append(std::to_string(temp.second));
			break;
		}
			
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
		case(8) : // TIMESTAMP
		{
			otl_datetime temp;
			sqlStream >> temp;
			result.append(std::to_string(temp.year));
			result.append("-");
			result.append(std::to_string(temp.month));
			result.append("-");
			result.append(std::to_string(temp.day));
			result.append(" ");
			result.append(std::to_string(temp.hour));
			result.append(":");
			result.append(std::to_string(temp.minute));
			result.append(":");
			result.append(std::to_string(temp.second));
			break;
		}
		//case(18) : // TZ TIMESTAMP
		//	break;
		//case(27) : // U BIG INT

		//	OTL_UBIGINT temp;
		//	sqlStream >> temp;
		//	break;
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
			std::cout << outputType;
			std::cin.get();
			std::cerr << "Unknown output type detected.";
		}

		return result;
}

/****************************************************************************
* FUNCTION Select
* ---------------------------------------------------------------------------
* More general function for using Select statements.The difference between
* this and SelectAll is column names are not displayed above the table.
* Formatting possible via FORMAT_WIDTH argument (defaults to 0);
* ---------------------------------------------------------------------------
* ARGS   : SELECT_STATEMENT: The statement query to be executed.
*		   FORMAT_WIDTH	   : The optimal size of an element's output plus
*							 whitespace. If the actual width is greater than
*							 this value, the output will just contain a
*							 single space after the element.
* OUTPUTS: Nothing
* RETURNS: The result of the query as a string with minor formatting. If the
*		   statement is invalid, an empty string will be returned
*		   (NEEDS TO BE IMPLEMENTED TODO).
* NOTES  : 
*****************************************************************************/
std::string Select(const std::string SELECT_STATEMENT,
				   const std::string::size_type FORMAT_WIDTH)
{
	std::string query;		// Contains the query sent to the SQL database
	std::string result;		// The "result" from the SQL database (rows are on seperate lines and columns are seperated by whitespace)
	std::string curResult;	// The individual output received from the stream.
	otl_stream sqlStream;	// Raw source of SQL result
	otl_var_desc* nextVar;	// Contains the information regarding the datatype of the next piece of data to be read from the database.
	int tempResultWidth;	// Size of output before padding is added (used for formatting).

	sqlStream.open(100, SELECT_STATEMENT.c_str(), db);
	nextVar		= sqlStream.describe_next_out_var();

	while (!sqlStream.eof())
	{
		curResult = StreamToString(sqlStream);
		tempResultWidth = curResult.size();

		for (int x = 0; x < (int)FORMAT_WIDTH - tempResultWidth - 1; x++)
		{
			curResult.append(" ");
		}

		// One space is always placed after an element to prevent run-together elements.
		result.append(" ");

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

/****************************************************************************
* FUNCTION Modifying Query
* ---------------------------------------------------------------------------
* For use with queries that will affect the database in some way:
* inserts, deletes, drop, modify, update etc.
* Returns true if the query was successful. Otherwise, returns false.
* Error code and error message passed back by reference.
* Error codes / message have varying usefulness and sometimes are
* completely worthless.
* ---------------------------------------------------------------------------
* ARGS   : QUERY	: The query to be executed.
		   errorCode: If the function throws an exception, the resulting
					  error code will be placed here and passed back by
					  reference.
		   errorMsg : If the function throws an exception, the resulting
					  error msg will be placed here and passed back by
					  reference.
* OUTPUTS: Nothing
* RETURNS: A bool which is true if the query succeeded. If it was not
*		   successful, the errorCode and errorMsg args will contain their
*		   relevent exception information.
*		   
* NOTES  : This function is not meant for queries that will need their result
*		   passed back (ie: select queries).
*****************************************************************************/
bool ModifyingQuery(const std::string QUERY,
					int& errorCode,
					std::string& errorMsg)
{
	bool querySuccessful;
	try
	{
		db.direct_exec(QUERY.c_str());
		querySuccessful = true;
	}
	catch(otl_exception& e)
	{
		errorCode = e.code;
		errorMsg = (char*)(e.msg);
		querySuccessful = false;
	}
	
	return querySuccessful;
}

// MIGHT BE BAD STYLE TO RETURN BY REFERENCE IN THIS MANNER TODO
std::map<std::string, Stock>& GetTableFromDatabase()
{
	std::map<std::string, Stock> tableMap;

	otl_connect::otl_initialize();
	otl_stream sqlStream;
	db.rlogon("DRIVER=MySQL ODBC 5.3 Unicode Driver;SERVER=ims.cj2zvsooupan.us-west-2.rds.amazonaws.com;PORT=3306;USER=imsmaster;PASSWORD=S0ftwareEngineeringDog!");

	db.direct_exec("USE ims");
	sqlStream.open(100, "SELECT * FROM item", db);

	while (!sqlStream.eof())
	{
		Stock* newStock = new Stock();

		unsigned short tempId[255];
		unsigned short tempName[255];
		int				tempQuantity;
		unsigned short tempShelfNum[255];
		unsigned short tempDescription[255];
		double			tempPrice;
		int				tempStatus;

		string tempStr;

		// Get ID from the stream
		sqlStream >> (unsigned char*)tempId;
		tempStr = (char*)tempId;
		newStock->SetID(tempStr);

		// Get name from the stream
		sqlStream >> (unsigned char*)tempName;
		tempStr = (char*)tempName;
		newStock->SetName(tempStr);

		// Get the description from the stream
		sqlStream >> (unsigned char*)tempDescription;
		tempStr = (char*)tempDescription;
		newStock->SetDescription(tempStr);

		// Get the price from the stream
		sqlStream >> tempPrice;
		newStock->SetPrice(tempPrice);

		// Get the quantity from the stream
		sqlStream >> tempQuantity;
		newStock->SetQuantity(tempQuantity);

		//// Get the status (NOT IN CLASS ATM TODO)
		//sqlStream >> tempStatus;
		//newStock->SetStatus(tempStatus);

		// Get the shelf number from the stream
		sqlStream >> (unsigned char*)tempShelfNum;
		tempStr = (char*)tempShelfNum;
		newStock->SetShelf(tempStr);

		// Get the item timestamp from the stream
		otl_datetime temp;
		std::string timeStampStr;
		sqlStream >> temp;
		timeStampStr.append(std::to_string(temp.year));
		timeStampStr.append("-");
		timeStampStr.append(std::to_string(temp.month));
		timeStampStr.append("-");
		timeStampStr.append(std::to_string(temp.day));
		timeStampStr.append(" ");
		timeStampStr.append(std::to_string(temp.hour));
		timeStampStr.append(":");
		timeStampStr.append(std::to_string(temp.minute));
		timeStampStr.append(":");
		timeStampStr.append(std::to_string(temp.second));

		tableMap.emplace(newStock->GetID(), *newStock);

	}

	return tableMap;
}


// Playground for testing sql functions etc.
void sqlTesting()
{
	otl_connect::otl_initialize();

	std::string errorMsg;
	int			errorCode;

	errorCode = 0;
	
	try
	{
		// You will need to install the 32-bit oracle MySql Connector for this (and the entire program) to function
		db.rlogon("DRIVER=MySQL ODBC 5.3 Unicode Driver;SERVER=ims.cj2zvsooupan.us-west-2.rds.amazonaws.com;PORT=3306;USER=imsmaster;PASSWORD=S0ftwareEngineeringDog!");

		db.direct_exec("USE ScottTest;");

		std::cout << SelectAll("TEST");

		std::cout << std::endl << std::endl;

		std::cout << Select("SELECT * FROM TEST WHERE SEX = 'f'", 15);

		std::cout << std::endl << std::endl;
		std::cout << SelectSingleElementFromTableByString("ID","TEST", "SEX", "f");
		std::cout << std::endl;

		//if (ModifyingQuery("UPDATE TEST SET BLUR = \'q\' WHERE ID = \'4\'", errorCode, errorMsg))
		//{
		//	std::cout << "query successful";
		//}
		//else
		//{
		//	std::cout << "Query failed" << std::endl;
		//	std::cout << "Error Code: " << errorCode << std::endl;
		//	std::cout << "Error Message: " << errorMsg <<  std::endl;
		//}


	}
	catch(otl_exception& e)
	{
		std::cout << e.msg;
		std::cout << e.code;
	}
	
}