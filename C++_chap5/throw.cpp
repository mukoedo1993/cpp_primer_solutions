#include<iostream>
#include<stdexcept>
using namespace std;
void test()throw(int, char, runtime_error())
{
	throw runtime_error("What the hack>");//CASE 3
	//throw 10; CASE 1
	//throw 't' CASE 2
}
int main()
{
	try {
		test();
	}
	catch (int e) { cout << "int!" << endl; }//CASE 1
	catch (char c) { cout << "char!" << endl; }//CASE 2
	catch (runtime_error err) { cout << err.what()<<"\nRuntime err!" << endl; }//case 3:
	//cout<<err.what() print out the content of the runtime_error
}
