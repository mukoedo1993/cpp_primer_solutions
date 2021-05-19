#include<iostream>
#include<string>
#include "Sales_data.h"
struct Foo {/* empty */ };//Without semicolon,...exercie 2.39
int main()
{
	Sales_data data1, data2;
	double price = 0;//price per book, used to calculate total revenue.
	std::cin >> data1.bookNo >> data1.units_sold >> price;
	//Calculate total revenue from price and units_sold
	data1.revenue = data1.units_sold *price;
	std::cin >> data2.bookNo >> data2.units_sold >> price;
	data2.revenue = data2.units_sold * price;
	if (data1.bookNo == data2.bookNo) {
		unsigned totalCnt = data1.units_sold + data2.units_sold;
		double totalRevenue = data1.revenue + data2.revenue;
		//print: ISBN, total sold, total revenue, average price per book
		std::cout << data1.bookNo << " " << totalCnt << " " << totalRevenue << " ";
		if (totalCnt != 0)
			std::cout << totalRevenue / totalCnt << std::endl;
		else
			std::cout << "(no sales)" << std::endl;
		return 0;
	}//indicate success
	else {//transactions weren't for the same ISBN:
		std::cerr << "Data must refer to the same ISBN" << std::endl;
		return -1;//indicate failure
	}
}