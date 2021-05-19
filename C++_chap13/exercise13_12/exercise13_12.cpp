#include"Sales_data_chap13_ver3.h"

bool fcn(const Sales_data* trans, Sales_data accum)
{
	Sales_data item1(*trans), item2(accum);
	
	return item1.isbn() != item2.isbn();
	
}

int main()
{
	string str = "yajusenpai",str1="iiyokoiyo";
	unsigned No_ = 13,No_1=15;
	Sales_data Ob1(str, No_);
	Sales_data Ob2(str1, No_1),*Ob3=&Ob2;
	
	std::cout << "fcn will be called immediately! Notice.\n";
	fcn(Ob3, Ob1);// 3 times.
	//Conclusion: 3 times. item1, item2 and accum respectively.
	std::cout << "end of fcn!" << std::endl;
}