#include"Message_Folder.h"

int main()
{
	std::string str1 = "dojo", str2 = "village", str3 = "Los", str4 = "ANgeles";
	Message M1(str1), M2(str2), M3(M2), M4(str4),M5(str4);
	M5 = M1;
	Folder f1,f2,f3,f4;
	M1.save(f1); M1.save(f2);
	M2.save(f2); M2.save(f3); M4.save(f4);
	f1.print_all_Messages();
	f2.print_all_Messages();
	f3.print_all_Messages();
	f4.print_all_Messages();
	swap(M1, M4);
	std::cout << std::endl << std::endl;
	f1.print_all_Messages();
	f2.print_all_Messages();
	f3.print_all_Messages();
	f4.print_all_Messages();
	
	
	
	
	
}
