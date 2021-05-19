#include"StrVec_ver4.h"
using std::allocator;
using std::string;
using std::vector;
//Like the string class(and other library classes), our own classes can benefit from being able to be moved
//as well as copied. 

//They steal resources from their given object rather than copy them. 

//Like the copy constructor, the move constructor has an initial parameter that is a reference to the class type.
//Different from the copy cosntructor, the reference parameter in the move constructor is an rvalue reference.

//In addition to moveing resources, the move constructor must ensure that the moved-from object is left in a state such that
//destroying that object will be harmless.
//In particular, once its resources are moved, the original object must no longer point to those moved resources-- respnsibility
//has been assumed by the newly created object.


//Unlike the copy constructor, the move constructor does not allocate any new memory.
//After an object is moved from, that object continues to exist. Eventually, the moved-from object will be destroyed, eaning
//that the destructor will be run on that object. 

//On the other hand, move operations have no requirements as to the value that remains in the moved-from object. As a result, 
// our programs should never depend on the value of a moved-from object.

//After a move operation, the "moved-from" object must remain a valid, destructible object but users may make no assumptions 
//about its value.

//The compiler will synthesize a move constructor or a move-assignment operator only if the class doesn't define any of its own
//copy-control members and if every nonstatic data member of the class can be moved.
//The compiler can move
//1: members of built-in type. 2: members of a class type if the member's a class has the corresponding move operation.

//the compiler will synthesize the move operations for X and hasX

//1 to 4: when the move constructor is defined as deleted.
//1: Unlike the copy constructor, the move constructor is defined as deleted if the class has a member
//that defines its own copy constructor but does not also define a move constructor, or if the class has a 
//member that doesn't define its own copy operations and for which the compiler is unable to synthesize a move
//constructor. Similarly for move-assignment.
//2: a member whose move-constructor or move-assignment operator is deleted or inaccessible.
//3: a member whose destructor is deleted or inaccessible
//4: the class has a const or reference member

struct X {
	int i;//built-in types can be moved
	std::string s;//string defines its own move operations
};

struct hasX {
	X mem;//X has synthesized move operations
};


struct Y {
	Y() :t(3) {}
	Y(const Y& orig) {
		t = orig.t;
	}
	Y(Y&&) = delete;
	int t;
};
struct hasY {
	hasY() = default;
	hasY(hasY&&) = default;
	Y mem;//hasY will have a deleted move constructor
};

class Foo {
public:
	Foo() = default;
	Foo(const Foo&) {}//copy constructor
	//other members, but Foo does not define a move constructor
};


int main()
{

	X x, x2 = std::move(x);//use the synthesized move constructor
	hasX hx, hx2 = std::move(hx);//use the synthesized move constructor

	hasY hy;
	//hasY hy2=std::move(hy);//error: move constructor is deleted.

	/*Rvalues are moved, lvalues are copied.*/
	StrVec v1, v2;
	v1 = v2;//v2 is an lvalue; copy assignment
	StrVec getVec(std::istream&);
	//v2 = getVec(std::cin);//!!!I don;t know why. But here it is an error.

	//Foo x;
	//Foo y(x);//copy constructor; x is an lvalue
	//Foo z(std::move(x));//copy constructor, because there is no more constructor
	//We could do that because we can convert a Foo&& to a const Foo&.
	//It is worth noting that using the copy constructor in 
	return 0;
}