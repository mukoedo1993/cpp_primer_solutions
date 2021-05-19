#include<memory>
#include<iostream>
#include<stdexcept>
using std::unique_ptr;
using std::shared_ptr;
int main()
{
	//We ask new to allocate an array of objects by specifying the number of objects to allocate
	// in a pair of square brackets after a type name.
	int get_size (5);
	int* pia = new int[get_size];//pia points to the first of these ints
	//The size inside the brakets must have integral type but need not be a constant.

	typedef int arrT[42];//arrT names the type array of 42 ints.
	int* p_yaju = new arrT;//allocates an array of 42 ints; p points to the first one

	//Here, new allocates an array of ints and returns a pointer to the first one. Even though there are no
	//brackets in our code, the compiler executes this expression using new[]. That is, the compiler excutes
	//this expression as if we had written:
	//int *p=new arrT[42];

	//When we get a pointer to allocate an array, we do not get an object with an array type. Instead, we get
	//a pointer to the element type of an array.


	/*Initializing an array of Dynamically allocated objects*/

	//block of ten strings; the first four are initialized from the given initializers
	int* pia_kimusa = new int[10];//block of ten unitialized ints
	int* pia2 = new int[10]();//block of ten ints value initialized to 0
	
	std::string* psa = new std::string[10];//block of ten empty strings
	std::string* psb = new std::string[10]();//block of ten empty strings


	//Under the new standard, we can also provide a braced list of elements initializers:
	//block of ten ints each initialized from the corresponding initializer
	int* pia3 = new int[10]{ 0,1,2,3,4,5,6,7,8,9 };
	
	//remaining elements are value initialized
	std::string* psa4 = new std::string[10]{"a","an","the",std::string(3,'x')};

	//Is it legal to dynamically allocate an empty array
	size_t n1_ = 1;
	int* p1_ = new int[n1_];//allocate an array to hold the elements
	//for (int* q = p; q != p + n; ++q);
	/* process the array */

	//Calling new[n] with n equal to 0 is legal even though we cannot create an array
	//variable of size 0:
	//char arr[0];//error: cannot define a zero_length array
	char* cp1 = new char[0];//ok: but cp can't be dereferenced
	
	/*Free a dynamic arrays*/
	int* psf = new int[10];
	int* psf1 = nullptr;
	delete[]psf;//psf must point to a dynamically array or be null
	delete[]psf1;
	
	typedef int arrTf[42];//arrT names the type array of 42 ints
	int* pf = new arrTf;//allocates an array of 42 ints; p points to the first one
	delete[]pf;

	/*Smart pointers and dynamic arrays*/
	//1: unique_ptr:
	unique_ptr<int[]>ups(new int[10]);
	//automatically uses delete[]to destroy its pointer

	//We cannot use a dot or an arrow member access operators.
	//After all, the unique_ptr points to an array, not an object, so these operators would be meaningless.

	//BUT, we can use the subscrpt operator
	for (size_t i = 0; i != 10; i++)
	{
		ups[i] = i*i;//assign a new value to each of the elements
		std::cout << "ups[i] is" << ups[i]<<std::endl;
	}
	ups.reset();
	//2: shared_ptr
	//Unlike unique_ptr, shared_ptr provide no direct support for managing dynamic array. 
	//We must provide our own deleter.

	shared_ptr<int>sps(new int[10], [](int* p) {delete[]p; });
	
	

	//The fact that shared_ptr don't have subscript operator and don't support pointer arithmetic
	for (size_t i = 0; i != 10; ++i)
	{
		*(sps.get() + i) = i;//use get to get a built-in pointer.
		std::cout << *(sps.get() + i) << " ";
	}
	std::cout << std::endl;
	sps.reset();//uses the lambda we supplied
	std::cout << std::boolalpha;
	std::cout << (sps == nullptr) << std::endl;//true
}