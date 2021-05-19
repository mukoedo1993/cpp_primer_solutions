#include<iostream>
using std::cout;
#include"Sales_data_chap13_ver2.h"

/*Introducing overloaded assignment*/
//Overloaded operators
//Overloaded operators are functions that have the name operator followed by the symbol for 
//the operator being defined. Hence, the assignment operator is a function named operator=. Like
//any other function, an operator has a return type and a parameter list.
class Foo {
public:
	int i;
	Foo& operator=(const Foo&rhs) {
		this->i = rhs.i;//assignment operator
	}
};
//More notes: 
//Just as it does for the copy constructor, 
//the compiler generates a synthesized copy-assignment operator for a class does not
//define by its own. Analogously to the copy constructor, for some classes the synthesized
//copy-assignment operator disallows assignment.

//Otherwise, it assigns each nonstatic member of the right-hand object to the corresponding member of
//the left-hand object using the copy-assignment operator for the type of that member.
//A

int main()
{
	Sales_data trans, accum;
	trans = accum;//uses the Sales_data copy_assignment operator

	//As with the copy constructor, the compiler synthesizes a copy-assignment operator
	//if the class does not define its own.


}