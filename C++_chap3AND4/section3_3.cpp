//count the number of grades by clusters of ten:0--9,10--19,...,90-99,100.
#include<iostream>
#include<vector>
#include<string>
using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;
vector<unsigned>grde(11, 0);
int inpt;
//Page: 104
int main()
{
	while (cin >> inpt)
	{
		if (inpt <= 100)
			++grde[inpt / 10];
		if (inpt > 100 || inpt < 0)break;
	}
	cout << "The distribution is:" << endl;
	for (int i = 0; i < grde.size(); i++)
	{
		cout << grde[i] << "; ";
	}
	/*
	Notice that: Programmers new to C++ sometimes think that subscripting a vector
	adds elements; it does not. The following code intends to add ten elements to ivec:
	vector<int>ivec;
	for(decltype(ivec.size())ix=0;ix!=10;++ix)
	 ivec[ix]=ix;//disaster: ivec has no elements
	*/
	vector<int>ivec1;
	for (decltype(ivec1.size())ix = 0; ix != 10;++ix)
	ivec1.push_back(ix);//ok: add a new element with value ix
	for (int ix1 = 0; ix1 < ivec1.size(); ++ix1)
		cout << ivec1[ix1] << endl;
}
 