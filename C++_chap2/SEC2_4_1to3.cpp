//exercise2.4.3
#include<iostream>

int main() {
    int i;
    const int v2 = 0;  // v2 has top-level const
    int v1 = v2+23;
    std::cout << v1 << std::endl;
    int* p1 = &v1, & r1 = v1;//p1 has neither low-level const nor top-level const
    const int* p2 = &v2, * const p3 = &i, & r2 = v2;  // p2 has low-level const
                                                    // p3 has both low-level and top-level const
                                                    // r2 has low-level const
    int ddt2 = 114514;
    int *const p19 = &ddt2;//p19 has only low-level but not top-level
    std::cout << *p19 << std::endl;
    *p19 = 28;
    p2 = p19;
    std::cout << ddt2 <<" "<<*p2<< std::endl;
    std::cout << *p19 <<" "<<v1<< std::endl;
    r1 = v2;  // OK
    //p1 = p2; //<- Error: low-level const doesn't match
    std::cout << v1 << std::endl;
    p2 = p1;  // OK
    //p1 = p3;  <- Error: low-level const doesn't match
   // p3 = p1;<-cannot assign to a variable that is constant
    p2 = p3;  // OK
    p2 = &v1;
    std::cout << "DDy:"<<*p2<<" "<<v1 << std::endl;
    //int &r = v2; // Error: low-level const doesn't match
    // The assignment can add but not lose the low-level `const` qualifier.
    // The assignment will ignore top-level `const` qualifier.
    return 0;
}