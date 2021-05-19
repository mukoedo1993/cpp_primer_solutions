#include<forward_list>
using std::forward_list;
#include<iostream>
#include<fstream>
/*1: When we add or remove an element, the element before the one we added or removed 
*has a different successor. To add or remove an element, we need access to its predecessor 
*in order to update that element's links.
* 2: *However, forward_list is a singly linked list. In a singly linked list there is no easy way to get
*to an element's predecessor.
*3:For this reason, the operations to add or remove elements operate by changing the element after the given
*element.
*/

int main()
{
	std::ofstream output("ex9_27o.txt");


	forward_list <int> flst = { 0,1,2,3,4,5,6,7,8,9 };
	auto prev = flst.before_begin();//denotes element "off the start" in flst
	auto curr = flst.begin();//denotes the first element in flst

	//Remove odd-valued elements:
	while (curr != flst.end())//while there are still elements to process 
	{
		if (*curr % 2)//if the element is odd
			curr = flst.erase_after(prev);//erase it and move curr
		else
		{
			prev = curr;//move the iteration to denote the next
			++curr;//element and one before the next element
		}
	}

	/*
	*Here, curr denotes the element we're checking, and prev denotes the element before curr.
	*We call begin to initialize curr, so that the first iteration checks whether the first element
	*is even and odd. We initialize prev from before_begin, which returns an iterator to the nonexistent
	* element just before curr.
	*
	*/


	//exercise 9_27:
	forward_list<int>ex9_27 = { 0,2,3,4,6,7,8,12,13,25,28 };
	forward_list<int>::iterator it_1 = ex9_27.before_begin();
	forward_list<int>::iterator it_2 = ex9_27.begin();

	while (it_2 != ex9_27.end())
	{
		if (*it_2 % 2)
		{
			it_2=ex9_27.erase_after(it_1);//it deletes the one after to which it_1 points.
			
		}
		else
		{
			
			it_1 = it_2;
			it_2++;
			
		}
		
	}
	output << "exercise 9_27:";
	for (auto it_4 = ex9_27.begin(); it_4 != ex9_27.end(); it_4++)
	{
		output << *it_4 << "; ";
	}
}