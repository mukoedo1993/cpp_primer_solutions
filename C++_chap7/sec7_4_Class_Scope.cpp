#include<iostream>
#include"Screen_ver5.h"


/*
*Compared to ver_4, we modify the class named Window_mgr.
*1: add a addScreen function.
*2: On the other hand, the return type is defined outside the class body, any
* name used in the return type is outside the class type. As a result, the return
* type must specify the class of which it is a member.
*
*
*/


/*Every class defines its own new scope. Outside the class scope,
* ordinary data and function members may be accessed only through an
*object, a reference, or a pointer using a member access operator.
*
*/
int main()
{
	Screen::pos ht = 24, wd = 80;//use the pos type defined by Screen
	Screen scr(ht, wd, ' ');
	Screen* p = &scr;
	char c = scr.get();//fetches the get member from the object scr
	c = p->get();//fetches the get member from the object to which p points
}