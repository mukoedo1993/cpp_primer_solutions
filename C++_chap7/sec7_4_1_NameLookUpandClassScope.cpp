#include<iostream>
/* Class definitions are processed in two phases:
*1: First, the member declarations are compiled.
*2: Function bodies are compiled only after the entire
*class has been seen.
*   For Money balance(){//}
*3:Because no matching member of Money is found, the compiler 
*then look for that name in the scopes in which the class is defined.
*4: On the other hand, the function body of balance is processed only
*after the entire class is seen. Thus, the return inside that function
*returns the member named bal, not the string from the outer space.
*
*/ 
/*5:Type names are special. However, in a class, if a member uses a name from an outer 
*scope and that name is a type, then he class may NOT subsequently redefine that name:
*
*/

//Normal Block-Scope Name Lookup inside Member Definitions
/*......
* //typedef double Money;//error: We may NOT redefine money.
*......
*/

//

#include "Account_ver1.h"
#include"Screen_ver5BAD1.h"


int main()
{
	Screen Ob1(6, 3);
	Ob1.dummy_fcn(7);
	Ob1.printout(std::cout);//7*3=21
	Ob1.dummy_fcn1(13);
	Ob1.printout(std::cout);//6*3=18
	Ob1.dummy_fcn2(17);
	Ob1.printout(std::cout);//6*3=18
	Ob1.dummy_fcn3(37);
	Ob1.printout(std::cout);//59*3=177
	//The global height is always 0.
}