#include<iostream>
//#include"Screen.h"
#include"exercise7_24.h"// enhanced Screen.h
int main()
{
	
	Screen myscreen(4,8,'c');
	myscreen.print();
	myscreen.cursor_print();
	myscreen.move(2, 1).set('#');
	//equivalent to:
	myscreen.print();
	myscreen.cursor_print();
	myscreen.move(2, 1); myscreen.set('#');
	//If we returns Screen not Screen&
	Screen temp = myscreen.move(2, 1);//the return value would be copied
	temp.set('!');//the contents inside myScreen would be unchanged.
	myscreen.print(); myscreen.cursor_print();
	temp.print(); myscreen.cursor_print();
	
}
