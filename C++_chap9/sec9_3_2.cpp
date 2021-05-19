#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<sstream>
#include<stdexcept>
using std::vector;
using std::string;

/*Each sequential container, including array, has a front member,
* and all except forward_list also have a back member. These operations return
*a reference to the first and last element, respectively:
*/
int main()
{
	vector<int>c = { 2,3,45,6,7 };
	if (!c.empty())
	{
		//val1 and val2 are copies of the value of the first element in c
		auto val1 = *c.begin(), val2 = c.front();
		//val3 annd val4 are copies of the last element in c
		auto last = c.end();

		auto val3 = *(--last);//can't decrement forward_list iterators
		auto val4 = c.back();//not supported by forward_list
	}

	if (!c.empty())
	{
		c.front() = 42;//assigns 42 to the first element in c
		auto& v = c.back();//get a reference to the last element
		v = 1024;//changes the element in c
		auto v2 = c.back();//v2 is not a reference; it's a copy of c.back()
		v2 = 0;//no change to the element in c
	}
	/* As usual, if we use auto to store the  return from one of these functions
	*and want to use that variable to change the element, we must remember to define our 
	*variables as a reference type.
	*/

	//Subscripting and Safe Random Access
	/*
	1: The container that provides fast random access(string, vector, deque, an array)also
	provide the subscript operator.
	2: Out_of_range error might happen, if you want to avoid it, use at()., which will throw
	an out_of_range exception.
	*/
	vector<string>empty_;
	std::out_of_range Ob11();
	//std::cout << empty_[0];//error:out_of_range
	//A window will pop out to say, very serious...
	try {
		 empty_.at(0)=22;
	}
	catch (std::out_of_range &Ob11)
	{
		std::cout << Ob11.what() << std::endl;// It says invalid vector subscript
	}
}