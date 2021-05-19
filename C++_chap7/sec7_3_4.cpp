//Sec7_3_4:
#include<iostream>
#include<vector>
#include"Screen_ver4.h"
//Friend declaration and scope:
/*
*Classes and nonmember functions need not have been declared before
*they are used in a friend delcaration. When a name first appears in a friend
declaration, that name is implicitly assumed to be part of the surrounding

*/
struct X1111
{
	friend int f111();
	//X() { f(); }//error: no declaration for f
	void g();
	void h();

};
//void X : g() { return f(); }//error: f hasn't been declared.
int f111() 
{
	return 3;
};
void X1111::h() { std::cout<<std::endl<<f111(); }//ok: declaration for f is now in scope


int main()
{
	Screen scr(2, 3, 't');
	
	Window_mgr ob1;
	scr.display(std::cout);
	X1111 kk1;
	kk1.h();



}