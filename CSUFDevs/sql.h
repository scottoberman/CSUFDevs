#ifndef SQL_H_
#define SQL_H_

#define OTL_STL
#define OTL_ODBC
#define OTL_ODBC_SELECT_STM_EXECUTE_BEFORE_DESCRIBE
#define OTL_UNICODE

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <map>
#include "otlv4.h" // ALL SQL FUNCTIONALITY WITHIN THIS HEADER FILE

using namespace std;

//class Stock // REPLACE THIS LATER WITH UPDATED VERSION TODO
//{
//	public:
//		//constructors
//		Stock();
//		
//		//Setters (Mutators)
//		void SetID(const string itemID);									
//		void SetName(const string itemName);
//		void SetQuantity(const int itemAmount);
//		void SetShelf(const string shelf);
//		void SetDescription(const string description);
//		void SetPrice(const double itemPrice);
//
//		//Getters (Accessors)
//		string 	 GetID() const;
//		string 	 GetName() const;
//		int      	 GetQuantity() const;
//		string 	 GetShelf() const;
//		string 	 GetDescription() const;
//		double GetPrice() const;
//
//		//Functions
//		
//	private:
//		string 	 ID;
//		string 	 name;
//		int 	 quantity;
//		string 	 shelfNum;
//		string 	 description;
//		double price;	
//};

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

//std::map<std::string, Stock>& GetTableFromDatabase();

void ScottMenu();

void sqlTesting();

#endif