
#include<iostream>
using std::string;

class HasPtr {
public:
	HasPtr(const string& s = string()) :ps(new string(s)), i(0)
	{}
	HasPtr(HasPtr&);
	void print_and_destroy()
	{
		std::cout << "*ps is:" << *ps << "\n" << "i is: " << i << std::endl;
		delete ps;//prevent memory leaking
		ps = nullptr;//prevent dangling pointer
	}
	~HasPtr()
	{
		std::cout << "Let's destroy it!!!\n\n";
		delete ps;
		ps = nullptr;
	}
private:
	string* ps;
	int i;
};

HasPtr::HasPtr(HasPtr& orig)
{
	this->i = orig.i;
	string mkft = *(orig.ps);
	ps = new string(mkft);
}

int main()
{
	//test:
	HasPtr Ob1("kkk");
	HasPtr Ob2(Ob1);//print lets detroy it twice. Well done.
	//Ob1 Ob2 have same results.
	//So, ps in two objects points to two different strings with same value.
}