#include<iostream>
#include<vector>
#include<deque>
#include<string>
#include<fstream>
#include<sstream>
#include<deque>
#include"Strong_sales_data.h"
using std::vector; using std::deque;
using std::deque;
//Using the emplace operations:
//The new standard introduced three new members--emplace_front, emplace, and emplace_back-
//that construct rather than copy elements.These operations correspond to push_front, insert
//and push_back operations in that they let us put an element at the front of the container,
//in front of the container, in front of a given position, or at the back of the container, 
//respectively.
int main()
{

	//TEST 1:
	std::ofstream output("sec9_3_emplace_log.txt");
	//construct a Sales_data Object at the end of c
	//use the 3-argument construtor
	Sales_data c1("kkt",13,14.6);
	std::deque<Sales_data>c(10,c1);

	c.emplace_back("978-0", 25, 15.99);
	output <<"test 1:\n"<< c[0].units_sold << "sold at index 0\n" << c[10].units_sold << "sold at index 10\n";

	//error: there is no version of push_back that takes three arguments:
	//c.push_back("978-0", 25, 15.99);



	//TEST 2:
	//ok: we create a temporary Sales_data a object to pass to push_back
	c.push_back(Sales_data("978-0", 25, 15.98));
	output << "test 2:\n"<<c[0].units_sold << "sold at index 0\n" << c[11].units_sold << "sold at index 1\n";


	//TEST 3:
	//iter refers to an element in c, which holds Sales_data elements
	deque<Sales_data>::iterator iter = c.begin() + 3;
	c.emplace(iter, "999-999999999");//uses Sales_data(string)
	//uses the Sales_data constructor that takes an ISBN, a count, and a price
	c.emplace_front("978-059353403", 25, 15.99);
	output << "test 3:\n" << c[0].units_sold << "sold at index 0\n" << c[11].units_sold << "sold at index 1\n";
}