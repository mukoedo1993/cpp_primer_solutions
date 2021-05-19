#include<iostream>
#include<string>
using std::string;

struct person{
	string name_of_person;
	string address_of_person;
	string returnPerson()
	{
		return name_of_person;
	}
	void writein(string& person,string &address)
	{
		name_of_person = person;
		address_of_person = address;
	}
	bool is_same_person(const person &rhs)
	{
		return(name_of_person == rhs.name_of_person) && (address_of_person == rhs.address_of_person);
	}
	
};
std::istream  &write(std::istream &is, person& Ob)
{
	std::cout << "Please first enter name and then enter address:";
	std::cin >> Ob.name_of_person
	 >> Ob.address_of_person;
	return is;
}
std::ostream& print(std::ostream& os, person& Ob)
{
	std::cout<<"The name of person: "<<Ob.name_of_person<<std::endl
		<<"The address of person: "<< Ob.address_of_person;
	return os;
}
int main()
{
	person a_German, a_France;
	person a_Hunanese, a_Japanese;
	string G_p, G_a, F_p, F_a;
	int cnt = 0;
	while (std::cin >> G_p >> G_a >> F_p >> F_a&&cnt<10)
	{
		a_German.writein(G_p, G_a);
		a_France.writein(F_p, F_a);
		if (a_German.is_same_person(a_France))
		{
			std::cout << "Oh! A dual citizen!\n" << std::endl;
			cnt++;
		}
		else
		{
			std::cout << "Oh! Two different spirits!\n" << std::endl;
			cnt++;
			
		}
	}
	//Sec 7.8:
	write(std::cin, a_Hunanese);
	write(std::cin, a_Japanese);
	if (a_Hunanese.is_same_person(a_Japanese))
	{
		std::cout << "He(She) is a Hunanese Japanese or Japanese Hunanese.";
		print(std::cout, a_Hunanese);
	}
		
	return 0;
}