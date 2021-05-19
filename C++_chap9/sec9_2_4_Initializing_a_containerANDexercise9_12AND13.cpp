#include<iostream>
#include<array>
#include<list>
#include<vector>
#include<forward_list>
#include<deque>

/* Initializing a container as a copy of another container
* There are two ways to create a new container as a copy of another one:
*1: We can directly copy the container
*2:or(excepting array) we can copy a range of elements denoted by a pair of iterators.
*/

int main()
{
	//each container has three elements, initialized from the given initializers
	std::list<std::string>authors = { "Milton","Shakespeare","Austen" };
	std::vector<const char*>articles = { "a","an","the" };

	std::list<std::string>list2(authors);//ok:types match
	//std::deque<std::string>authList(authors);//error: container types doesn't match
	//std::vector<std::string>words(articles);//error: element types must match

	//ok: converts const char* elements to string
	std::forward_list<std::string>words(articles.begin(), articles.end());

	/* Because the iterators denote a range, we can use this constructor to copy
	*a sequence of a container. For example, assuming it is an iterator denoting
	*an element in authors, we can write:
	*/

	//copies up to but not including the element denoted by it
	//deque<string>authList(authors.begin(),it);

	//List Initialization:
	//each container has three elements, initialized from the given initializers
	/*When we do so, we explicitly specify values for each element in the container.
	*For types other than array, the initializer list also implicitly specifies the 
	*size of container:the container will have as many elements as there are initializers.
	*/


	//Library arrays have fixed size
	/* Just as the size of a built-in array is part of its type,the size of a library array
	*is part of its type.
	*
	*/
	std::array<int, 42>;//type is: array that holds 42 ints.
	std::array<std::string, 10>;//type is:array that holds 10 strings.

	std::array<int, 10>::size_type i;//array type includes element type and size
	//std::array<int>::size_type j;//error: array<int> is not a type.


	//
	std::array<int, 10>ia1;//ten default-initialized ints
	std::array<int, 10>ia2 = {0,1,2,3,4,5,6,7,8,9};//list initialization
	std::array<int, 10>ia3 = { 42 };//ia3[0]is 42, remainging elements are 0
	
	/*It is worth noting that although we cannot copy or assign objects of built-in
	*array types, there is no such restriction on array.
	*/
	std::array<int, 10>digits = { 0,1,2,3,4,5,6,7,8,9 };
	std::array<int, 10>copy = digits;//ok: types of two containers, copy and digits match.

	//exercise 9_12:
	std::deque<int>deq1 = { 1,2,3,4,5,6,7,8,9 };
	std::deque<int>deq2(deq1.begin(), deq1.end());
	for (auto it = deq2.begin(); it != deq2.end(); it++)
		std::cout << *it << "!\n ";

	//exercise 9_13:
	std::list<int>eg1 = { 1,1,4,5,1,4 };
	std::vector<int>eg3 = { 1,1,4,5,1,4 };

	//part 1:
	std::vector<double>eg2;
	for (auto it1 = eg1.begin(); it1 != eg1.end(); it1++)
		eg2.push_back(double(*it1));

	//part 2:
	std::vector<double>eg4;
	for (auto it2 = eg3.begin(); it2 != eg3.end(); it2++)
		eg4.push_back(double(*it2));
	std::cout << "exercise 9_13:" << eg2[0] << "! " << eg3[0] << ";";
}
