//As an example, assume we have a function pointer that points
//to a function returning an int that takes two parameters, each of
//which is a reference to a const int. We can use that pointer to point 
//to an instantiation of compare:
#include<iostream>
using std::string;
template<typename T>auto compare(const T&v1,const T&v2)->int
{
    if(v1<v2)return -1;
    if(v1>v2)return 1;
    return 0;
}

//pf1 points to the instantiation int compare(const int&,const int&)
//When we use the pointer as a value, the compiler will automatically convert it to 
//a  pointer to point an instantiation of compare

int(*pf1)(const int&,const int&)=compare;

//It is an error if the template couldn;tbe determined from the function pointer type.

void func(int(*)(const string&,const string&))
{
   std::cout<<"\nWe called void func(int(*)(const string&,const string&))\n";
}
void func(int(*)(const int&,const int&))
{
   std::cout<<"\nvoid func(int(*)(const int&,const int&))\n";
}


 
int main()
{

  //func(compare);
  //error:call of overloaded ‘func(<unresolved overloaded function type>)’ is ambiguous

//We can disambiguate the call to func by using explicit template arguments:
func(compare<int>);//void func(int(*)(const int&,const int&))
//When the address of a function-template instantiation is taken, the context
//must be such that it allowd a unique type

}


