#include<vector>
using std::vector;
#include<algorithm>
#include<iostream>
using std::cout;using std::endl;
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
    cout<<"We called Foo1::sorted()&&!\n";
	return *this;
}
//this object is either const or it is an lvalue; either way we can't sort in place
Foo1 Foo1::sorted()const& {
	Foo1 ret(*this);//make a copy
	sort(ret.data.begin(), ret.data.end());//sort the copy
    cout<<"We called Foo1::sorted()const&\n";
	return ret;//return the copy
}
//We cannot add const&& or &. But const& and && is okay.
int main()
{
   vector<int>v1={1,3,-2,-8,13,27},v2={3,-8,6,-7,5,-13};
    Foo1(v2).sorted();//We called Foo1::sorted()&&!
    Foo1 ob1(v1);ob1.sorted();const Foo1 ob2(v2);//We called Foo1::sorted()const&
    std::move(ob1).sorted();//We called Foo1::sorted()&&!
    std::move(ob2).sorted();//We called Foo1::sorted()const&
}