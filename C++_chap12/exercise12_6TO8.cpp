#include<iostream>
#include<vector>
#include<list>
using std::vector;
#include<memory>
#include<initializer_list>
vector<int>* ex12_61(std::initializer_list<int>a)
{
	return new vector<int>(a);
}

std::shared_ptr<vector<int>> ex12_7(std::vector<int>a)
{
	std::shared_ptr<vector<int>> it;
	it = std::make_shared<vector<int>>(a);

	return it;
}


void ex12_61_accpt(vector<int>* v_ptr)
{
	for (auto it = v_ptr->begin(); it != v_ptr->end(); it++)
	{
		*it = 2 * (*it);
	}

}

void ex12_7_accpt(std::shared_ptr<vector<int>> s_ptr)
{
	for (auto it = s_ptr->begin(); it != s_ptr->end(); it++)
		*it = 2 * (*it);

}

//exercise 12_8:
bool b()
{
	int* p = new int;
	int q = 4;
	p = nullptr;
	return p;
}
bool b1()
{
	int* p = new int;
	int q = 4;
	p = &q;
	return p;

}

int main()
{
	std::initializer_list<int>lst_i = { 223,44,3,4,3,64,37,89,103 };
	auto x = ex12_61(lst_i);
	ex12_61_accpt(x);
	//exercise 12_6:
	std::cout << "exercise 12_6\n" << std::endl;
	for (auto it = x->begin(); it != x->end(); it++)
	{
		std::cout << *it << " ";//{ 223,44,3,4,3,64,37,89,103 }times 2. correct!
	}
	delete x;//prevent memory exhaustion
	x = nullptr;//prevent the existence of dangling pointer
	std::cout << std::endl;

	//exercise 12_7:
	auto x1 = ex12_7(lst_i);
	ex12_7_accpt(x1);
	std::cout << "\n]nexercise 12_7\n" << std::endl;
	for (auto it = x1->begin(); it != x1->end(); it++)
	{
		std::cout << *it << " ";//{ 223,44,3,4,3,64,37,89,103 }times 2. correct!
	}
	std::cout << std::endl;

	std::cout << std::boolalpha;
	std::cout << b() << std::endl;//false
	std::cout << b1() << std::endl;//true

}