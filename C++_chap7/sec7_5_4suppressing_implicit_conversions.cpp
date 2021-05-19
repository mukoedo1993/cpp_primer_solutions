#include<iostream>
#include"Sales_data_ver4.h"

int main()
{
	std::string null_book = "yiyiyokoiyo!";
	Sales_data item1;
	print(std::cout, item1);
	//item1.combine(null_book);//error: string constructor is explicit
	//item1.combine(std::cin);//error:istream constructor is explicit
	
	/*
	*The explicit keyword is used only on the constructor declaration inside
	*the class. It is not repeated on a definition made outside the class body.
	*/

	// explicit constructors can be used only for direct initialization
	Sales_data item2(null_book);//ok: direct initialization
	//Sales_data item3 = null_book;//error: not directly...
	print(std::cout, item2);


	//Although the compiler will not use an explicit constructor for an implicit conversion,
	//we can use such constructions explicitly to force a conversion.

	//ok:the argument is an explicitly constructed Sales_data object.
	Sales_data item3;
	 item3.combine(Sales_data(null_book));
	 print(std::cout, item3);


	//ok static_cast can use an explicit constructor
	 Sales_data item4;
	 item4.combine(Sales_data(std::cin));
	 print(std::cout, item4);
	


}