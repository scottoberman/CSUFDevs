#include "sql.h"

extern otl_connect db; // Connection to database

/****************************************************************************
* FUNCTION SelectAll
* ---------------------------------------------------------------------------
* Selects an entire table and returns a string with some formatting as
* well as the column labels. If you wish to get the entire table without
* the column labels, use the Select function instead.
* ---------------------------------------------------------------------------
* ARGS   : TABLE	   : The table to be selected.
*		   FORMAT_WIDTH: Size of each column
* OUTPUTS: Nothing
* RETURNS: The table with minor formatting and column labels. If the table
*		   does not exist, an empty string will be returned(NEEDS TO BE IMPLEMENTED TODO).
* NOTES  : Do not use in cases where an element could be longer than 18
*		   units.
*		   If you wish to get the entire table without the column labels,
*		   use the Select function instead.
*****************************************************************************/
std::string SelectAll(const std::string TABLE,
					  const std::string::size_type FORMAT_WIDTH)
{
	std::string query;		// Contains the query sent to the SQL database
	std::string colNames;	// Label for each column.
	std::string result;		// The "result" from the SQL database (rows are on seperate lines and columns are seperated by whitespace)
	std::string curResult;	// The individual output received from the stream.
	otl_stream sqlStream;	// Raw source of SQL result
	otl_var_desc* nextVar;	// Contains the information regarding the datatype of the next piece of data to be read from the database.
	int tempResultWidth;	// Size of output before padding is added (used for formatting).

	query.append("select column_name from INFORMATION_SCHEMA.COLUMNS where table_name = \'");
	query.append(TABLE);
	query.append("\'");
	sqlStream.open(1000, query.c_str(), db);

	// Output table labels
	while (!sqlStream.eof())
	{
		curResult = StreamToString(sqlStream);
		tempResultWidth = curResult.size();
		for (int x = 0; x < (int)FORMAT_WIDTH - tempResultWidth - 1; x++)
		{
			curResult.append(" ");
		}
		curResult.append(" ");
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
		for (int x = 0; x < (int)FORMAT_WIDTH - tempResultWidth - 1; x++)
		{
			curResult.append(" ");
		}
		curResult.append(" ");
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
* FUNCTION SelectAllFromItem
* ---------------------------------------------------------------------------
* Gets the Item table from the database and places it in a string.
* ---------------------------------------------------------------------------
* ARGS   : FORMAT_WIDTH: Size of each column
* OUTPUTS: Nothing
* RETURNS: The item table with minor formatting and column labels.
* NOTES  : Needs to be altered when table schema is changed.
*****************************************************************************/
std::string SelectAllFromItem(const std::string::size_type FORMAT_WIDTH)
{
	std::string query;		// Contains the query sent to the SQL database
	std::string colNames;	// Label for each column.
	std::string result;		// The "result" from the SQL database (rows are on seperate lines and columns are seperated by whitespace)
	std::string curResult;	// The individual output received from the stream.
	otl_stream sqlStream;	// Raw source of SQL result
	otl_var_desc* nextVar;	// Contains the information regarding the datatype of the next piece of data to be read from the database.
	int tempResultWidth;	// Size of output before padding is added (used for formatting).

	query = "select column_name from INFORMATION_SCHEMA.COLUMNS where table_name = \'item\'";
	sqlStream.open(1000, query.c_str(), db);

	// Output table labels
	curResult = "Item ID";
	curResult.insert(curResult.end(), FORMAT_WIDTH - curResult.size() - 1, ' ');
	curResult.append(" ");
	result.append(curResult);

	curResult = "Item Name";
	curResult.insert(curResult.end(), FORMAT_WIDTH - curResult.size() - 1, ' ');
	curResult.append(" ");
	result.append(curResult);

	curResult = "Item Desc.";
	curResult.insert(curResult.end(), FORMAT_WIDTH - curResult.size() - 1, ' ');
	curResult.append(" ");
	result.append(curResult);

	curResult = "Price";
	curResult.insert(curResult.end(), FORMAT_WIDTH - curResult.size() - 1, ' ');
	curResult.append(" ");
	result.append(curResult);

	curResult = "Stock Count";
	curResult.insert(curResult.end(), FORMAT_WIDTH - curResult.size() - 1, ' ');
	curResult.append(" ");
	result.append(curResult);

	curResult = "Shelf Number";
	curResult.insert(curResult.end(), FORMAT_WIDTH - curResult.size() - 1, ' ');
	curResult.append(" ");
	result.append(curResult);

	curResult = "Update Time";
	curResult.insert(curResult.end(), FORMAT_WIDTH - curResult.size() - 1, ' ');
	curResult.append(" ");
	result.append(curResult);
	
	result.append("\n");
	sqlStream.close();

	query = "SELECT * FROM item";
	sqlStream.open(100, query.c_str(), db);
	nextVar = sqlStream.describe_next_out_var();

	while (!sqlStream.eof())
	{
		curResult = StreamToString(sqlStream);
		tempResultWidth = curResult.size();
		for (int x = 0; x < (int)FORMAT_WIDTH - tempResultWidth - 1; x++)
		{
			curResult.append(" ");
		}
		curResult.append(" ");
		result.append(curResult);

		// If the end of the row has been reached, enter a newline char so the next row will be on its own line.
		// Else, add a whitespace character to seperate the column data.
		try
		{
			sqlStream.check_end_of_row();
			result.append("\n");

		}
		// This block adds a space between elements of the row but this is handled elsewhere now.
		catch (otl_exception&)
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

	if (sqlStream.is_null())
	{
		result = "NULL";
	}
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
		unsigned short temp[255];
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
		stringstream tempStr;
		
		sqlStream >> temp;

		tempStr.precision(2);

		tempStr << std::fixed << temp;
		result.append(tempStr.str());
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
	case(6) : // SHORT (All shorts assumed to be unsigned)
	{
		short temp;
		sqlStream >> temp;
		result.append(std::to_string((unsigned short)temp));
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
			tempStream << (char)temp[x];
		}

		result.append(tempStream.str());

		break;
	}
	default:
		std::cerr << "Unknown output type detected.";
	}

	if(sqlStream.is_null())
	{
		result = "NULL";
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
	if (result.size() != 0)
	{
		result.pop_back();
	}
	
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
// Fix this up once map class becomes accessible.
//std::map<std::string, Stock>& GetTableFromDatabase()
//{
//	std::map<std::string, Stock> tableMap;
//
//	otl_connect::otl_initialize();
//	otl_stream sqlStream;
//	db.rlogon("DRIVER=MySQL ODBC 5.3 Unicode Driver;SERVER=ims.cj2zvsooupan.us-west-2.rds.amazonaws.com;PORT=3306;USER=imsmaster;PASSWORD=S0ftwareEngineeringDog!");
//
//	db.direct_exec("USE ims");
//	sqlStream.open(100, "SELECT * FROM item", db);
//
//	while (!sqlStream.eof())
//	{
//		Stock* newStock = new Stock();
//
//		unsigned short tempId[255];
//		unsigned short tempName[255];
//		int				tempQuantity;
//		unsigned short tempShelfNum[255];
//		unsigned short tempDescription[255];
//		double			tempPrice;
//		int				tempStatus;
//
//		string tempStr;
//
//		// Get ID from the stream
//		sqlStream >> (unsigned char*)tempId;
//		tempStr = (char*)tempId;
//		newStock->SetID(tempStr);
//
//		// Get name from the stream
//		sqlStream >> (unsigned char*)tempName;
//		tempStr = (char*)tempName;
//		newStock->SetName(tempStr);
//
//		// Get the description from the stream
//		sqlStream >> (unsigned char*)tempDescription;
//		tempStr = (char*)tempDescription;
//		newStock->SetDescription(tempStr);
//
//		// Get the price from the stream
//		sqlStream >> tempPrice;
//		newStock->SetPrice(tempPrice);
//
//		// Get the quantity from the stream
//		sqlStream >> tempQuantity;
//		newStock->SetQuantity(tempQuantity);
//
//		//// Get the status (NOT IN CLASS ATM TODO)
//		//sqlStream >> tempStatus;
//		//newStock->SetStatus(tempStatus);
//
//		// Get the shelf number from the stream
//		sqlStream >> (unsigned char*)tempShelfNum;
//		tempStr = (char*)tempShelfNum;
//		newStock->SetShelf(tempStr);
//
//		// Get the item timestamp from the stream
//		otl_datetime temp;
//		std::string timeStampStr;
//		sqlStream >> temp;
//		timeStampStr.append(std::to_string(temp.year));
//		timeStampStr.append("-");
//		timeStampStr.append(std::to_string(temp.month));
//		timeStampStr.append("-");
//		timeStampStr.append(std::to_string(temp.day));
//		timeStampStr.append(" ");
//		timeStampStr.append(std::to_string(temp.hour));
//		timeStampStr.append(":");
//		timeStampStr.append(std::to_string(temp.minute));
//		timeStampStr.append(":");
//		timeStampStr.append(std::to_string(temp.second));
//
//		tableMap.emplace(newStock->GetID(), *newStock);
//
//	}
//
//	return tableMap;
//}

// Temp menu
void ScottMenu()
{
	int menuInput = -1;
	int errorCode;
	std::string errorMsg;

	do
	{
		std::cout << "CSUFDevs RDBMS Database 1.0\n\n"
					 "Please select an option:\n"
					 "1) Output inventory\n"
					 "2) Add Item to Inventory\n"
					 "3) Remove Item from Inventory\n"
					 "4) Modify Existing Item from Inventory\n"
					 "0) Exit\n";

		std::cin >> menuInput;

		if (std::cin.fail())
		{
			std::cin.clear();
			menuInput = -1;
		}
		
		std::cin.ignore(1000, '\n');

		switch (menuInput)
		{
			std::cout << endl;
			// Select All
			case 1:
			{
				std::cout << SelectAllFromItem(25) << std::endl << std::endl;
				break;
			}
			// Insert Values
			case 2:
			{
				int id;
				std::string name;
				std::string description;
				double price;
				int count;
				int shelf;

				do
				{
					if (std::cin.fail())
					{
						std::cin.clear();
						std::cin.ignore(1000, '\n');
						std::cout << "Invalid input.\n";
					}
					std::cout << "Enter an ID for the new item: ";
					cin >> id;

					
				} while (std::cin.fail());

				std::cin.ignore(1000, '\n');

				std::cout << "Enter a name for the new item: ";
				std::getline(cin, name);

				std::cout << "Enter a description for the new item: ";
				std::getline(cin, description);

				do
				{
					if (std::cin.fail())
					{
						std::cin.clear();
						std::cin.ignore(1000, '\n');
						std::cout << "Invalid input.\n";
					}

					std::cout << "Enter a price of the new item: ";
					cin >> price;

				} while (std::cin.fail());

				do
				{
					if (std::cin.fail())
					{
						std::cin.clear();
						std::cin.ignore(1000, '\n');
						std::cout << "Invalid input.\n";
					}

					std::cout << "Enter the stock count of the new item: ";
					cin >> count;

				} while (std::cin.fail());

				do
				{
					if (std::cin.fail())
					{
						std::cin.clear();
						std::cin.ignore(1000, '\n');
						std::cout << "Invalid input.\n";
					}

					std::cout << "Enter the shelf number of the item: ";
					cin >> shelf;

				} while (std::cin.fail());

				std::cin.ignore(1000, '\n');

				std::string query;

				query = "INSERT INTO item VALUES (";
				query.append(std::to_string(id));
				query.append(", \"");
				query.append(name);
				query.append("\", \"");
				query.append(description);
				query.append("\", ");
				query.append(std::to_string(price));
				query.append(", ");
				query.append(std::to_string(count));
				query.append(", ");
				query.append(std::to_string(shelf));
				query.append(", ");
				query.append("CURRENT_TIMESTAMP)");

				if (ModifyingQuery(query, errorCode, errorMsg))
				{
					std::cout << "Successfully added new item with id " << id << std::endl << std::endl;
				}
				else
				{
					std::cout << "Failed to add item.\n"
								 "Error Code: " << errorCode << "\n"
								 "Error Message: " << errorMsg << std::endl << std::endl;
				}

				break;

			}
			// Delete
			case 3:
			{
				int idToRemove;
				std::string query;

				do
				{
					if (std::cin.fail())
					{
						std::cin.clear();
						std::cin.ignore(1000, '\n');
						std::cout << "Invalid input\n";
					}
					std::cout << "Enter the item ID of the item you wish to remove: ";
					cin >> idToRemove;

				} while (std::cin.fail());

				std::cin.ignore(1000, '\n');

				query = "DELETE FROM item WHERE item_id = ";
				query.append(std::to_string(idToRemove));

				// Even if the id is not in the table, the database considers the removal a success.
				if (ModifyingQuery(query, errorCode, errorMsg))
				{
					std::cout << "Item of id " << idToRemove << " deleted.";
				}
				else
				{
					std::cout << "Item removal failed.";
				}

				break;
			}
			// Modify
			case 4:
			{
				int idToChange;
				std::string query;

				do
				{
					if (std::cin.fail())
					{
						std::cin.clear();
						std::cin.ignore(1000, '\n');
						std::cout << "Invalid input.\n";
					}

					std::cout << "Enter the item id of the item you wish to modify: ";
					std::cin >> idToChange;

				} while (std::cin.fail());

				std::cin.ignore(1000, '\n');

				query = "Select * FROM item WHERE item_id = ";
				query.append(std::to_string(idToChange));

				if (Select(query) != "")
				{
					int modifyChoice = -1;
					do
					{
						if (std::cin.fail())
						{
							std::cin.clear();
							std::cin.ignore(1000, '\n');
							std::cout << "Invalid input.\n";
						}
						std::cout << "Enter the value which corresponds to the value you would like to change: \n"
									 "1) Item ID\n"
									 "2) Item Name\n"
									 "3) Item Description\n"
									 "4) Price\n"
									 "5) Stock Count\n"
									 "6) Shelf Number\n";

					std::cin >> modifyChoice;
					} while (std::cin.fail());

					std::cin.ignore(1000, '\n');

					switch (modifyChoice)
					{
						// Update Item ID
						case 1:
						{
							int newItemId;
							do
							{
								if (std::cin.fail())
								{
									std::cin.clear();
									std::cin.ignore(1000, '\n');
									std::cout << "Invalid input.\n";
								}

								std::cout << "Enter the new item id: ";
								std::cin >> newItemId;

							} while (std::cin.fail());

							std::cin.ignore(1000, '\n');

							query = "UPDATE item SET item_id = ";
							query.append(std::to_string(newItemId));
							query.append(" WHERE item_id =");
							query.append(std::to_string(idToChange));

							if(ModifyingQuery(query, errorCode, errorMsg))
							{
								std::cout << "Item id changed to " << newItemId;
							}
							else
							{
								std::cout << "Item ID could not be altered. The new item id was already taken.";
							}
							break;
						}
						// Update Item Name
						case 2:
						{
							std::string newName;

							std::cout << "Enter the new item name: ";
							std::getline(std::cin, newName);

							query = "UPDATE item SET item_name = \"";
							query.append(newName);
							query.append("\" WHERE item_id = ");
							query.append(std::to_string(idToChange));

							if (ModifyingQuery(query, errorCode, errorMsg))
							{
								std::cout << "Item name changed to " << newName;
							}
							else
							{
								std::cout << "Failed to change item name.";
							}
							break;
						}
						// Update Item Description
						case 3:
						{
							std::string newDesc;

							std::cout << "Enter the new item description: ";
							std::getline(std::cin, newDesc);

							query = "UPDATE item SET item_description = \"";
							query.append(newDesc);
							query.append("\" WHERE item_id = ");
							query.append(std::to_string(idToChange));

							if (ModifyingQuery(query, errorCode, errorMsg))
							{
								std::cout << "Item description changed to " << newDesc;
							}
							else
							{
								std::cout << "Failed to change item description.";
							}
							break;
						}
						// Update Price
						case 4:
						{
							double newPrice;
							do
							{
								if (std::cin.fail())
								{
									std::cin.clear();
									std::cin.ignore(1000, '\n');
									std::cout << "Invalid input.\n";
								}

								std::cout << "Enter the new item price: ";
								std::cin >> newPrice;

							} while (std::cin.fail());

							std::cin.ignore(1000, '\n');

							query = "UPDATE item SET price = ";
							query.append(std::to_string(newPrice));
							query.append(" WHERE item_id =");
							query.append(std::to_string(idToChange));

							if (ModifyingQuery(query, errorCode, errorMsg))
							{
								std::cout << "Item price changed to " << newPrice;
							}
							else
							{
								std::cout << "Failed to change item price.";
							}
							break;
						}
						// Update Stock Count
						case 5:
						{
							int newCount;
							do
							{
								if (std::cin.fail())
								{
									std::cin.clear();
									std::cin.ignore(1000, '\n');
									std::cout << "Invalid input.\n";
								}

								std::cout << "Enter the new item count: ";
								std::cin >> newCount;

							} while (std::cin.fail());

							std::cin.ignore(1000, '\n');

							query = "UPDATE item SET stock_count = ";
							query.append(std::to_string(newCount));
							query.append(" WHERE item_id =");
							query.append(std::to_string(idToChange));

							if (ModifyingQuery(query, errorCode, errorMsg))
							{
								std::cout << "Item count changed to " << newCount;
							}
							else
							{
								std::cout << "Failed to change item count.";
							}
							break;
						}
						// Update Shelf Number
						case 6:
						{
							int newShelfNum;
							do
							{
								if (std::cin.fail())
								{
									std::cin.clear();
									std::cin.ignore(1000, '\n');
									std::cout << "Invalid input.\n";
								}

								std::cout << "Enter the new item shelf number: ";
								std::cin >> newShelfNum;

							} while (std::cin.fail());

							std::cin.ignore(1000, '\n');

							query = "UPDATE item SET status = ";
							query.append(std::to_string(newShelfNum));
							query.append(" WHERE item_id =");
							query.append(std::to_string(idToChange));

							if (ModifyingQuery(query, errorCode, errorMsg))
							{
								std::cout << "Item shelf number changed to " << newShelfNum;
							}
							else
							{
								std::cout << "Failed to change item count.";
							}
							break;
						}
						default:
							std::cout << "Invalid choice.";
					}
				}
				else
				{
					std::cout << "Item id not found.";
				}




				break;
			}
			case 0:
			{
				std::cout << "Execution complete.\n"
							 "Press enter to continue.";
				std::cin.get();
				break;
			}
			default:
			{
				std::cout << "Invalid input. Select a valid option.";
			}
		}

		std::cout << std::endl;

	} while (menuInput != 0);


				
}

// Acting as temporary menu. Playground for testing sql functions etc.
void sqlTesting()
{

	
}