#include<iostream>
#include<memory>
#include<vector>
#include<stdexcept>
using std::string;
using std::vector;

struct Foo {
	explicit Foo(int i) :factory(i)
	{

	}
		int factory;
};


Foo* factory(int i)
{
	return new Foo(i);//caller is responsible for deleting this memory
}

void use_factory(int i)
{
	Foo* p = factory(i);
	//use p but do not delete it
	//p goes out of scope, but the memory to which p points is not freed.

}

//Two better versions of use_factory
void use_fatory1(int i)
{
	Foo* p = factory(i);
	//use p
	delete p;
}

Foo* use_factory2(int a)
{
	Foo* p = factory(a);
	//use p
	return p;//caller must delete the memory
}

int main()
{
	//The new operator allocates memory, and delete frees memory allocated by new.

	//Objects allocated on the free store are unnamed, so new offers no way to name the objects
	//that it allocates. Instead, new returns a pointer to the object it allocates: 
	int* pi = new int;//pi points to a dynamically allocated,
	//unnamed, uninitialized int
	std::cout << *pi << std::endl;
	//By defauly, dynamically allocated objects are default initialized, which means that 
	//objects of built-in or compound type have undefined value; objects of class type are initialized
	// by their default constructor.

	string* ps = new string;//initialized to empty string
	
	int* pi1 = new int(1024);//object to which pi points has value 1024
	string* ps_1 = new string(10, '9');//*pi is "9999999999"

	//vector with ten elements with values from 0 to 9
	vector<int>* pv = new vector<int>{ 0,1,2,3,4,5,6,7,8,9 };


	//We can also value initialize a dynamically allocated object by following 
	//the type name with a pair of empty parentheses:
	string* ps1_ = new string; //default initialized to the empty string
	string* ps_1_ = new string();//value initialized to the empty string
	int* pi1_ = new int;//default initialized;*pi1 is undefined
	int* pi2 = new int();//default initialized tp 0; *pi2 is 0


	//When we provide an initializer inside parenthese, we can use auto to deduce
	//the type of the object we want to allocate from that initializer.

	//However, because the compiler uses the initializer's type to deduce the type to allocate.

	int obj = 3;
	auto p1_ = new auto(obj);//p1_ points to an object of the type of the obj taht object is initialized from obj

	//auto p2_ = new auto{a, b, c};//error: must use parathese for the initializer

	const int* pci = new const int(1024);//allocate and initialize a const int

	const string* pcs = new const string;
	//allocate a default-initialized const empty string




	/*Memory Exhaustion */
	//Although modern machines tend to have huge memory capacity, it is always possible that
	//the free store will be exhausted. 
	//Once a program has used all of its available memory, new expression will fail.
	
	//If allocation fails, new returns a null pointer
	int* p1_1 = new int; //if allocation fails, new throws std::bad_alloc
	int* p2 = new(std::nothrow)int;//If allocation fails, new returns a null pointer.

	//In order to prevent memory exhaustion, we must return dynamically allocated memory
	//to the system once we are finished using it.
	//delete:
	delete p1_1;//p1_1 and p2 must both either point to a dynamically allocated object or be null
	delete p2;

	int ia, * pia = &ia, * pib = nullptr;
	double* pda = new double(33),* pda2 = pda;

	//delete ia;//error: ia is not a pointer
	//delete pia;//undefined, pia refers to a local.
	delete pda;//ok
	//delete pda2;//undefined, the memory pointed by the pd2 was already freed
	delete pi2;//ok: it is always ok to delete a null pointer
	
	const int* pci_a = new const int(1024);
	std::cout << "* pci_a is " << *pci_a << std::endl;


	//A dynamic object managed through a built-in pointer exists until it is explicitly deleted.


	//Resettling the value of a pointer after a delte probvides only limited protection
	//After the delete, the pointer becomes what is referred as a dangling pointer.
	//A dangling pointer is one that refers to memory that one held an object but no longer does so.

	//We can avoid the problems with dangling pointers by deleting the memory associated with a pointer just
	//before the pointer itself goes out of scope.

	int* pyaju(new int(42));
	auto qyaju = pyaju;//qyaju and pyaju point to the same memory
	delete pyaju;//invalidates both pyaju and qyaju
	pyaju = nullptr;//indicates that pyaju is no longer bound to an object
	//But the line above doesn't work on qyaju.
}