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

int main()
{
    MI mi;
}
//Result:
/*

A::A()
A::A()
C::C()
X::X()
Y::Y()
Z::Z()
MI::MI()
MI::~MI()
Z::~Z()
Y::~Y()
X::~X()
C::~C()
B::~B()
A::~A()
*/
//It is identical to my analytical souluion.