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
	vector<string>vsec;
	std::ifstream input("ex10_29i.txt");
	std::ofstream output("ex10_29o.txt");
	std::istream_iterator<string>is(input), eof;
	while (is != eof)
	{
		vsec.push_back(*is);
		is++;
	}
	std::ostream_iterator<string>is1(output, "; ");
	std::ostream_iterator<string>is_(output, ". ");
	//print out the string in output file:
	copy(vsec.begin(), vsec.end(), is1);//Correct!!
	input.close(); output.close();

}