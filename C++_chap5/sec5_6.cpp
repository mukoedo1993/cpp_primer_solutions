#define _CRT_SECURE_NO_WARNINGS
/*The define above is very important.
Without it,strcat and strcpy will crash.
*/
#include<iostream>
#include<vector>
#include<string>
#include<stdexcept>
#include"Sales_item.h"

using std::cin; using std::cout;
using std::endl; using std::vector;
using std::begin; using std::end;
using std::string; using std::cerr;
void kk1(int kk2)
{
	if (kk2 % 2 == 0)goto ha1; 
	else if (kk2 % 5 == 0) goto ha2; 
	else goto ha3;
ha1:cout << "Case 1!" << endl;
ha2:cout << "Case 2!" << endl;
ha3:cout<<"Case 3!"<<endl;
}
int main()
{
	Sales_item item1, item2;
	cin >> item1 >> item2;
	//first check that item1 and item2 represent the same book
	if (item1.isbn() == item2.isbn())
	{
		cout << item1 + item2 << endl;
		//return 0;//indicate success
	}
	else {
		cerr << "Data must refere to same ISBN" << endl;
		return -1;//indicate failure
	}
	//if (item1.isbn() != item2.isbn())
		//throw std::runtime_error("Data must refer to same ISBN");

	//first check that the data are fore the same item
	/*
	int shds;
	cin >> shds;
	kk1(shds);
	*/
	/*
	Writing a Handler
	*/
	while (cin >> item1 >> item2) {
		try {
			// execute code that will add the two Sales_items
			//if the addition fails, the code throws a runtime_error exception
		}
		catch (std::invalid_argument err) {
			// remind the user that the ISBNs must match and prompt for another pair
			cout << err.what() << "\nTry again? Enter y or n" << endl;
			char c;
			cin >> c;
			if (!cin || c == 'n')
				break;//break out of the while loop
		}
	}

}
