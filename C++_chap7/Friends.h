#pragma once
#ifndef FRIENDS_H
#define FRIENDS_H
#include<iostream>
using std::string;

/*
A class cam allow another class or function to access its nonpublic
members by making that class or function a friend.

*/
class Sales_data {
	//friend declarations for nonmember Sales_data operations added
	friend Sales_data add(const Sales_data&, const Sales_data&);
	friend std::istream& read(std::istream&, Sales_data&);
	friend std::ostream& print(std::ostream&, const Sales_data&);
	//other members and access specifiers as before

public://access specifier added
	Sales_data() = default;
	Sales_data(const std::string& s, unsigned n, double p) :
		bookNo(s), units_sold(n), revenue(p* n) {}
	Sales_data(const std::string& s) :bookNo(s) {}
	Sales_data(std::istream&);
	std::string isbn()const { return bookNo; }
private:
	string bookNo;
	double ave_price()const
	{
		return units_sold ? revenue / units_sold : 0;
	}
	unsigned units_sold = 0;
	double revenue = 0.0;

};

std::istream& read(std::istream& is, Sales_data& item)
{
	double price = 0;
	std::cout << "Please input bookNo, units_sold and price one by one:\n";
	is >> item.bookNo >> item.units_sold >> price;
	if (price <= 0)
	{
		std::cerr << "Error! Price must be a positive integer! We turn all back to default data values!" << std::endl;
		item.units_sold = 0; price = 0;
	}
	item.revenue = price * item.units_sold;
	return is;//!!!!
}
std::ostream& print(std::ostream& os, const Sales_data& item)
{
	os << "Item's ISBN is:" << item.isbn() << ";  We have sold " << item.units_sold << " in total. The revenue is: "
		<< item.revenue << ". The average price is: " << item.ave_price() << std::endl;
	return os;//!!!!
}
#endif