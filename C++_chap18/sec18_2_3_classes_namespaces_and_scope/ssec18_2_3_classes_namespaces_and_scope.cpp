#include<iostream>
/*Friend Declarations and Argument-dependent lookup*/
//When we pass an object of a class type to a function, the compiler searches the
//namespace in which the agrument's class is defined in addition to the normal scope
//lookup. This exception also applies for calls that pass pointers or references to a class
//type.
namespace A{
    class C{
        //two friends; neither is declared apart from a friend declaration
        //these functions implicitly are members of namespace A
        friend void f2();
        friend void f(const C&);
    };
    void f(const C&){}
    void f2(){}
}

int main()
{
    A::C cobj;
    f(cobj);
    //f2();//error: ‘f2’ was not declared in this scope; did you mean ‘A::f2’?
}