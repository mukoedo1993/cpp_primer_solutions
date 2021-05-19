/*
*
*
*/

#include<algorithm>//count, find.
#include<vector>
#include<string>
#include<iostream>
#include<fstream>
#include<sstream>
using std::cout;
using std::find;
using std::vector; using std::endl;
using std::begin; using std::end;
using std::count; using std::string;
int main()
{
	/*e.g. 
	*The first two arguments to find are iterators denoting a range of elements,
	* and the third is a value.
	*/

	vector<int>vec = { 2,3,5,8,9,42 };
	int val = 42,val1=13;//value we'll look for
	//result will denote the element type we want if it's in vec, or vec.cend() if not
	//report the result

	auto result = find(vec.cbegin(), vec.cend(),val);
	cout << "The value " << val << (result == vec.end() ? "is not present" : " is present" ) << endl;

	auto result1 = find(vec.cbegin(), vec.cend(), val1);
	cout << "The value " << val1 << (result1 == vec.end() ? "is not present" : " is present") << endl;

	//Similarly, because pointers act like iterators on built-in arrays, we can use find to look in an array:
	int ia[] = { 27,210,12,47,109,83 };
	int val_ = 83;
	int* result2 = find(begin(ia), end(ia), val_);
	//Here we use the library begin and end functions to pass a pointer to the first and one past the last elements 
	//in ia.


	//search elements starting from ia[1] up to but not including ia[4]
	auto result3 = find(ia + 1, ia + 4, val_);//(] inclusive
	cout << (result3 == end(ia) ? "Result3 finds":"Result3 doesn't find." );

	//exercise 10_1:
	vector<int>ex10_1 = { 1,2,3,6,7,13,89,13,10,13,23,45,67,28,12 ,13};
	const int target_10_1 = 13;
	auto it_b = ex10_1.begin(), it_e = ex10_1.end() - 3;
	auto result10_1 = count(it_b, it_e, target_10_1);
	cout << "\nexercise 10_1: " << target_10_1 << " has occured "<<result10_1<<" time(s)."<<endl;

	//exercise10_2:
	vector<string>vec_str;
	std::ifstream input("ex10_2i.txt");
	if (!input.is_open())
	{
		std::cerr << "error!";
		return -1;
	}
	std::ofstream output("ex10_2o.txt");
	string str;
	string target10_2; int cnt = 0;
	while (getline(input, str))
	{
		string mkft;
		std::cout << str << ";" << std::endl;
		std::istringstream Ob1(str);
		while (Ob1 >> mkft)
		{
			if (cnt == 0)
			{
				target10_2 = mkft; cnt = 1;
				output <<"Our target is: "<< target10_2 <<std::endl
					<<"Then, our elements are:\n\n";
			}
			else

			{
				vec_str.push_back(mkft);
				output << mkft << std::endl;
			}
			
		}
	}
	auto result10_2 = count(vec_str.begin(), vec_str.end(), target10_2);
	output << "\nConclusion: for exercise 10_2: " << target10_2 << " has occured " << result10_2 << " time(s)." << endl;
}