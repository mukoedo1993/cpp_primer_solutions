#include<iostream>
#include<memory>
using std::string;
//Oridnarily, classes that manage resources that do not reside in the class must define the copy-control members.
//We can define the copy operations to make the class behave like a value or like a pointer.
//Classes that behave like values have their own state. When we copy a valuelike object, the copy and the original are 
//independent of each other.
//Classes that act like pointers share state. When we copy objects of such classes, the copy and the original use the same
//underlying data. 
//library containers and string class: valuelike behavior
//shared_ptr class pointer-like behavior
//IO types and unique-ptr neither valuelike nor pointerlike behavior.
class HasPtr {
public:
	HasPtr(const std::string& s = std::string()) :
		ps(new std::string(s)), i(0) {}
	~HasPtr() {
		delete ps;
		ps = nullptr;
	}
	HasPtr(HasPtr& orig)
	{
		i = orig.i;
		string str = *(orig.ps);
		ps = new string(str);
	}
	HasPtr& operator = (HasPtr& orig)
	{
		i = orig.i;
		string str = *(orig.ps);
		ps = new string(str);
		return *this;
	}

private: std::string* ps = nullptr;
	   unsigned i;
};

HasPtr f(HasPtr hp)//HasPtr passed by value. so it is copied
{
	HasPtr ret = hp;//copies the given HasPtr
	return ret;//ret and hp are destroyed

}

int main()
{
	HasPtr Ob1(string("jigoku")), Ob2(string("shojo")), Ob3 = Ob2,Ob4=Ob2;
	Ob4 = Ob1;
}
	