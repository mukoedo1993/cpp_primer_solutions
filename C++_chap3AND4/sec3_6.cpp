#define _CRT_SECURE_NO_WARNINGS
/*The define above is very important.
Without it,strcat and strcpy will crash.
*/
#include<iostream>
#include<vector>
#include<string>
using std::cin; using std::cout;
using std::endl; using std::vector;
using std::begin; using std::end;
using std::string;
int main()
{

	int ia[3][4] = {//three elements;each element is an array of size 4
		{0,1,2,3},//initializers for the row indexed by 0
		{4,5,6,7},//initializers for the row indexed by 1
		{8,9,10,11}//initializers for the row indexed by 2
	};
	int arr[10][20][30] = { 0 };//initialize all elements to 0.

	/*
	equivalent initialization without the optional nested braces for each row
	*/
	int ia1[3][4] = { 0,1,2,3,4,5,6,7,8,9,10,11 };
	/*
	We can initialize only the first element of each row as follows:
	*/
	vector<string>tt1 = { "sjsdj","sahsdhd","dshsdhds","","sjdjddwh" };
	auto it = tt1.end()-1;
	for (auto it11:tt1)
	{
		if (it->empty())break;
		cout << *it<<"; ";
		--it;
	}
	//explicitly initialize only element 0 in each row:
	int ia2[3][4] = { {0},{4},{8} };
	//explicitly initialize row 0; the remaining elements are value initialized
	int ix[3][4] = { 0,3,6,9 };
	//assign the 1st element of arr to the last element in the last row of ia
	ia[2][3] = arr[0][0][0];
	int(&row)[4] = ia[1];
	/*
	For the example above, we define row as a reference to an array of 4 ints.
	We bing that reference to the 2nd row in ia.
	*/
	constexpr size_t rowCnt = 3, colCnt = 4;
	int ia1192[rowCnt][colCnt];//12 uninitialize elements
	//for each row
	for (size_t i = 0; i != rowCnt; ++i)
		//for each column within the row
		for (size_t j = 0; j != colCnt; ++j) {
			//assign element's positional index as its value.
			ia1192[i][j] = i * colCnt + j;
			cout << ia1192[i][j]<<"; ";
			if (j == colCnt - 1)
				cout << endl;
		}
	/*Page 128:
	Using a Range for with Mulitidimensional Arrays
	*/
	size_t cnt = 0;
	for (auto& row : ia)//for every element in the outer array
		for (auto& col : row)//for every element in the inner array
		{
			col = cnt;//give this element the next value
			++cnt;// increment cnt
		}
	for (const auto& row1 : ia)
		for (auto &col1 : row1)
			cout << col1 << endl;
	//error one:
	/*
		for (const auto row1 : ia)
		for (auto &col1 : row1)
			cout << col1 << endl;
	*/
	//Because row1 is not a reference, when the compiler initializes row1 it will 
	//convert each array element(like any object of array type) to a 
	//pointer to that array's 1st element.
	int ia_1[3][4] = {1,2,4,6,5,6,7,8,9,13,11,12};//array of size 3; each  element is an array of ints of size 4
	int(*p)[4] = ia_1;//p points to an array of four elements
	p = &ia_1[2];//p now points to the last element in ia_1.
	//print the value of each element in ia, with each inner array on its own line
	//p points to an array of four ints
	for (auto p = ia_1; p != ia_1 + 3; ++p)
	{// q points to the 1st element of an array of 4 ints; that is, q points to an int.
		for (auto q = *p; q != *p + 4; ++q)
			cout << *q << ' ';
		cout << endl;
	}
	//p_1 points to the first array in ia_1
	cout << "page 129 lower part:" << endl;
	for (auto p_1 = begin(ia_1); p_1 != end(ia_1); ++p_1)
	{
		//q_1 points to the 1st element in an inner array
		for (auto q_1 = begin(*p_1); q_1 != end(*p_1); ++q_1)
			cout << *q_1 << ' ';//print the int value to which q_1 points.
		cout << endl;
	}
	/*
	Type alias
	*/
	using int_array = int[4];//new style type alias declaration
	typedef int int_array[4];//equivalent typedef declaration
	//print the value for each element in ia, with each inner array on its own line
	for (int_array *p=ia_1;p!=ia_1+3;++p)
	{
		for (int* q = *p; q != *p + 4; ++q)
		{
			cout << *q << ' ';
		}
		cout << endl;
	}

}