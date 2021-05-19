#pragma once
#ifndef HASAPTR_H
#define HASAPTR_H
#include<iostream>

//For sec 13-6-2 (PAGE 540)

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
		using std::swap;
		std::cout << "HasPtr& operator=(HasPtr rhs)\n";
		swap(*this, rhs); return *this;
	}
	/*Depending on the type or the move assignment, copy intialization uses either
	*the copy constructor or the move constructor; lvalues are copied and rvalues are
	*moved. As a result, this single assignment operator acts as both the copy assignment and move-assignment
	*operator.
	*/

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
