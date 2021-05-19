#include<vector>
#include<list>
#include<array>
#include<iostream>
using std::vector; using std::list;
using std::array; using std::string;
int main()
{
	//unlike the built-in arrays, the library array does allow assignment.
	//The left and right hand operands must have the same type:
	array<int, 10>a1 = { 0,1,2,3,4,5,6,7,8,9 };
	array<int, 10>a2 = { 0 };//elements all have value 0
	a1 = a2;//replace elements in a1
	a2 = { 0 };//error:cannot assign to an array from a braced list
	std::cout << a2[1];

	//assign
	//The sequential containers (except array) also define a member named assign that let 
	//us assign from a different but caompatible type, or assign from a subsequence of a container.

	list<string>names;
	vector<const char*>oldstyle;

	names.assign(oldstyle.cbegin(), oldstyle.cend());

	list<string>slist1(1);//one element, which is the empty string
	slist1.assign(10, "Hiya!");//ten elements, each one is Hiya!


	//Using swap:
	//The swap operation exchanges the contents of two containers of the SAME type:
	//After the call to swap, the elements in the two containers are interchanged.
	vector<string>svec1(10);//vector with 10 elements.
	vector<string>svec2(24);//vector with 24 elements.
	svec2[13] = "jklk";
	swap(svec1, svec2);
	std::cout << svec1[13]<<std::endl;
	/*
	*1:With the exception of arrats, swapping two containers is guaranteed to be fast--
	*the elements themselves are not swapped; internal data structures are swapped.
	*2: Differently from the containers, a call to swap on a string may invalidate iterators,
	*references and pointers.
	*3:Unlike how swap behaves for other containers, swapping two arrays does exchange the elements.
	*/

	//exercise 9_14:
	char a[5] = { 'a','b','c','d','\0' }, b[5] = { 'e','f','g','h','\0' }, c[5] = { 'i','j','l','m','\0' };
	char* a_1 = a, * b_1 = b, * c_1 = c;
	list<char*>lcharp = { a_1,b_1,c_1 };

	vector<string>vecs;
	vecs.assign(lcharp.begin(), lcharp.end());
	std::cout << vecs[0] << std::endl << vecs[1] << std::endl << vecs[2] << std::endl;
}