#include "Sales_data_chap13_ver2.h"
#include<memory>
#include<vector>
using std::shared_ptr;
using std::vector;
//Destructor
//The destructor operates inversely to the constructors:
//1: Constructors initialize the nonstatic data members of an object and may do other work;
//2:destructors do whatever work is needed to free the resources used by an object and destroy the
//nonstatic data members of the object.
//3: In a destructor, the function body is executed first and then the members are destroyed. Members
// are destroyed in reverse order from the order in which they were initialized.

class Foo {
public:
	~Foo(){
	//In a destructor, the function body is executed first and then the members are destroyed. Members are
		//destroyed in reverse order from the order in which they were initialized.
		//This destructor is equivalent to a synthesized destructor.

		//The members are automatically destroyed after the empty destructor body is run. 
		//In particular, the string destructor will be run to free the memory used by the bookNo member.

		//The destructor body does not directly destroy the members themselves:
		//Members are destroyed as part of the implicit destruction phase that follows the destructor body.
		//A destructor body executes in addition to the memberwise destruction that takes place as part of
		//destroying an object.
	}
};

int main()
{
	{
		//new scope
		//p and p2 point to dynamically allocated objects
		Sales_data* p = new Sales_data;// p is a built-in pointer
		auto p2 = std::make_shared<Sales_data>();//p2 is a shared_ptr
		Sales_data item(*p);//copy constructors copies *p into item
		vector<Sales_data>vec;//local object
		vec.push_back(*p2);//copies the object to which p2 points.
		delete p;//destructor called on the object pointed to by p.
	}//exit local scope; destructor called on item, p2 and vec.
	//destroying p2 decrements its use count; if the count goes to 0, the object is freed.
	//destroying vec destroys the elements in vec

}