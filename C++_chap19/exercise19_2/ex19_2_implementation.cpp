#include"StrVec_verex19_2.h"
#include<algorithm>
using std::allocator;
using std::string;
using std::vector;
allocator<string>StrVec::alloc;
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//The push_back function calls chk_n_alloc to ensure that there is room for an element.
//When chk_n_alloc returns, push_back knows that there is room for the new element. It asks alloc
//member to construct a new last element:
void StrVec::push_back(const std::string& s)
{
	chk_n_alloc();//ensure that there is room for another element.
	alloc.construct(first_free++, s);
}

//The alloc_n_copy member will allocate enough storage to hold its given range of elements, and
//will copy those elements into the newly allocated space. This function returns a pair of pointers, pointing
//to the beginning of the new space and just past the last element it copied.
std::pair<string*, string*>
StrVec::alloc_n_copy(const string* b, const string* e)
{
	//allocate space to hold as many elements as are in the range
	auto data = alloc.allocate(e - b);
	//initialize and return a pair constructed from data and 
	//the value returned by uninitialized_copy
	return{ data, uninitialized_copy(b, e, data) };
}

/*The free member*/
//The free member must destroy the elements and then deallocate the space this StrVec allocated.
void StrVec::free()
{
	//may not pass deallocate a 0 pointer; if elements is 0, there's no work to do.
	if (elements) {
		//destroy the old elements in reverse order
		for (auto p = first_free; p != elements;/*empty*/)
			alloc.destroy(--p);
		alloc.deallocate(elements, cap - elements);
	}
}

//copy_control members
//Given our alloc_n_memory and free members, the copy-control members of our class are straightforward.
//The copy constructor calls alloc_n_copy:
StrVec::StrVec(const StrVec& s)
{
	//call alloc_n_copy to allocate exactly as many elements as in s
	auto newdata = alloc_n_copy(s.begin(), s.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
}
StrVec::StrVec(std::istream& is)
{
	string str; vector<string>v_str;
	while (getline(is, str) && str != "q")
	{
		v_str.push_back(str);
	}
	elements=alloc.allocate(v_str.size());
	cap=first_free=uninitialized_copy(v_str.begin(), v_str.end(), elements);

}
StrVec::StrVec(std::initializer_list<std::string> lst)
{
	elements = alloc.allocate(lst.size());
	cap = first_free = uninitialized_copy(lst.begin(), lst.end(), elements);
}
//The destructor calls free:
StrVec::~StrVec() { free(); }

//The copy assignment operator calls alloc_n_copy before freeing its existing elements. By doing so it protects self_assignment:
StrVec& StrVec::operator=(const StrVec& rhs)
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
void StrVec::reallocate()
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
	free();//free the old space once we've moved the elements
	//update our data structure to point to the new elements
	//After moving the elements, we call free to destroy the old elements and free the memory that
	//this StrVec was using before the call to reallocate. The strings themselves no longer manage the memory
	//to which they had pointed; responsibility for their data has been moved to the elements in the new StrVec memory.
	//We don't know what value the strings in the old StrVec memory have, but we are guaranteed that it is safe to run the string
	//destructor on these objects.
	elements = newdata;
	first_free = dest;
	cap = elements + newcapacity;
}

void StrVec::reserve(size_t sz)
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

void StrVec::resize(size_t sz, const string &str=string()) {
	if (sz < size())
	{
		auto b = alloc.allocate(sz);
		auto e = uninitialized_copy(elements, elements + sz, b);
		free();
		elements = b;
		first_free = cap = e;
	}
	else if (sz == size())return;
	else if (sz > size() && sz < capacity())
	{
		auto b = alloc.allocate(sz); auto e1 = b + capacity();//(...,e1) unfilled part
		auto e2 = uninitialized_copy(elements, elements + size(), b);//copied part
		auto e3 = b + sz;//[e2,e3) the part we need to fill
		free();
		elements = b;
		first_free = e3; cap = e1;
		while ( e2 != e3)alloc.construct(e2++, str);
	}
	else
	{
		auto b = alloc.allocate(sz); //
		auto e2 = uninitialized_copy(elements, elements + size(), b);//[b,e2)copied part
		auto e3 = b + sz;//[e2,e3) the part we need to fill
		free();
		elements = b;
		cap=first_free = e3;
		while (e2 != e3)alloc.construct(e2++, str);
	}
	
}


StrVec::StrVec(StrVec&& s)noexcept//move won't throw any exceptions
//member initializers take over the resources in s
	:elements(s.elements),first_free(s.first_free),cap(s.cap)
{
	//member initializers take over the resources in s
	s.elements = s.first_free = s.cap = nullptr;
}