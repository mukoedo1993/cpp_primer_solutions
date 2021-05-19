#define _CRT_SECURE_NO_WARNINGS
/*The definition above is very important.
Without it,strcat and strcpy will crash.
*/
#include<iostream>
#include<vector>
#include<string>
using std::cin; using std::cout;
using std::endl; using std::vector;
using std::begin; using std::end;
using std::string; using std::boolalpha;
void print(const char* cp);
void print(const int* beg, const int* end);
void print(const int ia[], size_t size);
void print(int(&arr)[10]);
int main()
{
	/*
    Array's two most important properties:
    1: We cannot copy an array.
    2: When we use an array it is (usually converted to a pointer.)
    */
    //despite appearances, these three declarations of print are equivalent
    //each function has a single parameter of type const int*
    //void print(const int*);
    //void print(const int[]);//shows the intent that the function takes an array 
    //void print(const int[10]);// dimension for documentation purposes(at best)
    char i1 = 'A', j[] = { 'F','t','k' ,'a','&','\0'};
    char i2 = 'c';
    //1st method:
    print(j);//ok: j is converted to an char* that points to j[0]
    /*
    Because arrays are passed as pointers, functions ordinarily don't know the size
    of the array they are given. They must rely on additional information provided by
    the caller. There are three common techniques used to manage pointer parameters.
    */

    //2nd method:
    int j1[2] = { 0,1 };
    //j1 is converted to a pointer to the first element in j1
    //the second argument is a pointer to one past the end of j1
    print(begin(j1), end(j1));

    //3rd method:
    int j2[] = { 0,1 };//int array of size 2
    print(j2, end(j2) - begin(j2));

    //Array parameters and const:
    int i4 = 0, j4[2] = { 0,1 };
    int k4[10] = { 0,1,2,3,4,5,6,7,8,9 };
    //print(&i4);//error: argument is not an array of ten ints
    //print(j4);//error: argument is not an array of ten ints
    print(k4);//ok: argument is an array of ten ints.
 
    // passing a multidimensional array
    /*
    //matrix points to the first element in an array whose elements are arrays of ten ints
    void print(int (*matrix)[10],int rowSize){//}
    */

}

// First method: Using a marker to specify the extent of an array:
void print(const char* cp)
{
    if (cp)//if cp is not a null pointer
        while (*cp)//so long as the character it points to is not a null character
            cout << *cp++<<"; ";//print the character and advance the pointer
}
//Second method: Using the standard library conventions
/*
A second technique used to manage array arguments is to pass pointers to the 1st and one past the last element
in the array.
*/
void print(const int* beg, const int* end)
{
    // print every element starting at beg up to but not including end
    while (beg != end)
        cout << *beg++ << endl;//print the current element
                               //and advance the pointer

    //The while uss the dereferecne and postfix increment operators to print
    //the current element and advance beg one element at a tiem through the 
    //array. The loop stops when beg is equal to end.
}

//Third method: explicitly passing a size parameter
/*
A third approach for array arguments, which is common in C programs and
older C++ programs, is to define parameters that indicates the size of the
array. Using this approach, we'll rewrite print as follows:
*/
//const int ia[] is equivalent to const int*ia
//size is passed explicitly and used to control access to elements of is
void print(const int ia[], size_t size)
{
    for (size_t i = 0; i != size; ++i)
    {
        cout << ia[i] << endl;
    }
}
//array reference parameters:
 /*
 */
 //OK:parameter is a reference to an array; the dimension is part of the type:
void print(int(&arr)[10])
{
    for (auto elem : arr)
        cout << elem << endl;
}