//The value version of HasPtr is:
#include<iostream>

class HasPtr {
public:
	HasPtr(const std::string& s = std::string()) :
		ps(new std::string(s)), i(0) {
		//each HasPtr has its own copy of the string to which ps points
	}
	
private:
	std::string* ps;
	int i;
};

//Valuelike copy-assignment operator
//Assignment operators typically combine the actions of the destructor and the copy constructor.
//In this case, we can handle self-assignment -- and make our code safe should an exception happen--
//--by first copying the right-hand side. After the copy is made, we'll free the left-hand side and update
//the pointer to the newly allocated string:


int main()
{
	HasPtr Ob1(std::string("naka"));
	HasPtr Ob2(Ob1), Ob3;
	Ob3 = Ob1;
}
//Conclusion:
//If we didn't define a destructor, the memory stored the string will be leak.
//If we didn't define a copy constructor, 
//then both the new object and the old object being copyed will point to the same underline string.