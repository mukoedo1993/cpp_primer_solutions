#include<iostream>
#include<string>

using std::cout;
using std::string;
using std::boolalpha; using std::endl;
void ff(int*)
{

}
void ff(unsigned int)
{

}

int main()
{
	/*
	As usual, when we use an overloaded function, the context must make
	it clear which version is being used. When we declare a pointer to
	an overloaded function.
	*/
	void(*pf1)(unsigned int) = ff;//pf1 points to ff (unsigned int)
	 //void(*pf2)(int)=ff;//error: no ff with a matching parameter list
	 //double(*pf3)(int*)=ff;//error: return type of ff and pf3 don't match
}