/*
Class authors often define auxiliary functions, such as our add, read, and print functions.
Although such functions define operations that are conceptually part of the interface of the class, they
are not part of the class itself.
We define nonmember functions as we would any other function. As with any other fucntion, we normally separate declaration
of the function from its definition. Functions that are conceptually part of a class, but not defined inside the clas, 
are typically declared (but not defined) in the same header as the class itself.


*/
//Many we need are in sales_data_read_write.h. 
#include<iostream>
#include"sales_data_read_write.h"
//exercise 7.7:
int main()
{
	Sales_data total,trans;
	read(std::cin, total);
	read(std::cin, trans);
	while (total.isbn() == trans.isbn())
	{
		total.combine(trans);
		print(std::cout, total);
		read(std::cin, trans);
		if (total.isbn() != trans.isbn())
			error_send1();
	}
	
}