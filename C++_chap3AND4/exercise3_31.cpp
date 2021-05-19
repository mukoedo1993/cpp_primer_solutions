#include<iostream>
#include<vector>
#include<string>
using std::cin; using std::cout;
using std::endl; using std::vector;
using std::string;
int main()
{
	int tt[] = {1,2,3,4,5,6,7,8,9,10};
	const int cnt1 = sizeof(tt) / sizeof(*tt);//size of the int array 
	int tt2[cnt1];
	for (int i = 0; i < cnt1; i++)
	{
		tt2[i] = tt[i];
		cout << tt2[i] << endl;
	}
	vector<int>tt3 = { 1,2832,2,34,53,3223,343,29,10 };
	vector<int>tt4(tt3.size(), 0);
	auto c1 = tt4.begin(), c2 = tt3.begin();
	for (auto c:tt3)
	{
		*c1 = *c2;
		cout << *c1 << endl;
		++c1;
		++c2;

	}
}