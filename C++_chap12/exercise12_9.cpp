#include<iostream>
#include<memory>
int main()
{
	int* q = new int(42), * r = new int(100);
	delete r;//I add this line. 
	r = q;//r now points to what q points.//Without the line above, the object to which r had pointed will be dangling. 
	//But the results of printer will hold.


	std::cout << "r now points to : " << *r << ". q2 now points to: " << *q << std::endl;;//42 42

	//But, notice that the value to which r had pointed is not destroyed.
	auto q2 = std::make_shared<int>(42), r2 = std::make_shared<int>(100);
	//Note that, the destructor for shared_ptr decrements the reference count of the object to which
	//that shared_ptr points. If the count goes to zero, the shared_ptr destructor destroys the object
	//to which the shared_ptr points and frees the memory used by that object.
	
	r2 = q2;
	std::cout << "r2 now points to : " << *r2 << ". q2 now points to: " << *q2;//42 42
}
