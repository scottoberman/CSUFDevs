//updated 10-7-16 @ 2:34pm by Austin Blanke
//updated 10-8-16 @ 11:00am by Cristopher Hernandez
//current status: Basic functionality is there, several sections need handling for bad user input
//the Find_Item function needs to be modified to work
//sections have been commented out to comply with current iteration
#include <iostream>
#include <iomanip>
#include <map>
#include <string>
#include "Stock.h"
#include "sql.h"

using namespace std;
//Five functional requirements: menu, insert, delete, print, database
enum { CHOICE1 = 1, CHOICE2, CHOICE3, CHOICE4, CHOICE5, CHOICE6 };

void Print_Menu();
void Get_Menu_Choice(map<string, Stock>& warehouse);
void Flush_Input(istream &inStream);
void Insert_Item(map<string, Stock>& warehouse);
void Delete_Item(map<string, Stock>& warehouse);
void Update_Item(map<string, Stock>& warehouse);
void Find_Item(map<string, Stock> warehouse);
void Print_Inventory(const map<string, Stock>& warehouse);
void Write_Line_Menu(int length = 50, char style = '_', string title = "");
void Write_Line(int length = 50, char style = '_');

extern otl_connect db; // Connection to database

int main()
{
	bool EndProgram = false;
	map<string, Stock> warehouse;

	// Connect to MySql Server
	// If this fails, the program will terminate.
	if (InitConnection())
	{
		GetItemsFromDatabase(warehouse); // Fill the warehouse map with items from the database (uncaught exception on failure)

		do
		{
			Print_Menu();
			Get_Menu_Choice(warehouse);

		} while (!EndProgram);
	}
	



	cout << "REACHED END OF MAIN()" << endl;
	return 0;
}

//==========================================================
// Description: This function prints the menu of options
//              the user can perform to on the warehouse
//              inventory
//
// Input: NONE
//
// Output: NONE
//
//==========================================================
void Print_Menu()
{

	Write_Line_Menu(50, '_', " MENU ");
	/*cout << "1) Insert New Item     " << endl;
	cout << "2) Delete Item         " << endl;
	cout << "3) Update Item         " << endl;
	cout << "4) Find Item           " << endl;
	cout << "4) Print Inventory     " << endl;
	cout << "5) Quit Program        " << endl;
	*/
	cout << "1) Insert New Item     " << endl;
	cout << "2) Delete Item         " << endl;
	cout << "3) Print Inventory     " << endl;
	cout << "4) Quit Program        " << endl;
	Write_Line();

} // end of Print_Menu()




  //==========================================================
  // Description: This function will ask the user to enter
  //              which menu option they would like to perform
  //
  // Input: vector<Stock> & warehouse - a reference to a
  //                  vector<Stock> in which we have access
  //                  to the warehouse items
  //
  // Output: NONE
  //
  //==========================================================
void Get_Menu_Choice(map<string, Stock>& warehouse)
{
	int usersChoice;
	bool validChoice = false;

	//perform action once assuming they will enter it correctly
	cout << "Perform Task: ";
	cin >> usersChoice;
	cout << endl << endl;

	do
	{
		switch (usersChoice)
		{

		case CHOICE1:
			validChoice = true;
			Insert_Item(warehouse);
			break;

		case CHOICE2:
			validChoice = true;
			Delete_Item(warehouse);
			break;

			/* case CHOICE3:
			validChoice = true;
			Update_Item(warehouse);
			break;


			case CHOICE4:
			validChoice = true;
			Find_Item();
			break;
			*/
		case CHOICE3:
			validChoice = true;
			Print_Inventory(warehouse);
			break;

		case CHOICE4:
			validChoice = true;
			cout << "QUITING PROGRAM GOODBYE" << endl;
			exit(EXIT_SUCCESS); // This need to be altered; could be dangerous to SQL Connection and program in general.

		default:
			//this occurs when invalid choice and get new valid choice
			Flush_Input(cin);
			Print_Menu();
			cout << endl;
			cout << "Invalid Choice..." << endl;
			cout << "Please Enter A Valid Task To Perform: ";
			cin >> usersChoice;
			cout << endl << endl;
		}
	} while (!validChoice);

	cout << endl << endl;
} // end of Get_Menu_Choice(vector<Stack> & warehouse




  //==========================================================
  // Description: This function flushes the input stream of any
  //             remaining content, up to a newline character
  //             or EOF.
  //
  // Input: istream inStream - a reference to an istream object
  //
  // Output: NONE
  //
  //==========================================================
