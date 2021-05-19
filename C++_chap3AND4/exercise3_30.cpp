#include<iostream>
#include<vector>
#include<string>
using std::cin; using std::cout;
using std::endl; using std::vector;
using std::string;
int main()
{
	constexpr size_t array_size = 10;
	int ia[array_size];
	for (size_t ix = 1; ix < array_size; ++ix)
	{
		ia[ix] = ix;
		cout << ia[ix] << "; " << ix << endl;
	}
	return 0;
}