/*The define above is very important.
Without it,strcat and strcpy will crash.
*/
#include<iostream>
#include<vector>
#include<string>
#include<limits>
using std::cin; using std::cout;
using std::endl; using std::vector;
using std::begin; using std::end;
using std::string;
int main()
{
	unsigned long quiz1 = 0;//we'll use this value as a collection of bits
	//generate a value with only bit number 27 passed
	// 1UL has a 1 in the low-order and (at least)31 zero bits.
	quiz1 |= 1UL << 27;//equivalent to quiz1=quiz1|1UL<<27;
	quiz1 &= ~(1UL << 27);// student number 27 failed
	/*
	Finally, we might want to know how the student at position 27 fared:
	*/
	bool status = quiz1 & (1UL << 27);
	cout << std::boolalpha;
	cout << status << endl;
	return 0;
}
