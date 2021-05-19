#include<iostream>
/*exercise 2.23*/
#include<vector>
using std::cin; using std::cout;
using std::vector;
int main()
{
	vector<int>haha(10, 23);
	auto it1 = haha.begin();
	for (int i = 0; i < haha.size(); i++)
	{
		*it1 = 2 * *it1;
		cout << *it1<<std::endl;
		++it1;
	}
		
}