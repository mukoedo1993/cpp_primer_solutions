#pragma once
#ifndef EX16_58_IMPLEMENTATION_H
#define EX16_58_IMPLEMENTATION_H
#include<algorithm>
using std::allocator;
using std::vector;

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//The push_back function calls chk_n_alloc to ensure that there is room for an element.
//When chk_n_alloc returns, push_back knows that there is room for the new element. It asks alloc
//member to construct a new last element:
template<class T>
std::allocator<T> Vec<T>::alloc;

template<typename T>
void Vec<T>::push_back(const T& s)
{
	chk_n_alloc();//ensure that there is room for another element.
	alloc.construct(first_free++, s);
}

//The alloc_n_copy member will allocate enough storage to hold its given range of elements, and
//will copy those elements into the newly allocated space. This function returns a pair of pointers, pointing
//to the beginning of the new space and just past the last element it copied.
template<typename T>
std::pair<T*, T*>
Vec<T>::alloc_n_copy(const T* b, const T* e)
{
	//allocate space to hold as many elements as are in the range
	auto data = alloc.allocate(e - b);
	//initialize and return a pair constructed from data and 
	//the value returned by uninitialized_copy
	return{ data, uninitialized_copy(b, e, data) };
}

/*The free member*/
//The free member must destroy the elements and then deallocate the space this Vec allocated.



//copy_control members
//Given our alloc_n_memory and free members, the copy-control members of our class are straightforward.
//The copy constructor calls alloc_n_copy:
template<typename T>
Vec<T>::Vec(const Vec<T>& s)
{
	//call alloc_n_copy to allocate exactly as many elements as in s
	auto newdata = alloc_n_copy(s.begin(), s.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
}
template<typename T>
Vec<T>::Vec(std::istream& is)
{
	T str; vector<T>v_str;
    try{
	while (getline(is,str) && str != "q")
	{
		v_str.push_back(str);
	}
	elements=alloc.allocate(v_str.size());
	cap=first_free=uninitialized_copy(v_str.begin(), v_str.end(), elements);
    }catch(...){std::cerr<<"Error!";exit(-1);}
}
template<typename T>
Vec<T>::Vec(std::initializer_list<T> lst)
{
	elements = alloc.allocate(lst.size());
	cap = first_free = std::uninitialized_copy(lst.begin(), lst.end(), elements);
}
//The destructor calls free:
//template<typename T>
//Vec<T>::~Vec() { free(); }

//The copy assignment operator calls alloc_n_copy before freeing its existing elements. By doing so it protects self_assignment:
template<typename T>
Vec<T>& Vec<T>::operator=(const Vec<T>& rhs)
{
	auto data = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	elements = data.first;
	first_free = cap = data.second;
	return *this;
}
//Like the copy constructor, the copy-assignment operator uses the values returned from alloc_n_copy to initialize its pointers.

//Moving, Not Copying, Elements during Reallocation
//Before we write the reallocate member, we should think a bit about what it must do.
//This function will:
//1: allocate memory for a new, larger array of strings
//2: construct the first part of that space to hold the existing elements
//3: Destroy the elements in the existing memory and dellocate that memory.
template<typename T>
void Vec<T>::reallocate()
{
	//we'll allocate space for twice as many elements as the current size
	auto newcapacity = size() ? 2 * size() : 1;
	//allocate new memory
	auto newdata = alloc.allocate(newcapacity);
	//move the data from the old memory to the new
	auto dest = newdata;//points to the next free position in the new array
	auto elem = elements;//points to the enxt element in the old array
	for (size_t i = 0; i != size(); ++i)
		alloc.construct(dest++, std::move(*elem++));
	free();
	elements = newdata;
	first_free = dest;
	cap = elements + newcapacity;
}
template<typename T>
void Vec<T>::reserve(size_t sz)
{
	std::cout << "capacity is: " << capacity()<<std::endl;
	if (sz == size())return;
	else if (sz > capacity()) {
		std::cout << "Reserve " << sz << std::endl;
		auto b = alloc.allocate(sz);
		auto e1 = b + sz;
		auto e2=std::uninitialized_copy(elements, first_free, b);
		free();
		elements = b;
		first_free = e2;
		cap = e1;
	}
	else;//null statement
}

template<typename T>
void Vec<T>::resize(size_t sz, const T &str) {
	if (sz < size())
	{
		auto b = alloc.allocate(sz);
		auto e = std::uninitialized_copy(elements, elements + sz, b);
		free();
		elements = b;
		first_free = cap = e;
	}
	else if (sz == size())return;
	else if (sz > size() && sz < capacity())
	{
		auto b = alloc.allocate(sz); auto e1 = b + capacity();//(...,e1) unfilled part
		auto e2 = std::uninitialized_copy(elements, elements + size(), b);//copied part
		auto e3 = b + sz;//[e2,e3) the part we need to fill
		free();
		elements = b;
		first_free = e3; cap = e1;
		while ( e2 != e3)alloc.construct(e2++, str);
	}
	else
	{
		auto b = alloc.allocate(sz); //
		auto e2 = std::uninitialized_copy(elements, elements + size(), b);//[b,e2)copied part
		auto e3 = b + sz;//[e2,e3) the part we need to fill
		free();
		elements = b;
		cap=first_free = e3;
		while (e2 != e3)alloc.construct(e2++, str);
	}
	
}

template<typename T>
Vec<T>::Vec(Vec<T>&& s)noexcept//move won't throw any exceptions
//member initializers take over the resources in s
	:elements(s.elements),first_free(s.first_free),cap(s.cap)
{
	//member initializers take over the resources in s
	s.elements = s.first_free = s.cap = nullptr;
}

template<typename T>
 template<class... Args> void Vec<T>::emplace_back(Args&&... args)
 {
     	chk_n_alloc();//ensure that there is room for another element.
	alloc.construct(first_free++, std::forward<Args>(args)...);
 }

#endif