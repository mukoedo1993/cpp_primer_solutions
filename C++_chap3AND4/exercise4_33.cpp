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
	int sameValue = 0, x = 33, y = 55;
	int k=(sameValue ? ++x, ++y : --x, --y);
	cout << k << endl;
}