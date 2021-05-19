#include<iostream>

class HasPtr {
public:
	friend void swap(HasPtr&,HasPtr&);
	HasPtr(const std::string& s = std::string()) :
		ps(new std::string(s)), i(0) {
		//each HasPtr has its own copy of the string to which ps points
	}
	HasPtr(const HasPtr& p) :
		ps(new std::string(*p.ps)), i(p.i) {}
	HasPtr& operator=(const HasPtr&);
	~HasPtr() { delete ps; }
	void print() {
		if (ps != nullptr)
			std::cout << *ps << " is ps. " << i << " is i. \n\n";
		else
			std::cout << "ps is a nullptr. And, i is: " << i << std::endl<<std::endl;
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
HasPtr& HasPtr::operator=(const HasPtr& rhs)
{
	auto newp = new std::string(*rhs.ps);//copy the underlying string
	delete ps;//free the old memory
	ps = newp;//copy data from rhs into this object
	i = rhs.i;
	return *this;
}

void swap(HasPtr& lhs, HasPtr& rhs)
{
	using std::swap;
	swap(lhs.i, rhs.i);
	if (lhs.ps != nullptr && rhs.ps != nullptr)
	{
		auto str1 = *(lhs.ps);
		*(lhs.ps) = *(rhs.ps);
		*(rhs.ps) = str1;
	}
	else if (lhs.ps == nullptr && rhs.ps != nullptr)
	{
		auto str1 = *(rhs.ps);
		lhs.ps = new std::string(str1);
		rhs.ps = nullptr;
	}
	else if (rhs.ps == nullptr && lhs.ps != nullptr)
	{
		auto str1 = *(lhs.ps);
		rhs.ps = new std::string(str1);
		lhs.ps = nullptr;
	}
	else;//null statement
	
	std::cout << "We have finished the swap once!\n";

}

int main()
{
	std::string str1 = "dojo", str2 = "majhong",str3="";
	HasPtr Ob1(str1), Ob2(str2), Ob3(Ob1),Ob4(str3);
	Ob1.print(); Ob2.print(); Ob3.print();
	swap(Ob2, Ob3);
	Ob2.print(); Ob3.print();//We have made a correct swap.
	Ob4.print();
}