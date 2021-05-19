#include"example.h"
#include<iostream>
#include<vector>

double Example::rate = 6.5;
Example Ob1, * Ob2 = &Ob1;

//We could use an object or a pointer to class or scope access the static double value, vecSize, but only 
//trhough scope to get the vec,vec1 and vec2, respectively.

	std::vector<double>Example::vec(Example::vecSize);
	std::vector<double>Example::vec1(Ob1.vecSize);
	std::vector<double>Example::vec2(Ob2->vecSize);
	int main()
	{
		std::cout << Example::vec[0] << std::endl;
		std::cout << Example::vec1[1] << std::endl;
		std::cout << Example::vec2[1] << std::endl;
	}
