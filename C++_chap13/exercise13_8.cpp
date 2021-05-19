#include<iostream>
using std::string;
class HasPtr {
public:
	HasPtr(const string& s = string()) :ps(new string(s)), i(0)
	{}
	HasPtr(HasPtr&);
	HasPtr& operator=(HasPtr& rhs)
	{
		auto str = *(rhs.ps);
		ps = new string(str);
		i = rhs.i;

		return *this;
	}
	void change_string(const string &s)
	{
		*ps = s;
	}

	void print_and_destroy()
	{
		std::cout << "*ps is:" << *ps << "\n" << "i is: " << i << std::endl;
		delete ps;//prevent memory leaking
		ps = nullptr;//prevent dangling pointer
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
	string str1 = "coup de'tat",str2="Fuhsiangrian";
	HasPtr Ob1(str1);
	HasPtr Ob2 = Ob1;
	Ob2.change_string(str2);
	Ob1.print_and_destroy();//coup de'tat
	Ob2.print_and_destroy();//Fuhsiangrian
	//PASSED THE TEST.
}