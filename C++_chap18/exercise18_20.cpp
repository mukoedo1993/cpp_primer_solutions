#include<iostream>
using std::cout;
namespace primerLib{
    void compute()
    {
      std::cout<<"void primerLib::compute()\n";
    }
    void compute(const void*)
    {
        std::cout<<"void primerLib::compute(const void*)\n";
    }
    }
//using primerLib::compute;
void compute(int)
{
    cout<<"::compute(int)\n";
}
void compute(double,double=3.4)
{
    cout<<"::compute(double,double=3.4)\n";
}
void compute(char*,char* c_ptr=0)
{
    cout<<" compute(char*,char*=0)\n";
}
void f()
{
    compute(0);
}

int main()
{
   // using primerLib::compute;
    f();
    //Results:
    //::compute(int)//If we remove comment flag on the line 13.
    //::compute(int)//If we remove comment flag on the line 33.
}