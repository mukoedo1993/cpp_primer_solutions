#include<iostream>
#include<vector>
#include<list>
#include<stdexcept>
#include<sstream>
#include<fstream>
using std::vector;
using std::list;
using std::string;

/*1: The pop_front and pop_back functions remove the first and last elements, respectively.
*
*
*/

int main()
{
	
	std::ofstream output("ex9_26o.txt");
	using alias1 = list<int>::iterator;
	//erase:
	list<int>lst = { 0,1,2,3,4,5,6,7,8,9 };
	auto it = lst.begin();
	while (it != lst.end())
		if (*it % 2)//if the element is odd
			it = lst.erase(it);//erase this element
	/*Removes the element denoted by the iterator p and returns an iterator to
	* the element after the one deleted or the off-the-end iterator if p denotes
	*the last element. Undefined if p is the off-the-end iterator.
	*/
		else
			++it;


	/*
	*
	*On each iteration, we check whether the current element is odd. If so, we erase that
	* element, setting it to denote the element after the one we erased. If *it is even, we
	* increment it so we'll look at the next element on the next iteration.
	*
	*/
	alias1 it2 = lst.begin(); it2++,it2++;
	alias1 it3 = lst.end(); it3--; it3--;
	auto it3_=lst.erase(it2, it3);
	output << *lst.begin() << "! "<<*it3_<<"!" << lst.back()<< "!\n";

	lst.clear();
	lst.erase(lst.begin(), lst.end());//equivalent
	list<int>neo = { 1,2,3,4,5,6 };
	neo.erase(neo.begin(), neo.begin());
	output <<"neo: " <<*neo.begin() << "\n";

	//exercise 9_26:
	//vector:
	vector<int>v926 = { 0,1,1,2,3,5,8,13,21,55,89 };
	list<int>l926 = { 0,1,1,2,3,5,8,13,21,55,89 };
	for (auto it = v926.begin(); it != v926.end(); )
	{
		if (*it % 2 == 0)
		{
			it=v926.erase(it);


		}
		else
			it++;
	}
	
	output << "The result for vector is:\n";
	for (auto it = v926.begin(); it != v926.end(); it++)
	{
		output << *it << "; ";
	}

	output << std::endl;
	output << "The result for list is:\n";
	for (auto it = l926.begin(); it != l926.end(); )
	{
		if (*it % 2 == 1)
		{
			it=l926.erase(it);

		}
		else
			it++;
	}

	for (auto it = l926.begin(); it != l926.end(); it++)
	{
		output << *it << "; ";
	}

}