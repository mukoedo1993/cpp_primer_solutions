//https://www.youtube.com/watch?v=eUsTO5BO3WI

#include<iostream>
#include<tuple>
#include<string>

/*
1:
tuple<return_type1,return_type2,...>tuple_name(parameters)
{
....
    return{name1, nam2};
}

2:No.th value of tuple's value =std::get<index No.>tuple_name(...)



*/

std::tuple<std::string, int>CreatePerson()
{
	return{ "Yaju",114514 };
}

int main()
{
	auto Person = CreatePerson();//Person={"Yaju",114514};

	std::string& name = std::get<0>(Person);
	int age = std::get<1>(Person);
	std::cout << "Case 1: name is: " << name << ".\nage is: " << age << std::endl;

	//Equivalent method:
	std::string name1; int age1;
	std::tie(name1, age1) = CreatePerson();
	std::cout << "Case 2: name is: " << name1 << ".\nage is: " << age1 << std::endl;

	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//another equivalent way:(Only works well since C++17:)
	auto [name3, age3] = CreatePerson();//structured bindings
	//Similar to MATLAB here, really.
	std::cout << "Case 3: name is: " << name3 << ".\nage is: " << age3 << std::endl;
}