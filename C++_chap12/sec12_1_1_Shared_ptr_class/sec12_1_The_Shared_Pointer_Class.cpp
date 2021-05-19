#include<memory>
#include<iostream>
#include<list>
#include<vector>
#include<string>
#include"Blob.h"
using std::string;
using std::vector;
using std::make_shared;

//struct Blob
//{
	//int i = 13;
	//int j = 14;
//};



struct Foo
{
	Foo(int j, string k) :i(j), str(k)
	{

	}
	Foo(string k, int j) :str(k)
	{
		j = k.size();
	}
	int i;
	string str;
	bool operator==(const Foo& b)
		const//The line 19's content is very very important.
	{
		if (this->str == b.str)
			return true;
		else
			return false;
	}
};

std::shared_ptr<Foo>factory(int i, string j)
{
	//std::shared_ptr<Foo> p = factory( i,  j);
	return make_shared<Foo>(i, j);
}

void use_factory(int i, string j)
{
	std::shared_ptr<Foo>p = factory(i, j);
}

std::shared_ptr<Foo> use_factory1(int i, string j)
{
	std::shared_ptr<Foo>p = factory(i, j);
	// use p
	return p;//reference count is increment when we return p
	//p goes out of scope; the memory to which p points is not freed
}

//Our programs have used only static or stack memory.

//Static memory is used for local static objects, for class static data 
//and for variables defined outside any function.

/*
*In addtion to static or stack memory, every program also has a pool of memory
*that it can use. The memory is refered to as the free store or heap.
*/

//Programs use the heap for objects that they dynamically allocate--that is, for 
//objects that the program allocates at the run time.


//new and delete:
//1:new: It allocates and optionally initializes, an object in dynamic memory and 
//returns a pointer to that object.

//2: delete: It takes a pointer to a dynamic object, destroys that object, and frees
// the associated memory.


//Two smart pointers: manage dynamic objects

//A smart pointer acts like a regular pointer with the important exception that it
//automatically deletes the object to which it points.
//1: shared_ptr: It allows multiple pointers to refer to the same object.
//2: unique_ptr: it "owns" the object to which it points.
//3: The library also defines a companion class names weak_ptr that is a weak reference
//to an object managed by a shared_ptr. All there are defined in the memory header.

int main()
{
	//Like vectors, smart pointers are templates.
	std::shared_ptr<std::string>p1;//shared_ptr that can point at a string
	std::shared_ptr<std::list<int>>p2;//shared_ptr that can point at a list of ints

	//if p1 is not null, check whether it's the empty string
	if (p1 && p1->empty())
		*p1 = "hi";//if so, dereference p1 to assign a new value to that string

	//The make_shared function
	//This function:
	//1: Allocates and initializes an object in dynamic memory.
	//2: Returns a shared_ptr that points to that object. 

	/*
	*When we call make_shared, we must specify the type of object we want to create.
	*We do so in the same way as we use a template class, by following the function
	* name with a type enclosed in an angle brackets.
	*/

	//shared_ptr that points to an int with value 42
	std::shared_ptr<int>p3 = std::make_shared<int>(42);
	//p4 points to a string with value 999999999
	std::shared_ptr<string>p4 = std::make_shared<string>(10,'9');
	//p5 points to an int th that is value initialized to 0
	std::shared_ptr<int>p5 = std::make_shared<int>();

	/*
	*Like the sequential-container emplace members, make_shared uses
	*its arguments to construct an object of the given type. For example, a call
	*to make_shared<string> must pass argument(s) that match one of the string constructors.
	*/
	//Calls to make_shared<int>can pass any value we can use to initialize an int. And so on/ 
	//If we do not pass any arguments, then the object is value-initialized.

	auto p6 = make_shared<vector<string>>();//an empty vector of string.


	//When we copy or assign a shared_ptr, each shared_ptr keeps track of how many other
	//shared_ptrs point to the same object:

	auto p = make_shared<int>(42);//object to which p points has one user
	auto q(p);//p and q points to the same object
	//object to which p and q point has two users
	std::cout << "now, the number of pointers sharing with p is: " << p.use_count()<<std::endl;//2


	auto r = make_shared<int>(42);//int to chich r points has one user
	r = q;//assign to r, making it point to a different address
	      //increase the use count for the object
	      //reduce the use count of the object to which r had pointed
	      // the object r had pointed to has no users; that object is automatically freed
	
    /*
	* Here we allocate an int and store a pointer to that int in r. Next, we assign
	*a new value to r. In this case, r is the only shared_ptr pointing to the one we 
	*previously allocated. That int is automatically freed as part of assigning q to r.
	*/

	//The fact that the shared_ptr class automatically frees dynamic objects when they are
	//no longer needed makes it fairly easy to use dynamic memory. For example, we might
	//have a function that returns a shared_ptr to a dynamically allocated object of a type named Foo
	//that can be initialized by an argument of type T

	
	//factory returns a shared_ptr pointing to a dynamically allocated object
	string init = "fsjfsjd"; int i1 = 13;
	Foo ob1(i1, init);
	
	vector<string>v1;
	{//new scope
		vector<string>v2 = {"a","an","the"};
		v1 = v2;//copies the elements from v2 into v1
	}//v2 is destroyed, which destroys the elements in v2
	//v1 has three elements, which are copies of the ones originally in v2
	
}
