#include<iostream>
//If many using directives are present, then the names from each namespace
//become part of the candidate set:
namespace AW{
    int print(int){
std::cout<<" int AW::print(int)\n";
return 3;
    }
}
namespace Primer{
    double print(double)
    {
      std::cout<<"  double Primer::print(double)\n";
      return 3.3;
    }
}
//using directives create an overload set of functions from different namespaces
using namespace AW;
using namespace Primer;
long double print(long double)
{
    std::cout<<"long double ::print(long double)\n";
    return 3.1415926;
}

int main()
{
    print(1);
    print(3.1);
    AW::print(3.1);
    Primer::print(17);
    ::print(47);
    return 0;
}

/*
 int AW::print(int)
  double Primer::print(double)
 int AW::print(int)
  double Primer::print(double)
long double ::print(long double)
*/