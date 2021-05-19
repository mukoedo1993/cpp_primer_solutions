#pragma once
#ifndef EXERCISE7_35_H
#define EXERCISE7_35_H
#include<iostream>
#include<string>
typedef std::string Type;
Type initVal() { std::string t = "55sjsdj"; return t; };
class Exercise {
public: 
	typedef double Type1;//redefined, error.
	Type setVal(Type);
	Type1 initial();
private:
	int val;
};
Type Exercise::setVal(Type parm) {
	std::string val1 = parm + initVal();
	return val1;
}




#endif