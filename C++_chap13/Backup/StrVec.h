#pragma once


#ifndef STRVEC_H
#define STRVEC_H
#include<memory>
#include<iostream>
#include<utility>
#include<string>

using std::string;
//simplified implementation of the memory allocation strategy for a vector-like class
class StrVec {
public:
	StrVec():
		elements(nullptr),first_free(nullptr),cap(nullptr){}
	StrVec(const StrVec&);//copy constructor
	StrVec& operator=(const StrVec&);//copy assignment
	~StrVec();//destructor
	void push_back(const std::string&);//copy the element
	size_t size()const { return first_free - elements; }
	size_t capacity()const { return cap - elements; }
	std::string* begin()const { return elements; }
	std::string* end()const { return first_free; }
	//...
private:
	static std::allocator<std::string>alloc;//allocates the elements
	void chk_n_alloc()//used by functions that add elements to a StrVec
		//allocates the elements
	{if (size() == capacity())reallocate();}
	
	//utilities used by the copy constructor, assignment operator, and destructor.
	std::pair<std::string*, std::string*>alloc_n_copy
	(const std::string*, const std::string*);
	void free();//destroy the elements and free the space
	void reallocate();//get more space and copy the existing elements

	std::string* elements;//pointer to the first element in the array.
	std::string* first_free;//pointer to the first free element in the array
	std::string* cap;//pointer to the end of the array
};
//alloc must be defined in the StrVec implementation file(WHY???????????)



//The class body defines several of its members:
//1: The default constructor(implicitly) default initializes alloc and (explicitly) initializes
//the pointers to nullptr, indicating that there are no elements.
//2: The size member returns the number of elements actually in use, which is equal to first_free-elements







#endif