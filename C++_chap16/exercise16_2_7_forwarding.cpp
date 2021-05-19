//Some functions need to forward one or more of their argunments with their types unchanged to
//another, forwarded-to function. In such cases, we need to preserve everything about
//the forwarded arguments, including whether or not the argument type is const, and 
//whether the argument is an lvalue or an rvalue.

//As an example, we'll write a function that takes a callable expression and two additional
//arguments. Our function will call the given callable with the other two arguments in
//reverse order. The following is a first cut at our flip function.

//template that takes a callable and two parameters
//and calls the given callable with the other two arguments in reverse order.
//flip1 is an incomplete implementation: top-level const and references are lost
#include<iostream>
#include<utility>
using std::cout;
template<class F,typename T1,typename T2>
void filp1(F f,T1 t1,T2 t2)
{
    f(t2,t1);
}
//This templates works fine until we want to use it to call a call a function that has a reference
//parameter:
void f(int v1,int &v2)
{
   cout<<v1<<" "<<++v2<<std::endl;
}

/*Defining function parameters that retain type information*/
//To retain: 1: lvalue reference 2: const


//We can preserve all the type information by defining its corresponding function
//parameter as an rvalue reference to a template type parameter.

//Using a reference parameter(either lvalue or rvalue)lets us preserve constness, 
//because the const in a reference type is low-level. Through refrecne-collapsing
//if we define the function parameters as T1&& and T2&&, we can preserve the lvalue
//and rvalue property of filp's arguments:

template<class F,typename T1,typename T2>
void flip2(F f,T1 &&t1,T2 &&t2)
{
    f(t2,t1);
}

void g(int &&i,int &j)
{
    cout<< i << " "<<j<<std::endl;
}

/*Using std::forward to preserve type information in a Call*/
/*
template<class Type>intermediary(Type &&arg)
{
    finalFcn(std::forward<Type>(arg));
}
*/
//1: If that agrument was an rvalue, then Type is an ordinary (nonreference) type.
//and forward will return Type&&
//2:If that argument was an lvalue, then through reference collapsing -- Type itself
//is an lvalue reference type.
template<typename F,typename T1,typename T2>
void flip2_(F f, T1 &&t1, T2 &&t2)
{
    f(std::forward<T2>(t2),std::forward<T1>(t1));
}


int main()
{
    int i=42;
    int j=42;
  f(42,i);//f changes its argument i

  filp1(f,j,42);//f called flip1 leaves j unchanged
  //The value of j is copied into t1.
  //That is, the instantiation of this call to flip1 is:
  //void flip1(void(*fcn)(int,int&),int t1,int t2);
  //The value of j is copied into t1. The reference parameter in f is bound to
  //t1, not to j.


  std::cout<<"i is: "<<i<<std::endl;//43
  std::cout<<"j is: "<<j<<std::endl;//42


  int i1=42,j1=42;
 
  //If we try to call g through flip2, we will be passing the parameter t2 to g's
  //rvalue reference parameter. EVen if we pass an rvalue to flip2:
   
   //flip2(g,i1,j1);
   //what is passed to g will be the parametr named t2 inside flip2. A function
   //parameter, like any other variable, is an lvalue expression. As a result,
   //the call to g in flip2 passes an lvalue to g's rvalue reference parameter.




   int g2=42,i2=42;
   flip2_(g,i2,42);//42 42
   //When used with a function parameter that is an rvalue reference to template
   //type parameter(T&&), forward preserves all the details about an argument's type.
   //As with std::move, it's a good idea not to provide a using declaraion for
   //std::forward p798 will explain why.
  }
