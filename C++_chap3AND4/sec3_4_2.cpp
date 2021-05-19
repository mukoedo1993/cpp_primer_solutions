#include<iostream>
#include<vector>
#include<string>
using std::cin; using std::cout;
using std::endl; using std::vector;
using std::string;
int main()
{
	//text must be sorted.
	//beg and end will denote the range we're searching
	vector<int>text{ 1*1,2*2,3*3,4*4,5*5,6*6,7*7,8*8,9*9,10*10,11*11,12*12,13*13,14*16,15*17,16*19};
	auto beg = text.begin(),end1 = text.end();
	int sought = 15*18;
	auto mid = text.begin() + (end1 - beg) / 2;//original midpoint
	while (mid != end1 && *mid != sought)
	{
		if (sought < *mid)
			end1 = mid;
		else
			beg = mid + 1;
		mid = beg + (mid - beg) / 2;
	}
	if (*mid == sought)
		cout << "We have reached! It is " << *mid << endl;
	else
		cout << "Whoops! Failure!" << endl;
	return 0;
}