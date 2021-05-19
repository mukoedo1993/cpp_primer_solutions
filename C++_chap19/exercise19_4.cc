#include<typeinfo>
#include<iostream>

class A{
    public:
    A(){}
   virtual ~A(){}
   void fcn1(){std::cout<<"A::fcn1()\n";}
};

class B:virtual public A{
    public:
    B(){}
   virtual ~B(){}
};

class C:public B{
    public:
    C(){}
    void fcn(){
        std::cout<<"C::fcn()\n";
    }
   virtual ~C(){}
};
class D:public B,virtual public A{
      public:
    D(){}
   virtual ~D(){}
};

int main()
{

A *pa=new C;
if(
C *pc=dynamic_cast<C*>(pa))
{
    pa=pc;
    pc->fcn();
}
else
{
    std::cerr<<"Oops... bad_cast...\n";
    pa->fcn1();
}

}
//Result:
//C::fcn()