/*1: Operators that add or remove elements from a container can invalidate
*pointers, references, or iterators to container elements. 
*2:An invalidated pointer,
*reference, or iterator is one that no longer denotes an element.
*/

/*
1: Iterators, pointers and references to a vector or string are invalid if the container
was reallocated. If no reallocation happens, indirect references to elements before the 
insertion remain valid; those to elements after the insertion are invalid.

2:(1):Iterators,pointers and references to a deque are invalid if we add elements anywhere 
but at the front or back.
(2):If we add at the front or back, iterators are invalidated, but references and pointers to existing 
elements are not.

3:Iterators, pointers, and references (including the off-the-end and the before-the-beginning iterators)
to a list or forward_list remain valid.

*/
#include<iostream>
#include<vector>
#include<list>
#include<forward_list>
using std::list;
using std::forward_list;
using std::vector;
int main()
{
	//part A:
	//silly loop to remove even-valued elements and insert a duplicate of odd-valued elements
	vector<int>vi = { 0,1,2,3,4,5,6,7,8,9 };
	auto iter = vi.begin();//call begin,not cbegin because we're changing vi.

	while (iter != vi.end())
	{
		if (*iter % 2) {
			iter = vi.insert(iter, *iter);//duplicate the current element
			iter += 2;//advance past this element and the one inserted before
		}
		else {
			iter = vi.erase(iter);
			//don't advance the iterator;iter denotes the element after the one we erase
		}
	}

	//part B:avoid storing the iterator returned from end
	/*
	vector<int>v = { 1,1,4,5,6,1 };
	auto begin = v.begin(),
		end = v.end();//bad idea, storing the value of the end iterator
	while (begin != end)
	{
		//do some processing
		//insert the new value and reassign begin, which otherwise would be invalid
		++begin;//advance begin because we want to insert after this element
		begin = v.insert(begin, 42);//insert the new value
		++begin;//advance begin past the value we just defined
	}

	*/   //disaster: the behavior of this loop is undefined
	//Because the end pointer become invalid once after the we add an element.

	//safter: recalculate end on each trip whenever the loop adds/erases elements
	vector<int>v = { 1,1,4,5,6,1 };
	auto begin = v.begin();
	while (begin != v.end()) {
		//do some processing
		++begin;//advance 
		begin = v.insert(begin, 42);
		++begin;//advance begin past the element we just added
		}
		//Don't cache the iterator returned from end() in loops that in a 
	//deque, string, or vector.


	//exercise 9_31:
	//Part A:list:
	list<int>vi_1 = { 0,1,2,3,4,5,6,7,8,9 };
	list<int>::iterator iter_1 = vi_1.begin();//call begin,not cbegin because we're changing vi.
	auto ending = vi_1.end();
	while (iter_1 != ending)
	{
		if (*iter_1 % 2) {
			iter_1 = vi_1.insert(iter_1, *iter_1);//duplicate the current element
			iter_1 ++;
			iter_1++;//advance past this element and the one inserted before
		}
		else {
			iter_1 = vi_1.erase(iter_1);
			//don't advance the iterator;iter denotes the element after the one we erase
		}
	}
	for (auto it8 = vi_1.begin(); it8 != ending; it8++)
	{
		std::cout << *it8 << "; ";
	}
	std::cout << std::endl;

	//Part B:forward list:
	forward_list<int>vi_2 = { 0,1,2,3,4,5,6,7,8,9 };
	
	auto fl_before = vi_2.before_begin();
	for (forward_list<int>::iterator fl_curr = vi_2.begin(); fl_curr != vi_2.end();)
	{
		if (*fl_curr % 2)
		{
			fl_curr = vi_2.insert_after(fl_curr, *fl_curr);
			fl_before++; fl_before++; fl_curr++;
		}
		else
		{
			fl_curr = vi_2.erase_after(fl_before);

		}
	}

	for (auto it8 = vi_2.begin(); it8 != vi_2.end(); it8++)
	{
		std::cout << *it8 << "; ";
	}
	std::cout << std::endl;
	
}