#include<iostream>
#include<list>
#include<deque>
#include<vector>


using std::vector;
//The begin and end operations yield operators that refer to the first and one past the
//last element in the container.
//These iterators are most often used to form an iterator range that encompasses all the elements 
// in the container.


int main()
{
	std::list<std::string>a = { "Milton","Shakespeare","Austen" };
	auto it1 = a.begin();//list<string>::iterator
	auto it2 = a.rbegin();//list<string>::reverse_iterator
	auto it3 = a.cbegin();//list<string>::const_iterator
	auto it4 = a.crbegin();//list<string>::const_reverse_iterator



	std::list<std::string>::const_reverse_iterator alpha = it4;

	/*The function that do not begin with c are overloaded. That is, there are
*actually two members named begin. 
*1: One is a const member that returns the conatiner's const_itetrator type.
*2: The other is nonconst and returns the container's iterator type.
*  Similarly for rbegin, end, and rend.
*4: When we call one of these members on a nonconst object, we get the version that
*returns iterator.
*5:We get a const version of the iterators only when we call these functions on a const
*object.
*6
:
*/

	//type is explicitly specified
	std::list<std::string>::iterator it5 = a.begin();
	std::list<std::string>::const_iterator it6 = a.begin();

	//iterator or const_iterator depending on a's type of a
	auto it7 = a.begin();//const_iterator only if a is const
	auto it8 = a.cbegin();//it8 is const operator
	
}
