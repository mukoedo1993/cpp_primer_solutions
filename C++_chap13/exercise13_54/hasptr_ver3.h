
#pragma once
#ifndef HASAPTR_VER3_H
#define HASAPTR_VER3_H
#include<iostream>

//For exercise13_54:
//WRONG CODE. JUST FOR SOLVE THIS question.

class HasPtr {
public:
	//added move constructor
	HasPtr(HasPtr&& p)

		noexcept :ps(p.ps), i(p.i) {
		std::cout << "HasPtr(HasPtr&& p)\n";
		p.ps = 0;
	}
	//assignment operator in both move- and copy-assignment operator.
	/*
	The move-assignment operator does the same work as the destuctor and the move constructor.
	regardless of whether the copy or move constructor was used, the body of the assignment operator
	swaps the state of two operands.
	*/
	HasPtr& operator=(HasPtr rhs)
	{
		if (this != &rhs)
		{
			i = std::move(rhs.i);
			ps = std::move(rhs.ps);
			rhs.ps = nullptr;
		}
		return *this;
	}

	HasPtr& operator=(const HasPtr &rhs)
	{
		auto newp = new std::string(*rhs.ps);
		delete ps;
		ps = newp;
		i = rhs.i;
		return *this;
	}

	HasPtr(const std::string& s = std::string()) :
		ps(new std::string(s)), i(0) {

		//each HasPtr has its own copy of the string to which ps points
	}

	HasPtr(const HasPtr& p) :
		ps(new std::string(*p.ps)), i(p.i) {
		std::cout << "HasPtr(const HasPtr& p)\n";
	}

	~HasPtr() { delete ps; }
private:
	std::string* ps;
	int i;
};

#endif