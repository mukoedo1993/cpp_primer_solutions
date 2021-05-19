/*
As we saw in the previous section, name lookup for functions that have
class-type arguments include the namespace in which each argument's class
is defined. This rule also impacts how we determine the candidate set. Each
namespace that defines a class used as an agrument (and those define its base
 classes) is searched for candidate functions. Any functions in those namespaces
that have the same name as the called function are added to the candidate set.
These functions are added even though they otherwise are not visible at the point of
the call.
*/
#include<iostream>
namespace NS{
    class Quote{/*
    */};
    void display(const Quote&){/*...*/}
}
//Bulk_item's base class is declared in namespace NS
class Bulk_item: public NS::Quote{/*...*/};
/*Overloading and using declarations*/
namespace libs_R_us{
    extern void print(int)
    {
        std::cout<<" extern void print(int)";
    }
    extern void print(double)
    {
        std::cout<<" extern void print(double)\n";
    }
}
//ordinary declration
void print(const std::string&)
{
    std::cout<<"void print(const std::string&)";
}
//this using directive adds names to the candidate set for calls to print
using namespace libs_R_us;
//the candidates for call to print at the program are:
//print(int) from libs_R_us
//print(double) from libs_R_us
//print(const std::string&)declared explicitly
void fooBar(int ival)
{
    print("Value: ");//ocalls global print(const string&)
    print(ival);//calls lib_R_us::print(int)
}
int main()
{
    Bulk_item book1;
    display(book1);
    //The argument was passed to display has type Bulk_item. The candidate functions
    //for the call to display are not only the functions for the call to display are
    //not only the functions with declarations that are in scope where display is
    //called, but laso the functions in the namespace where bulk_item and its base class.
    //Quote, are declared. The function display(const Quote&) declared in namespace NS
    //is added to the set of candidate functions.


    fooBar(4);
    return 0;
}