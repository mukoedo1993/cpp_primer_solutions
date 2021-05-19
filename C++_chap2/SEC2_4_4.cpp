#include<iostream> 

int main()
{

    int ddt = 20;
    int ddt2 = 21;
    //constexpr int ddt2 = ddt;<-expression must have a constant value.
    std::cout << ddt << std::endl;
    constexpr int mf = 20;//20 is a constant expression
    constexpr int limit = mf + 1;//mf+1 is a constant expression
    //constexpr int sz=size();//ok only if size is a constexpr function.
    //PAGE 67
    //It is important to understand that when we define a pointer in a constexpr declaration, the const...
    //expr declaration, the constexpr specifier applies to the pointer, not the type to which the pointer points:
    const int* p = nullptr;//p is a pointer to a const int.
    int *const p2 = &ddt;
    constexpr int* q = nullptr;//q is a const pointer to int that is NULL.
    *p2=ddt2;
    std::cout << ddt << std::endl;
}
