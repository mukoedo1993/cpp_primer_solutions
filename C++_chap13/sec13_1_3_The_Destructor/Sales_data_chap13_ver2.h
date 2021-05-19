#pragma once
#ifndef SALES_DATA_CHAP13_VER2_H
#define SALES_DATA_CHAP13_VER2_H
//sec. 13.1.2 
#include <iostream>
#include <string>
using std::string;
using std::istream;
using std::ostream;

struct Sales_data {
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
	Sales_data& operator=(const Sales_data& rhs);
	Sales_data() = default;
	Sales_data(const std::string& s) :bookNo(s) {} //case a

	Sales_data(const std::string& s, unsigned n, double p) :
		bookNo(s), units_sold(n), revenue(p* n) {}//case b

	/*//legal but sloppier way to write the Sales_data constructor: no constructor initializers
	*Sales_data::Sales_data(const string &s, unsigned cnt, double price)
	*{
	*      bookNo=s;
	*      units_sold=cnt;
	*      revenue=cnt*price;
	*}
	*
	*
	*
	*/
	std::string isbn()const { return bookNo; }
	Sales_data& combine(const Sales_data& rhs)
	{
		units_sold += rhs.units_sold;
		revenue += rhs.revenue;
		return *this;
	}

	double ave_price()const;

	Sales_data add(const Sales_data& lhs, const Sales_data& rhs)
	{
		Sales_data sum = lhs;//copy data members from lhs into sum
		sum.combine(rhs);//add data members from rhs into sum
		return sum;
	}
};

//
//copy-assignment operator(=)
Sales_data& Sales_data::operator=(const Sales_data& rhs)
{
	bookNo = rhs.bookNo;//calls the string::operator=
	units_sold = rhs.units_sold;//uses the built-in int assignment
	revenue = rhs.revenue;//uses the built-in double assignment
	return *this;//return a reference to this object
}
#endif