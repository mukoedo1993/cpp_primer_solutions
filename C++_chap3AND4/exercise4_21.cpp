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
	vector<int>kk1 = { 1,2,6,34,2,3,5,8,7,3 };
	for (auto& k : kk1)
	{
		if (k % 2 == 1)
			k = 2 * k;
	}
	for (auto k1 : kk1)
		cout << k1 << endl;

}