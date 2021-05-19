#include<iostream>
#include<vector>
#include"Sales_data_ver3.h"

int main()
{
	//conversion: a string to a class
	std::string null_book = "9-999-99999-9";
	Sales_data item1;
	item1.combine(null_book);
	print(std::cout, item1);
	print(std::cout, null_book);//Same result given as the statement above



	// Only one Class-Type Conversion is allowed

	/* We noted that the compiler will automatically apply only one
	* class-type conversion. For example, the following code is in
	*error :
	*1: convert "9-999-99999-9" to string
	*2: convert that (temporary) string to Sales_data
	*/
	//item1.combine("9-999-99999-9");//error:

	//ok: convert string literal to a string
	item1.combine(std::string("9-999-99999-8"));
	print(std::cout, item1);
	//ok: convert string literal to the class type Sales_data
	item1.combine(Sales_data("9-999-99999-9"));
	print(std::cout, item1);

	//Class-Type Conversion Are Not Always Useful
	/* The code implicitly converts std::cin to Sales_data.
	*This conversion executes the Sales_data constructor that takes an 
	*istream. That constructor creates a temporary Sales_data object by reading
	the standard input. That object is then passed to combine.
	*/

	item1.combine(std::cin);
	print(std::cout, item1);


	//We want to make a comparsion with explicit constructor.
	//We could find that we could convert a string or istream& by assign it to a object
	//of Sales_data.


	Sales_data Ob1k = null_book;
	print(std::cout, Ob1k);

	Sales_data Ob2k = std::cin;
	print(std::cout, Ob2k);
	
	std::vector<Sales_data>vec_clss(2, Sales_data());//blank
	std::cout<<vec_clss[0].isbn()<<std::endl;
	std::vector<Sales_data>vec_clss2(2, Sales_data(std::string("ttd!")));//string literal to string explicitly, then 
	                                                                    //string to type of class named Sales_data
	std::cout<<vec_clss2[0].isbn();//print out ttd!\n

	Sales_data Ob44k("SAKE DOJO");// Primer C++ says it should be error, but on VS2019, it runs smoothly.
}