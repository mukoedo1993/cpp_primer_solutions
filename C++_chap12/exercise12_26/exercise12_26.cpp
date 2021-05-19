#include<memory>
using std::allocator;
#include<iostream>
#include<fstream>
#include<string>
using std::string;


int main()
{
	int n = 12;
	std::ifstream input("ex12_26i.txt");
	//std::istream_iterator<string>it(input), eof;
	if (!input.is_open())exit(-1);
	std::ofstream output("ex12_26o.txt");

	allocator<string>alloc;
	string* const p = alloc.allocate(n);
	string s;
	string* q = p;

	while (getline(input, s) && q != p + n)
	{
		alloc.construct(q++,s);//assign a new value to *q
		//We construct from the p to the (final q -1)

	}
	const size_t size = q - p;//remember how many strings we read
	auto q_clone = q - 1;
	while (q_clone != p-1)
	{
		output << *q_clone << " ";//To verify we have destroyed all:
		alloc.destroy(q_clone);
		q_clone--;
	}
	alloc.deallocate(p, n);
}