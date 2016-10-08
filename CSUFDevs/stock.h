//Stock class and location class to be used by IMS
#pragma once
#include <iostream>
#include <string>
using namespace std;

/*class location
{
protected:
char s; int num;
public:
char GetShelf() const;
int GetNumber() const;
void SetShelf(const char sh);
void SetNumber(const int n);
};*/

class Stock
{
protected:
	string ID;
	string name;
	int quantity;
	string shelf;
	string description;
	double price;

public:
	void SetID(const string itemID);
	void SetName(const string itemName);
	void SetQuantity(const int itemAmount);
	void SetShelfLocation(const string nshelf);
	void SetDescription(const string descript);
	void SetPrice(const double itemPrice);
	//void SetShelfNumber(const int n);
	//void SetShelfLetter(const char c);
	string GetID() const;
	string GetName() const;
	int GetQuantity() const;
	string GetShelfLocation() const;
	//void PrintLocation() const;
	//char GetStockShelf() const;
	//int GetShelfNumber() const;
	string GetDescription() const;
	double GetPrice() const;
};


