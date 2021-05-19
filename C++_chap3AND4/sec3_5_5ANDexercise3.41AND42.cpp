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
    string s("Hello World");//s holds Hello World
    /*
    We can use a null-termina ed character array anywhere that we can use a string literal:
    1: We can use a null-terminated character array to initialize or assign a string.
    2:We can use a null-terminated character array as one operand(but not both operands)to the string addition operator
    or as tge right-hand operand in the sitring compound assignment(+=) operator.
    */
    string* str1 = &s;//OK: str1 is a pointer that points to a string.
    //char* str2 = s;//error: can't initialize a char* from a string
    /*
       1:For example, there is no way to initialize a character pointer from a string.
       2: There is, however, a string member function named c_str that we can often use to accomplish what we want:
    */
    const char* str2 = s.c_str();//ok
    const char* str3 = &s[0];//ok
    cout << *str2<<"; "<<*str3;
    /*
       Using an array to initialize a vector:
    */
    int int_arr[] = { 0,1,2,3,4,5 };
    //ivec has six elements; each is a copy of the corresponding element in int_err
    vector<int>ivec(begin(int_arr), end(int_arr));
    //copies 3 elements: int_arr[1],int_arr[2],int_arr[3]
    vector<int>subVec(int_arr + 1, int_arr + 4);
    //exericse3.41:
    int exercise3_41[5] = { 1,3,4,2,7 };
    vector<int>exercise3_41a(begin(exercise3_41), end(exercise3_41));
    cout <<endl<< exercise3_41a[1] << endl;
    //exercise 3.42:
    vector<int>exercise3_42a = { 3,4,10,8,7,12 };
    int exercise3_42b[6] = {};
    auto* ib = &exercise3_42a[0];
    for (int i = 0; i < exercise3_42a.size(); i++)
    {
        exercise3_42b[i] = exercise3_42a[i];
        cout << exercise3_42b[i] << endl;
    }
}   