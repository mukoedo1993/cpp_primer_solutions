#include<typeinfo>
#include<iostream>
using std::cout;
using std::endl;
class A{
    public:
    A(){}
    virtual ~A(){}
};
class B:public A{
    public:
    B(){}
    virtual ~B(){}
};
class C:public B{
    public:
    C(){}
    virtual ~C(){}
};

int main()
{
    A *pa=new C;
    cout<<typeid(pa).name()<<endl;//P1A

     C cobj;
    A &ra=cobj;
    cout<<typeid(&ra).name()<<endl;//P1A

    B *px=new B;
    A &ra1=*px;
    cout<<typeid(ra1).name()<<endl;//1b
}

/*
P1A
P1A
1B
*/