#include<iostream>
#include<fstream>
#include<string>
#include<iterator>
#include<vector>
#include<numeric>
#include<algorithm>
#include"Sales_item.h"
using std::string;
using std::vector;
using std::cin; using std::cout;
using std::endl;
int main()
{
	std::istream_iterator<int> int_it(cin);//reads ints from cin
	std::istream_iterator<int> int_eof;//end iterator value
	std::ifstream in("sec10_4_2i.txt");
	std::istream_iterator<string> str_it(in);//read strings from sec10_3_2.txt


	//As an example, we can use an istream_iterator to read the standard input into
	//a vector:
	vector<int>vec;
	std::istream_iterator<int> in_iter(cin);//read ints from cin
	std::istream_iterator<int> eof;//istream "end" iteratir
	while (in_iter != eof)//while there's a valid input to read
		//postfix increment reads the stream and returns the old value of
		//the iterator
		vec.push_back(*in_iter++);

	
	//PART2: 
	std::istream_iterator<int> in_iter_(std::cin), eof_;//read ints from cin
	vector<int>vec1(in_iter_, eof_);//conduct vec from an iterator range
	//Here we construct vec1 from a pair of iterators that denote a 
	//range of elements.


	//PART3:
	/*Because algorithms operate in terms of iterator operations, and
	* the stream iterators support at leact some iterator operations, we
	*can use stream iterators with at least some of the algorithms.
	*
	*/
	std::ifstream in11("sec10_4_2i11.txt");
	std::istream_iterator<int> in1(in11), eof1;
	cout <<endl<<"accumulate:"<< accumulate(in1, eof1, 0) << endl;

	/*
	*However, if we create an istream_iterator that we destroy without using
	*or if we are synchronizing reads to the same stream from two different objects,
	*then we might care a great deal when the read happens.
	*/

	//Operations on ostream_iterators
	cout << "\n\noperations on ofstream_iterators:\n";
	std::ostream_iterator<int>out_iter(cout, " ");
	vector<int> vec__ = { 12,12,34,65,34,63,674,23,4 };
	for (auto e : vec__)
	{
		out_iter = e;//the assignment writes this element to cout
	}
	cout << endl;

	/*
	*The * and ++ operators do nothing on an ostream_iterator, so omitting them has 
	*no effect on our program.
	*/
	
	//Part 4:
	//Rather than writing a loop,we could more easily print the elements by calling copy:
	
	cout << "\n\nCalling copy to print without a loop:\n\n";
	copy(vec__.begin(), vec__.end(), out_iter);

	//Part 5:
	//Using stream iterators with Class Types.
	std::ifstream Ob("sec10_4_2_stream_iterator_with_class_types_input.txt");
	std::ofstream Ob19("sec10_4_2_stream_iterator_with_class_types_output.txt");
	std::istream_iterator<Sales_item>item_iter(Ob), eof_yiyiyo;
	std::ostream_iterator<Sales_item>out_iter_(Ob19, "\n");

	//store the first iteration in sum and read the next record
	Sales_item sum_ = *item_iter++;
	while (item_iter != eof_yiyiyo)
	{
		//if the transaction (which is stored in item_iter)has the same ISBN
		if (item_iter->isbn() == sum_.isbn())
		{
			sum_ += *item_iter++;
		}
		else
		{
			out_iter_ = sum_;//write the current sum
			sum_ = *item_iter++;
		}
	}
	out_iter_ = sum_;
}