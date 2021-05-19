#include<iostream>
#include<vector>
#include<string>
using std::cin; using std::cout;
using std::endl; using std::vector;
using std::string;
int main()
{
	unsigned cnt = 42;//not a constant expression
	constexpr unsigned sz = 42;//constant expression
	int arr[10];//array of 10 ints
	int* parr[sz];//array of 42 pointers to int
	/*
	string bad[cnt];//error: cnt is not a constant expression.
	*/
	string strs[sz];//ok if sz is constexpre,error ogtherwise.
	/*
	  If we omit the dimension, the compiler infers it from the
	  number of initializers. If we specify a dimension, the number
	  of initializers must not exceed the specified size.
	*/
	const unsigned sz1 = 3;
	int ia1[sz1] = { 0,1,2 };//array of three ints with values 0,1,2
	int a2[] = { 0,1,2 };//an array of dimension 3
	int a3[5] = { 0,1,2 };//equivalent to a3[]={0,1,2,0,0}
	string a4[3] = { "hi","bye" };//same as a4[]={"hi","bye",""}
	//int a5[2] = { 0,1,2 };//error:too many initializers
	char a1_1[] = { 'C','+','-' };//list initialization, no null
	char a2_1[] = { 'C','+','+','\0' };//list initialization, explicit null
	char a3_1[] = "C++";//null terminator added aiyomatically
	char a4_1[8] = "Daniel";

	/*Page 115:*/
	int* ptrs[10];//ptrs is an array of 10 pointers to int
	/*
	int &refs[10]= ?;
	*/
	int(*Parray)[10] = &arr;//Parray points to an array pf 10 ints
	int(&arrRef)[10] = arr;//arrRef refers to an array of 10 ints
	unsigned buf_size = 1024;
	int ia[buf_size];
	cout << buf_size << endl;
	int ia1114[ 4 * 7 - 14 ];
	char st[12] = "fundamental";
	return 0;
}