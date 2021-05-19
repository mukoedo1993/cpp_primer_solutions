/*
*With the usual exception of arrays, we can use resize, to make a container larger or smaller.
*
*/
#include<list>
#include<iostream>
#include<vector>
using std::vector;
using std::list;
struct A {
	double B = 3.7;
	A(double K) :B(K) {} 
	A() = default;
};
int main()
{
	list<int>ilist(10, 42);//ten ints: each has value 42
	ilist.resize(15);//adds five elementgs of value 0 to the back of ilist
	ilist.resize(25, -1);//adds ten elements of -1 to the back of ilist
	ilist.resize(5);//erase 15 elements from the back of ilist
	vector<A>A_; double K = 12.3;
	A_.resize(10, K);//case 1:
	A Ob1(5.3);
	A_.resize(11, Ob1);//case 2:
	
	A_.resize(12, A());//default initailizer: case 3

	std::cout << A_.at(3).B << std::endl //result: 12.3
		<< ((A_.end() - 2)->B)<<std::endl//result: 5.3
		<<((A_.end()-1)->B);//result: 3.7
}