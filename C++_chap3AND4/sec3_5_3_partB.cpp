#include<iostream>
#include<vector>
#include<string>
using std::cin; using std::cout;
using std::endl; using std::vector;
using std::begin; using std::end;
using std::string;
int main()
{
	int ia[] = { 0,2,4,6,8 };// array with 5 elements of type int
	int last = *(ia + 4);//ok: initializes last to 8, the value of ia[4].
	last = *ia + 4;//ok: last=4,equivalent to ia[0]+4
	int* p = &ia[2];//p points to the element indexed by 2.
	int j = p[1];//it equals int j=*(p+1)
	int k = p[-2];//it equals int k=*(p-2)
	cout << "j is: " << j << endl;
	cout << "k is: " << k << endl;
}