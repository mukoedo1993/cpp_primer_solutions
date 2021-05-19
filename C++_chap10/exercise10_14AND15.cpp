#include<vector>
#include<iostream>
#include<string>
#include<numeric>//accumulate
#include<algorithm>
#include<fstream>
#include<sstream>
#include<list>
#include"elims_printPAC_ver1_1.h"
using std::vector;
using std::list;
using std::cout;
using std::string; using std::endl;

int main()
{
	//exercise 10_14:
	
	auto ex10_14 = [](int a, int b)->int {return(a + b); };
	cout <<"exercise10_14: " <<ex10_14(7, 9)<<std::endl;

	//exercise 10_15:
	int ex10_15i = 5;
	auto ex10_15 = [ex10_15i](int b) {return (ex10_15i + b); };
	cout << "exercise10_15: " << ex10_15(9) << std::endl;


}