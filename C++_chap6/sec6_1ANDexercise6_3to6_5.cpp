#define _CRT_SECURE_NO_WARNINGS
/*The define above is very important.
Without it,strcat and strcpy will crash.
*/
#include<iostream>
#include<vector>
#include<string>
#include<stdexcept>
#include<limits>
#include"Sales_item.h"
#include"abs_vl.h"
using std::cin; using std::cout;
using std::endl; using std::vector;
using std::begin; using std::end;
using std::string; using std::cerr;
//factorial of val is val*(val-1)...blah blah blah...
int fact( int ret)throw(std::out_of_range())
{
	int val = ret;//local variable to hold the result as we calculate it
	if (ret == 0)return 1;
	if (ret > 12 || ret < 0)
		throw std::out_of_range("Out of range! Notice that I didn't use long int");
	while (ret > 1)
	{
		ret--;
		val =val*ret;
			//cout<<val<<endl;
     }//assign ret*val to ret and decrement val
        return val;//return the result

}

int main()
{
	try {
		int t,t2=18;
		abs_vl t1; 
		cout<<(t1.abs_vl1(t2))<<endl;
		cout << "Please input the number:\n";
		while (cin >> t)
		{
			int k = fact(t);
			cout << "The result should be: "<<k << endl;
		}
	}
	catch (std::out_of_range oOr) { cerr << oOr.what() << endl; }
}