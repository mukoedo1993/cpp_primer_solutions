#ifndef SALES_DATA_READ_WRITE_H
//For this file, we will add read and write, both are nonmember functions here.
//All other member functions  of the struct Sales_data have declaration on sec.7.1.2.
//Sec.7.1.3:
#define SALES_DATA_READ_WRITE_H
#include <iostream>
#include <string>
using std::istream;
using std::ostream;
struct Sales_data {
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
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
double Sales_data::ave_price()const
{
	if (units_sold)
		return revenue / units_sold;
	else
		return 0;
}

//input transcations contain ISBN, number of copies sold, and sales price
/*
2 points:
1: Both read and print take a reference to their respective IO class types.
The IO classes are types that cannot be copied, so we may only pass them by
reference.


*/
istream& read(istream& is, Sales_data& item)
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
ostream& print(ostream& os, const Sales_data& item)
{
	os <<"Item's ISBN is:"<< item.isbn() << ";  We have sold " << item.units_sold << " in total. The revenue is: "
		<< item.revenue << ". The average price is: " << item.ave_price()<<std::endl;
	return os;//!!!!
}
void error_send1()
{
	std::cerr << "Error! Two different ISBN found!" << std::endl;
}


#endif
/*
Tips: how to call read and print?
	soln1:read(std::cin, sum);
	soln2: print(std::cout,sum);
*/