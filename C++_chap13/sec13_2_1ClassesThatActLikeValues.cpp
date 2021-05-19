//To provide valuelike behavior, each object has to have its own copy of the resource that the class manages.
//That means each HasPtr object must have its own copy of the string to which ps points. To implement valuelike 
//behavior HasPtr needs:
//1: A copy constructor that copies the string, not just the pointer
//2: A destructor to free the string
//3: A copy-assignment operator to free the object's existing string and copy the string from its right-hand oeprand.

//The value version of HasPtr is:
#include<iostream>

class HasPtr {
public:
	HasPtr(const std::string& s = std::string()) :
		ps(new std::string(s)), i(0) {
		//each HasPtr has its own copy of the string to which ps points
	}
	HasPtr(const HasPtr&p):
		ps(new std::string(*p.ps)),i(p.i){}
	HasPtr& operator=(const HasPtr&);
	~HasPtr() { delete ps; }
private:
	std::string* ps;
	int i;
};

//Valuelike copy-assignment operator
//Assignment operators typically combine the actions of the destructor and the copy constructor.
//In this case, we can handle self-assignment -- and make our code safe should an exception happen--
//--by first copying the right-hand side. After the copy is made, we'll free the left-hand side and update
//the pointer to the newly allocated string:
HasPtr& HasPtr::operator=(const HasPtr& rhs)
{
	auto newp = new std::string(*rhs.ps);//copy the underlying string
	delete ps;//free the old memory
	ps = newp;//copy data from rhs into this object
	i = rhs.i;
	return *this;
}

int main()
{
	HasPtr Ob1(std::string("naka"));
	HasPtr Ob2(Ob1), Ob3;
	Ob3 = Ob1;
}