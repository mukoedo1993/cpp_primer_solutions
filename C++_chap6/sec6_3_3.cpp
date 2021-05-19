#define _CRT_SECURE_NO_WARNINGS
/*The define above is very important.
Without it,strcat and strcpy will crash.
*/
#include<iostream>
#include<vector>
#include<string>
#include<initializer_list>//  new operations!
#include <system_error>   // std::error_code, std::generic_category
// std::error_condition
#include<cstdlib>

using std::cin; using std::cout;
using std::endl; using std::vector;
using std::begin; using std::end;
using std::string; using std::initializer_list;
/*
Because we cannot copy an array, a function cannot return an array.
However, a function can return a pointer or a reference to an array.

*/
//The form of a function that returns a pointer to an array is:
//Type(*function(parameter_list){dimension})
//e.g.:
//int(*func(int i)[10]);
/*
   func(int) says we call func with an int argument
   (*func(int)) says we can dereference the result of that call.
   (*func(int))[10] says that dereferencing the result of a call to func
   yields an array of size ten. says the element type 
   int(*func(int i)[10]) says the element type in that array is int.

   
*/

//func takes an int argument and returns a pointer to an array of 10 ints
auto func1(int i)->int(*)[10]
{
    int b[10];
for (int i1 = 0; i1 < 10; i1++)
    b[i1] = i1*i;
int(* a)[10]=&b;
return a;
}

int main()
{
	typedef int arrT[10];//arrT is a synonym for the type array of ten ints
	using arrT1 = int[10];//arrT1: equivalent declaration of arrT
	arrT* func(int i);//func returns a pointer to anarray of ten ints
    
    //trailing return type:
    cout << "trailing return type:\n";
    for (int i3 = 0; i3 < 10; i3++)
    {
        int c[10] = { 0,0,0,0,0,0,0,0,0,0 };
        c[i3] = (*func1(4))[i3];
       cout << c[i3]<<endl;
    }
    
}