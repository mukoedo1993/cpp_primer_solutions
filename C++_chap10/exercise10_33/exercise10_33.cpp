#include<iostream>
#include<fstream>
#include<string>
#include<iterator>
#include<vector>
#include<numeric>
#include<algorithm>
#include<functional>
#include<sstream>
using std::string;
using std::vector;
using std::cin; using std::cout;
using std::endl;
using std::placeholders::_1;
using std::placeholders::_2;

int main()
{
	std::ifstream input("ex10_33i.txt");
	std::ofstream output1("ex10_33o1.txt"), output2("ex10_33o2.txt");
	vector<int>vint;
	std::istream_iterator<int> it_in(input),eof;
	std::ostream_iterator<int> it_out1(output1," "), it_out2(output2, "\n");
	while (it_in != eof)
	{
		vint.push_back(*it_in);
		it_in++;
	}

	for (auto it_t : vint)
	{
		if (it_t % 2)
			it_out1 = it_t;
		else
			it_out2 = it_t;
	}
	input.close(); output1.close();
	output2.close();

}