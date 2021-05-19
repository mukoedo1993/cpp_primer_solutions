
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
/*It won't compile.*/


#include<iostream>
#include<memory>
using std::shared_ptr;
using std::make_shared;

void process(shared_ptr<int>ptr)
{
	
}

void process1(shared_ptr<int>ptr)
{
	ptr = NULL;
}

int main()
{
	shared_ptr<int>yaju (new int(114514));
	
	//process(shared_ptr<int>(yaju.get()));
	/*If the code above is not commented:*/
	//1: get()will return a plain pointer points to which the shared_ptr<int> yaju points.
	//2:shared_ptr<int> will convert the pointer the get() returns to a shared_ptr<int>
	//3: the process function will take the shared_ptr<int> returns, and destroy the object to which yaju also points.
	//4:yaju will become a dangling pointer.
	//yaju = nullptr;
	//std::cout << yaju.use_count() << std::endl;

	//std::cout <<"Will yaju survive?"<< *yaju << std::endl;


	//The object to which yaju points will be destroyed.

	process1(shared_ptr<int>(yaju.get()));
}