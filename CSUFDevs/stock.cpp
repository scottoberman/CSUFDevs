//StockFunct.cpp contains functions for use by the Stock class
#include "Stock.h"

//sets the ID member to the given string
void Stock::SetID(const string itemID)
{
	ID = itemID;
}

//sets the name member to the given string
void Stock::SetName(const string itemName)
{
	name = itemName;
}

//sets the quantity member to the given integer
void Stock::SetQuantity(const int itemAmount)
{
	quantity = itemAmount;
}

//sets the shelf member to the given string
void Stock::SetShelfLocation(const string nshelf)
{
	shelf = nshelf;
}

//Sets the shelf number
/*void Stock::SetShelfNumber(const int n)
{
	shelf.SetNumber(n);
}

//Sets the shelf letter
void Stock::SetShelfLetter(const char c)
{
	shelf.SetShelf(c);
}*/

//sets the description member to the given string
void Stock::SetDescription(const string descript)
{
	description = descript;
}

//sets the price member to the given double
void Stock::SetPrice(const double itemPrice)
{
	price = itemPrice;
}

//returns Stock ID
string Stock::GetID() const 
{
	return ID; 
}

//returns Stock name
string Stock::GetName() const 
{ 
	return name; 
}

//returns stock quantity
int Stock::GetQuantity() const 
{ 
	return quantity;
}

string Stock::GetShelfLocation() const
{
	return shelf;
}

//Prints the location object within stock in a letter first number second format
/*void Stock::PrintLocation() const 
{ 
	cout << shelf.GetShelf() << shelf.GetNumber(); 
}

//Returns the Stock's shelf letter
char Stock::GetStockShelf() const 
{ 
	return shelf.GetShelf(); 
}

//returns the Stock's shelf number
int Stock::GetShelfNumber() const 
{ 
	return shelf.GetNumber(); 
}*/

//returns the Stock description
string Stock::GetDescription() const 
{ 
	return description; 
}

//returns the Stock price
double Stock::GetPrice() const 
{ 
	return price; 
}

//returns the location shelf letter
/*char location::GetShelf() const 
{ 
	return s; 
}

//returns the location shelf number
int location::GetNumber() const 
{ 
	return num; 
}

//sets the value of the location shelf letter
void location::SetShelf(const char sh) 
{ 
	s = sh; 
}

//sets the value of the location shelf number
void location::SetNumber(const int n) 
{ 
	num = n; 
}*/


