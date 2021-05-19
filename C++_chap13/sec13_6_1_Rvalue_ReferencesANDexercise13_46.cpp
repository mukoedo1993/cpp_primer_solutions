//To support move operations, the new standard introduced a new kind of reference, an rvalue reference.

//By using && rather than &
//rvalue reference is a reference that must be bound to an rvalue. 
//Some expressions yield or require lvalues; others yield or require rvalues.
//Generally speaking, an lvalue expression refers to an object's identity whereas an rvalue expression
//referes to an object's value.

//We cannot bind regular references--which we'll refer to as  lvalue references when we need to distinguish them
//from rvalue references-- which we'll refer to as lvalue references to--
//1: a conversion 2: a literal 3: expressions that return an rvalue
#include<utility>//std::move
#include<vector>
using std::vector;
int f()
{
	return 3;
}

int main()
{
	int i = 42;
	int& r = i;//ok:r  refers to i
	//int&& r = i;//error: cannot bind an rvalue reference to an lvalue
	//int& r2 = i * 42;//error: r*42 is an rvalue

	const int& r3 = i * 42;//ok: we can bind a reference to const to an rvalue.
	int&& rr2 = i * 42;//ok: bind rr2 to the result of multiplication.

	
	
	//Function that return lvalue references, along with: 1: assignment 2: subscript 3: dereference 
	//4: prefix incremenet/decrement operators, are all example s of expressions that return lvalues.

	//Function that return a nonreference type, along with the arithmetic, relational, bitwise, and postfix
	//increment/decreemnt operators, all yield ravlues.
	//lvalue reference NO!
	//rvalue reference OR an lvalue reference to const OK!

	//rvalue references can only be bound to temporaries,
	//The referred_to_object is about to be destroyed
	//There can be no other users of that object

	int&& rr3 = 42;//ok: 42 is a lietral
	//int&& rr4 = rr3;//error: the expression rr1 is an lvalue

	/*The library move function*/
	//Calling move tells the compiler that we have an lvalue that we want to treat as if
	//it were an rvalue. It is essential to realize that the call to move promises that we
	//do not intend to use rr3 again...
	int&& rr_yaju = std::move(rr3);//ok

	//exercise 13_46:

	
	int f();
	vector<int>v1(100);
	
	int&& to1 = f();
	int& to2 = v1[0];
	int& to3 = to1;
	int&& to4 = v1[0] * f();
	
}