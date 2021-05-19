#include<iostream>
#include<vector>
#include<map>
#include<utility>
using std::vector; using std::map;
using std::string; using std::pair;

int main()
{
	//exercise11.28:
	string str("USC");
	vector<int>V = {23,34734,238,38,49};
	map<string, vector<int>>var_ex11_28;
	var_ex11_28.insert(make_pair(str, V));
	map<string, vector<int>>::iterator it11_28 = var_ex11_28.find(str);
	std::cout << it11_28->first << std::endl;//USC
	std::cout << it11_28->second.at(3);//38

	//exercise 11_29:
	std::cout << "\n\n\n\nexercise11_29:\n\n";
	std::cout << std::boolalpha;
	string str1 = "jk";
	pair<map<string, vector<int>>::iterator, map<string, vector<int>>::iterator>pair11_29 =
		var_ex11_28.equal_range(str1);
	std::cout << (var_ex11_28.end() == pair11_29.first && var_ex11_28.end() == pair11_29.second)<<std::endl;//true
		
	map<string, vector<int>>::iterator lower_bound_it = var_ex11_28.lower_bound(str1);//true
	std::cout << (var_ex11_28.end() == lower_bound_it) << std::endl;

	map<string, vector<int>>::iterator upper_bound_it = var_ex11_28.upper_bound(str1);//true
	std::cout << (var_ex11_28.end() == upper_bound_it) << std::endl;
	
}