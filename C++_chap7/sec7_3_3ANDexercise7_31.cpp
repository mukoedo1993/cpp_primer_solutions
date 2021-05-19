//Every class defines a unique type.
#include<iostream>
#include"Screen_ver2.h"
#include"exercise7_31.h"
struct First {
	int memi;
	int getMem();
};
int First::getMem()
{
	return 3;
}

struct Second {
	int memi;
	int getMem();
};
int Second::getMem()
{
	return 3;
}
First Ob1;
//Second Ob2 = Ob1;//error: obj1 and obj2 have different types!

class Screen3;//declaration of the Screen3 class
class Link_screen {
	Screen window;
	Link_screen* next;
	Link_screen* prev;
};
/*
*1:A class must be defined--not just declared--before we can write code that create objects of that type.
*2:With one exception, data members can bespecified to be of a class type only if the class has been defined.
*3: Therefore, a class can have data members that are pointers or references to its own type.
*/
int main()
{
	
}