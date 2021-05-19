//std::find example
#include<iostream>
#include<algorithm>//std::find
#include<vector>//std::vector

/*
Find value in range
Returns an iterator to the first element in the range [first,last) that compares equal to val. 
If no such element is found, the function returns last.
*/

int main()
{
	//using std::find with array and pointer:
	int myints[] = { 10,20,30,40 };
	int* p;
	p = std::find(myints, myints + 4, 30);
	if (p != myints + 4)
		std::cout << "Element found in myints: " << *p << '\n';
	else
		std::cout << "Element not found in myints\n";

	//using std::find with vector and iterator:
	std::vector<int>myvector(&myints[0], &myints[4]);
	// A new way to initialize the vector of int, (&array[start],&array[end])
	std::vector<int>::iterator it;
	it = std::find(myvector.begin(), myvector.end(), 30);
	if (it != myvector.end())std::cout << "Element found in the vector!"<<*it<<std::endl;
	else
		std::cout << "Element not found in the vector!"<<*it<<std::endl;
}