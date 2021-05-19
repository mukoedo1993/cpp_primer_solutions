#include<iostream>
#include<string>
using std::string;

struct person {
	person() :name_of_person("Tom"), address_of_person("Los Angalas") {};
private:
	string name_of_person;
	string address_of_person;
public:
	string returnPerson()
	{
		return name_of_person;
	}
	void writein(string& person, string& address)
	{
		name_of_person = person;
		address_of_person = address;
	}
	bool is_same_person(const person& rhs)
	{
		return(name_of_person == rhs.name_of_person) && (address_of_person == rhs.address_of_person);
	}
	string print_address()
	{
		std::cout<< address_of_person;
		return address_of_person;
	}
	string print_name()
	{
		std::cout<< name_of_person;
		return name_of_person;
	}

};

int main()
{
	person a_German();
	person a_France, a_Dutch;
	string name1, address1;
	std::cin >> name1 >> address1;
	a_France.writein(name1, address1);
	name1 = name1 + a_France.print_name();
	address1 = a_France.print_address()+" kkt";
	std::cout << std::endl << address1;
	a_Dutch.writein(name1 , address1 );



}