#define _CRT_SECURE_NO_WARNINGS
/*The define above is very important.
Without it,strcat and strcpy will crash.
*/
#include<iostream>
#include<vector>
#include<string>
using std::cin; using std::cout;
using std::endl; using std::vector;
using std::begin; using std::end;
using std::string; using int_array = int[4];
int main()
{
	//exercise 3_44:
	
	//part 1: Range:
	int ia_1[3][4] = { 2,3,6,7,888,999,100,333,33,44,55,77 };
	for (int(&it1)[4] : ia_1)
		for (int(&it2) : it1)
			cout << it2 << "!" << endl;
	//part 2:subscript:
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
			cout << ia_1[i][j] << ";" << endl;
	}
	//part 3: pointer
	for (int_array* it_3 = begin(ia_1); it_3 != end(ia_1); it_3++)
		for (int* it_4 = begin(*it_3); it_4 != end(*it_3); it_4++)
			cout << *it_4 << "..." << endl;
	return 0;
}