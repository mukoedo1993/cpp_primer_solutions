#include<iostream>
#include<fstream>
using std::cout;
struct X {
	X() { std::cout<< "X()" << std::endl; }
	X(const X&rhs) {std::cout << "X(const X&)" << std::endl; }
	const X& operator=(const X& rhs) {
		cout << "X==(const X&)" << std::endl;
		return rhs;
	}
	~X() { cout << "~X()" << std::endl; }
};

int main()
{
	X Ob1;
	X Ob2(Ob1);
	Ob1 = Ob2;
	X& Ob3 = Ob1;

}