void Flush_Input(istream &inStream)
{
	//if user enters: eeyi the program will give three errors and then i for insert
	char tempChar;

	inStream.clear();

	while (false == inStream.eof())
	{
		inStream.get(tempChar);
		if (tempChar == '\n')
		{
			break;
		}
	}

} // end of Flush_Input(istream &inStream)



  //==========================================================
  // Description: This function will insert an item into the
  //              warehouse inventory.
  //
  // FUTURE ADDITIONS: could make the self letter capitolized
  //                   or lowercased always
  //
  // Input: [IN/OUT] vector<Stock> & warehouse - a reference to
  //                 a vector<Stock> in which we have access to
  //                 warehouse items
  //==========================================================
void Insert_Item(map<string, Stock>& warehouse)
{
	string tempname;
	string tempShelf;
	int tempq;
	Stock temp;
	bool test;
	string query;
	string tempId;

	// For outputing errors with MySQL database
	int errorCode;
	string errorMsg;
	bool sqlInsertSucceed;

	// For outputing errors with c++ warehouse map
	bool warehouseEmplaceSucceed;


	cout << "Enter name of new item: ";

	Flush_Input(cin);
	getline(cin, tempname);
	temp.SetName(tempname);

	do
	{
		cout << "Enter quantity of item: ";
		cin >> tempq;
		temp.SetQuantity(tempq);
		if (cin.fail())
		{
			Flush_Input(cin);
			test = false;
			cout << "Invalid value! Please try again..." << endl;
		}
		else if (tempq < 1)
		{
			cout << "Invalid value! Please try again..." << endl;
			test = false;
		}
		else
		{
			test = true;
		}
	} while (test == false);

	cout << "Store onto shelf (please enter shelf identifier): ";
	Flush_Input(cin);
	getline(cin, tempShelf);
	temp.SetShelfLocation(tempShelf);

	
	tempId = (to_string(std::stoi(Select("SELECT item_id from item ORDER BY item_id DESC LIMIT 1")) + 1)); // "Generate" an id for the new item (Should have option to input ID probably somewhere instead)
	temp.SetID(tempId);   // Insert Item Id into warehouse map

	// Create the query for the MySQL database
	query = "INSERT INTO item (item_id, item_name, item_description, price, stock_count, status, update_ts) VALUES (\'";
	query.append(tempId); // Insert Item Id
	query.append("\', \'");
	query.append(tempname); // Insert Item Name
	query.append("\', \'");
	query.append("DESC TODO"); // Insert item description. Need to have a description input
	query.append("\', \'");
	query.append(to_string(0));// Need to have a price input
	query.append("\', \'");
	query.append(to_string(tempq)); // Insert into item quantity
	query.append("\', \'");
	query.append(tempShelf); // Insert into Shelf Location
	query.append("\', CURRENT_TIMESTAMP)"); // Insert the date that the item was added (now).
	//error-check temp

	cout << endl << query << endl; // REMOVE. FOR DEBUGGING ATM

	warehouseEmplaceSucceed = warehouse.emplace(temp.GetName(), temp).second;
	sqlInsertSucceed = ModifyingQuery(query, errorCode, errorMsg);
	//success? push into vector
	// Need considerable error checking for this. The new item could
	// be added to just the database or just the warehouse map. Need
	// error checks on every case.
	// Also need to add more error checks for the nested conditions.
	// BEWARE OF SERVER/MAP DESYNC
	if (warehouseEmplaceSucceed && sqlInsertSucceed)
	{
		cout << "New item added successfully!";
	}
	else if (warehouseEmplaceSucceed && !sqlInsertSucceed)
	{
		cout << "ERROR: New item was added to warehouse but could not be added to MySQL Database.\n"
			    "Removing element from warehouse...";
		warehouse.erase(tempname);
	}
	else if (!warehouseEmplaceSucceed && sqlInsertSucceed)
	{
		cout << "ERROR: New item was added to MySQL database but could not be added to warehouse.\n"
				"Removing element from MySQL database...";

		query = "DELETE * FROM item where item_id = ";
		query.append(tempId);
		// Might need some more error checking on this func call too. Nested error checks on error checks...
		ModifyingQuery(query, errorCode, errorMsg);
	}
	else
	{
		// This message is not strictly true but if the connection is active, this is the most likely problem.
		cout << "Item addition failed, item with ID already exists.";
	}

	cout << endl;

} // end of Insert_Item(vector<Stock>&warehouse)




  //==========================================================
  // Description: This function will delete an item from the
  //              warehouse inventory
  //
  // Input: [IN/OUT] vector<Stock> & warehouse - a reference to
  //                 a vector<Stock> in which we have access to
  //                 the warehouse items
  //
  // Output: NONE
  //
  //==========================================================
