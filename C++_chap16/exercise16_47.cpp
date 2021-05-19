#include<iostream>
#include<utility>
template<typename F,typename T1,typename T2>
void flip(F f1,T1 &&t1,T2 &&t2)
{
   f1(std::forward<T2>(t2),std::forward<T1>(t1));
}

template<typename T>
void g(T &&t1,T &t2)
{
      
}

int main()
{
    int i=42;
   
    //flip(g,i,43);
    flip(g<int>,i,43);

    //flip(g<int>,43,i);
    //cannot bind rvalue reference of type ‘int&&’ to lvalue of type ‘int’
}