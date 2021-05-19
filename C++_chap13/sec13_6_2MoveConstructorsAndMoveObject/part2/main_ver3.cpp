#include"hasaptr.h"

int main()
{
	 std::string str1 = "dojo", str2 = "nmsl";
	HasPtr Ob1(str1); 
	HasPtr Ob2 = Ob1;
	HasPtr Ob3 = std::move(Ob1);
	/*For the 1st assignment:
	*1: The right hand operator is an lvalue, so the move constructor is not viable.
	The copy constructor->1se assignment
	2: rvalue:both copy and move constructor available. But move is the exact match. So,
	*/
}