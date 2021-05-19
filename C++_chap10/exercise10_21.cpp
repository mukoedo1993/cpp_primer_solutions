#include<algorithm>
#include<numeric>
#include<iostream>
#include<vector>
using std::vector;
using std::string;
using std::endl; using std::cout;
int main()
{
	int k=23;
	int &k1 = k;
	auto ex10_21=[=]()mutable->bool {if (k > 0) { k--; return false; } else return true; };
	//
	auto ex10_21_ = [&]()->bool {if (k > 0) { k--; return false; } else return true; };
	cout << std::boolalpha;
	cout << "Part a:\n";
	while (!ex10_21())
	{
		cout<<ex10_21()<<endl;
	} 

	cout << "\n\n";

	cout << "Part b:\n";
	while (!ex10_21_())
	{
		cout << ex10_21_() << endl;
	}


}