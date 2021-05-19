#include<iostream>
class Base1{
    public:
    virtual void print()
    {
        std::cout<<"Base1::print()\n";
    }
    virtual ~Base1()
    {
        std::cout<<"Base1::~Base1()\n";
    }
};
class Base2{
    public:
     virtual void print()
    {
        std::cout<<"Base2::print()\n";
    }
    virtual ~Base2()
    {
        std::cout<<"Base2::~Base2()\n";
    }
};

class D1:public Base1{
      public:
    void print()override
    {
        std::cout<<"D1::print()\n";
    }
};
class D2:public Base2{
      public:
    virtual void print() override;
};
//virtual and override could only appear within the class
 void D2::print()
   {  std::cout<<"D2::print()\n";}

class MI:public D1,public D2{
   public:
    virtual void print()override
    {
        std::cout<<"MI::print()\n";
    }
};

int main()
{
    Base1 *pb1=new MI;
    Base2 *pb2=new MI;
    D1 *pd1=new MI;
    D2 *pd2=new MI;

    //(a):
    pb1->print();//MI::print()
   
   //
   pb2->print();//MI::print()

   //(b):
   pd1->print();//MI::print()

   //(c):
   pd2->print();//MI::print()

   //(d):
   delete pb2;
   //Base2::~Base2()
   //Base1::~Base1()

   //(e):
   delete pd1;
   //Base2::~Base2()
   //Base1::~Base1()

   //(f):
   delete pd2;
   //Base2::~Base2()
   //Base1::~Base1()
}