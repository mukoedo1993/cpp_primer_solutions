#include<iostream>
//A namespace alias can be used to associate a shorter synonym with a namespace name.
//For example, a long namespace name such as
namespace cplusplus_primer{}

namespace primer=cplusplus_primer;

//a using directive begins with the keyword using, followed by the keyword namespace,
//followed by a namespace name. It is an error if the name is not a previously defined
//namespace name. A using directive may appear in global, local, or namespace scope.
//It may not appear in a class scope.

/*Using directives and scope*/
namespace A{
    int i,j;
}
void f()
{
    using namespace A;
    std::cout<<i*j<<std::endl;
}
/*using Directives Example*/
namespace blip{
    int i=16,j=15,k=23;
    //other declarations
}
int j=0;//ok: j inside blip is hidden inside a namespace

//The members of blip appear as if they were defined in the scope in which
//both blip and manip are defined. Assuming 
int main()
{     
    //using directive; the names in blip are "added" to the global scope
    using namespace blip;//clash between ::j and blio::j
    //detected only if j is used
    ++i;

    //++j;//error ambiguous: global j or blip::j?

++::j;//ok: set global j to 1
++blip::j;//ok: set blip::j to 16
int k=97;//local k hides blip::k
++k;
}
