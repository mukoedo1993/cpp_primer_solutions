#pragma once

//exercise 16_16:
#ifndef Vec_EX16_16_H
#define Vec_EX16_16_H
#include<memory>
#include<iostream>
#include<utility>
#include<string>
#include<vector>
using std::string;
//simplified implementation of the memory allocation strategy for a vector-like class
class TextQuery;
template<class T>
class Vec {
	friend class TextQuery;
	friend class StrBlobPtr;
	friend class StrBlob;
public:
	Vec() :
		elements(nullptr), first_free(nullptr), cap(nullptr) {}
	Vec(const Vec&);//copy constructor

	Vec(Vec<T>&&)noexcept;
	Vec(std::istream&);
	Vec(std::initializer_list<T>);
	Vec& operator=(const Vec&);//copy assignment
	~Vec(){free();}//destructor
	void push_back(const T&);//copy the element
	size_t size()const { return first_free - elements; }
	size_t capacity()const { return cap - elements; }
	T* begin()const { return elements; }
	T* end()const { return first_free; }
	void resize(size_t,const T &str=T());
	void reserve(size_t);
	//...
private:
	 static std::allocator<T> alloc;//allocates the elements
	void chk_n_alloc()//used by functions that add elements to a Vec
		//allocates the elements
	{
		if (size() == capacity())reallocate();
	}
	void alloc_n_move(size_t sz)
	{
		auto elem = elements;
		auto new_elements = alloc.allocate(sz);
		auto new_first_free = elements + sz;
		auto new_cap = cap + sz;
		for (size_t i = 0; i < sz; i++)
		{
			if (i < size())
				alloc.construct(new_first_free++, std::move(*elem++));
		}

		elements = new_elements; first_free = new_first_free; cap = new_cap;

	}
			void free(){
				if (elements) {
		//destroy the old elements in reverse order
		for (auto p = first_free; p != elements;/*empty*/)
			alloc.destroy(--p);
		alloc.deallocate(elements, cap - elements);
	}
		}
public:
	//utilities used by the copy constructor, assignment operator, and destructor.
	std::pair<T*, T*>alloc_n_copy
	(const T*, const T*);

	void reallocate();//get more space and copy the existing elements

private:
	T* elements;//pointer to the first element in the array.
	T* first_free;//pointer to the first free element in the array
	T* cap;//pointer to the end of the array
};

#endif