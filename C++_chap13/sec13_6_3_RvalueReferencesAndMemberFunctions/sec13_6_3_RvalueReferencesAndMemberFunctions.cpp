//Member functions other than constructors and assignment can benefit from providing both
//copy and move versions.
//Such move-enabled members typically use the same parameter pattern as the copy and the assignment operators---
//one version takes an lvalue reference to const, and the second takes an rvalue reference to nonconst.

//e.g. push_back
//Assume X is the element type, these containers define:
//void push_back(const X&);//case a: binds to any kind of X
//void push_back(X&&);//move:binds only to modifiable rvalues of type X

#include"StrVec_sec13_6.h"
#include<vector>
#include<algorithm>
using std::vector;

class Foo {
public:
	Foo& operator=(const Foo&)&;//may assign only to modifiable lvalues

	//A function can be both 1: reference 2:const
	//Foo someMem()& const {return *this;}//error:const qualifter must come first
	Foo anotherMem()const& { return *this; }
};

Foo& retFoo() { Foo Ob1; return  Ob1; }
Foo retVal() { return Foo(); }
//The reference qualifier can be either & or &&, indicating that this may point to
//a rvalue or lvalue, respectively. Like the const qualifier, a reference qualifier may appear only
//on a (nonstatic) member function and must appear in both the declaration and definition of the function.
Foo& Foo::operator=(const Foo& rhs)&//reference qualifier
{
	//do whatever is needed to assign rhs to this object
	return *this;
}


/*Overloading and Reference Functions*/
//1:We can overload a function based on its reference qualifier. 
//2: We may overload a function by its reference qualifier and by whether it is a const member.
//e.g. Foo1
class Foo1 {
public:
	//sorted: retun a copy of the Foo1 object in which the vector is sorted
	Foo1 sorted()&&;//may run on modifiable rvalues
	Foo1 sorted()const&;//may run on any kind of Foo1
	//other members of Foo1

	Foo1(vector<int>v) {for_each(v.begin(), v.end(), [this](int t) {data.push_back(t); });}
	void print() {
		for_each(data.cbegin(), data.cend(), [](const int &i) {std::cout << i << " "; });
		std::cout << std::endl;
	}
	//Comment:
	/*Here
	*
	*
	*/
	using comp = bool(*)(const int&, const int&);
	Foo1 sorted(comp fn) {
		sort(data.begin(), data.end(),fn);
		return *this;
	}
	Foo1 sorted(comp fn)const {
		Foo1 ret(*this);
		sort(ret.data.begin(), ret.data.end(), fn);
		return *this;
	}

private:
	vector<int>data;
};
//this object is an rvalue; so we can sort in place
Foo1 Foo1::sorted()&& {
	sort(data.begin(), data.end());
	return *this;
}
//this object is either const or it is an lvalue; either way we can't sort in place
Foo1 Foo1::sorted()const& {
	Foo1 ret(*this);//make a copy
	sort(ret.data.begin(), ret.data.end());//sort the copy
	return ret;//return the copy
}
//When we run sorted on an rvalue, it is safe to sort the data member directly.
//When we run sorted on a const rvalue or on an lvalue, we can't change this object,
//so we copy data before sorting it.

int main()
{
	/*Consider two kinds of void push_back()*/
	//These members are nearly identical. The difference is that the rvalue reference version of push_back
	//calls move to pass its parameter to construct. 
	StrVec vec;//empty StrVec
	string s = "some string or another";
	vec.push_back(s);//calls push_back(const string&)
	vec.push_back("done");//calls push_back(string&&)

	/*Rvalue and Lvalue Reference Member Functions*/
	string s1 = "a value", s2 = "another";
	auto a = (s1 + s2).find('a');

	//Here, we called the find member on the string rvalue that results from adding two strings. 
	//Sometimes such usage can bes surprising.
	s1 + s2 = "wow";//Here we assign to the rvalue result of concatenating these strings.
	std::cout << s1 + s2 << std::endl;//still, a valueanother

	
	//We may run a function qualified by &only on an lvalue and may run a function qualified by && only on an rvalue:
	
	Foo i, j;//i and j are lvalues
	
	i = j;//ok: i is an lvalue
	retFoo() = i;//ok: retFoo() returns an lvalue
	
	//retVal() = j;//error: retVal()returns an rvalue(lhs must take a lvalue)
	i = retVal();//ok: we can pass an rvalue as the rhs operand to assignment
	vector<int>v = { 12,15,27,39,4,1,0,-3 };
	Foo1 Ob1(v);
	Ob1.print();
}

