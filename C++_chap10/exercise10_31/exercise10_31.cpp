
#include<iostream>
#include<fstream>
#include<string>
#include<iterator>
#include<vector>
#include<numeric>
#include<algorithm>
#include<functional>
using std::string;
using std::vector;
using std::cin; using std::cout;
using std::endl;
using std::placeholders::_1;
using std::placeholders::_2;

bool isShorter(const int& a, const int& b)
{
	if (a < b)return true;
	else return false;
}


int main()
{
	std::ifstream input1("ex10_31i.txt");
	std::ofstream output("ex10_31o.txt");
	std::istream_iterator<int>is2(input1), eof2;
	std::ostream_iterator<int>is_(output, "; ");
	vector<int>veci;
	while (is2 != eof2)
	{
		veci.push_back(*is2);
		is2++;
	}
	sort(veci.begin(), veci.end(), bind(isShorter, _2, _1));
	//Rather than following the original function, we used
	//the function adapter here to make a decreasing sequence.
	unique_copy(veci.begin(), veci.end(), is_);
	input1.close(); output.close();
}