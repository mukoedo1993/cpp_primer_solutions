#include<iostream>
#include<memory>
using std::shared_ptr;
using std::make_shared;

shared_ptr<int>clone(int p)//We will test this in the Case A: 
{
	//ok: explicitly create a shared_ptr<int> from int*
	return shared_ptr<int>(new int(p));
}

void process(shared_ptr<int>ptr)
{
	//use ptr
	//ptr goes out of scope and is destroyed.
}
/*
shared_ptr<int>clone1(int p)
{
	return new int(p);//error: new suitable constructor exists to convert from int* to std::shared_ptr<int>
}
*/

int main()
{
	//As we've seen, if we do not initialize a smart pointer, it is initialized as a 
	//null pointer.

	shared_ptr<double>p1;//shared_ptr that can point at a double
	shared_ptr<int>(new int(42));//p2 points to an int with value 42
	//C26444 warning given here

	//But,we 
	//CANNOT implicitly convert a pointer to a smart pointer, this initialization is an error.

	//shared_ptr<int>p3 = new int(1024);//error: must use direct initialization.
	shared_ptr<int>p4(new int(1024));//ok: use direct initialization

	//Case A: 
	int i = 13;
	shared_ptr<int>shrd_ptr = clone(i);
	std::cout << "Case A: *shred_ptr== " << *shrd_ptr << std::endl;

	/*Don't mix ordinary pointers and smart pointers*/
	//A shared_ptr can coordinate destruction only with other shared_ptrs that are copies of itself.
	//See the function "process" above.

	/*Some right ways to use shared_ptr: */
	shared_ptr<int>p5(new int(47));//reference count is 1
	process(p5);//copying p5 increments its count; in process the reference count is 2
	int i_ = *p5;//ok: reference count is 1

	int* x_1(new int(114514));//dangerous: x is a plain pointer, not a smart pointer
	//process(x_1);//error: cannot convert a plain pointer to a std::shared_ptr<int>

	process(shared_ptr<int>(x_1));//legal, but the memory will be deleted!!
	//After the line above, the x_1 will become a dangling pointer.(equivalent to a pointer uninitialized)

	//CASE B:
	//int jiucai = *x_1;//pass the compile
	//std::cout <<"CASE B: "<< jiucai << std::endl;//So sad. The object to which x_1 pointed had been deleted.

	//One more case:
	int* pi_2 = new int;
	//process(pi_2);//pi_2 is a plain pointer. Cannot convert a plain int pointer to a shared_ptr<int>
	process(shared_ptr<int>(pi_2));//passed the test

	/*
	*When we bind a shared_ptr to a plain pointer, we give responsibility for that memory to that shared_ptr.
	* Once we give shared_ptr responsibility for a pointer, we should use a built-in pointer to access the memory
	*to which the shared_pointer now points.
	*
	*/

	/*Don't use get to initialize or assign another smart pointer*/
	shared_ptr<int> p7ka(new int(810));//reference count is 1
	int* q7ka = p7ka.get();//ok: but don't use q7ka in any way that might delete 
	//(the object to which )its pointer (points).
	{

		//new block
		//undefined: two independent shared_ptrsp point to the same memory


		//auto local11 = shared_ptr<int>(q7ka);
		//If the line above is not commented, q7ka will be equivalent to a null pointer. very dangerous. 

		//block ends, local is destroyed; the memory to which p7ka and q7ka points is freed.
	}
	//int foo11_ = *p7ka;
	//std::cout << "Now fool1_ is: " << foo11_ << std::endl;
	//memory leaking will occur, if aren't made commented two lines above.



	/*Other shared_ptr operations*/
	shared_ptr<int>p9ka(new int(8964));
	//p7ka = new_int(1024222);//error: cannot assign a pointer to a shared_ptr
	p9ka.reset(new int(1024));//ok: p7ka now points to a new object

	shared_ptr<std::string>p9kb(new std::string("eess"));
	std::string str1 = "ddff", * str2 = &str1;

	char newVal = 'Y';
	if (!p9kb.unique())
		p9kb.reset(new std::string(*str2));//we aren;t alone; allocate a new copy

	//Now that we know we're the only pointer, okay to change this object.
	*p9kb += newVal;
	std::cout << "*p9kb==" << *p9kb << std::endl;//string "eessY"
	std::cout << "*p9ka is: " << *p9ka << std::endl;//1024

	//exercise 12_10:
	shared_ptr<int>p12_10(new int(1210));
	process(shared_ptr<int>(p12_10));
	std::cout << *p12_10;//1210
	//correct!
}