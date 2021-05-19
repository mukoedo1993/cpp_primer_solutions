#include<iostream>
#include<stdexcept>
using namespace std;
void test1(int k1,int k2)//throw(int,char,runtime_error())
{
	if (k2 == 0)throw domain_error("Should not 0!");
	else throw 4;
}
int main()
{
	int i1 = 20, i2 = 0;
	try {
		test1(i1, i2);
	}
	catch (int) { cout << "OK!" <<i1+i2<<"; "<< endl; }
	catch (char) { cout << "Skosh!"<<i1+i2<<"\n" << endl; }
	catch (domain_error r_1) { cout << r_1.what() << "\n!!!!\n"; }
	
}