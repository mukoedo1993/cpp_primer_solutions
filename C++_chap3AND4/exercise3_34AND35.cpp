#include<iostream>
#include<vector>
#include<string>
using std::cin; using std::cout;
using std::endl; using std::vector;
using std::begin; using std::end;
using std::string;
int main()
{
	int p[] = { 2,3,54,3,23,54,42327,47,83,24 };
	vector<int> tt1 = { 1,5,9,20,30,20,88 };
	auto p1 = p, p2 = p1 + 3;
	 p1 += p2 - p1;
	 cout << *p1;
	 vector<int>*tt1_1 = &tt1;
	 if(!tt1_1->empty())
	 {
		 cout << "Ha ha!";
	 }
	 auto p_1 = begin(p), p_2 = end(p);
	 // exercise 3.35:
	 while (p_1 != p_2)
	 {
		 *p_1 = 0;
		 cout << *p_1 << endl;
		 ++p_1;
	 }
}