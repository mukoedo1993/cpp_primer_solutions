#pragma once
#ifndef PERSON_H
#define PERSON_H
#include<iostream>
using std::string;
struct person {
	person() :name_of_person("Tom"), address_of_person("Los Angalas") {};//EXERCISE 7.15
private:
	string name_of_person;
	string address_of_person;
	string returnPerson()
	{
		return name_of_person;
	}
public:
	void writein(string& person, string& address)
	{
		name_of_person = person;
		address_of_person = address;
	}
	bool is_same_person(const person& rhs)
	{
		return(name_of_person == rhs.name_of_person) && (address_of_person == rhs.address_of_person);
	}

};
#endif