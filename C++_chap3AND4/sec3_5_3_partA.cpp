#include<iostream>
#include<vector>
#include<string>
using std::cin; using std::cout;
using std::endl; using std::vector;
using std::begin; using std::end;
using std::string;
int main()
{
	string nums[] = { "one","two","three" };//array of strings
	string* p = nums;//It equals string *p=&nums[0];
	/*
	  There are various implications of the fact that operations on arrays are often
	  really operations on pointers. One such implications is that when we use an array
	  as an initializer for a variable defined using auto, the deduced type is a pointer, 
	  not an array.
	*/
	int ia[] = { 0,1,2,3,4,5,6,7,8,9 };//ia is an array of ten ints
	auto ia2(ia);//ia2 is an int* that points to the first element in ia
	*ia2 = 329;
	int ia44;
	auto ia55 = &ia44;
	*ia55 = 569;
	auto ia2_1(&ia[1]);//now it is clear that ia2 has type int*
	cout << ia[0] << endl;
	// ia3 is an array of 10 ints
	decltype(ia)ia3 = { 0,1,2,3,4,5,6,7,8,9 };
	/*
	ia3=p;//error: can't assign an int* to an array
		*/
	ia3[4] = 125473;//ok:assigns the value of i to an element in ia3.
	int arr118[] = { 0,1,2,3,4,5,6,7,8,9 };
	int* p_a = arr118;//p points to the 1st element in arr
	++p;//p_a points to arr[1]
	int* e = &arr118[10];//pointer just past the last element in arr
	/*
	   The only thing we can do with this element is take its address, which we do
	   to initialize e. Like an off-the-end iterator, an off-the-end pointer does not point to an element.
	   As a result,we may not dereference or increment an off-the-end pointer.
	*/
	for (int* b_1 = arr118; b_1 != e; ++b_1)
	{
		cout << *b_1 << endl; //print the elements in arr
	}
	int* beg_1 = begin(arr118);
	int* last = end(arr118);
	cout << *beg_1 << " ; " << *last << endl;
	// pbeg points to the first and pend points just past the last element in arr
	int* pbeg = begin(arr118), * pend = end(arr118);
	//find the first negative element, stopping if we've seen all the elements
	while (pbeg != pend && *pbeg >= 0)
		++pbeg;
	/*
	
	dereference, increment, comparisons, addition of an integral value, subtraction of 
	two pointers.
	Pointers that address array elements can use all the iterator operations:
	
	*/
	constexpr size_t sz = 5;
	int arr_7[sz] = { 1,2,3,4,5 };
	int* ip = arr_7;//equivalent to int *ip=&arr[0]
	int* ip2 = ip + 4;// ip2 points to arr[4], the last element in arr
	/*
	The result of adding 4 to ip is a pointer that points to the element four elements further on
	in the array from the one to which ip currently points.
	*/
	//ok: arr is converted to a pointer to its 1st element. p_kkk points one past the end of arr
	int* p_kkk = arr_7 + sz;//use caution! Do not dereference!
	/*
	int* p_kkk2 = arr_7 + 10;//error:arr_7 has only 5 elements; p2 has undefined value.
	*/
	auto n = end(arr_7) - begin(arr_7);
	int* b_8 = arr_7, * e_8 = arr_7 + sz;
	while (b_8 < e_8+(-1))
	{
		// use *b
		++b_8;
		cout << *b_8 << endl;
	}



}