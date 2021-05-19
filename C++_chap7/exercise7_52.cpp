
#include <string>


/*
* 1: All of its data members are public.
* 2:It does not define any constructors
* 3: It has no in-class initializers
* 4: It has no base classes or virtual functions, which
*are class-related features that we'll cover in chap 15.
*
*/


struct Sales_data {
    std::string bookNo;
    unsigned units_sold; //= 0;
    double revenue; //= 0.0;
    
};

int main() {
    Sales_data item = { "978-0590353403", 25, 15.99 };

    return 0;
}