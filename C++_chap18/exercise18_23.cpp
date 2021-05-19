#include<iostream>
struct A{
    A(){std::cout<<"A::A()\n";}
    virtual ~A(){std::cout<<"A::~A()\n";}
};
struct B:A{
    B(){std::cout<<"A::A()\n";}
    virtual ~B()override{std::cout<<"B::~B()\n";}
};
struct C:B{
    C(){std::cout<<"C::C()\n";}
     ~C(){std::cout<<"C::~C()\n";}
};
struct X{
    X(){std::cout<<"X::X()\n";}
      virtual ~X(){std::cout<<"X::~X()\n";}
};
struct Y{
    Y(){std::cout<<"Y::Y()\n";}
    virtual ~Y(){std::cout<<"Y::~Y()\n";}
};
struct Z:X,Y{
    Z(){std::cout<<"Z::Z()\n";}
     ~Z()override{std::cout<<"Z::~Z()\n";}
};
struct MI:C,Z{
    MI(){std::cout<<"MI::MI()\n";}
      ~MI()override{std::cout<<"MI::~MI()\n";}
};
struct D:X,C{
    D(){std::cout<<"D::D()\n";}
      ~D()override{std::cout<<"D::~D()\n";}
};
int main()
{
    D *pd=new D;
    //(a):
    X *px=pd;//OK
    
    //(b):
    A *pa=pd;//OK

    //(c):
    B *pb=pd;//ok

    //(d):
    C *pc=pd;//ok
    delete pd;
    pd=nullptr;
}

//Conclusion: Everyone is OK here.