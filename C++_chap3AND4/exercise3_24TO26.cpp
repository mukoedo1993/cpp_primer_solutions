/*exercise 3,24*/
#include<iostream>
#include<vector>
#include<string>
using std::cin; using std::cout;
using std::endl; using std::vector;
using std::string;
int main()
{
	vector<int>vecint = { 2,3,454,545,23,4,54,3,54 ,32,45,239};
	auto it1 = vecint.begin(),it2 = it1 + 1;
	cout << "Part A" << endl;
	while (it1!=vecint.end())
	{
		it2 = it1 + 1;
		cout << *it1 + *it2 << endl;
		it1 = it2 + 1;
	}
	cout << "Part B" << endl;
	auto it3 = vecint.begin() ,it4 = vecint.end()-1;
	/* exercise 2_26
	auto it666 = (it3 + it4) / 2;
	*/
	while (it3<it4)
	{
		cout << *it3 + *it4 << endl;
		it3=it3+1;
		it4=it4-1;
	}
	// EXERCISE 3.25:
	vector<int> grde = { 11,23,100,26,23,34,23,0,2,56,32 };
	vector<int>dist(11, 0); int mkft;
	auto it5 = grde.begin();
	while (it5 != grde.end())
	{
		mkft = *it5 / 10;
		dist[mkft]=dist[mkft]+1;
		it5=it5+1;
	}
	for (int i1 = 0; i1 < dist.size(); i1++)
	{
		cout << dist[i1] << endl;
	}

	return 0;
}