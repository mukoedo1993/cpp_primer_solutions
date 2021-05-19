#include<iostream>
#include<fstream>

int tst, tst1;
// As we saw, we cannot copy or assign objects of the IO types.
std::istream& func1(std::istream& is)
{
	std::cin >> tst >> tst1;
	return is;
}

int main()
{
	std::ofstream out1, out2;
	//out1=out2;//error: cannot assign stream objects
	//ofstream print(ofstream);//error: can't initialize the ofstream parameter

	//out2=print(out2);//errror: cannot copy stream objects.
	//pass IO type through reference(NOT a const reference)

		//remember the current state of cin
	auto old_state = std::cin.rdstate();//remember the current state of cin
	std::cin.clear();//make cin valid
	//process_input(std::cin);//use cin
	func1(std::cin);

	std::cin.setstate(old_state); //now,reset cin to its old state.
	std::cout << std::boolalpha;
	std::cout << std::cin.good() << std::endl;

     // As an example of an IO error, consider the following code:

	std::string ival;
	
	while (std::cin >> ival)
	{
		std::cout << "Print_out: "+ ival << std::endl;
	}


}