#include<vector>
#include<algorithm>
#include<iostream>
//exercise 13_57:
using std::vector;
class Foo1 {
public:
	const Foo1() {}
	//sorted: retun a copy of the Foo1 object in which the vector is sorted
	Foo1 sorted()&&;//may run on modifiable rvalues
	Foo1 sorted()const&;//may run on any kind of Foo1
	//other members of Foo1

	Foo1(vector<int>v) { for_each(v.begin(), v.end(), [this](int t) {data.push_back(t); }); }
	void print() {
		for_each(data.cbegin(), data.cend(), [](const int& i) {std::cout << i << " "; });
		std::cout << std::endl;
	}

	using comp = bool(*)(const int&, const int&);
	Foo1 sorted(comp fn) {
		sort(data.begin(), data.end(), fn);
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
	std::cout << "Foo1 Foo1::sorted()&& triggered\n";
	return *this;
}
Foo1 Foo1::sorted()const&
{
	
	std::cout << "exercise 13_57 triggered!";//endlessly printed
	return Foo1(*this).sorted();
}

int main()
{
	const Foo1 Ob1;
	Ob1.sorted();
	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	/*
	*Result:
	*1st step:exercise 13_57 triggered!
	*2nd step: Foo1 Foo1::sorted()&& triggered
	*/
}