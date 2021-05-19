#include<iostream>
int main()
{
    //Instead, we use the placement new from of new to construct an object. 
    //new (place_address)type
    //new (place_address)type (initializers)
    //new (place_address)type [size]
    //new (place_address)type [size] {braced initializer list}

    /*
    Although in many ways using placement new is analogous to the construct member
    of an allocator, there is one important difference. The pointer that pass to construct
    must point to space allocated by the same allocator or object. The pointer that we pass
    to placement new need not point to memory allocated by operator new.
    */

std::string *sp=new std::string("a value");//allocate and initialize a string
using std::string;
sp->~string();
//calling a destructor cleans up the given object but does not free the space in which
//that object resides. We can reuse the space if desired.

//Calling a destructor destroys an object but does not free the memory, in general.

//reuse:
sp=new string("bbbb value");
std::cout<<*sp<<std::endl;
sp->~string();
sp=nullptr;
}
//Result:
//bbbb value