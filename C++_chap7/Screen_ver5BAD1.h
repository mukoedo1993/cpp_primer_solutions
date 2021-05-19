#pragma once
#pragma once


#ifndef SCREEN_VER5_BAD1_H
#define SCREEN_VER5_BAD1_H

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
int height=59;//the global height
//It is hilarious to see that if we use 
//int height;
//instead, we will get global parameter height's value as 0 no matter
//what value we will define inside the class Screen(private).
class Screen {
public:
	typedef std::string::size_type pos;
	Screen(pos ht, pos wd) :height(ht), width(wd) {
		std::cout << "Get Screen!\n";
	}
	void dummy_fcn(pos height)//which height? The parameter.
	{
		cursor = width * height;
		std::cout << "width is:" << width << ". height is:" << height << ".\n";
		std::cout << "Cursor is:" << cursor;//The height will not be reserved once this function ended.
	}
	void dummy_fcn1(pos height);
	void dummy_fcn2(pos height);
	void dummy_fcn3(pos height);
	std::ostream& printout(std::ostream &os)
	{
		os << "cursor is:" << cursor <<" . "<< std::endl;
		return os;
	}
private:
	pos cursor = 0;
	pos height = 0, width = 0;
};

//:( bad example:
void Screen::dummy_fcn1(Screen::pos height) {
	cursor = width * this->height;//member height
	cursor = width * Screen::height;//member height
	//without this-> or Screen:: definition within the function
	//with this-> or Screen:: definition w.r.t. the member
	std::cout << "width is:" << width << ". height is:" << Screen::height << ".\n";
	std::cout << "Cursor is:" << cursor;

}//With the block, we define it.
//However, without a block, we redeclare it, which is NOT allowed.


//:) good example:
void Screen::dummy_fcn2(Screen::pos ht) {
	cursor = width * this->height;//member height
	cursor = width * Screen::height;//member height
	std::cout << "width is:" << width << ". height is:" << this->height << ".\n";
	std::cout << "Cursor is:" << cursor;

}

//:( bad example
void Screen::dummy_fcn3(Screen::pos height) {
	cursor = width * ::height;//Which height? the global one
	
	std::cout << "width is:" << width << ". height is:" << ::height << ".\n";
	std::cout << "Cursor is:" << cursor;

}

#endif