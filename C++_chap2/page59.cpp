#include<iostream>
int main()
{
	//SECTION 2_4_1
	const int bufSize = 512;
	std::cout << bufSize << std::endl;
	//Sometimes we want to define a variable whose value we know cannot be changed.
	//It must be initialized.
	//const int bufSize;<-error
	int i1 = 42;
	const int& r1 = i1;//We can bind a const int reference to a plain int object
	std::cout << r1 << std::endl;
	const int& r2 = 42;//r2 is a reference i
	const int& r3 = r1 * 2;
	//int& r4 = r1 * 2;<-error
	double dval = 3.1415;
	const int& ri = dval;//dval was given to ri and cast into an integer:3
	std::cout << ri << std::endl;
	//The codes for three lines above run like:
	//const int temp=dval;
	//const int &ri = temp;
	int i3 = 42;
	int& r11 = i3;//r11 bound to i3
	const int& r22 = i3;//r22 also bound to i3;but cannot be used to change i3
	r11 = 0;
	i3 = 114;
	//r22 = 0;<-error
	std::cout << i3 << std::endl;
	std::cout << r22 << std::endl;
	//SECTION 2_4_2
	//We may store the address of a const object ONLY in a pointer to const.
	const double pi = 3.14;//pi is const;its value may not be changed.
	//double* ptr = &pi;<--error
	const double* cptr1 = &pi;//OK: cptr1 may point to a double that is const.
	//*cptr1 = 42;<-ERROR:cannot assign to *cptr
	std::cout << *cptr1 << std::endl;
	double dval1 = 3.1415;
	cptr1 = &dval1;//dval1 is a plain double;its value can be changed
	std::cout << *cptr1 << std::endl;//ok: but can't change dval through cptr
	//const pointers
	int errNumb11 = 0;
	int* const curErr1 = &errNumb11;//curErr will always point to errNumb
	*curErr1 = 514.1919;
	std::cout << errNumb11 << std::endl;
	const double pi111 = 3.14159;
	const double* const pip = &pi111;//pip is a const pointer to a const object
	int nkds2 = 5.6;
	//double *const p2=&nkds2; <-ERROR: we must use an address of integer object to initialize a constant pointer.
	int* const p2 = &nkds2;
	std::cout << *p2 << std::endl;
	const int i174 = 2646;
	const int* const p175 = &i174;
	std::cout << *p175 << std::endl;
	int i47 = 56;
	const int* p47 = &i47;
	std::cout << *p47 << std::endl;
	int i48 = 484;
	const int* p1 = &i48;
	std::cout << *p1 << std::endl;
	int i49 = 494;
	const int& const r49 = i49;
	std::cout << r49 << std::endl;
	int i50 = 20;
	const int isodf2 = i50, & isode2 = i50;
	std::cout << isodf2 << " " << isode2 << std::endl;

}