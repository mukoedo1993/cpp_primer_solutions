#include<iostream>
#include<memory>
using std::shared_ptr;
using std::make_shared;


int main()
{
	auto sp = make_shared<int>();//value-default initialized.
	auto p = sp.get();
	delete p;// first delete
	//second delete double-freed error.
}