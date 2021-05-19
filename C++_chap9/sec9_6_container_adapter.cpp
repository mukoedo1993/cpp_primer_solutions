/*
*1: In addition to the sequential containers, the library defines three sequential container
*adaptors: stack,queue, and priority_queue.
*
*/

/*
Defining an adaptor:
An adpator is a mechanism for making one thing act like another. A container adaptor takes
an existing container type and makes it act like a different type.

Each adaptor defines two constructors:
the default constructor that creates an empty object, and a constructor that takes a container and
initializes the adaptor by copying the given container.
*/
#include<iostream>
#include<stack>
#include<string>
#include<vector>
#include<deque>
using std::deque;
using std::stack;
using std::string; using std::vector;
int main()
{
	deque<int>deq = { 1,2,3,4,5,6,7,8,9 };
	stack<int>stk(deq); //copies elements from deq into st
	vector<string>svec = { "hehe","haha","caocao" };
   
	/*
	*By default both stack and queue are implemented om terms of deque, and a priority_queue
	*is implemented on a vector. We can override the default container type by naming a sequential container
	as a second type argument when we create the adaptor.
	*/

    //empty stack implemented on top of vector
	stack<string, vector<string>>str_stk;

	//str_stk2 is implemented on top of vector and initially holds a copy of svec
	stack<string, vector<string>>str_stk2(svec);

	/*
	*There are constraints on which containers can be used for a given adaptor.
	*1: Not built on an array.
	2:NOT built on a forward_list.
	*
	stack:
	Not special extra requirements

	queue:
	Requires push_back, pop_back, push_front and pop_front.
	So, deque and list OK but not vector.

	priority_queue:
	Requires RANDOM ACCESS in addition to the front, push_back and pop_back.
	So, vector and deque OK but not on a list.
	*/

	//Stack adaptor
	stack<int>intStack;
	for (size_t ix = 0; ix != 10; ++ix)
		intStack.push(ix);//intStack holds 0,...9 inclusive
	while (!intStack.empty())
	{
		int value = intStack.top();
		std::cout << value << std::endl;
		intStack.pop();//pop the top element, and repeat
	}
}
