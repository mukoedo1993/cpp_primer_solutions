#include<iostream>
#include<vector>
using std::vector;
int va=14;
//ex 16_42AND16_43:
template<class T>void g(T&&val)
{
     
}

//ex16_43:
template<class T>void g1(T val)
{
     
}

//ex16_43:
template<class T>void g2(const T &val)
{
     
}

//ex:16_45:
template<typename T>void g3(T&&val)
{
     vector<T>v;
     
}

int main()
{
    //exercise 16_42:
    int i=0;const int ci=i;
   g(i);// T==int&, val is int&

   g(ci);//ci==const int&, val is const int&

   g(i*ci);//T is int, val is int&&.

   //exercise16_43:
   //It returns an lvalue,i=ci. And,the T will be deduced to int&. val will be int&& &,
   //which will be reduced as int&.

   //exercise16_44:
   //(a):
      g1(i);//T will be int

   g1(ci);//T will be const int(top-level const is dropped here.)

   g1(i*ci);//T will be int

   //(b):
        g2(i);//T will be int

   g2(ci);//T will be int

   g2(i*ci);//T will be int

   //exercise16_45:
   //T will be deduced to int. 
   //call the g3:
   g3(42);

   //T will be deduced to int&
   //g3(i);//error: 

   //Whey vector's template parameter couldn't be int&:
   // http://stackoverflow.com/questions/922360/why-cant-i-make-a-vector-of-references
}