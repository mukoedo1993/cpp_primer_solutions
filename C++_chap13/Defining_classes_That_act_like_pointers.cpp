#include<iostream>
#include<memory>
using std::string;

class HasPtr {
public:
	HasPtr(const std::string& s = std::string()) :
		ps(new std::string(s)), i(0),use(new std::size_t(1)) {}
	
	HasPtr(const HasPtr& p) :ps(p.ps), i(p.i), use(p.use) { ++* use; i++; }
	HasPtr& operator = (const HasPtr&);
	~HasPtr();
	std::size_t use_count() {
		return *use;
	}
	unsigned get_i() {
		return i;
	}

private: std::string* ps;
	   std::size_t* use;
	   unsigned i=1;
};

//When we copy or assign a HasPtr Object, we wan
HasPtr::~HasPtr()
{
	if (-- * use == 0)//if the reference count goes to 0
	{
		delete ps;//delete the string
		delete use;//and the counter
	}
}



HasPtr f(HasPtr hp)//HasPtr passed by value. so it is copied
{
	HasPtr ret = hp;//copies the given HasPtr
	return ret;//ret and hp are destroyed

}

HasPtr& HasPtr::operator=(const HasPtr& rhs)
{
	++*rhs.use;//increment the use count of the right-hand operand
	if (-- * use == 0) {
		delete ps;
		delete use;
	}
	ps = rhs.ps;//copy data from  rhs into this object
	i = rhs.i;
	use = rhs.use;
		return *this;//return this object
}

int main()
{
	HasPtr Ob1(string("jigoku")), Ob2(string("shojo"));
	std::cout << Ob1.use_count() << " " << Ob2.use_count() << std::endl ;
	std::cout << Ob1.get_i() << " " << Ob2.get_i() << std::endl;
	HasPtr Ob3(Ob1);
	std::cout << Ob1.use_count() << " " << Ob3.use_count() << std::endl;
	std::cout << Ob1.get_i() << " " << Ob3.get_i() << std::endl;
	Ob2 = Ob3;
	std::cout << Ob3.use_count() << " " << Ob2.use_count() << std::endl;
	std::cout << Ob3.get_i() << " " << Ob2.get_i() << std::endl;
	return 0;
}