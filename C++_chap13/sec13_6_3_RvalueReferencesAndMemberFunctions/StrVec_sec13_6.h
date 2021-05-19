#pragma once
#ifndef STRVEC_SEC13_6_H
#define STRVEC_SEC13_6_H
//SEC 13.6.3: page 544, rvalue references and member functions
#include<memory>
#include<iostream>
#include<utility>
#include<string>

using std::string;
class StrVec {
public:
	StrVec() :
		elements(nullptr), first_free(nullptr), cap(nullptr) {}
	StrVec(const StrVec&);//copy constructor
	StrVec& operator=(const StrVec&);//copy assignment
	~StrVec();//destructor
	void push_back(const std::string&);//copy the element
	void push_back(std::string&&);//move the element
	size_t size()const { return first_free - elements; }
	size_t capacity()const { return cap - elements; }
	std::string* begin()const { return elements; }
	std::string* end()const { return first_free; }
	//...
private:
	static std::allocator<std::string>alloc;
	void chk_n_alloc()
	{
		if (size() == capacity())reallocate();
	}
	std::pair<std::string*, std::string*>alloc_n_copy
	(const std::string*, const std::string*);
	void free();//destroy the elements and free the space
	void reallocate();//get more space and copy the existing elements
	std::string* elements;//pointer to the first element in the array.
	std::string* first_free;//pointer to the first free element in the array
	std::string* cap;//pointer to the end of the array
};
std::allocator<std::string>StrVec::alloc;
void StrVec::push_back(const std::string& s)
{
	chk_n_alloc();//ensure that there is room for another element.
	alloc.construct(first_free++, s);
	std::cout << "push_back(const std::string& s)\n";
}


/*push_back takes a string as an rvalue*/
//These members are nearly identical. The difference is that the rvalue reference version
//of push_back calls move to pass its parameter to construct. 

void StrVec::push_back(string&& s)
{
	chk_n_alloc();//reallocates the StrVec if necessary
	alloc.construct(first_free++, std::move(s));
	std::cout << "push_back(string&& s)\n";
}

std::pair<string*, string*>
StrVec::alloc_n_copy(const string* b, const string* e)
{
	auto data = alloc.allocate(e - b);
	return{ data, uninitialized_copy(b, e, data) };
}

void StrVec::free()
{
	if (elements) {
		//destroy the old elements in reverse order
		for (auto p = first_free; p != elements;/*empty*/)
			alloc.destroy(--p);
		alloc.deallocate(elements, cap - elements);
	}
}

StrVec::StrVec(const StrVec& s)
{
	auto newdata = alloc_n_copy(s.begin(), s.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
}

StrVec::~StrVec() { free(); }
StrVec& StrVec::operator=(const StrVec& rhs)
{
	auto data = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	elements = data.first;
	first_free = cap = data.second;
	return *this;
}
void StrVec::reallocate()
{
	auto newcapacity = size() ? 2 * size() : 1;
	auto newdata = alloc.allocate(newcapacity);
	auto dest = newdata;
	auto elem = elements;
	for (size_t i = 0; i != size(); ++i)
		alloc.construct(dest++, std::move(*elem++));
	free();
	elements = newdata;
	first_free = dest;
	cap = elements + newcapacity;
}


#endif