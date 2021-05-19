#include<map>
#include<iostream>
#include<vector>
#include<utility>
using std::map; using std::multimap;
using std::string; using std::vector;
//1: The map and unordered map container provide the subscript
// operator and a corresponding at function.
//2:The set types do not support subscripting because there is no "value"
//associated with a key in a set.
//3: We cannot subscript a multimap or an unordered_multimap because there may be
// more than one value associated with a given key.

int main()
{
	//c[k]
	/* Returns the element with key k; if k is not in c, adds a new, value-initailized
	* element with key k.
	*/

	//c.at[k]
	/*
	*Checked access to the element with key k; throws an out_of_range exception if k is not in
	*c.
	*
	*/
	map<string, int>c;
	auto it=c["kt"];
	std::cout << it << std::endl;//result: 0
	std::cout << c.begin()->second << std::endl;//result: 0

	//exercise11_24: 
	map<int, int>m;
	m[0] = 1;
	std::cout << "\n\nexercise11_24: The only element: first: " << m.begin()->first << std::endl
		<< "second: " << m.begin()->second << std::endl;


	//exercise11_25:
	//vector<int>v;
	//v[0] = 1;//error: vector script out of range.


	//exercise11_26:
	/*
	*Q1:What type can be used to subscript a map? 
	*A1: the key_type.
	*Q2: What type deos the subscript operator return?
	*A2: the mapped_type.
	*/

	/*
	*Q3: Give an concrete example--that is, define a map
	* and then write the types that can be used to subscript
	* the map and the type that would be returned from the subscript 
	*operator.
	*/
	string LMAO = "LMAO";
	map<string, size_t>ex11_26m;
	ex11_26m.insert(map<string, size_t>::value_type(LMAO, 17));
	
	map<string, size_t>::key_type str11_26 = "11_26banzai!";
	ex11_26m[str11_26] = 13;
	map<string, size_t>::mapped_type var1 = ex11_26m[str11_26];
	std::cout << "\n\n exercise11_26:" << var1 << std::endl;
}