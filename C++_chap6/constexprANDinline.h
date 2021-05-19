#pragma once
#ifndef CONSTEXPRANDINLINE_H
#define CONSTEXPRANDINLINE_H
#include<iostream>
using std::string;

	inline const string&
		shorterString(const string& s1, const string& s2)
	{
		return s1.size() <= s2.size() ? s1 : s2;
	}
	//constexpr functions
	/*
	A constexpr function is a function that can be used in a constant
	expression. A const expr function is defined like any other function
	but must meet certain restrictions.
	The return type and the type of each parameter in must ne a literal type, and the function
	body must contain exactly one return statement.
	*/
	constexpr int new_sz() { return 42; }
	constexpr size_t scale(size_t cnt) { return new_sz() * cnt; }
#endif