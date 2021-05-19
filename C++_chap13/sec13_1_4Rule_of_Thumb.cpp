//The rule of Three/Five:
//1: Copy constructor 2: Copy-assignment operator 3: destructor 4: move constructor
//5:move-assignment constructor

//If one is needed, all five are needed.
// There is a example below. Notice that IT WON'T COMPILE.
#include<iostream>
class HasPtr {
public:
	HasPtr(const std::string&s=std::string()):
		ps(new std::string(s)),i(0){}
	~HasPtr() { delete ps; }
	//WRONG: HasPtr needds a copy constructor and copy-assignment operator
	//other members as before
	
private: std::string* ps=nullptr;
	   unsigned i;
};

HasPtr f(HasPtr hp)//HasPtr passed by value. so it is copied
{
	HasPtr ret = hp;//copies the given HasPtr
	return ret;//ret and hp are destroyed
	
}

int main()
{
	HasPtr p("some values");
	f(p);//when p completes, the memory to which p.ps points is freed.
	HasPtr q(p);//now both p and q point to invalid memory
	//double freed(corruption)


	//std::cout << std::boolalpha;
	//std::cout << q.is_valid()<<std::endl;
	//std::cout << p.is_valid() << std::endl;
}