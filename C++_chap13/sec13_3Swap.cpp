//sec 13.3 Swap

//In additon to defining the copy-control members, classes that manage resources often
//also define a function named swap. Defining swap is particularly important for classes that
//we plan to use with algorithms that reorder elements.

//If a class defines its own swap, then the algorithm use that class-specific version.
//Otherwise, it uses the swap function defined by the library. 
//It involves a copy and two assugnments.

#include<iostream>
using std::string;
class HasPtr {
	friend void swap(HasPtr&, HasPtr&);
public:
	HasPtr(const std::string& s = std::string()) :
		ps(new std::string(s)), i(0), use(new std::size_t(1)) {}

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
	   unsigned i = 1;
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

HasPtr& HasPtr::operator=(const HasPtr& rhs)
{
	++* rhs.use;//increment the use count of the right-hand operand
	if (-- * use == 0) {
		delete ps;
		delete use;
	}
	ps = rhs.ps;//copy data from  rhs into this object
	i = rhs.i;
	use = rhs.use;
	return *this;//return this object
}


//
void swap(HasPtr& lhs, HasPtr&rhs)
{
	//It is essential to follow this form.
	using std::swap;
	swap(lhs.ps, rhs.ps);//swap the pointers, not the string data.
	swap(lhs.i, rhs.i);//swap the int members

	//Each call should be to swap, not std::wap.
}

int main()
{
	HasPtr Ob1(string("dojo")), Ob2(string("jigoku"));
	swap(Ob1, Ob2);
	Ob1 = Ob2;
}