#include"Message_Folder.h"

int main()
{
	Message M1("str1"),M2("str2"),M3("str4");
	Folder fld1, fld2=fld1;
	M1.save(fld1);
	M2.save(fld1);
	M3.save(fld2);
}