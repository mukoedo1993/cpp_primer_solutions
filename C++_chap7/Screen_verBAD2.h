
#pragma once


#ifndef SCREEN_VER5_BAD2_H
#define SCREEN_VER5_BAD2_H

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
*
*/

/*Bad practice: names local to member functions shouldn't hide
*member names.
*/

#include<iostream>
#include<vector>
int height;

class Screen {
public:
	typedef std::string::size_type pos;
	void setHeight(pos);
	//pos height = 0;//error: redifinition
	//So, we cannot allow a global height and a Screen::height(public) to coexist.
	// Otherwise, we will see error.
private:
	pos cursor = 0;
	pos height = 0;
	//typedef std::string::size_type pos;
};

Screen::pos verify(Screen::pos kk1) {
	return kk1;
}
void Screen::setHeight(pos var) {
	//var: refers to the parameter
	//height: refers to the class member
	//verify: refers to the global function
	height = verify(var);
}
#endif
