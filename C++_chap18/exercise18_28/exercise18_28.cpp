#include<iostream>
struct Base{
    void bar(int)
    {
       std::cout<<" void bar(int)\n";
    }
    protected:
    int ival;
};
struct Derived1:virtual public Base{
void bar(char)
{
    std::cout<<"Derived1::bar(char)\n";
}
void foo(char)
{
    std::cout<<"Derived1::foo(char)\n";
}
protected:
char cval;
};
struct Derived2:virtual public Base{

void foo(int)
{
    std::cout<<"Derived1::foo(char)\n";
}
protected:
char cval;
int ival;
};
class VMI:public Derived1,public Derived2{
    public:
void check()
{
    ival;//OK
    ival=16;
    std::cout<<(Derived2::ival)<<std::endl;//16
    bar('d');//ok  Derived1::bar(char)
   // foo(13);//error: ambiguous
    //foo('d');//error: ambiguous
    Derived1::foo(13);
    Derived2::foo('k');
  // cval;//error
  Derived1::cval;Derived2::cval;//ok
  Base::bar(17);//ok
  Base::ival;//ok
}
};
int main()
{
   VMI().check();
}

/*

16
Derived1::bar(char)
Derived1::foo(char)
Derived1::foo(char)
 void bar(int)
*/