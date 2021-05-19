#include<typeinfo>
#include<iostream>

class A{
    public:
    A(){}
   virtual ~A(){}
};

class B:virtual public A{
    public:
    B(){}
   virtual ~B(){}
};

class C:public B{
    public:
    C(){}
   virtual ~C(){}
};
class D:public B,virtual public A{
      public:
    D(){}
   virtual ~D(){}
};

int main()
{
    //(a):
    A *pa=new C;
    if(
    B *pb=dynamic_cast<B*>(pa))
    std::cout<<"OK at part a!\n";//printed
    //OK
    //pa's static type has a virtual destructor. And, its dynmaic type contains A as a
    //subobject.

    //(b):
    B *pb1=new B;
    if(
    C *pc=dynamic_cast<C*>(pb1))
     std::cout<<"OK at part b!\n";//Not printed
//B's dynamic type is still B, neither it contain or is equal to C.

//(c):
//Attention!
//If we don't add virtual inheritances above,we will get :error: A is ambuguous.
//However, with the help of virtual inheritance, we will have:
A *pa1=new D;//
if(
B *pb11=dynamic_cast<B*>(pa1))
std::cout<<"OK at part c\n";//OK
}