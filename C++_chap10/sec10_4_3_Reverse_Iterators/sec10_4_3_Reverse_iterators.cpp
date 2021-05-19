#include<iostream>
#include<iterator>
#include<vector>
#include<algorithm>
#include<fstream>
using std::vector;
using std::endl;

int main()
{
	std::ofstream output("sec10_4_3o.txt");
	//PART 1:
	vector<int>vec = {0,1,2,3,4,5,6,7,8,9};
	//reverse iterator of vector from back to front
	for (auto r_iter = vec.crbegin();//bind r_iter to the last element
		r_iter != vec.crend();//crend refers 1 before 1st element
		++r_iter)//decrements the iterator one element
		output << *r_iter << endl;//prints 9,8,7,...0

	/*
	*Although it may seen confusing to have the meaning of the increment and 
	*decrement operators reverses, doing so lets us use the algorithms transparently
	* to process a container forward or backward. For example, we can sort our vector 
	*in descending order by passing sort a pair of reverse iterators.
	*/
	std::ostream_iterator<int>it1(output," ");
	sort(vec.begin(), vec.end());//sorts vec in normal order
	copy(vec.cbegin(), vec.cend(), it1);//print
	output << std::endl;
	sort(vec.rbegin(), vec.rend());
	copy(vec.cbegin(), vec.cend(), it1);

	//PART 2:
	//Relationship between Reverse iterators and other iterators
	std::string line = "FIRST,MIDDLE,LAST";

	//find the first element in a comma-separated list
	auto comma = find(line.cbegin(), line.cend(), ',');
	output <<"\n\nfind the first element in a comma-separated list: "
		<<std::string(line.cbegin(), comma) << std::endl;

	//find the last element in a comma-separated list
	auto rcomma = find(line.crbegin(), line.crend(), ',');//wrong way:
	output << "Before we use the base, a wrong way to find find the first element in a comma-separated list: "
		<< std::string(line.crbegin(),rcomma) << std::endl;


	/*
	*However, we cannot use rcomma directly. That iterator is a reverse
	*iterator, which means that it goes backward toward the beginning of the string.
	* We need to-> transform the rcomma back:
	*
	*/
	output <<"After we use the base, "
		<< std::string(rcomma.base(), line.cend()) << std::endl;
	output.close();
}