void Delete_Item(map<string, Stock>& warehouse)
{
	//Find_Item();
	bool test;
	string x; // The id number to delete (is an int currently but can convert in case its changed to string)
	int y;
	bool didAnythingPop = false;

	Print_Inventory(warehouse);
	do
	{
		cout << "ID of stock to delete: ";
		cin >> x;
		if (cin.fail())
		{
			Flush_Input(cin);
			test = false;
			cout << "Invalid ID choice! Please try again..." << endl;
		}
	} while (test == false);


	cout << "Delete " << warehouse.at(x).GetName() << "?\n"
		<< "Yes(1) No(0): ";
	cin >> y;
	if (cin.fail())
	{
		Flush_Input(cin);
		test = false;
		cout << "Invalid entry! Please try again..." << endl;
	}
	else if (y > 1 || y < 0)
	{
		test = false;
		cout << "Invalid entry! Please try again..." << endl;
	}
	else
	{
		test = true;
	}

	// Like with the function Insert_Item, both the status of the server and the map need to be checked for errors. Could cause desync otherwise.
	if (y == 1)
	{
		if (warehouse.erase(x))
		{
			cout << "Item successfully deleted!\n";
		}
		else
		{
			cout << "Item deletion failed. Item not found.\n";
		}
		
	}
} // end of Delete_Item(vector<Stock> & warehouse)




  //==========================================================
  // Description: This function will update an item based on
  //              what attribute the user wants to update about
  //              the item.
  //
  // FUTURE ADDITIONS: if a user wants to update multiple items
  //                   (instead of continuously entering the
  //                   option from the menu to keep updating)
  //                   we could use binary to see which
  //                   attributes the users want to update.
  //                   For example if the user wanted to update
  //                   name and price. Name would be assigned
  //                   the value 1 and the next item would be
  //                   assigned the value 2 (price) and the
  //                   next item value 4 (quantity). So if the
  //                   user wanted to change name and price
  //                   a temp variable would be 3 and it will
  //                   update name and price.
  //
  // Input: [IN/OUT]vector<Stock> & warehouse - a referecence
  //               to a vector<Stock> in which we have access
  //               to warehouse items
  //
  // Output: NONE
  //
  //==========================================================
