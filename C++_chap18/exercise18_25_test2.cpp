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
    ~D1() {std::cout<<"D1::~D1()\n";}
};
class D2:public Base2{
      public:
    virtual void print() override;
       ~D2() {std::cout<<"D2::~D2()\n";}
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
     ~MI() {std::cout<<"MI::~MI()\n";}
};

int main()
{
    Base1 *pb1=new MI;
    Base2 *pb2=new MI;
    D1 *pd1=new MI;
    D2 *pd2=new MI;

    //(a):
    pb1->print();
   
   //
   pb2->print();

   //(b):
   pd1->print();

   //(c):
   pd2->print();

   //(d):
   delete pb2;
  
   //(e):
   delete pd1;


   //(f):
   delete pd2;
 
}

/*

MI::print()
MI::print()
MI::print()
MI::print()
MI::~MI()
D2::~D2()
Base2::~Base2()
D1::~D1()
Base1::~Base1()
MI::~MI()
D2::~D2()
Base2::~Base2()
D1::~D1()
Base1::~Base1()
MI::~MI()
D2::~D2()
Base2::~Base2()
D1::~D1()
Base1::~Base1()
*/