#include<iostream>
#include"Strong_sales_data.h"

	Sales_data first_item(std::cin);
	
	//Sales_data(std::istream&);

	int main()
	{
		print(std::cout, first_item);
		Sales_data next;
		//Sales_data() = default;
		print(std::cout, next);
		Sales_data last("9-999-99999-9");
		print(std::cout, last);
		//Sales_data(const std::string & s) :bookNo(s) {}//case a
		// it works well.
	}