void Update_Item(map<string, Stock>& warehouse)
{
	string x;
	string tempname;	//may be subject to change, temp variables for getline and for set functions
	int tempnum;
	bool test;
	map<string, Stock>::iterator itemToUpdate;

	Print_Inventory(warehouse);

	cout << "What Would You Like To Update (enter item id)? " << endl;
	do
	{
		cin >> x;
		itemToUpdate = warehouse.find(x);
		if (cin.fail())
		{
			Flush_Input(cin);
			test = false;
			cout << "Invalid entry! Please try again..." << endl;
			cout << "entry to update: ";
		}
		else if (itemToUpdate != warehouse.end())
		{
			test = true;
		}
		else
		{
			cout << "The input is out of range please enter an integer within the inventory values." << endl;
			cout << "entry to update: ";
			test = false;
		}
	} while (test == false);

	Write_Line_Menu(50, '_', " UPDATE ITEM ");
	cout << "1) Name Of Item        " << endl;
	cout << "2) Number Of Items     " << endl;
	cout << "3) Item Location       " << endl;
	//cout << "4) Number Of Item Sold " << endl;
	//cout << "5) Popularity of Item  " << endl;
	Write_Line();

	int usersChoice;
	bool validChoice = false;
	string query;
	
	// These vars are used for determining database issues.
	int errorCode;
	string errorMsg;

	query = "UPDATE item SET ";

	cout << "Enter Choice: ";
	cin >> usersChoice;

	// Like with the function Insert_Item, both the status of the server and the map need to be checked for errors. Could cause desync otherwise.
	do
	{
		switch (usersChoice)
		{
		case CHOICE1:
			validChoice = true;
			cout << "Please enter a name: ";
			Flush_Input(cin);
			getline(cin, tempname);
			itemToUpdate->second.SetName(tempname);

			// Change MySQL Data (might be able to make nicer with a function)
			query.append("item_name = \'");
			query.append(tempname);
			query.append("\' WHERE item_id = ");
			query.append(x);
			// Need error check to see if element was added to database (duplicate element etc)
			ModifyingQuery(query, errorCode, errorMsg);

			break;

		case CHOICE2:
			validChoice = true;
			do
			{
				cout << "Please enter a new item quantity: ";
				cin >> tempnum;
				if (cin.fail())
				{
					Flush_Input(cin);
					test = false;
					cout << "Invalid entry! Please try again..." << endl;
				}
				else if (tempnum < 1)
				{
					test = false;
					cout << "Invalid entry! Please try again..." << endl;
				}
				else
				{
					test = true;
				}
			} while (test == false);
			itemToUpdate->second.SetQuantity(tempnum);

			// Change MySQL Data (might be able to make nicer with a function)
			query.append("stock_count = \'");
			query.append(to_string(tempnum));
			query.append("\' WHERE item_id = ");
			query.append(x);
			// Need error check to see if element was added to database (duplicate element etc)
			ModifyingQuery(query, errorCode, errorMsg);
			break;

		case CHOICE3:
			validChoice = true;
			cout << "Please enter the new item location (new shelf identifier): ";
			Flush_Input(cin);
			getline(cin, tempname);
			itemToUpdate->second.SetShelfLocation(tempname);

			// Change MySQL Data (might be able to make nicer with a function)
			query.append("status = \'");
			query.append(tempname);
			query.append("\' WHERE item_id = ");
			query.append(x);
			// Need error check to see if element was added to database (duplicate element etc)
			ModifyingQuery(query, errorCode, errorMsg);
			break;

			/*case CHOICE3:
			validChoice = true;
			cout << "CHANGING ITEM ID" << endl;
			//INSERT FUNCTION CALL HERE?
			break;*/

			/*case CHOICE4:
			validChoice = true;
			cout << "CHANGING NUMBER OF ITEMS SOLD" << endl;
			//INSERT FUNCTION CALL HERE?
			break;*/

			/*case CHOICE5:
			validChoice = true;
			cout << "CHANGING POPULARITY OF ITEM" << endl;
			//INSERT FUNCTION CALL HERE?
			break;*/

		default:
			//this occurs when invalid choice and get new valid choice
			Flush_Input(cin);
			cout << endl << endl;
			Write_Line_Menu(50, '_', " UPDATE ITEM ");
			cout << "1) Name Of Item        " << endl;
			cout << "2) Number Of Items     " << endl;
			cout << "3) Item Location       " << endl;
			//cout << "4) Number Of Item Sold " << endl;
			//cout << "5) Popularity of Item  " << endl;
			Write_Line();
			cout << endl;
			cout << "Invalid Choice..." << endl;
			cout << "Please Enter A Valid Choice To Update: ";
			cin >> usersChoice;
		}

	} while (!validChoice);

} // End of void Update_Item(vector<Stock> &warehouse)




  //==========================================================
  // Description: This function will find an item based on
  //              how the user wishes to find the item by
  //              Name, ID, # of items, and other attributes
  //
  // Input:
  //
  // Output:
  //
  //==========================================================
