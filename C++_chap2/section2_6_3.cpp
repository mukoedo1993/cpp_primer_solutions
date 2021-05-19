#include<iostream>
#include<string>
#include "Esu_celebrity.h"
#include "Esu_fake.h"
int main()
{
	Esu_Celebrity data1;
	std::cin >> data1.name >> data1.ID >> data1.HP;
	std::cout << 2 * (data1.HP) << " "<<data1.name <<" "<< data1.ID;
}