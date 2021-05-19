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
	vector<int>ivec = { 2,3,6,8,20 };
	vector<int>::size_type cnt = ivec.size();
	for (vector<int>::size_type ix = 0; ix != ivec.size(); ++ix, --cnt)
		ivec[ix] != cnt;

	return 0;
}