//void Find_Item(map<string, Stock>& warehouse)
//{
//	map<string, Stock>::const_iterator itemIterator;
//	bool itemFound;
//
//	cout << "How Would You Like To Search For An Item?" << endl;
//	cout << endl;
//
//	Write_Line_Menu(50, '_', " FIND ITEM ");
//	cout << "1) Name Of Item        " << endl;
//	cout << "2) Number Of Items     " << endl;
//	cout << "3) Item ID             " << endl;
//	cout << "4) Number Of Item Sold " << endl;
//	cout << "5) Popularity of Item  " << endl;
//	Write_Line();
//
//	int usersChoice;
//	bool validChoice = false;
//
//	cout << "Enter Choice: ";
//	cin >> usersChoice;
//
//	do
//	{
//		switch (usersChoice)
//		{
//		case CHOICE1:
//		{
//			string nameToFind;
//			validChoice = true;
//			cout << "FINDING ITEM BY NAME" << endl;
//			cout << "Enter the name of the item to find: ";
//			Flush_Input(cin);
//			getline(cin, nameToFind);
//			//INSERT FUNCTION CALL HERE?
//			while (itemIterator != warehouse.end() && !itemFound)
//			{
//				if (itemIterator->second.GetName() == nameToFind)
//				{
//					Write_Item(itemIterator->second);
//				}
//				else
//				{
//					itemIterator++;
//				}
//			}
//			break;
//		}
//		// LEFT OFF HERE - Scott 10-8-16 TODO
//		case CHOICE2:
//			validChoice = true;
//			cout << "FINDING ITEM BY NUMBER OF ITEMS" << endl;
//			int quantityToFind;
//
//			//INSERT FUNCTION CALL HERE?
//			break;
//
//		case CHOICE3:
//			validChoice = true;
//			cout << "FINDING ITEM BY ITEM ID" << endl;
//			//INSERT FUNCTION CALL HERE?
//			break;
//
//		case CHOICE4:
//			validChoice = true;
//			cout << "FINDING ITEM BY NUMBER OF ITEMS SOLD" << endl;
//			//INSERT FUNCTION CALL HERE?
//			break;
//
//		case CHOICE5:
//			validChoice = true;
//			cout << "FINDING ITEM BY POPULARITY OF ITEM" << endl;
//			//INSERT FUNCTION CALL HERE?
//			break;
//
//		default:
//			//this occurs when invalid choice and get new valid choice
//			Flush_Input(cin);
//			cout << endl << endl;
//			Write_Line_Menu(50, '_', " FIND ITEM ");
//			cout << "1) Name Of Item        " << endl;
//			cout << "2) Number Of Items     " << endl;
//			cout << "3) Item ID             " << endl;
//			cout << "4) Number Of Item Sold " << endl;
//			cout << "5) Popularity of Item  " << endl;
//			Write_Line();
//			cout << endl;
//			cout << "Invalid Choice..." << endl;
//			cout << "Please Enter A Valid Choice To An Item By: ";
//			cin >> usersChoice;
//		}
//
//	} while (!validChoice);
//
//} // end of Find_Item()




  //==========================================================
  // Description: This function will print the current
  //              warehouse inventory.
  //
  // FUTURE ADDITIONS: Could print out warehouse inventory
  //                   based on alphabetical order, ID, or other
  //                   attribute
  //
  // Input:[IN] const vector<Stock> & warehouse - a reference
  //            to a vector<Stock>
  //
  // Output: NONE
  //
  //==========================================================
void Print_Inventory(const map<string, Stock>& warehouse)
{
	//for loop displays all elements of the vector
	cout << left << "id" << "___________________" << "name" << "____________________" << "quantity" << "____________________"
		 << "location" << endl;
	for (map<string, Stock>::const_iterator i = warehouse.begin(); i != warehouse.end() ; i++)
	{
		cout << left << "[" << i->first << setw(25) << "] ";
		cout << left << setw(24) << i->second.GetName();
		cout << left << setw(28) << i->second.GetQuantity();
		cout << left << i->second.GetShelfLocation();
		cout << endl;
	}

} // end of void Print_Inventory(const vector<Stock>& warehouse




  //==========================================================
  // Description: This function will write the top line of the
  //              menu design given the length of the bar you
  //              want and the character as a style and given
  //              a string as the title you want at the top.
  //              NOTE: The title string should have a space
  //                    at the front and end but depends on
  //                    how you want it to look
  //
  // Input: [IN]int lenght - the length of the bar you want
  //        [IN]char style - the character you want the bar to
  //                         be made up of
  //        [IN]string title - the title at the top of the menu
  //                           design
  // Output: NONE
  //
  //==========================================================
void Write_Line_Menu(int length, char style, string title)
{
	length /= 2;
	length -= title.length() / 2;
	cout << setw(length) << setfill(style) << "" << title
		<< setw(length) << setfill(style) << "" << endl << endl;

} // end of Write_Line_Menu(int length, char style, string title)



  //==========================================================
  // Description: This function will write the bottom line
  //              of the menu design given the a length
  //              of the bar you want and the character as a
  //              style
  //
  // Input: [IN]int length - the length of the menu design bar
  //        [IN]char style - a character that will make up the bar
  //
  // Output: NONE
  //
  //==========================================================
void Write_Line(int length, char style)
{
	cout << setw(length) << setfill(style) << "";
	cout << setfill(' ') << endl;
} // end of void Write_Line(int lenght, char style)

void Write_Item(Stock item)
{
	std::cout << "ID      : " << item.GetID()			 << '\n' 
			  << "Name    : " << item.GetName()			 << '\n'
			  << "Quantity: " << item.GetQuantity()		 << '\n'
			  << "Location: " << item.GetShelfLocation() << '\n';
}

