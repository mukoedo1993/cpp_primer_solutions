#include<iostream>
#define max_size 17
//An object should be declared volatile when its value might
//be changed in ways outside the control or detection of the program.
//The volatile keyword is a directive to the compiler that it hsould not perform
//optimization on such objects.
class Task{};
class Screen{};


//We must define explicitly for our copy-control members for volatile objects.
class Foo{
    public:
    Foo(){std::cout<<"Foo::Foo()\n";}
    Foo(const volatile Foo&){std::cout<<"Foo::Foo(const volatile&)\n";}
    //assign from a nonvolatile object
    Foo &operator=(const volatile Foo&){std::cout<<" Foo &operator=(const volatile Foo&)\n";
        return *this;}
    //assign from a volatile object
    Foo& operator=(const volatile Foo&rhs)volatile{
      Foo&  ob=const_cast< Foo&>(rhs);std::cout<<" Foo& operator=(const volatile Foo&rhs)volatile\n";
        return ob;}
    //remainder of class Foo
};
int main()
{
   volatile int display_register;//int value that might change
   volatile Task *curr_task;//curr_task points to a volatile object
   volatile int iax[max_size];//each element in iax is volatile
   volatile Screen bitmapBuf;//each member of bitmaPBuf is volatile
   //There is no interaction between the const and volatile type qualifiers.
   //A type can be both const and volatile, in which case it has the properties of both.

   //Only volatile member function may be called on volatile objects.


   volatile int v;//v is a volatile int
   int *volatile vip;//vip is a volatile pointer to int
    volatile int* ivp;//ivp is a pointer to a volatile int
    //vivp is a volatile pointer to volatile int
    volatile int *volatile vivp;
   // int *ip=&v;//error: must use a pointer to volatile
    //const_cast ok for volatile
    int* ivp_dev_ol=const_cast<int*>(ivp);//OK
    ivp=&v;//ok: ivp is a pointer to volatile
    vivp=&v;//ok: vivp is a volatile pointer to volatile
    /*synthesized copy does not apply to volatile objects*/
    //No synthesized copy/move and assignment for volatile objects. The synthesized
    //members take parameters that are references to (nonvolatile) const, and we cannot
    //bind a nonvolatile reference to a volatile object. 

    Foo foo1;volatile Foo foo2;foo2=foo1;foo1=foo2;
    Foo foo3(foo1);
}

/*

Foo::Foo()
Foo::Foo()
 Foo& operator=(const volatile Foo&rhs)volatile
 Foo &operator=(const volatile Foo&)
Foo::Foo(const volatile&)
*/