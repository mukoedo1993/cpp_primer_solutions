#pragma once
#ifndef ACCOUNT_VER1_H
#define ACCOUNT_VER1_H
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
*/

/*5:Type names are special. However, in a class, if a member uses a name from an outer
*scope and that name is a type, then he class may NOT subsequently redefine that name:

*/
typedef double Money;
std::string bal;
class Account {
public:
	Money balance() { return bal; }
private: Money bal;
	  //typedef double Money;//error: We may NOT redefine money.
};

#endif
